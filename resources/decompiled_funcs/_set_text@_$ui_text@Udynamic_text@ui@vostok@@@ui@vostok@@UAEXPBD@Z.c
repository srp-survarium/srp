void __thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::set_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        char *text)
{
  char *m_begin; // eax
  vostok::ui::dynamic_text *p_m_text; // ecx
  char *v5; // eax

  m_begin = this->m_text.m_text.m_begin;
  p_m_text = &this->m_text;
  if ( !m_begin || strcmp(m_begin, text) )
  {
    v5 = p_m_text->m_text.m_begin;
    if ( p_m_text->m_text.m_begin != text )
    {
      p_m_text->m_text.m_end = v5;
      *v5 = 0;
      vostok::buffer_string::operator+=(&p_m_text->m_text, text);
    }
    vostok::ui::ui_window::emit_event(
      (vostok::ui::ui_window *)p_m_text,
      ev_text_changed,
      &this->vostok::ui::ui_window,
      0,
      0);
  }
}
