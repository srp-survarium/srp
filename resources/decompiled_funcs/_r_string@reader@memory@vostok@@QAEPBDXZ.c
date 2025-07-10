const char *__usercall vostok::memory::reader::r_string@<eax>(vostok::memory::reader *this@<ecx>, _DWORD *a2@<esi>)
{
  const char *result; // eax
  int v3; // edx
  const char *i; // ecx

  result = (const char *)a2[1];
  v3 = *a2 + a2[2];
  for ( i = result; i != (const char *)v3; ++i )
  {
    if ( !*i )
      break;
  }
  a2[1] = i + 1;
  return result;
}
