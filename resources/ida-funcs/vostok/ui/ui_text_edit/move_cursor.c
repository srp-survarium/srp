void __usercall vostok::ui::ui_text_edit::move_cursor(
        vostok::ui::ui_text_edit *this@<esi>,
        vostok::ui::enum_cursor_moving action@<eax>,
        vostok::ui::ui_text_edit *a3@<ecx>)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int16 *p_m_caret_pos; // eax
  vostok::ui::ui_text_edit *m_caret_pos; // ecx
  unsigned __int16 v9; // di
  unsigned __int16 i; // ax
  vostok::ui::ui_text_edit *v11; // ecx

  v3 = 0;
  if ( action == cr_left )
  {
    p_m_caret_pos = &this->m_caret_pos;
    m_caret_pos = (vostok::ui::ui_text_edit *)this->m_caret_pos;
    if ( !(_WORD)m_caret_pos )
      return;
    if ( (this->m_shift_state.m_data.dummy & 3) != 0 )
    {
      v9 = *p_m_caret_pos;
      if ( *p_m_caret_pos )
      {
        for ( i = (unsigned __int16)vostok::ui::ui_text_edit::calc_right_word_position(m_caret_pos, (int)this, 0);
              v9 > i;
              i = (unsigned __int16)vostok::ui::ui_text_edit::calc_right_word_position(v11, (int)this, i) )
        {
          v3 = i;
        }
        LOWORD(v6) = v3;
      }
      else
      {
        LOWORD(v6) = 0;
      }
      v6 = (unsigned __int16)v6;
    }
    else
    {
      v6 = (unsigned __int16)m_caret_pos - 1;
    }
    goto LABEL_21;
  }
  v4 = action - 1;
  if ( !v4 )
  {
    if ( (this->m_shift_state.m_data.dummy & 3) != 0 )
      v6 = (unsigned __int16)vostok::ui::ui_text_edit::calc_right_word_position(a3, (int)this, this->m_caret_pos);
    else
      v6 = this->m_caret_pos + 1;
LABEL_21:
    this->set_caret_position(this, v6, 1);
    return;
  }
  v5 = v4 - 1;
  if ( v5 )
  {
    if ( v5 == 1 )
      this->set_caret_position(this, LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin), 1);
  }
  else
  {
    this->set_caret_position(this, 0, 1);
  }
}
