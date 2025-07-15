vostok::buffer_string *__userpurge vostok::buffer_string::appendf_va_list@<eax>(
        vostok::buffer_string *this@<ecx>,
        _DWORD *a2@<edi>,
        char *format,
        char *argptr)
{
  int v4; // esi
  void *v5; // esp
  char *v6; // eax
  char *i; // ecx
  char v8; // bl
  char v10[8]; // [esp+0h] [ebp-8h] BYREF

  v4 = a2[2] - *a2;
  v5 = alloca(v4);
  v6 = &v10[vsnprintf_s(v10, v4, v4, format, argptr)];
  for ( i = v10; i != v6; ++a2[1] )
  {
    v8 = *i++;
    *(_BYTE *)a2[1] = v8;
  }
  *(_BYTE *)a2[1] = 0;
  return (vostok::buffer_string *)a2;
}
