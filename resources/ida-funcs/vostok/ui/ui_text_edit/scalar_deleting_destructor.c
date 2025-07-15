vostok::ui::ui_text_edit *__thiscall vostok::ui::ui_text_edit::`scalar deleting destructor'(
        vostok::ui::ui_text_edit *this,
        char a2)
{
  vostok::ui::ui_text_edit::~ui_text_edit(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
