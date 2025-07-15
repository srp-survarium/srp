void __thiscall vostok::logging::format_specifier::format_specifier(
        vostok::logging::format_specifier *this,
        const vostok::logging::format_specifier *left,
        const vostok::logging::format_specifier *right)
{
  this->m_left = left;
  this->m_right = right;
  this->m_specifier = format_specifier_unset;
}


void __thiscall vostok::logging::format_specifier::format_specifier(
        vostok::logging::format_specifier *this,
        vostok::logging::format_specifier_enum specifier)
{
  this->m_left = 0;
  this->m_right = 0;
  this->m_specifier = specifier;
}
