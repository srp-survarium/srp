void __thiscall vostok::render::scene_manager::~scene_manager(vostok::render::scene_manager *this, int a2)
{
  vostok::ai::fsm_state **v3; // ecx
  vostok::ai::fsm_state **v4; // eax
  bool has_passed_filters; // al
  vostok::ai::fsm_state **v6; // edi
  vostok::ai::fsm_state **v7; // edi
  vostok::ai::fsm_state **v8; // esi
  vostok::ai::fsm_state **v9; // [esp-4h] [ebp-40h]
  const char *v10; // [esp+0h] [ebp-3Ch]
  const char *v11; // [esp+4h] [ebp-38h]
  unsigned int v12; // [esp+8h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+10h] [ebp-2Ch] BYREF
  vostok::ai::fsm_state **v14; // [esp+30h] [ebp-Ch]
  vostok::ai::fsm_state **pointer; // [esp+34h] [ebp-8h]
  char v16; // [esp+44h] [ebp+8h]

  v3 = *(vostok::ai::fsm_state ***)a2;
  v4 = *(vostok::ai::fsm_state ***)(a2 + 4);
  v16 = 0;
  pointer = v3;
  v14 = v4;
  if ( v3 != v4 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)2),
          v3 = v9,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3,
        &v13);
      v16 = 1;
      vostok::logging::append(
        &v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\scene_manager.cpp",
        0x1Du,
        "__thiscall vostok::render::scene_manager::~scene_manager(void)",
        "render_pc_dx11",
        error,
        "Some scenes were not deleted before render engine destruction.");
    }
    if ( (v16 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v13);
    v6 = pointer;
    do
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        v6++,
        v10,
        v11,
        v12);
    while ( v6 != v14 );
  }
  v7 = *(vostok::ai::fsm_state ***)(a2 + 76);
  v8 = *(vostok::ai::fsm_state ***)(a2 + 80);
  while ( v7 != v8 )
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
      vostok::render::g_allocator,
      v7++,
      v10,
      v11,
      v12);
  vostok::quasi_singleton<vostok::render::scene_manager>::pinst = 0;
  *(_DWORD *)(a2 + 156) = *(_DWORD *)(a2 + 152);
  *(_DWORD *)(a2 + 80) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)a2;
}
