void __thiscall vostok::console_commands::cc_float::status(vostok::console_commands::cc_float *this, char (*dest)[512])
{
  char *i; // eax

  vostok::sprintf<512>(dest, "%3.5f", *this->m_value);
  for ( i = &(*dest)[strlen((const char *)dest) - 1]; *i == 48 && *(i - 1) == 48; --i )
    *i = 0;
}
