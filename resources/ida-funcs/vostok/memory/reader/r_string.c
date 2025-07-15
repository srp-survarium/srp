const char *__fastcall vostok::memory::reader::r_string(vostok::memory::reader *this, _DWORD *a2)
{
  const char *result; // eax
  const char *i; // esi

  result = (const char *)a2[1];
  for ( i = result; i != (const char *)(*a2 + a2[2]) && *i; ++i )
    ;
  a2[1] = i + 1;
  return result;
}
