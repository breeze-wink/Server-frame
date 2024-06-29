#include "xml.h"
#include "parser.h"
#include <fstream>
#include <sstream>
using namespace breeze::xml;

Xml::Xml(const char * name) : m_name(name)
{
}

Xml::Xml(const string & name) : m_name(name)
{
}

Xml::Xml(const Xml & other)
{
    copy(other);
}

Xml::Xml(Xml && other)
{
    swap(other);
}

Xml::~Xml()
{
    clear();
}

string Xml::name() const
{
    return m_name;
}

void Xml::name(const string & name)
{
    m_name = name;
}

string Xml::text() const
{
    return m_text;
}

void Xml::text(const string & text)
{
    m_text = text;
}

Value & Xml::attr(const string & key)
{
    return m_attrs[key];
}

void Xml::attr(const string & key, const Value & value)
{
    m_attrs[key] = value;
}

Xml & Xml::operator = (const Xml & other)
{
    if (this == &other)
    {
        return *this;
    }
    copy(other);
    return *this;
}

Xml & Xml::operator = (Xml && other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    swap(other);
    return *this;
}

void Xml::append(const Xml & child)
{
    m_child.push_back(child);
}

void Xml::append(Xml && child)
{
    m_child.push_back(std::move(child));  
}

void Xml::remove(int index)
{
    if (m_child.empty())
    {
        return;
    }
    int size = (int)m_child.size();
    if (index < 0 || index >= size)
    {
        return;
    }
    m_child.erase(m_child.begin() + index);
}

void Xml::remove(const char * name)
{
    for (auto it = m_child.begin(); it != m_child.end();)
    {
        if (it->name() == name)
        {
            it = m_child.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Xml::remove(const string & name)
{
    remove(name.c_str());
}

Xml & Xml::operator [] (int index)
{
    return m_child.at(index);
}

Xml & Xml::operator [] (const char * name)
{
    for (auto it = m_child.begin(); it != m_child.end(); ++it)
    {
        if (it->name() == name)
        {
            return *it;
        }
    }
    m_child.push_back(Xml(name));
    return m_child.back();
}

Xml & Xml::operator [] (const string & name)
{
    return (*this)[name.c_str()];
}

int Xml::size() const
{
    return (int)m_child.size();
}

bool Xml::empty() const
{
    return m_child.empty();
}

void Xml::clear()
{
    m_name.clear();
    m_text.clear();
    m_attrs.clear();
    m_child.clear();
}

string Xml::str() const
{
    if (m_name.empty())
    {
        return "";
    }
    std::ostringstream oss;
    oss << "<";
    oss << m_name;
    for (auto it = m_attrs.begin(); it != m_attrs.end(); ++it)
    {
        oss << " " << it->first << "=\"" << (string)it->second << "\"";
    }
    oss << ">";
    for (auto it = m_child.begin(); it != m_child.end(); ++it)
    {
        oss << it->str();
    }
    oss << m_text;
    oss << "</" << m_name << ">";
    return oss.str();
}

bool Xml::load(const string & filename)
{
    Parser p;
    if (!p.load(filename))
    {
        return false;
    }
    *this = p.parse();
    return true;
}

bool Xml::load(const char *buf, int len)
{
    Parser p;
    if (!p.load(buf, len))
    {
        return false;
    }
    *this = p.parse();
    return true;
}

bool Xml::save(const string & filename)
{
    std::ofstream ofs(filename);
    if (ofs.fail())
    {
        return false;
    }
    ofs << str();
    ofs.close();
    return true;
}

void Xml::copy(const Xml & other)
{
    clear();
    m_name = other.m_name;
    m_text = other.m_text;
    m_attrs = other.m_attrs;
    m_child = other.m_child;
}

void Xml::swap(Xml & other)
{
    clear();
    m_name.swap(other.m_name);
    m_text.swap(other.m_text);
    m_attrs.swap(other.m_attrs);
    m_child.swap(other.m_child);
}
