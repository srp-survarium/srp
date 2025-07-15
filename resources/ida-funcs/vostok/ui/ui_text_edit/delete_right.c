void __thiscall vostok::ui::ui_text_edit::delete_right(vostok::ui::ui_text_edit *this)
{
  unsigned __int16 m_caret_pos; // ax
  vostok::ui::dynamic_text *p_m_text; // esi
  vostok::buffer_string v4; // [esp+4h] [ebp-210h] BYREF
  _BYTE v5[512]; // [esp+10h] [ebp-204h] BYREF
  int v6; // [esp+210h] [ebp-4h] BYREF

  if ( this->m_sel_start == this->m_sel_end )
  {
    m_caret_pos = this->m_caret_pos;
    p_m_text = &this->m_text;
    if ( m_caret_pos != LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin) )
    {
      v4.m_begin = v5;
      v4.m_end = v5;
      v6 = m_caret_pos;
      v4.m_max_end = (char *)&v6;
      v5[0] = 0;
      vostok::buffer_string::substr(0, (char *)m_caret_pos, &v4, &this->m_text.m_text);
      vostok::buffer_string::append(&v4, this->m_text.m_text.m_end, &p_m_text->m_text.m_begin[this->m_caret_pos + 1]);
      this->set_text(&this->vostok::ui::ui_text<vostok::ui::dynamic_text>, v4.m_begin);
      this->set_caret_position(this, v6, 1);
    }
  }
  else
  {
    vostok::ui::ui_text_edit::delete_selection(this, (int)this);
  }
}
