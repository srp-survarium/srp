double __thiscall vostok::input::receiver::gamepad::get_vibration(
        vostok::input::receiver::gamepad *this,
        vostok::input::gamepad_vibrators vibrator)
{
  if ( vibrator )
    return (double)this->m_current_vibration.wRightMotorSpeed * 0.000015259022;
  else
    return (double)this->m_current_vibration.wLeftMotorSpeed * 0.000015259022;
}
