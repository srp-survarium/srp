char __cdecl vostok::strings::iterate_items<vostok::logging::logger_predicate,char *>(
        char *const string,
        unsigned int length,
        const vostok::logging::logger_predicate *predicate)
{
  vostok::logging::logger_predicate *v3; // ecx
  void *v4; // esp
  _BYTE *v5; // esi
  char *v6; // eax
  int v7; // edi
  char v8; // al
  unsigned int v10; // [esp-10h] [ebp-24h]
  _BYTE v11[12]; // [esp+0h] [ebp-14h] BYREF
  int v12; // [esp+Ch] [ebp-8h]
  unsigned int v13; // [esp+10h] [ebp-4h]

  v4 = alloca(length + 1);
  v5 = v11;
  v6 = v11;
  v13 = 0;
  if ( !*string )
    return vostok::logging::logger_predicate::operator()(v3, (int)predicate, 0, string, length, 1);
  v7 = string - v11;
  v12 = string - v11;
  do
  {
    LOBYTE(v3) = v5[v7];
    if ( (_BYTE)v3 == 10 )
    {
      v10 = v13;
      *v5 = 0;
      v8 = vostok::logging::logger_predicate::operator()(
             (vostok::logging::logger_predicate *)(v5 - v6),
             (int)predicate,
             v10,
             v6,
             v5 - v6,
             0);
      ++v13;
      if ( !v8 )
        return 0;
      v7 = v12;
      v6 = v5 + 1;
    }
    else
    {
      *v5 = (_BYTE)v3;
    }
    ++v5;
  }
  while ( v5[v7] );
  if ( !v13 )
    return vostok::logging::logger_predicate::operator()(v3, (int)predicate, 0, string, length, 1);
  *v5 = 0;
  return vostok::logging::logger_predicate::operator()(v3, (int)predicate, v13, v6, v5 - v6, 1);
}
