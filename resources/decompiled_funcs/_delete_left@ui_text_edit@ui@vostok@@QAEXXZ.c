void __thiscall vostok::ui::ui_text_edit::delete_left(vostok::ui::ui_text_edit *this)
{
  unsigned __int16 m_caret_pos; // ax
  unsigned int v3; // ebx
  vostok::ui::dynamic_text *p_m_text; // edi
  char *v5; // eax
  unsigned int v6; // edi
  vostok::fixed_string<512> result; // [esp+4h] [ebp-20Ch] BYREF
  _UNKNOWN *retaddr; // [esp+210h] [ebp+0h] BYREF

  if ( this->m_sel_start == this->m_sel_end )
  {
    m_caret_pos = this->m_caret_pos;
    if ( m_caret_pos )
    {
      v3 = (unsigned __int16)(m_caret_pos - 1);
      result.m_begin = result.m_buffer;
      result.m_end = result.m_buffer;
      result.m_max_end = (char *)&retaddr;
      p_m_text = &this->m_text;
      result.m_buffer[0] = 0;
      vostok::buffer_string::substr(&this->m_text.m_text, 0, v3, &result);
      v5 = &p_m_text->m_text.m_begin[this->m_caret_pos];
      v6 = this->m_text.m_text.m_end - v5;
      memcpy((unsigned __int8 *)result.m_end, (unsigned __int8 *)v5, v6);
      result.m_end += v6;
      *result.m_end = 0;
      this->set_text(&this->vostok::ui::ui_text<vostok::ui::dynamic_text>, result.m_begin);
      this->set_caret_position(this, v3, 1);
    }
  }
  else
  {
    vostok::ui::ui_text_edit::delete_selection(this, (int)this);
  }
}
