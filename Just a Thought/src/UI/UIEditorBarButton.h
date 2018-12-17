#pragma once
#include <UI/UIElement.h>
#include <UI/ButtonBase.h>
class UIEditorBarButton :
	public Jangine::ButtonBase
{
public:
	UIEditorBarButton(std::string path);
	~UIEditorBarButton();

	void draw() override;
	void update() override;
private:
	void onHover() override;
	int alpha;
};

