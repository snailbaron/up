#include "ui.hpp"

void Ui::processInputEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved) {
        auto newFocusedWidget =
            widgetAtPosition(event.mouseMove.x, event.mouseMove.y);
        if (newFocusedWidget != _focusedWidget) {
            if (_focusedWidget) {
                _focusedWidget->onLoseFocus();
            }
            _focusedWidget = newFocusedWidget;
            if (_focusedWidget &&
                    (!_pressedWidget || _focusedWidget == _pressedWidget)) {
                _focusedWidget->onGetFocus();
            }
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (_focusedWidget) {
            _focusedWidget->onPress();
            _pressedWidget = _focusedWidget;
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        if (_pressedWidget) {
            bool activate = (_focusedWidget == _pressedWidget);
            _pressedWidget->onRelease();
            _pressedWidget = nullptr;
            if (activate) {
                _focusedWidget->onActivate();
            } else if (_focusedWidget) {
                _focusedWidget->onGetFocus();
            }
        }
    }
}

void Ui::draw(sf::RenderWindow& window)
{
    for (const auto& widget : _widgets) {
        widget->draw(window);
    }
}

Widget* Ui::widgetAtPosition(int x, int y)
{
    for (const auto& widget : _widgets) {
        if (widget->contains(x, y)) {
            return widget.get();
        }
    }
    return nullptr;
}
