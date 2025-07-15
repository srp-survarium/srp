BOOL __thiscall vostok::input::platform::keyboard::check_modifier(
        vostok::input::platform::keyboard *this,
        vostok::input::enum_modifiers modifier)
{
  return (modifier & this->m_modifiers) != 0;
}
