vostok::ui::ui_scroll_bar *__thiscall vostok::ui::ui_scroll_bar::`scalar deleting destructor'(
        vostok::ui::ui_scroll_bar *this,
        char a2)
{
  vostok::ui::ui_scroll_bar::~ui_scroll_bar(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
