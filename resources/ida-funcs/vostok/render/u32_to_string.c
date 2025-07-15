vostok::fixed_string<260> *__usercall vostok::render::u32_to_string@<eax>(
        int a1@<esi>,
        vostok::fixed_string<260> *result)
{
  *(_DWORD *)a1 = a1 + 12;
  *(_DWORD *)(a1 + 4) = a1 + 12;
  *(_DWORD *)(a1 + 8) = a1 + 272;
  *(_BYTE *)(a1 + 12) = 0;
  *(_BYTE *)(a1 + 12) = 0;
  vostok::fs_new::path_string_impl::assignf(
    (_DWORD *)a1,
    (vostok::buffer_string *)(a1 + 272),
    (vostok::buffer_string *)"%d",
    (const char *)result);
  return (vostok::fixed_string<260> *)a1;
}
