bool __thiscall vostok::ui::shift_state_action::execute(
        vostok::ui::shift_state_action *this,
        vostok::input::enum_keyboard_action action)
{
  vostok::ui::ui_text_edit::set_shift_state(
    this->m_parent,
    (const vostok::ui::enum_shift_state)this->m_shift_switch_state,
    action != kb_key_up);
  return 0;
}
