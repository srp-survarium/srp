void __thiscall vostok::debug::detail::string_helper::appendf_va_list(
        vostok::debug::detail::string_helper *this,
        const char *format,
        char *argptr)
{
  unsigned int v3; // [esp+0h] [ebp-18h]

  v3 = strlen(this->m_buffer);
  vostok::vsprintf(format, argptr, &this->m_buffer[v3], 4096 - v3);
}
