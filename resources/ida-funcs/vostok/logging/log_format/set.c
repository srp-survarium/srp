void __usercall vostok::logging::log_format::set(vostok::logging::log_format *this@<ecx>, char *a2@<esi>)
{
  char *v2; // edx
  unsigned int v3; // eax
  char *v4; // ecx
  unsigned int i; // ecx
  vostok::logging::format_specifier_enum *v6; // eax
  vostok::fixed_vector<enum vostok::logging::format_specifier_enum,8> list; // [esp+4h] [ebp-2Ch] BYREF
  char vars0; // [esp+30h] [ebp+0h] BYREF

  list.m_begin = (vostok::logging::format_specifier_enum *)list.m_buffer;
  list.m_end = (vostok::logging::format_specifier_enum *)list.m_buffer;
  list.m_max_end = (vostok::logging::format_specifier_enum *)&vars0;
  vostok::logging::format_specifier::fill_specifier_list(
    (vostok::logging::format_specifier *)this,
    &list,
    (char (*)[512])a2);
  v2 = a2 + 520;
  v3 = 0;
  v4 = a2 + 520;
  do
  {
    *(_DWORD *)v4 = 0;
    a2[v3++ + 512] = 0;
    v4 += 4;
  }
  while ( v3 < 8 );
  for ( i = 0; i < list.m_end - list.m_begin; v2 += 4 )
  {
    v6 = &list.m_begin[i];
    *(vostok::logging::format_specifier_enum *)v2 = *v6;
    a2[*v6 + 512] = 1;
    ++i;
  }
}
