void __userpurge survarium::options_monitor_index_selector::options_monitor_index_selector(
        survarium::options_monitor_index_selector *this@<ecx>,
        int a2@<esi>,
        survarium::options_tab *parent_tab)
{
  vostok::buffer_string *v3; // ecx
  char *v4; // eax
  const char *v5; // edi
  bool v6; // zf
  int v7; // eax
  unsigned __int8 v8; // dl
  bool v9; // cc
  int v10; // ecx
  vostok::buffer_string *v11; // [esp-4h] [ebp-10h]
  const char *v12; // [esp+0h] [ebp-Ch]
  const char *v13; // [esp+4h] [ebp-8h]
  unsigned int v14; // [esp+8h] [ebp-4h]
  int v15; // [esp+14h] [ebp+8h]
  _DWORD *v16; // [esp+14h] [ebp+8h]

  survarium::options_item_int::options_item_int(this, a2, parent_tab, "r_monitor_index", 0, 0, 0);
  v3 = (vostok::buffer_string *)(a2 + 32);
  *(_DWORD *)a2 = &survarium::options_monitor_index_selector::`vftable';
  v15 = 5;
  v4 = (char *)(a2 + 44);
  do
  {
    v3->m_begin = v4;
    *((_DWORD *)v4 - 2) = v4;
    *((_DWORD *)v4 - 1) = v4 + 32;
    *v4 = 0;
    v3 = (vostok::buffer_string *)((char *)v3 + 44);
    v4 += 44;
    --v15;
  }
  while ( v15 >= 0 );
  v5 = 0;
  v16 = (_DWORD *)(a2 + 32);
  v14 = 6;
  do
  {
    vostok::fs_new::path_string_impl::assignf(v16, v3, (vostok::buffer_string *)"%d", v5);
    v16 += 11;
    ++v5;
    v6 = v14-- == 1;
    v3 = v11;
  }
  while ( !v6 );
  *(_DWORD *)(a2 + 24) = vostok::memory::new_array_helper<char const *>::call<vostok::memory::doug_lea_allocator>(
                           survarium::g_allocator,
                           vostok::render::g_num_monitors,
                           v12,
                           v13,
                           v14);
  v7 = vostok::render::g_num_monitors;
  v8 = 0;
  v9 = (int)vostok::render::g_num_monitors <= 0;
  *(_BYTE *)(a2 + 28) = vostok::render::g_num_monitors;
  if ( !v9 )
  {
    v10 = 0;
    do
    {
      ++v8;
      *(_DWORD *)(*(_DWORD *)(a2 + 24) + 4 * v10) = *(_DWORD *)(44 * v10 + a2 + 32);
      v10 = v8;
    }
    while ( v8 < v7 );
  }
}
