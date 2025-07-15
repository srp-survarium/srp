void __userpurge vostok::sound::propagator_statistic::fill_text_tree(
        vostok::sound::propagator_statistic *this@<ecx>,
        int a2@<esi>,
        vostok::strings::text_tree_item *item)
{
  vostok::strings::text_tree_item *v3; // edi
  vostok::buffer_string *v4; // ecx
  vostok::strings::text_tree_item *v5; // ecx
  vostok::buffer_string *v6; // ecx
  vostok::strings::text_tree_item *v7; // ecx
  vostok::buffer_string *v8; // ecx
  const char *v9; // eax
  char *v10; // [esp+4h] [ebp-58h]
  vostok::strings::text_tree_item *v11; // [esp+4h] [ebp-58h]
  char *v12[3]; // [esp+Ch] [ebp-50h] BYREF
  _BYTE v13[64]; // [esp+18h] [ebp-44h] BYREF
  char v14; // [esp+58h] [ebp-4h] BYREF

  v10 = *(char **)(a2 + 4);
  v12[0] = v13;
  v12[1] = v13;
  v12[2] = &v14;
  v13[0] = 0;
  v3 = vostok::strings::text_tree_item::new_child((vostok::strings::text_tree_item *)this, (const char *)item, v10);
  vostok::fs_new::path_string_impl::assignf(
    v12,
    v4,
    (vostok::buffer_string *)"Dist:%3.1fm",
    (const char *)COERCE_UNSIGNED_INT64(*(float *)(a2 + 284)),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(a2 + 284))));
  vostok::strings::text_tree_item::add_column_impl(v5, (const char *)v3, v12[0]);
  vostok::fs_new::path_string_impl::assignf(
    v12,
    v6,
    (vostok::buffer_string *)"f:%1.2f",
    (const char *)COERCE_UNSIGNED_INT64(*(float *)(a2 + 300)),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(a2 + 300))));
  vostok::strings::text_tree_item::add_column_impl(v7, (const char *)v3, v12[0]);
  v9 = "MONO";
  if ( *(_BYTE *)(a2 + 304) != 1 )
    v9 = "STEREO";
  vostok::fs_new::path_string_impl::assignf(v12, v8, (vostok::buffer_string *)&stru_7F9BE8.allocator, v9);
  vostok::strings::text_tree_item::add_column_impl(v11, (const char *)v3, v12[0]);
}
