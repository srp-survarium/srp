vostok::ui::ui_world *__thiscall vostok::ui::ui_world::`scalar deleting destructor'(
        vostok::ui::ui_world *this,
        char a2)
{
  vostok::ui::ui_font::~ui_font((vostok::ui::ui_font *)this, &this->m_font_manager.m_font.__vftable);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
