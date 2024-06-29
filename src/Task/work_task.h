#pragma once
#include "task.h"
using namespace breeze::thread;

namespace breeze::task
{
    class WorkTask : public Task
    {
    public:
        WorkTask() = delete;
        WorkTask(int sockfd);
        ~WorkTask() = default;

        virtual void run() override;
        virtual void destroy() override;

    private:
        int m_sockfd = 0;
        bool m_closed = false;
    };
}