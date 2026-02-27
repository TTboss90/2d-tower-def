
#include <raylib.h>
#include <array>
#include <functional>
#include <string>
#include <memory>

struct button
{
	Rectangle rect{ 0 };
	std::function<void()> on_click;
	std::string label;
};

class scene
{
public:
	scene() = default;
	virtual ~scene() = default;
	
	virtual void draw_scene() {};
	virtual void update() {};

private:
};

class main_menu : public scene
{
public:
	main_menu();
	~main_menu() override = default;

	void draw_scene() override;
	void update() override;

private:
	Camera2D m_camera{ 0 };

	float m_dt{ 0 };

	std::array<button, 5> m_buttons;
};

class tower_def
{
public:
	tower_def();
	~tower_def();
	void run();

private:

	std::unique_ptr<scene> m_scene{ nullptr };
};