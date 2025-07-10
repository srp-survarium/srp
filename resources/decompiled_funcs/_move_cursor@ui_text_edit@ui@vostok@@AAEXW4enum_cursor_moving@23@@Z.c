void __usercall vostok::ui::ui_text_edit::move_cursor(vostok::ui::ui_text_edit *this@<ecx>, int a2@<eax>)
{
  vostok::ui::ui_text_edit *v2; // esi
  unsigned __int16 m_caret_pos; // ax
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // ax

  v2 = this;
  switch ( a2 )
  {
    case 0:
      m_caret_pos = this->m_caret_pos;
      if ( m_caret_pos )
      {
        LOBYTE(this) = (this->m_shift_state.m_data.dummy & 3) != 0;
        if ( (v2->m_shift_state.m_data.dummy & 3) != 0 )
        {
          v4 = vostok::ui::ui_text_edit::calc_left_word_position(this, (int)v2, v2->m_caret_pos);
          v2->set_caret_position(v2, v4, 1);
        }
        else
        {
          v2->set_caret_position(v2, m_caret_pos - 1, 1);
        }
      }
      break;
    case 1:
      if ( (this->m_shift_state.m_data.dummy & 3) != 0 )
      {
        v5 = vostok::ui::ui_text_edit::calc_right_word_position(
               (vostok::ui::ui_text_edit *)this->m_caret_pos,
               (int)this,
               this->m_caret_pos);
        v2->set_caret_position(v2, v5, 1);
      }
      else
      {
        this->set_caret_position(this, this->m_caret_pos + 1, 1);
      }
      break;
    case 2:
      this->set_caret_position(this, 0, 1);
      break;
    case 3:
      this->set_caret_position(this, LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin), 1);
      break;
  }
}
