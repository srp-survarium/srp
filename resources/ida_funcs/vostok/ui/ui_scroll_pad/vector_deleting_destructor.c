vostok::ui::ui_scroll_pad *__thiscall vostok::ui::ui_scroll_pad::`vector deleting destructor'(
        vostok::ui::ui_scroll_pad *this,
        char a2)
{
  vostok::ui::ui_window::~ui_window(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
