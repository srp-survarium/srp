void __thiscall vostok::console_commands::cc_string::status(
        vostok::console_commands::cc_string *this,
        char (*dest)[512])
{
  vostok::strings::copy<512>(dest, this->m_value);
}
