void __thiscall vostok::console_commands::cc_string::status(
        vostok::console_commands::cc_string *this,
        char (*dest)[512])
{
  strcpy_s((char *)dest, 0x200u, this->m_value);
}
