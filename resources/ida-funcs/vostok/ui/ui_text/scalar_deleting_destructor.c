vostok::ui::ui_text<vostok::ui::dynamic_text> *__thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::`scalar deleting destructor'(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        char a2)
{
  vostok::ui::ui_text<vostok::ui::dynamic_text>::~ui_text<vostok::ui::dynamic_text>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
