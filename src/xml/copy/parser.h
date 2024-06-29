#pragma once
#include "xml.h"


namespace breeze
{
    namespace xml
    {
        class Parser
        {
        public:
            Parser() = default;
            bool load(const string & filename);
            bool load(const char * buf, int len);
            Xml parse();

        private:
            void skip_white_space();
            bool parse_declaration();
            bool parse_comment();
            Xml parse_element();
            string parse_element_name();
            string parse_element_text();
            string parse_element_attr_key();
            string parse_element_attr_val();

        private:
            string m_str;
            int m_idx = 0;
        };
    }
}