vostok::ui::ui_scroll_view *__thiscall vostok::ui::ui_scroll_view::`scalar deleting destructor'(
        vostok::ui::ui_scroll_view *this,
        char a2)
{
  vostok::ui::ui_scroll_view::~ui_scroll_view(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
