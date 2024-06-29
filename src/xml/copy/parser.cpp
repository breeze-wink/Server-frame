#include "parser.h"
#include <fstream>
#include <sstream>
using namespace breeze::xml;

bool Parser::load(const string & filename)
{
    std::ifstream fin(filename);
    if (fin.fail())
    {
        return false;
    }
    std::stringstream ss;
    ss << fin.rdbuf();
    m_str = ss.str();
    m_idx = 0;
    return true;
}

bool Parser::load(const char * buf, int len)
{
    m_str.assign(buf, len);
    m_idx = 0;
    return true;
}

void Parser::skip_white_space()
{
    while (m_str[m_idx] == ' ' || m_str[m_idx] == '\r' || m_str[m_idx] == '\n' || m_str[m_idx] == '\t')
    {
        m_idx++;
    }
}

Xml Parser::parse()
{
    skip_white_space();
    if (m_str.compare(m_idx, 5, "<?xml") == 0)
    {
        if (!parse_declaration())
        {
            throw std::logic_error("parse declaration error");
        }
    }
    skip_white_space();
    while (m_str.compare(m_idx, 4, "<!--") == 0)
    {
        if (!parse_comment())
        {
            throw std::logic_error("parse comment error");
        }
        skip_white_space();
    }
    if (m_str[m_idx] == '<' && (isalpha(m_str[m_idx+1]) || m_str[m_idx+1] == '_'))
    {
        return parse_element();
    }
    throw std::logic_error("parse element error");
}

bool Parser::parse_declaration()
{
    if (m_str.compare(m_idx, 5, "<?xml") != 0)
    {
        return false;
    }
    m_idx += 5;
    size_t pos = m_str.find("?>", m_idx);
    if (pos == std::string::npos)
    {
        return false;
    }
    m_idx = (int)pos + 2;
    return true;
}

bool Parser::parse_comment()
{
    if (m_str.compare(m_idx, 4, "<!--") != 0)
    {
        return false;
    }
    m_idx += 4;
    size_t pos = m_str.find("-->", m_idx);
    if (pos == std::string::npos)
    {
        return false;
    }
    m_idx = (int)pos + 3;
    return true;
}

Xml Parser::parse_element()
{
    Xml elem;
    m_idx++;
    skip_white_space();
    const string & name = parse_element_name();
    elem.name(name);
    while (m_str[m_idx] != '\0')
    {
        skip_white_space();
        if (m_str[m_idx] == '/')
        {
            if (m_str[m_idx+1] == '>')
            {
                m_idx += 2;
                break;
            }
            else
            {
                throw std::logic_error("xml empty element is error");
            }
        }
        else if (m_str[m_idx] == '>')
        {
            m_idx++;
            string text = parse_element_text();
            if (!text.empty())
            {
                elem.text(text);
            }
        }
        else if (m_str[m_idx] == '<')
        {
            if (m_str[m_idx+1] == '/')
            {
                // find the end tag
                string end_tag = "</" + name + ">";
                size_t pos = m_str.find(end_tag, m_idx);
                if (pos == std::string::npos)
                {
                    throw std::logic_error("xml element " + name + " end tag not found");
                }
                m_idx = (int)(pos + end_tag.size());
                break;
            }
            else if (m_str.compare(m_idx, 4, "<!--") == 0)
            {
                // parse xml comment
                if (!parse_comment())
                {
                    throw std::logic_error("xml comment is error");
                }
            }
            else
            {
                // parse child element
                elem.append(parse_element());
            }
        }
        else
        {
            // parse xml attr
            string key = parse_element_attr_key();
            skip_white_space();
            if (m_str[m_idx] != '=')
            {
                throw std::logic_error("xml element attr is error" + key);
            }
            m_idx++;
            skip_white_space();
            string val = parse_element_attr_val();
            elem.attr(key, val);
        }
    }
    return elem;
}

string Parser::parse_element_name()
{
    int pos = m_idx;
    if (isalpha(m_str[m_idx]) || (m_str[m_idx] == '_'))
    {
        m_idx++;
        while (isalnum(m_str[m_idx]) || (m_str[m_idx] == '_') || (m_str[m_idx] == '-') || (m_str[m_idx] == ':') || (m_str[m_idx] == '.'))
        {
            m_idx++;
        }
    }
    return m_str.substr(pos, m_idx - pos);
}

string Parser::parse_element_text()
{
    int pos = m_idx;
    while (m_str[m_idx] != '<')
    {
        m_idx++;
    }
    return m_str.substr(pos, m_idx - pos);
}

string Parser::parse_element_attr_key()
{
    int pos = m_idx;
    if (isalpha(m_str[m_idx]) || (m_str[m_idx] == '_'))
    {
        m_idx++;
        while (isalnum(m_str[m_idx]) || (m_str[m_idx] == '_') || (m_str[m_idx] == '-') || (m_str[m_idx] == ':'))
        {
            m_idx++;
        }
    }
    return m_str.substr(pos, m_idx - pos);
}

string Parser::parse_element_attr_val()
{
    if (m_str[m_idx] != '"')
    {
        throw std::logic_error("xml element attr value should be in double quotes");
    }
    m_idx++;
    int pos = m_idx;
    while (m_str[m_idx] != '"')
    {
        m_idx++;
    }
    m_idx++;
    return m_str.substr(pos, m_idx - pos - 1);
}