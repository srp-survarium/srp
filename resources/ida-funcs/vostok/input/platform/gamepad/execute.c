void __thiscall vostok::input::platform::gamepad::execute(vostok::input::platform::gamepad *this)
{
  bool v2; // al
  bool v3; // zf
  bool v4; // cl
  bool v5; // cl
  int bRightTrigger; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  XINPUT_STATE pState; // [esp+4h] [ebp-20h] BYREF
  float v10; // [esp+18h] [ebp-Ch]
  float v11; // [esp+1Ch] [ebp-8h]
  bool m_connected; // [esp+23h] [ebp-1h]

  m_connected = this->m_connected;
  if ( m_connected )
  {
    v2 = XInputGetState(this->m_user_index, &pState) == 0;
    v3 = !m_connected;
    this->m_connected = v2;
    v4 = !v3 && !v2;
    v3 = !m_connected;
    this->m_removed = v4;
    v5 = v3 && v2;
    this->m_inserted = v5;
    if ( v2 )
    {
      if ( v5 )
      {
        memset((void *)&this->m_current_state, 0, sizeof(this->m_current_state));
        XInputGetCapabilities(this->m_user_index, 1u, &this->m_device_capabilities);
        this->m_current_vibration = this->m_device_capabilities.Vibration;
        XInputSetState(this->m_user_index, &this->m_current_vibration);
      }
      memcpy(
        (unsigned __int8 *)&this->m_previous_state,
        (unsigned __int8 *)&this->m_current_state,
        sizeof(this->m_previous_state));
      this->m_current_state.buttons = pState.Gamepad.wButtons;
      bRightTrigger = pState.Gamepad.bRightTrigger;
      this->m_current_state.left_trigger = (float)pState.Gamepad.bLeftTrigger * 0.0039215689;
      v7 = (float)bRightTrigger;
      LOWORD(bRightTrigger) = pState.Gamepad.sThumbLX;
      this->m_current_state.right_trigger = v7 * 0.0039215689;
      LODWORD(v10) = convert_stick_value(bRightTrigger, 0x1EA9u);
      LODWORD(v8) = convert_stick_value(pState.Gamepad.sThumbLY, 0x1EA9u);
      this->m_current_state.left_thumb_stick.x = v10;
      v11 = v8;
      this->m_current_state.left_thumb_stick.y = v8;
      LODWORD(v10) = convert_stick_value(pState.Gamepad.sThumbRX, 0x21F1u);
      LODWORD(v11) = convert_stick_value(pState.Gamepad.sThumbRY, 0x21F1u);
      this->m_current_state.right_thumb_stick.x = v10;
      this->m_current_state.right_thumb_stick.y = v11;
    }
  }
}
