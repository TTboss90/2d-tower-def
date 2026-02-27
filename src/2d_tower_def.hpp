
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
	
	virtual void draw_scene() = 0;
	virtual void update() = 0;

	std::unique_ptr<scene> next_scene{ nullptr };

	bool exit = false;

private:
};

class main_menu : public scene
{
public:
	main_menu();
	~main_menu() override;

	void draw_scene() override;
	void update() override;

private:
	std::array<button, 5> m_buttons;

	int m_click_count = 0;
};

class game_scene : public scene
{
	public:
	game_scene();
	~game_scene() override;
	void draw_scene() override;
	void update() override;

private:
	Camera2D m_camera{ 0 };

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