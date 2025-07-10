unsigned int __thiscall vostok::input::receiver::keyboard::is_key_down(
        vostok::input::receiver::keyboard *this,
        vostok::input::enum_keyboard key)
{
  return ((unsigned int)SLOBYTE(this->m_current_key_state[key]) >> 7) & 1;
}
