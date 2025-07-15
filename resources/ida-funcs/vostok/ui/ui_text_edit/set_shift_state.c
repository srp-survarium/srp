void __fastcall vostok::ui::ui_text_edit::set_shift_state(
        vostok::ui::ui_text_edit *this,
        bool b_set,
        const vostok::ui::enum_shift_state state)
{
  vostok::ui::shift_state *p_m_shift_state; // eax
  char v4; // cl

  if ( state )
  {
    if ( state == ks_Ctrl )
    {
      p_m_shift_state = &this->m_shift_state;
      v4 = (this->m_shift_state.m_data.dummy ^ b_set) & 3;
    }
    else
    {
      if ( state != ks_Alt )
      {
        this->m_shift_state.m_data.dummy = (16 * b_set) | b_set | this->m_shift_state.m_data.dummy & 0xCC;
        return;
      }
      p_m_shift_state = &this->m_shift_state;
      v4 = (this->m_shift_state.m_data.dummy ^ (4 * b_set)) & 0xC;
    }
  }
  else
  {
    p_m_shift_state = &this->m_shift_state;
    v4 = (this->m_shift_state.m_data.dummy ^ (16 * b_set)) & 0x30;
  }
  p_m_shift_state->m_data.dummy ^= v4;
}
