#pragma once

namespace breeze
{
    namespace task
    {
        class EchoTask
        {
        public:
            EchoTask() = delete;
            EchoTask(int sockfd);
            ~EchoTask();

            bool run();
            void destroy();
        private:
            int m_sockfd = 0;
        };
    }
}