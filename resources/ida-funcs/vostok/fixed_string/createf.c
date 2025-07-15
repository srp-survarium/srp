vostok::fixed_string<32> *__usercall vostok::fixed_string<32>::createf@<eax>(
        _DWORD *a1@<eax>,
        vostok::fixed_string<32> *result,
        const char *format,
        ...)
{
  _DWORD *v4; // eax

  v4 = a1 + 3;
  *a1 = v4;
  a1[1] = v4;
  a1[2] = v4 + 8;
  *(_BYTE *)v4 = 0;
  *(_BYTE *)v4 = 0;
  vostok::buffer_string::appendf_va_list((vostok::buffer_string *)(v4 + 8), a1, (char *)result, (char *)&format);
  return (vostok::fixed_string<32> *)a1;
}


vostok::fixed_string<512> *__usercall vostok::fixed_string<512>::createf@<eax>(
        _DWORD *a1@<eax>,
        vostok::fixed_string<512> *result,
        const char *format,
        ...)
{
  _DWORD *v4; // eax

  v4 = a1 + 3;
  *a1 = v4;
  a1[1] = v4;
  a1[2] = v4 + 128;
  *(_BYTE *)v4 = 0;
  *(_BYTE *)v4 = 0;
  vostok::buffer_string::appendf_va_list((vostok::buffer_string *)(v4 + 128), a1, (char *)result, (char *)&format);
  return (vostok::fixed_string<512> *)a1;
}


vostok::fixed_string<128> *__usercall vostok::fixed_string<128>::createf@<eax>(
        _DWORD *a1@<eax>,
        vostok::fixed_string<128> *result,
        const char *format,
        ...)
{
  _DWORD *v4; // eax

  v4 = a1 + 3;
  *a1 = v4;
  a1[1] = v4;
  a1[2] = v4 + 32;
  *(_BYTE *)v4 = 0;
  *(_BYTE *)v4 = 0;
  vostok::buffer_string::appendf_va_list((vostok::buffer_string *)(v4 + 32), a1, (char *)result, (char *)&format);
  return (vostok::fixed_string<128> *)a1;
}
