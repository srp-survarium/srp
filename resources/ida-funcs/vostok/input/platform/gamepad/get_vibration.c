double __thiscall vostok::input::platform::gamepad::get_vibration(
        vostok::input::platform::gamepad *this,
        vostok::input::gamepad_vibrators vibrator)
{
  int wRightMotorSpeed; // [esp+8h] [ebp+8h]

  if ( vibrator )
    wRightMotorSpeed = this->m_current_vibration.wRightMotorSpeed;
  else
    wRightMotorSpeed = this->m_current_vibration.wLeftMotorSpeed;
  return (double)wRightMotorSpeed * 0.000015259022;
}
