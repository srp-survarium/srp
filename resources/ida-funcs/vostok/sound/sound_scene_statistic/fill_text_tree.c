void __userpurge vostok::sound::sound_scene_statistic::fill_text_tree(
        vostok::sound::sound_scene_statistic *this@<ecx>,
        int a2@<eax>,
        vostok::strings::text_tree_item *item)
{
  vostok::strings::text_tree_item *v5; // edi
  vostok::buffer_string *v6; // ecx
  vostok::strings::text_tree_item *v7; // ecx
  vostok::strings::text_tree_item *v8; // ecx
  vostok::strings::text_tree_item *v9; // edi
  vostok::buffer_string *v10; // ecx
  vostok::strings::text_tree_item *v11; // ecx
  vostok::strings::text_tree_item *v12; // ecx
  vostok::buffer_string *v13; // ecx
  vostok::strings::text_tree_item *v14; // ecx
  vostok::buffer_string *v15; // ecx
  vostok::strings::text_tree_item *v16; // ecx
  vostok::strings::text_tree_item *v17; // edi
  vostok::buffer_string *v18; // ecx
  vostok::strings::text_tree_item *v19; // ecx
  vostok::strings::text_tree_item *v20; // ecx
  vostok::sound::proxy_statistic *v21; // ecx
  _DWORD *i; // esi
  vostok::strings::text_tree_item *v23; // [esp+14h] [ebp-60h]
  vostok::strings::text_tree_item *v24; // [esp+14h] [ebp-60h]
  bool v25; // [esp+18h] [ebp-5Ch]
  char *v26[3]; // [esp+24h] [ebp-50h] BYREF
  _BYTE v27[64]; // [esp+30h] [ebp-44h] BYREF
  char v28; // [esp+70h] [ebp-4h] BYREF
  vostok::strings::text_tree_item *v29; // [esp+7Ch] [ebp+8h]
  vostok::strings::text_tree_item *v30; // [esp+7Ch] [ebp+8h]

  v26[0] = v27;
  v26[1] = v27;
  v26[2] = &v28;
  v27[0] = 0;
  v5 = vostok::strings::text_tree_item::new_child(
         (vostok::strings::text_tree_item *)this,
         (const char *)item,
         "HDR window");
  vostok::fs_new::path_string_impl::assignf(
    v26,
    v6,
    (vostok::buffer_string *)"%3.1f:%3.1f(%3.1f)",
    (const char *)COERCE_UNSIGNED_INT64(*(float *)(a2 + 40)),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(a2 + 40))),
    *(float *)(a2 + 36),
    (float)(*(float *)(a2 + 36) - *(float *)(a2 + 40)));
  vostok::strings::text_tree_item::add_column_impl(v7, (const char *)v5, v26[0]);
  v9 = vostok::strings::text_tree_item::new_child(v8, (const char *)item, "voices count(mono:st)");
  vostok::fs_new::path_string_impl::assignf(
    v26,
    v10,
    (vostok::buffer_string *)"%d:%d",
    *(const char **)(a2 + 28),
    *(_DWORD *)(a2 + 32));
  vostok::strings::text_tree_item::add_column_impl(v11, (const char *)v9, v26[0]);
  v29 = vostok::strings::text_tree_item::new_child(v12, (const char *)item, "proxies count");
  vostok::fs_new::path_string_impl::assignf(v26, v13, (vostok::buffer_string *)"%d", *(const char **)(a2 + 16));
  vostok::strings::text_tree_item::add_column_impl(v23, (const char *)v29, v26[0]);
  v30 = vostok::strings::text_tree_item::new_child(v14, (const char *)item, "propagators count");
  vostok::fs_new::path_string_impl::assignf(v26, v15, (vostok::buffer_string *)"%d", *(const char **)(a2 + 20));
  vostok::strings::text_tree_item::add_column_impl(v24, (const char *)v30, v26[0]);
  v17 = vostok::strings::text_tree_item::new_child(v16, (const char *)item, "proxy types");
  vostok::fs_new::path_string_impl::assignf(
    v26,
    v18,
    (vostok::buffer_string *)"point:[%d] hud:[%d]",
    *(const char **)a2,
    *(_DWORD *)(a2 + 12));
  vostok::strings::text_tree_item::add_column_impl(v19, (const char *)v17, v26[0]);
  vostok::strings::text_tree_item::new_child(v20, (const char *)item, "active proxies:");
  for ( i = *(_DWORD **)(a2 + 52); i; i = (_DWORD *)*i )
    vostok::sound::proxy_statistic::fill_text_tree(v21, (int)i, item, v25);
}
