vostok::ui::ui_dialog *__thiscall vostok::ui::ui_dialog::`scalar deleting destructor'(
        vostok::ui::ui_dialog *this,
        char a2)
{
  vostok::ui::ui_dialog::~ui_dialog(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
