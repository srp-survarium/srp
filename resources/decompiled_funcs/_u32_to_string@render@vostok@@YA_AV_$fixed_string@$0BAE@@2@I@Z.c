vostok::fixed_string<260> *__usercall vostok::render::u32_to_string@<eax>(unsigned int v@<edx>, int a2@<esi>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 272;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
  vostok::buffer_string::assignf((vostok::buffer_string *)a2, "%d", v);
  return (vostok::fixed_string<260> *)a2;
}
