void __userpurge survarium::game::update_stats(
        survarium::game *this@<ecx>,
        const char *a2@<edi>,
        unsigned int current_frame_id)
{
  vostok::console_commands::cc_bool *v4; // ecx
  float v5; // edx
  int v6; // eax
  unsigned int *v7; // eax
  float *v8; // eax
  int v9; // eax
  const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *v10; // esi
  const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *v11; // eax
  survarium::stats_graph *v12; // ecx
  float *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // esi
  char *v15; // eax
  vostok::memory::doug_lea_allocator *v16; // ecx
  char *v17; // esi
  vostok::sound::world_user *v18; // eax
  int v19; // eax
  vostok::sound::sound_debug_stats *v20; // edi
  _DWORD *v21; // eax
  int v22; // ebx
  float value; // [esp+4h] [ebp-18h]
  vostok::console_commands::cc_bool *valuea; // [esp+4h] [ebp-18h]
  const char *v25; // [esp+8h] [ebp-14h]
  const char *v26; // [esp+Ch] [ebp-10h]
  unsigned int v27; // [esp+10h] [ebp-Ch]
  unsigned int v28; // [esp+14h] [ebp-8h]
  float v29; // [esp+18h] [ebp-4h]
  float time; // [esp+24h] [ebp+8h]

  v25 = a2;
  time = (double)(unsigned int)(*(_DWORD *)(current_frame_id + 13956) - *(_DWORD *)(current_frame_id + 13948)) * 0.001;
  if ( fabs(time - *(float *)(current_frame_id + 13960)) >= 0.0000099999997 )
    v29 = s_bm_current_air_resistance / (float)(time - *(float *)(current_frame_id + 13960));
  else
    v29 = FLOAT_10000_0;
  survarium::stats_graph::add_value((survarium::stats_graph *)this, time, v29);
  v5 = *(float *)(current_frame_id + 13840);
  v6 = *(_DWORD *)(current_frame_id + 13956);
  *(float *)(current_frame_id + 13960) = time;
  *(_DWORD *)(current_frame_id + 13952) = v6;
  if ( v5 != 0.0 && *(_BYTE *)(LODWORD(v5) + 216) )
  {
    v7 = *(unsigned int **)(current_frame_id + 132);
    value = (double)v7[8] / (*(float *)(*v7 + 8) - *(float *)(*(_DWORD *)*v7 + 8));
    survarium::lobby_menu::set_fps_stats((survarium::lobby_menu *)*v7, v5, value);
  }
  if ( (_S14_0 & 1) == 0 )
  {
    _S14_0 |= 1u;
    vostok::console_commands::cc_bool::cc_bool(
      v4,
      (int)&fps_graph,
      "draw_fps_graph",
      &draw_fps_graph,
      0,
      command_type_user_specific,
      (const vostok::console_commands::execution_filter)a2);
    atexit((int (__cdecl *)())survarium::game::update_stats_::_4_::_dynamic_atexit_destructor_for__fps_graph__);
    v4 = valuea;
  }
  if ( draw_fps_graph && !*(_BYTE *)(current_frame_id + 11) && *(_BYTE *)(current_frame_id + 408) )
  {
    v8 = *(float **)(current_frame_id + 132);
    v8[2] = FLOAT_5_0;
    survarium::stats_graph::adjust_time_interval((survarium::stats_graph *)v4, v8);
    v9 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)current_frame_id + 44))(current_frame_id);
    v10 = (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(current_frame_id + 13900) + 8);
    v11 = (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 52))(v9);
    v12 = *(survarium::stats_graph **)(current_frame_id + 132);
    if ( v12->m_newest_value )
      survarium::stats_graph::render(v12, (unsigned int)v12, v11, v10, (unsigned int)v25, (unsigned int)v26, v27, v28);
  }
  else
  {
    v13 = *(float **)(current_frame_id + 132);
    v13[2] = s_bm_current_air_resistance;
    survarium::stats_graph::adjust_time_interval((survarium::stats_graph *)v4, v13);
  }
  if ( s_draw_snd_stats_value && *(_BYTE *)(current_frame_id + 408) )
  {
    if ( !*(_DWORD *)(current_frame_id + 15160) )
    {
      v14 = survarium::g_allocator;
      v15 = type_info::raw_name(&vostok::sound::sound_debug_stats `RTTI Type Descriptor');
      v17 = vostok::memory::doug_lea_allocator::malloc_impl(v16, (int)v14, 0x24u, v15, v25, v26, v27);
      if ( v17 )
      {
        v18 = (vostok::sound::world_user *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(current_frame_id + 156) + 8))(*(_DWORD *)(current_frame_id + 156));
        vostok::sound::sound_debug_stats::sound_debug_stats(
          (vostok::sound::sound_debug_stats *)v17,
          *(vostok::ui::world **)(current_frame_id + 168),
          v18,
          (vostok::sound::world_user *)(current_frame_id + 340),
          (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v25);
      }
      else
      {
        v19 = 0;
      }
      *(_DWORD *)(current_frame_id + 15160) = v19;
    }
    v20 = *(vostok::sound::sound_debug_stats **)(current_frame_id + 15160);
    if ( !v20->m_started )
      vostok::sound::sound_debug_stats::start((vostok::sound::sound_debug_stats *)v12, v20);
    v21 = *(_DWORD **)(current_frame_id + 15160);
    if ( v21[5] != -1 )
    {
      if ( *v21 )
      {
        _InterlockedExchange(&vostok::sound::sound_debug_stats::m_s_debug_draw_mode, 1);
        if ( vostok::sound::sound_debug_stats::m_s_debug_draw_mode == 1 )
          vostok::sound::sound_debug_stats::draw_overall_stats(
            (vostok::sound::sound_debug_stats *)(*(_DWORD *)(current_frame_id + 13900) + 8),
            (vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(current_frame_id + 13900) + 8),
            (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)v25);
      }
    }
  }
  else
  {
    v22 = *(_DWORD *)(current_frame_id + 15160);
    if ( v22 && *(_BYTE *)(v22 + 32) )
    {
      _InterlockedExchange((volatile __int32 *)(v22 + 20), -1);
      *(_BYTE *)(v22 + 32) = 0;
    }
  }
  if ( !(++qpf_checker % 0x3E8) )
    vostok::timing::check_qpf();
}
