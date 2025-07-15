void __thiscall vostok::ui::ui_text_edit::delete_left(vostok::ui::ui_text_edit *this)
{
  unsigned __int16 m_caret_pos; // ax
  vostok::ui::dynamic_text *p_m_text; // esi
  vostok::buffer_string *v4; // ecx
  vostok::buffer_string v5; // [esp+4h] [ebp-210h] BYREF
  _BYTE v6[512]; // [esp+10h] [ebp-204h] BYREF
  int v7; // [esp+210h] [ebp-4h] BYREF

  if ( this->m_sel_start == this->m_sel_end )
  {
    m_caret_pos = this->m_caret_pos;
    if ( m_caret_pos )
    {
      v5.m_begin = v6;
      v5.m_end = v6;
      v7 = (unsigned __int16)(m_caret_pos - 1);
      v5.m_max_end = (char *)&v7;
      p_m_text = &this->m_text;
      v6[0] = 0;
      vostok::buffer_string::substr(0, (char *)(unsigned __int16)v7, &v5, &this->m_text.m_text);
      vostok::buffer_string::append(v4, this->m_text.m_text.m_end, &p_m_text->m_text.m_begin[this->m_caret_pos]);
      this->set_text(&this->vostok::ui::ui_text<vostok::ui::dynamic_text>, v5.m_begin);
      this->set_caret_position(this, v7, 1);
    }
  }
  else
  {
    vostok::ui::ui_text_edit::delete_selection(this, (int)this);
  }
}
