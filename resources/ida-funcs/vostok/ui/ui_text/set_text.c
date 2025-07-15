void __thiscall vostok::ui::ui_text<vostok::ui::static_text>::set_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        char *text)
{
  vostok::ui::dynamic_text *p_m_text; // esi
  char *m_begin; // eax
  char *v5; // eax

  p_m_text = &this->m_text;
  m_begin = this->m_text.m_text.m_begin;
  if ( !m_begin || vostok::strings::compare(m_begin, text) )
  {
    v5 = p_m_text->m_text.m_begin;
    if ( p_m_text->m_text.m_begin != text )
    {
      p_m_text->m_text.m_end = v5;
      *v5 = 0;
      vostok::buffer_string::operator+=(&p_m_text->m_text, text);
    }
    vostok::ui::ui_window::process_event((vostok::ui::ui_window *)5, &this->vostok::ui::ui_window, 0, 0);
  }
}
