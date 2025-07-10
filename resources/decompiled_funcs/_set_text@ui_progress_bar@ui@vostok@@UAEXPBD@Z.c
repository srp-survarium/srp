void __thiscall vostok::ui::ui_progress_bar::set_text(vostok::ui::ui_progress_bar *this, char *text)
{
  char *m_begin; // eax
  vostok::fixed_string<32> *p_m_text; // ecx

  m_begin = this->m_text.m_begin;
  p_m_text = &this->m_text;
  if ( m_begin != text )
  {
    p_m_text->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(p_m_text, text);
  }
}
