vostok::ui::ui_world *__thiscall vostok::ui::ui_world::`scalar deleting destructor'(
        vostok::ui::ui_world *this,
        char a2)
{
  vostok::memory::base_allocator *m_allocator; // ecx

  m_allocator = this->m_font_manager.m_font.m_allocator;
  this->m_font_manager.m_font.__vftable = (vostok::ui::ui_font_vtbl *)&vostok::ui::ui_font::`vftable';
  if ( this->m_font_manager.m_font.m_char_map )
  {
    m_allocator->call_free(m_allocator, this->m_font_manager.m_font.m_char_map);
    this->m_font_manager.m_font.m_char_map = 0;
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
