vostok::ui::ui_font *__thiscall vostok::ui::ui_font::`scalar deleting destructor'(vostok::ui::ui_font *this, char a2)
{
  vostok::ui::ui_font::~ui_font(this, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
