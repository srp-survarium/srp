vostok::ui::ui_text<vostok::ui::dynamic_text> *__thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::`vector deleting destructor'(
        char *this,
        char a2)
{
  return vostok::ui::ui_text<vostok::ui::dynamic_text>::`scalar deleting destructor'(
           (vostok::ui::ui_text<vostok::ui::dynamic_text> *)(this - 4),
           a2);
}


vostok::ui::ui_text<vostok::ui::static_text> *__thiscall vostok::ui::ui_text<vostok::ui::static_text>::`vector deleting destructor'(
        vostok::ui::ui_text<vostok::ui::static_text> *this,
        char a2)
{
  vostok::ui::ui_text<vostok::ui::static_text>::~ui_text<vostok::ui::static_text>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::ui::ui_text<vostok::ui::static_text> *__thiscall vostok::ui::ui_text<vostok::ui::static_text>::`vector deleting destructor'(
        char *this,
        char a2)
{
  return vostok::ui::ui_text<vostok::ui::static_text>::`vector deleting destructor'(
           (vostok::ui::ui_text<vostok::ui::static_text> *)(this - 4),
           a2);
}
