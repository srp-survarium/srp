void __usercall vostok::input::platform::gamepad::gamepad(
        vostok::input::platform::gamepad *this@<edx>,
        vostok::input::world *input_world@<eax>)
{
  float v2; // xmm0_4

  v2 = SNaN;
  this->m_world = input_world;
  this->__vftable = (vostok::input::platform::gamepad_vtbl *)&vostok::input::platform::gamepad::`vftable';
  this->m_current_state.left_thumb_stick.x = v2;
  this->m_current_state.left_thumb_stick.y = v2;
  this->m_current_state.right_thumb_stick.x = v2;
  this->m_current_state.right_thumb_stick.y = v2;
  this->m_previous_state.left_thumb_stick.x = v2;
  this->m_previous_state.left_thumb_stick.y = v2;
  this->m_previous_state.right_thumb_stick.x = v2;
  this->m_previous_state.right_thumb_stick.y = v2;
  this->m_user_index = 0;
  this->m_connected = 0;
  this->m_inserted = 0;
  this->m_removed = 0;
  *(_DWORD *)&this->m_device_capabilities.Type = 0;
  *(_DWORD *)&this->m_device_capabilities.Gamepad.wButtons = 0;
  *(_DWORD *)&this->m_device_capabilities.Gamepad.sThumbLX = 0;
  *(_DWORD *)&this->m_device_capabilities.Gamepad.sThumbRX = 0;
  this->m_device_capabilities.Vibration = 0;
  this->m_current_vibration = 0;
  memset((void *)&this->m_current_state, 0, sizeof(this->m_current_state));
  memset((void *)&this->m_previous_state, 0, sizeof(this->m_previous_state));
}
