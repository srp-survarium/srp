vostok::fixed_string<256> *__usercall vostok::fixed_string<256>::createf@<eax>(
        int a1@<esi>,
        vostok::fixed_string<256> *result,
        const char *format,
        ...)
{
  *(_DWORD *)a1 = a1 + 12;
  *(_DWORD *)(a1 + 4) = a1 + 12;
  *(_DWORD *)(a1 + 8) = a1 + 268;
  *(_BYTE *)(a1 + 12) = 0;
  *(_BYTE *)(a1 + 12) = 0;
  vostok::buffer_string::appendf_va_list((vostok::buffer_string *)a1, (const char *const)result, (char *)&format);
  return (vostok::fixed_string<256> *)a1;
}


vostok::fixed_string<512> *__usercall vostok::fixed_string<512>::createf@<eax>(
        int a1@<esi>,
        vostok::fixed_string<512> *result,
        const char *format,
        ...)
{
  *(_DWORD *)a1 = a1 + 12;
  *(_DWORD *)(a1 + 4) = a1 + 12;
  *(_DWORD *)(a1 + 8) = a1 + 524;
  *(_BYTE *)(a1 + 12) = 0;
  *(_BYTE *)(a1 + 12) = 0;
  vostok::buffer_string::appendf_va_list((vostok::buffer_string *)a1, (const char *const)result, (char *)&format);
  return (vostok::fixed_string<512> *)a1;
}
