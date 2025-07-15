unsigned int __thiscall vostok::input::platform::keyboard::is_key_down(
        vostok::input::platform::keyboard *this,
        vostok::input::enum_keyboard key)
{
  return ((unsigned int)SLOBYTE(this->m_current_key_state[key]) >> 7) & 1;
}
