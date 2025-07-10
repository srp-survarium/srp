void __thiscall vostok::logging::format_specifier::format_specifier(
        vostok::logging::format_specifier *this,
        vostok::logging::format_specifier_enum specifier)
{
  this->m_left = 0;
  this->m_right = 0;
  this->m_specifier = specifier;
}
