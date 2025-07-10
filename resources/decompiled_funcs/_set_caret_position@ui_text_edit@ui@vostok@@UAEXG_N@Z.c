void __thiscall vostok::ui::ui_text_edit::set_caret_position(
        vostok::ui::ui_text_edit *this,
        unsigned __int16 pos,
        bool b_move)
{
  unsigned __int16 m_caret_pos; // di
  unsigned __int16 v4; // ax

  m_caret_pos = this->m_caret_pos;
  this->m_caret_pos = pos;
  v4 = pos;
  if ( pos )
  {
    if ( pos > (unsigned __int16)(LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin)) )
      v4 = LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin);
  }
  else
  {
    v4 = 0;
  }
  this->m_caret_pos = v4;
  if ( v4 != m_caret_pos )
  {
    if ( (this->m_shift_state.m_data.dummy & 0x30) != 0 && b_move )
    {
      if ( v4 <= this->m_sel_end && (v4 < this->m_sel_start || pos > m_caret_pos) )
      {
        this->m_sel_start = v4;
        return;
      }
    }
    else
    {
      this->m_sel_start = v4;
    }
    this->m_sel_end = v4;
  }
}
