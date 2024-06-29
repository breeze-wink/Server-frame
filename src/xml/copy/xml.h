#pragma once

#include <iostream>
#include <map>
#include <vector>

#include <string>
using std::string;

#include "Value.h"
using namespace breeze::utility;


namespace breeze
{
    namespace xml
    {
        class Xml
        {
        public:
            Xml() = default;
            Xml(const char * name);
            Xml(const string & name);
            Xml(const Xml & other);
            Xml(Xml && other);
            ~Xml();

            string name() const;
            void name(const string & name);

            string text() const;
            void text(const string & text);

            Value & attr(const string & key);
            void attr(const string & key, const Value & value);

            Xml & operator = (const Xml & other);
            Xml & operator = (Xml && other) noexcept;

            void append(const Xml & child);
            void append(Xml && child);

            void remove(int index);
            void remove(const char * name);
            void remove(const string & name);

            Xml & operator [] (int index);
            Xml & operator [] (const char * name);
            Xml & operator [] (const string & name);

            int size() const;
            bool empty() const;
            void clear();

            string str() const;
            friend std::ostream & operator << (std::ostream & os, const Xml & xml)
            {
                os << xml.str();
                return os;
            }

            typedef std::vector<Xml>::iterator iterator;
            iterator begin()
            {
                return m_child.begin();
            }
            iterator end()
            {
                return m_child.end();
            }
            iterator erase(iterator it)
            {
                it->clear();
                return m_child.erase(it);
            }

            bool load(const string & filename);
            bool load(const char * buf, int len);
            bool save(const string & filename);

        private:
            void copy(const Xml & other);
            void swap(Xml & other);

        private:
            string m_name;
            string m_text;
            std::map<string, Value> m_attrs;
            std::vector<Xml> m_child;
        };
    }
}