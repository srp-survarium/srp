void __thiscall vostok::console_commands::cc_string::syntax(
        vostok::console_commands::cc_string *this,
        char (*dest)[512])
{
  vostok::sprintf<512>(dest, "max size is %d", this->m_size);
}
