void __thiscall vostok::render::resource_manager::resource_manager(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *in_config,
        unsigned __int64 video_memory_size)
{
  _DWORD *v3; // edx
  _DWORD *v4; // eax
  char *v5; // edx
  _DWORD *v6; // eax
  char *v7; // edx
  _DWORD *v8; // eax
  char *v9; // edx
  _DWORD *v10; // eax
  char *v11; // edx
  _DWORD *v12; // eax
  char *v13; // edx
  _DWORD *v14; // edx
  _DWORD *v15; // edx
  _DWORD *v16; // edx
  _DWORD *v17; // edx
  _DWORD *v18; // edx
  _DWORD *v19; // edx
  _DWORD *v20; // eax
  char *v21; // edx
  _DWORD *v22; // eax
  char *v23; // edx
  _DWORD *v24; // eax
  char *v25; // edx
  _DWORD *v26; // eax
  char *v27; // edx
  _DWORD *v28; // eax
  char *v29; // edx
  _DWORD *v30; // edx
  _DWORD *v31; // eax
  char *v32; // edx
  _DWORD *v33; // eax
  _DWORD *v34; // eax
  char *v35; // edx
  vostok::render::shader_binary_source_cook *v36; // ecx
  bool v37; // zf
  vostok::tasks::task *v38; // [esp-4h] [ebp-28h]
  vostok::render::shader_binary_source_cook *v39; // [esp-4h] [ebp-28h]

  in_config->m_deferred_context = 0;
  in_config->m_video_memory_size = video_memory_size;
  in_config->available_memory = 0x20000000;
  in_config->m_loaded_texture_names.m_begin = (vostok::fixed_string<260> *)in_config->m_loaded_texture_names.m_buffer;
  in_config->m_loaded_texture_names.m_end = (vostok::fixed_string<260> *)in_config->m_loaded_texture_names.m_buffer;
  in_config->m_loaded_texture_names.m_max_end = (vostok::fixed_string<260> *)&in_config->m_render_target_video_memory;
  in_config->m_render_target_video_memory = 0;
  vostok::quasi_singleton<vostok::render::resource_manager>::pinst = in_config;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_config->shader_name_to_mask_config,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
  in_config->m_num_bytes_of_texture_video_memory = 0;
  in_config->m_num_bytes_of_buffers_video_memory = 0;
  in_config->m_vs_hw_registry._M_t._M_key_compare.gap0 = HIBYTE(in_config);
  *(_DWORD *)&in_config->m_vs_hw_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_vs_hw_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_vs_hw_registry._M_t._M_header._M_data._M_left = 0;
  in_config->m_vs_hw_registry._M_t._M_header._M_data._M_right = 0;
  in_config->m_vs_hw_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_vs_hw_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_vs_hw_registry._M_t._M_header._M_data._M_left = &in_config->m_vs_hw_registry._M_t._M_header._M_data;
  in_config->m_vs_hw_registry._M_t._M_header._M_data._M_right = &in_config->m_vs_hw_registry._M_t._M_header._M_data;
  in_config->m_vs_hw_registry._M_t._M_node_count = 0;
  *(_DWORD *)&in_config->m_gs_hw_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_gs_hw_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_gs_hw_registry._M_t._M_header._M_data._M_left = 0;
  in_config->m_gs_hw_registry._M_t._M_header._M_data._M_right = 0;
  in_config->m_gs_hw_registry._M_t._M_key_compare.gap0 = HIBYTE(in_config);
  in_config->m_gs_hw_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_gs_hw_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_gs_hw_registry._M_t._M_header._M_data._M_left = &in_config->m_gs_hw_registry._M_t._M_header._M_data;
  in_config->m_gs_hw_registry._M_t._M_header._M_data._M_right = &in_config->m_gs_hw_registry._M_t._M_header._M_data;
  in_config->m_gs_hw_registry._M_t._M_node_count = 0;
  *(_DWORD *)&in_config->m_ps_hw_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_ps_hw_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_ps_hw_registry._M_t._M_header._M_data._M_left = 0;
  in_config->m_ps_hw_registry._M_t._M_header._M_data._M_right = 0;
  in_config->m_ps_hw_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_ps_hw_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_ps_hw_registry._M_t._M_header._M_data._M_left = &in_config->m_ps_hw_registry._M_t._M_header._M_data;
  in_config->m_ps_hw_registry._M_t._M_key_compare.gap0 = HIBYTE(in_config);
  in_config->m_ps_hw_registry._M_t._M_header._M_data._M_right = &in_config->m_ps_hw_registry._M_t._M_header._M_data;
  in_config->m_ps_hw_registry._M_t._M_node_count = 0;
  in_config->m_rt_registry._M_t._M_node_count = 0;
  *(_DWORD *)&in_config->m_rt_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_rt_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_rt_registry._M_t._M_header._M_data._M_left = 0;
  in_config->m_rt_registry._M_t._M_header._M_data._M_right = 0;
  in_config->m_rt_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_rt_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_rt_registry._M_t._M_header._M_data._M_left = &in_config->m_rt_registry._M_t._M_header._M_data;
  in_config->m_rt_registry._M_t._M_header._M_data._M_right = &in_config->m_rt_registry._M_t._M_header._M_data;
  *(_DWORD *)&in_config->m_texture_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_texture_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_texture_registry._M_t._M_header._M_data._M_left = 0;
  in_config->m_texture_registry._M_t._M_header._M_data._M_right = 0;
  in_config->m_texture_registry._M_t._M_header._M_data._M_color = 0;
  in_config->m_texture_registry._M_t._M_header._M_data._M_parent = 0;
  in_config->m_texture_registry._M_t._M_header._M_data._M_left = &in_config->m_texture_registry._M_t._M_header._M_data;
  in_config->m_texture_registry._M_t._M_header._M_data._M_right = &in_config->m_texture_registry._M_t._M_header._M_data;
  in_config->m_texture_registry._M_t._M_node_count = 0;
  *(_DWORD *)&in_config->m_const_tables._M_t._M_header._M_data._M_color = 0;
  in_config->m_const_tables._M_t._M_header._M_data._M_parent = 0;
  in_config->m_const_tables._M_t._M_header._M_data._M_left = 0;
  in_config->m_const_tables._M_t._M_header._M_data._M_right = 0;
  in_config->m_const_tables._M_t._M_header._M_data._M_color = 0;
  in_config->m_const_tables._M_t._M_header._M_data._M_parent = 0;
  in_config->m_const_tables._M_t._M_header._M_data._M_left = &in_config->m_const_tables._M_t._M_header._M_data;
  in_config->m_const_tables._M_t._M_header._M_data._M_right = &in_config->m_const_tables._M_t._M_header._M_data;
  in_config->m_const_tables._M_t._M_node_count = 0;
  *(_DWORD *)&in_config->m_const_buffers._M_t._M_header._M_data._M_color = 0;
  in_config->m_const_buffers._M_t._M_header._M_data._M_parent = 0;
  in_config->m_const_buffers._M_t._M_header._M_data._M_left = 0;
  in_config->m_const_buffers._M_t._M_header._M_data._M_right = 0;
  in_config->m_const_buffers._M_t._M_header._M_data._M_color = 0;
  in_config->m_const_buffers._M_t._M_header._M_data._M_parent = 0;
  in_config->m_const_buffers._M_t._M_header._M_data._M_left = &in_config->m_const_buffers._M_t._M_header._M_data;
  in_config->m_const_buffers._M_t._M_header._M_data._M_right = &in_config->m_const_buffers._M_t._M_header._M_data;
  in_config->m_const_buffers._M_t._M_node_count = 0;
  *(_DWORD *)((char *)&loc_880EC + (_DWORD)in_config) = vostok::tasks::create_new_task_type("texture_create_task", 0);
  vostok::tasks::task::task(v38, &in_config->m_parent_task.m_next_task_in_child_queue);
  v3 = (_DWORD *)((char *)&loc_88150 + (_DWORD)in_config);
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  *(_BYTE *)v3 = 0;
  v3[2] = v3;
  v3[3] = v3;
  v3[1] = 0;
  v3[4] = 0;
  *(_DWORD *)&in_config->m_g_shaders._M_t._M_header._M_data._M_color = 0;
  in_config->m_g_shaders._M_t._M_header._M_data._M_parent = 0;
  in_config->m_g_shaders._M_t._M_header._M_data._M_left = 0;
  in_config->m_g_shaders._M_t._M_header._M_data._M_right = 0;
  in_config->m_g_shaders._M_t._M_header._M_data._M_color = 0;
  in_config->m_g_shaders._M_t._M_header._M_data._M_parent = 0;
  in_config->m_g_shaders._M_t._M_header._M_data._M_left = &in_config->m_g_shaders._M_t._M_header._M_data;
  in_config->m_g_shaders._M_t._M_header._M_data._M_right = &in_config->m_g_shaders._M_t._M_header._M_data;
  in_config->m_g_shaders._M_t._M_node_count = 0;
  *(_DWORD *)&in_config->m_p_shaders._M_t._M_header._M_data._M_color = 0;
  in_config->m_p_shaders._M_t._M_header._M_data._M_parent = 0;
  in_config->m_p_shaders._M_t._M_header._M_data._M_left = 0;
  in_config->m_p_shaders._M_t._M_header._M_data._M_right = 0;
  in_config->m_p_shaders._M_t._M_header._M_data._M_color = 0;
  in_config->m_p_shaders._M_t._M_header._M_data._M_parent = 0;
  in_config->m_p_shaders._M_t._M_header._M_data._M_left = &in_config->m_p_shaders._M_t._M_header._M_data;
  in_config->m_p_shaders._M_t._M_header._M_data._M_right = &in_config->m_p_shaders._M_t._M_header._M_data;
  in_config->m_p_shaders._M_t._M_node_count = 0;
  *(_DWORD *)((char *)&loc_88198 + (_DWORD)in_config) = 0;
  in_config->m_total_vertex_buffers_size = 0;
  in_config->m_total_index_buffers_size = 0;
  in_config->m_indices_pool = 0;
  in_config->m_vertices_pool = 0;
  v4 = (_DWORD *)((char *)&loc_881AC + (_DWORD)in_config);
  v5 = (char *)&loc_881AC + (_DWORD)in_config + 12;
  *v4 = v5;
  v4[1] = v5;
  v4[2] = v4 + 8195;
  v6 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_901B6 + 2);
  v7 = (char *)&in_config->cb_created + (_DWORD)&loc_901B6 + 2;
  *v6 = v7;
  v6[1] = v7;
  v6[2] = v6 + 387;
  v8 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_907C3 + 1);
  v9 = (char *)&in_config->cb_created + (_DWORD)&loc_907C3 + 1;
  *v8 = v9;
  v8[1] = v9;
  v8[2] = v8 + 483;
  v10 = (_DWORD *)((char *)&loc_90F50 + (_DWORD)in_config);
  v11 = (char *)&loc_90F50 + (_DWORD)in_config + 12;
  *v10 = v11;
  v10[1] = v11;
  v10[2] = v10 + 2179;
  v12 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_9315B + 1);
  v13 = (char *)&in_config->cb_created + (_DWORD)&loc_9315B + 1;
  *v12 = v13;
  v12[1] = v13;
  v12[2] = v12 + 483;
  v14 = (_DWORD *)((char *)&loc_938E8 + (_DWORD)in_config);
  *v14 = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  *(_BYTE *)v14 = 0;
  v14[1] = 0;
  v14[2] = v14;
  v14[3] = v14;
  v14[4] = 0;
  v15 = (_DWORD *)((char *)&loc_93900 + (_DWORD)in_config);
  *v15 = 0;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  *(_BYTE *)v15 = 0;
  v15[1] = 0;
  v15[2] = v15;
  v15[3] = v15;
  v15[4] = 0;
  v16 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_93914 + 4);
  *v16 = 0;
  v16[1] = 0;
  v16[2] = 0;
  v16[3] = 0;
  *(_BYTE *)v16 = 0;
  v16[1] = 0;
  v16[2] = v16;
  v16[3] = v16;
  v16[4] = 0;
  v17 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_9392C + 4);
  *v17 = 0;
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  *(_BYTE *)v17 = 0;
  v17[1] = 0;
  v17[2] = v17;
  v17[3] = v17;
  v17[4] = 0;
  v18 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_93947 + 1);
  v18[4] = 0;
  *v18 = 0;
  v18[1] = 0;
  v18[2] = 0;
  v18[3] = 0;
  *(_BYTE *)v18 = 0;
  v18[1] = 0;
  v18[2] = v18;
  v18[3] = v18;
  v19 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_9395C + 4);
  v19[4] = 0;
  *v19 = 0;
  v19[1] = 0;
  v19[2] = 0;
  v19[3] = 0;
  *(_BYTE *)v19 = 0;
  v19[1] = 0;
  v19[2] = v19;
  v19[3] = v19;
  v20 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_93973 + 5);
  v21 = (char *)&in_config->cb_created + (_DWORD)&loc_93973 + 5;
  *v20 = v21;
  v20[1] = v21;
  v20[2] = v20 + 67;
  v22 = (int *)((char *)&dword_93A84 + (_DWORD)in_config);
  v23 = (char *)&dword_93A84 + (_DWORD)in_config + 12;
  *v22 = v23;
  v22[1] = v23;
  v22[2] = v22 + 643;
  v24 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_9448F + 1);
  v25 = (char *)&in_config->cb_created + (_DWORD)&loc_9448F + 1;
  *v24 = v25;
  v24[1] = v25;
  v24[2] = v24 + 35;
  v26 = (_DWORD *)((char *)&loc_9451C + (_DWORD)in_config);
  v27 = (char *)&loc_9451C + (_DWORD)in_config + 12;
  *v26 = v27;
  v26[1] = v27;
  v26[2] = v26 + 35;
  v28 = (_DWORD *)((char *)&loc_945A8 + (_DWORD)in_config);
  v29 = (char *)&loc_945A8 + (_DWORD)in_config + 12;
  *v28 = v29;
  v28[1] = v29;
  v28[2] = v28 + 35;
  v30 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_94631 + 3);
  *v30 = 0;
  v30[1] = 0;
  v30[2] = 0;
  v30[3] = 0;
  *(_BYTE *)v30 = 0;
  v30[1] = 0;
  v30[2] = v30;
  v30[3] = v30;
  v30[4] = 0;
  *((_BYTE *)&in_config->sh_created + (_DWORD)&loc_94649 + 3) = 0;
  v31 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_9464F + 1);
  v32 = (char *)&in_config->cb_created + (_DWORD)&loc_9464F + 1;
  *v31 = v32;
  v31[1] = v32;
  v31[2] = v31 + 163;
  *(unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_948DA + 2) = 0;
  v33 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_948DE + 2);
  v33[1] = 0;
  *v33 = 0;
  v34 = (unsigned int *)((char *)&in_config->sh_created + (_DWORD)&loc_948EB + 1);
  *((_BYTE *)&in_config->sh_created + (_DWORD)&loc_948E5 + 3) = 0;
  *((_BYTE *)&loc_948E9 + (_DWORD)in_config) = 1;
  v35 = (char *)&in_config->cb_created + (_DWORD)&loc_948EB + 1;
  *v34 = v35;
  v34[1] = v35;
  v34[2] = &in_config->m_loaded_texture_names.m_buffer[32].m_store[(_DWORD)&loc_948EB + 1 + 92];
  *(int *)((char *)&dword_96B78 + (_DWORD)in_config) = 0;
  memset((int)s_command_lists, 0, sizeof(s_command_lists));
  v37 = (_S5_14 & 1) == 0;
  in_config->sh_returned = 0;
  in_config->sh_created = 0;
  in_config->tl_created = 0;
  in_config->cb_created = 0;
  in_config->sl_created = 0;
  if ( v37 )
  {
    _S5_14 |= 1u;
    vostok::render::shader_binary_source_cook::shader_binary_source_cook(v36);
    atexit((int (__cdecl *)())vostok::render::resource_manager::resource_manager_::_2_::_dynamic_atexit_destructor_for__shader_binary_source_cooker__);
    v36 = v39;
  }
  vostok::resources::resources_manager::register_cook(
    &shader_binary_source_cooker,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)v36);
}
