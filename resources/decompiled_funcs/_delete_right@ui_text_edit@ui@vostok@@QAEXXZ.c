void __thiscall vostok::ui::ui_text_edit::delete_right(vostok::ui::ui_text_edit *this)
{
  unsigned __int16 m_caret_pos; // ax
  vostok::ui::dynamic_text *p_m_text; // edi
  int v4; // ebx
  char *m_begin; // ecx
  unsigned int v6; // edi
  vostok::fixed_string<512> result; // [esp+4h] [ebp-20Ch] BYREF
  _UNKNOWN *retaddr; // [esp+210h] [ebp+0h] BYREF

  if ( this->m_sel_start == this->m_sel_end )
  {
    m_caret_pos = this->m_caret_pos;
    p_m_text = &this->m_text;
    if ( m_caret_pos != LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin) )
    {
      result.m_begin = result.m_buffer;
      v4 = m_caret_pos;
      result.m_max_end = (char *)&retaddr;
      result.m_end = result.m_buffer;
      result.m_buffer[0] = 0;
      vostok::buffer_string::substr(&this->m_text.m_text, 0, m_caret_pos, &result);
      m_begin = p_m_text->m_text.m_begin;
      v6 = this->m_text.m_text.m_end - &p_m_text->m_text.m_begin[this->m_caret_pos + 1];
      memcpy((unsigned __int8 *)result.m_end, (unsigned __int8 *)&m_begin[this->m_caret_pos + 1], v6);
      result.m_end += v6;
      *result.m_end = 0;
      this->set_text(&this->vostok::ui::ui_text<vostok::ui::dynamic_text>, result.m_begin);
      this->set_caret_position(this, v4, 1);
    }
  }
  else
  {
    vostok::ui::ui_text_edit::delete_selection(this, (int)this);
  }
}
