void __usercall vostok::input::receiver::gamepad::gamepad(
        vostok::input::receiver::gamepad *this@<eax>,
        vostok::input::world *input_world@<ecx>)
{
  this->m_world = input_world;
  this->__vftable = (vostok::input::receiver::gamepad_vtbl *)&vostok::input::receiver::gamepad::`vftable';
  this->m_user_index = 0;
  this->m_connected = 0;
  this->m_inserted = 0;
  this->m_removed = 0;
  *(_QWORD *)&this->m_device_capabilities.Type = 0;
  *(_QWORD *)&this->m_device_capabilities.Gamepad.sThumbLX = 0;
  this->m_device_capabilities.Vibration = 0;
  this->m_current_vibration = 0;
  this->m_current_state.left_thumb_stick = 0;
  this->m_current_state.right_thumb_stick = 0;
  *(_QWORD *)&this->m_current_state.left_trigger = 0;
  this->m_current_state.buttons = 0;
  this->m_previous_state.left_thumb_stick = 0;
  this->m_previous_state.right_thumb_stick = 0;
  *(_QWORD *)&this->m_previous_state.left_trigger = 0;
  this->m_previous_state.buttons = 0;
}
