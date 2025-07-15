char __thiscall survarium::lobby_client::read_shop_items(
        survarium::lobby_client *this,
        vostok::render::stage_screen_space_reflections *reader,
        int a3)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::render::shader_constant_host *v8; // esi
  int v9; // edi
  vostok::render::shader_constant_host *v10; // esi
  survarium::shop_items_container *i; // ecx
  int v13; // [esp-4h] [ebp-14h]
  const char *v14; // [esp+0h] [ebp-10h]
  const char *v15; // [esp+4h] [ebp-Ch]
  unsigned int v16; // [esp+8h] [ebp-8h]
  vostok::render::shader_constant_host *v17; // [esp+18h] [ebp+8h]

  v17 = **(vostok::render::shader_constant_host ***)(a3 + 4);
  v4 = survarium::g_allocator;
  *(_DWORD *)(a3 + 4) += 4;
  reader[235].m_use_rain_parameter = v17;
  v5 = type_info::raw_name(&survarium::shop_items_container `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 264 * (_DWORD)v17 + 8, v5, v14, v15, v16);
  *(_DWORD *)v7 = v17;
  v7 += 4;
  v8 = (vostok::render::shader_constant_host *)(v7 + 4);
  v13 = (int)&v7[264 * (_DWORD)v17 + 4];
  *(_DWORD *)v7 = 264;
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)v17);
  reader[235].m_rain_offset_parameter = v8;
  v9 = 0;
  v10 = 0;
  for ( i = (survarium::shop_items_container *)v13; v10 < reader[235].m_use_rain_parameter; v9 += 264 )
  {
    survarium::shop_items_container::deserialize(
      i,
      (vostok::network_core::buffer_reader *)((char *)reader[235].m_rain_offset_parameter + v9),
      a3);
    v10 = (vostok::render::shader_constant_host *)((char *)v10 + 1);
  }
  return 1;
}
