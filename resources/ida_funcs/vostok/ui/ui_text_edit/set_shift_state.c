void __userpurge vostok::ui::ui_text_edit::set_shift_state(
        vostok::ui::ui_text_edit *this@<eax>,
        bool b_set@<cl>,
        vostok::ui::enum_shift_state state)
{
  switch ( state )
  {
    case ks_Shift:
      this->m_shift_state.m_data.dummy ^= (this->m_shift_state.m_data.dummy ^ (16 * b_set)) & 0x30;
      break;
    case ks_Ctrl:
      this->m_shift_state.m_data.dummy ^= (this->m_shift_state.m_data.dummy ^ b_set) & 3;
      break;
    case ks_Alt:
      this->m_shift_state.m_data.dummy ^= (this->m_shift_state.m_data.dummy ^ (4 * b_set)) & 0xC;
      break;
    case ks_CtrlShift:
      this->m_shift_state.m_data.dummy = (16 * b_set) | b_set | this->m_shift_state.m_data.dummy & 0xCC;
      break;
  }
}
