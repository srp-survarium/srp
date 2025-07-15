void __thiscall vostok::input::receiver::gamepad::set_vibration(
        vostok::input::receiver::gamepad *this,
        vostok::input::gamepad_vibrators vibrator,
        float value_raw)
{
  signed int v4; // eax
  DWORD m_user_index; // ecx

  if ( this->m_inserted )
  {
    v4 = vostok::math::floor(value_raw * 65535.0);
    if ( v4 > 0 )
    {
      if ( v4 > 0xFFFF )
        LOWORD(v4) = -1;
    }
    else
    {
      LOWORD(v4) = 0;
    }
    m_user_index = this->m_user_index;
    if ( vibrator )
      this->m_current_vibration.wRightMotorSpeed = v4;
    else
      this->m_current_vibration.wLeftMotorSpeed = v4;
    XInputSetState(m_user_index, &this->m_current_vibration);
  }
}
