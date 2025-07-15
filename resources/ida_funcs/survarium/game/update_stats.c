void __usercall survarium::game::update_stats(survarium::game *this@<ecx>, int a2@<edi>)
{
  double v2; // st7
  float v3; // ecx
  vostok::console_commands::cc_value<bool> *v4; // ecx
  float v5; // edx
  volatile int m_pending_queries_count; // eax
  int v7; // eax
  const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *v8; // esi
  vostok::render::ui::renderer *v9; // eax
  int v10; // eax
  int v11; // eax
  const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *v12; // esi
  vostok::render::ui::renderer *v13; // eax
  survarium::stats_graph *v14; // ecx
  int v15; // eax
  vostok::sound::sound_debug_stats *v16; // esi
  vostok::sound::world_user *v17; // eax
  int v18; // eax
  float time; // [esp+0h] [ebp-5Ch]
  vostok::ui::world *value; // [esp+4h] [ebp-58h]
  vostok::console_commands::command_type v21; // [esp+8h] [ebp-54h]
  vostok::console_commands::execution_filter v22; // [esp+Ch] [ebp-50h]
  float v23; // [esp+10h] [ebp-4Ch]
  float last_frame_time; // [esp+14h] [ebp-48h]
  float last_frame_timea; // [esp+14h] [ebp-48h]
  char buff[64]; // [esp+18h] [ebp-44h] BYREF

  v2 = (double)(unsigned int)(*(_DWORD *)(a2 + 1000) - *(_DWORD *)(a2 + 992)) * 0.001;
  last_frame_time = v2;
  v3 = fabs(last_frame_time - *(float *)(a2 + 1004));
  if ( v3 >= 0.0000099999997 )
    v23 = *(float *)&clear_value / (float)(last_frame_time - *(float *)(a2 + 1004));
  else
    v23 = 10000.0;
  time = v2;
  survarium::stats_graph::add_value((survarium::stats_graph *)LODWORD(v3), *(float **)(a2 + 108), time, v23);
  *(_DWORD *)(a2 + 996) = *(_DWORD *)(a2 + 1000);
  v5 = *(float *)(a2 + 884);
  *(float *)(a2 + 1004) = last_frame_time;
  if ( v5 != 0.0 && *(_BYTE *)(LODWORD(v5) + 180) )
    survarium::lobby_menu::set_fps_stats(**(survarium::lobby_menu ***)(a2 + 108), v5);
  if ( BYTE5(survarium::g_allocator.f_.f_) && !*(_BYTE *)(a2 + 11) && *(_BYTE *)(a2 + 332) )
  {
    last_frame_timea = (double)*(unsigned int *)(*(_DWORD *)(a2 + 108) + 32)
                     / (*(float *)(**(_DWORD **)(a2 + 108) + 8) - *(float *)(***(_DWORD ***)(a2 + 108) + 8));
    survarium::stats::set_fps_stats(*(survarium::stats **)(a2 + 116), last_frame_timea, *(float *)(a2 + 116));
    if ( vostok::resources::g_resources_manager.m_initialized )
      m_pending_queries_count = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
    else
      m_pending_queries_count = 0;
    vostok::sprintf<64>((char (*)[64])buff, "pending queries: %d", m_pending_queries_count);
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)(*(_DWORD *)(a2 + 116) + 24) + 8))(
      *(_DWORD *)(*(_DWORD *)(a2 + 116) + 24),
      buff);
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 36))(a2);
    v8 = (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 940) + 8);
    v9 = (vostok::render::ui::renderer *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 52))(v7);
    survarium::stats::draw(*(survarium::stats **)(a2 + 116), v8, v9);
  }
  if ( (_S10_1 & 1) == 0 )
  {
    _S10_1 |= 1u;
    vostok::console_commands::cc_value<bool>::cc_value<bool>(
      v4,
      (int)&fps_graph,
      "draw_fps_graph",
      &draw_fps_graph,
      0,
      command_type_user_specific,
      execution_filter_general,
      v21,
      v22);
    fps_graph.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
    fps_graph.m_need_args = 1;
    atexit(survarium::game::update_stats_::_7_::_dynamic_atexit_destructor_for__fps_graph__);
  }
  if ( draw_fps_graph && !*(_BYTE *)(a2 + 11) && *(_BYTE *)(a2 + 332) )
  {
    v10 = *(_DWORD *)(a2 + 108);
    *(_DWORD *)(v10 + 8) = 1084227584;
    survarium::stats_graph::adjust_time_interval((survarium::stats_graph *)v4, (float *)v10);
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 36))(a2);
    v12 = (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 940) + 8);
    v13 = (vostok::render::ui::renderer *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 52))(v11);
    v14 = *(survarium::stats_graph **)(a2 + 108);
    if ( v14->m_newest_value )
      survarium::stats_graph::render(v14, v14, v13, v12, 0x23Eu, 0x80u, v21, v22);
  }
  else
  {
    v15 = *(_DWORD *)(a2 + 108);
    *(_DWORD *)(v15 + 8) = clear_value;
    survarium::stats_graph::adjust_time_interval((survarium::stats_graph *)v4, (float *)v15);
  }
  if ( BYTE4(survarium::g_allocator.f_.f_) && *(_BYTE *)(a2 + 332) )
  {
    if ( !*(_DWORD *)(a2 + 2156) )
    {
      v16 = (vostok::sound::sound_debug_stats *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                                  0x24u);
      if ( v16 )
      {
        value = *(vostok::ui::world **)(a2 + 144);
        v17 = (vostok::sound::world_user *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 132) + 8))(*(_DWORD *)(a2 + 132));
        vostok::sound::sound_debug_stats::sound_debug_stats(
          v16,
          (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
          v17,
          (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 308),
          value);
      }
      else
      {
        v18 = 0;
      }
      *(_DWORD *)(a2 + 2156) = v18;
    }
    if ( *(_DWORD *)(*(_DWORD *)(a2 + 2156) + 24) != -1 )
    {
      vostok::sound::sound_debug_stats::set_debug_draw_mode(move_forward);
      vostok::sound::sound_debug_stats::draw(
        *(vostok::sound::sound_debug_stats **)(a2 + 2156),
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 940) + 4),
        (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 940) + 8));
    }
  }
}
