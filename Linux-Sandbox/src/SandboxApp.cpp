#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		std::cout << "Created" << std::endl;
	}

	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
