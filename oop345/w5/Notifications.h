#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Message.h"
namespace w5 {
	const size_t MAX_NOTIFICATIONS = 10;
	
	class Notifications
	{
	private:
		Message messageTable[MAX_NOTIFICATIONS];
		size_t count = 0;
	public:
		Notifications()
		{
		}
		Notifications(const Notifications& other)
		{
			*this = other;
		}
		Notifications& operator=(const Notifications& other)
		{
			if (this != &other)
			{
				this->count = other.count;
				for (size_t i = 0; i < count; i++)
				{
					this->messageTable[i] = other.messageTable[i];
				}
			}
			return *this;
		}
		Notifications(const Notifications&& other)
		{
			*this = std::move(other);		
		}
		Notifications&& operator=(Notifications&& other) 
		{
			if (this != &other)
			{
				this->count == other.count;
				for (size_t i = 0; i < count; i++)
				{
					this->messageTable[i] = std::move(other.messageTable[i]);
				}
			}
			return std::move(*this);
		}
		~Notifications() 
		{
			
		}
		void operator+=(const Message& msg)
		{
			static int i = 0;
			if (count < MAX_NOTIFICATIONS)
			{
				this->messageTable[i] = msg;
				count++;
				i++;
			}
			else
			{
				std::cerr << "messageTable full.";
				exit(99);
			}
		}
		void display(std::ostream& os) const
		{
			for (size_t i = 0; i < count; i++)
			{
				messageTable[i].display(os);
			}
		}
	};
}