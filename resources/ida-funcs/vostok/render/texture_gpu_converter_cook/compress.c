void __thiscall vostok::render::texture_gpu_converter_cook::compress(
        vostok::render::texture_gpu_converter_cook *this,
        vostok::render::compress_temp_data *temp_data,
        int a3)
{
  vostok::render::texture_gpu_converter_cook *v4; // ecx
  int v5; // edx
  unsigned int v6; // edi
  unsigned __int8 *v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // esi
  vostok::render::backend *v10; // esi
  survarium::pure_game_effect_emitter_base *v11; // edi
  survarium::pure_game_effect_emitter_base *v12; // ecx
  unsigned int v13; // esi
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::timing::timer *v15; // ecx
  survarium::pure_game_effect_emitter_base *m_object; // ecx
  bool has_passed_filters; // al
  double v18; // st7
  int v19; // eax
  __int64 v20; // [esp+8h] [ebp-68h]
  __int64 v21; // [esp+8h] [ebp-68h]
  int v22; // [esp+10h] [ebp-60h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v23; // [esp+14h] [ebp-5Ch] BYREF
  const char *v24; // [esp+18h] [ebp-58h]
  const char *v25; // [esp+1Ch] [ebp-54h]
  unsigned int v26; // [esp+20h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v27; // [esp+28h] [ebp-48h] BYREF
  vostok::resources::memory_usage_type v28; // [esp+48h] [ebp-28h] BYREF
  int v29; // [esp+54h] [ebp-1Ch]
  void *v30; // [esp+58h] [ebp-18h]
  unsigned int v31; // [esp+5Ch] [ebp-14h]
  unsigned int v32; // [esp+64h] [ebp-Ch]
  unsigned __int8 *v33; // [esp+68h] [ebp-8h] BYREF
  unsigned int i; // [esp+6Ch] [ebp-4h]
  float elapsed_sec; // [esp+78h] [ebp+8h]
  vostok::render::backend *v36; // [esp+7Ch] [ebp+Ch]
  unsigned int v37; // [esp+7Ch] [ebp+Ch]

  v29 = 0;
  vostok::timing::timer::timer((vostok::timing::timer *)this, (LARGE_INTEGER *)&v27.functor);
  *((LARGE_INTEGER *)&v27.functor.data + 1) = vostok::timing::get_QPC();
  *(_QWORD *)&v27.functor.obj_ptr = 0;
  vostok::render::texture_gpu_converter_cook::filtration(v4, temp_data, a3);
  v5 = *(_DWORD *)(*(_DWORD *)(a3 + 12) + 848);
  v6 = *(_DWORD *)(a3 + 40);
  v7 = (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a3 + 4) + 264) + 128);
  v8 = *(_DWORD *)(a3 + 32) >> 2;
  v9 = *(_DWORD *)(a3 + 36) >> 2;
  v33 = v7;
  if ( v5 == 3 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v32 = v9;
      v31 = v9;
      v36 = 0;
      for ( *(float *)&v28.size = (double)i * 0.16666667; (unsigned int)v36 < v6; v31 >>= 1 )
      {
        *((float *)&v20 + 1) = 0.16666667;
        *(float *)&v20 = *(float *)&v28.size;
        vostok::render::texture_gpu_converter_cook::compress_surface(
          (vostok::render::texture_gpu_converter_cook *)v7,
          (unsigned __int8 **)temp_data,
          &v33,
          v32,
          v31,
          v20,
          v36,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)a3);
        v36 = (vostok::render::backend *)((char *)v36 + 1);
        v32 >>= 1;
      }
    }
    goto LABEL_10;
  }
  if ( v5 == 1 )
  {
    v31 = v9;
    v10 = 0;
    v37 = v8;
    if ( v6 )
    {
      do
      {
        *((float *)&v21 + 1) = 1.0;
        *(float *)&v21 = 0.0;
        vostok::render::texture_gpu_converter_cook::compress_surface(
          (vostok::render::texture_gpu_converter_cook *)v7,
          (unsigned __int8 **)temp_data,
          &v33,
          v37,
          v31,
          v21,
          v10,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)a3);
        v37 >>= 1;
        v31 >>= 1;
        v10 = (vostok::render::backend *)((char *)v10 + 1);
      }
      while ( (unsigned int)v10 < v6 );
LABEL_10:
      v7 = v33;
    }
  }
  *v7 = *(_BYTE *)(*(_DWORD *)(a3 + 12) + 858);
  v11 = *(survarium::pure_game_effect_emitter_base **)(a3 + 4);
  v23.m_object = (survarium::pure_game_effect_emitter_base *)v7;
  v28.type = &vostok::resources::nocache_memory;
  v28.size = 272;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v23,
    v11);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    &v28,
    v12,
    *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)a3,
    v23);
  v13 = 0;
  vostok::resources::query_result_for_cook::finish_query_impl(
    v14,
    *(vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> **)a3,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  if ( *(_DWORD *)(a3 + 40) )
  {
    do
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(a3 + 8) + 4 * v13++));
    while ( v13 < *(_DWORD *)(a3 + 40) );
  }
  elapsed_sec = vostok::timing::timer::get_elapsed_sec(v15, (int)&v27.functor);
  *(float *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7392) = *(float *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7392) + elapsed_sec;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"render_pc_dx11",
                               (const char *)4),
        m_object = v23.m_object,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_object,
      &v27);
    v18 = (double)*(int *)(a3 + 20);
    v23.m_object = *(survarium::pure_game_effect_emitter_base **)(a3 + 36);
    v19 = *(_DWORD *)(a3 + 20);
    v22 = *(_DWORD *)(a3 + 32);
    v29 = 1;
    if ( v19 < 0 )
      v18 = v18 + 4294967300.0;
    v30 = &loc_100000;
    v31 = 0;
    v28 = 0;
    vostok::logging::append(
      &v27,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\texture_gpu_converter_cook.cpp",
      0x28Au,
      "void __thiscall vostok::render::texture_gpu_converter_cook::compress(struct vostok::render::compress_temp_data *)",
      "render_pc_dx11",
      info,
      "gpu compress time: %.3f ms, %.2fMb %dx%d",
      (float)(elapsed_sec * 1000.0),
      v18 / ((double)(unsigned int)&loc_100000 - (double)0LL),
      v22,
      v23.m_object);
  }
  if ( (v29 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_object,
      (int *)&v27);
  if ( *(_DWORD *)(a3 + 8) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)m_object,
      (int)vostok::render::g_allocator,
      *(char **)(a3 + 8),
      v24,
      v25,
      v26);
    *(_DWORD *)(a3 + 8) = 0;
  }
  vostok::memory::doug_lea_allocator::free_impl(
    (vostok::memory::doug_lea_allocator *)m_object,
    (int)vostok::render::g_allocator,
    (char *)a3,
    v24,
    v25,
    v26);
}
