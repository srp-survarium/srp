void __thiscall survarium::ladder_cook::on_animations_loaded(
        survarium::ladder_cook *this,
        vostok::resources::queries_result *data,
        const vostok::configs::binary_config_value *config)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // edi
  volatile int m_result; // eax
  int v5; // ebx
  const vostok::math::float3 *v6; // esi
  const vostok::math::float3 *v7; // edi
  vostok::math::float4x4 *v8; // esi
  vostok::math::float4x4 *rotation; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // edi
  survarium::ladder *v14; // ecx
  vostok::resources::managed_resource *m_object; // esi
  survarium::pure_game_effect_emitter_base *v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v18; // ecx
  vostok::resources::managed_resource *v19; // esi
  int v20; // eax
  const vostok::math::float3 *v21; // ebx
  const vostok::math::float3 *v22; // esi
  vostok::math::float4x4 *v23; // edi
  vostok::math::float4x4 *v24; // eax
  vostok::memory::doug_lea_allocator *v25; // esi
  char *v26; // eax
  vostok::memory::doug_lea_allocator *v27; // ecx
  vostok::math::float4x4 *v28; // ecx
  char *v29; // ebx
  vostok::math::float3 *angles_xyz; // eax
  const char **v31; // eax
  vostok::resources::query_result_for_user *v32; // ecx
  vostok::resources::managed_resource *v33; // edi
  const char **v34; // eax
  vostok::resources::query_result_for_user *v35; // ecx
  vostok::resources::managed_resource *v36; // edi
  bool has_passed_filters; // al
  volatile int *p_m_thread_id; // eax
  vostok::resources::query_result_for_cook *v39; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v40; // [esp-Ch] [ebp-24Ch] BYREF
  assert_on_fail_bool v41; // [esp-8h] [ebp-248h]
  vostok::resources::cook_base::result_enum v42; // [esp-4h] [ebp-244h]
  const char *v43; // [esp+0h] [ebp-240h]
  const char *v44; // [esp+4h] [ebp-23Ch]
  unsigned int v45; // [esp+8h] [ebp-238h]
  int v46; // [esp+10h] [ebp-230h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v47; // [esp+14h] [ebp-22Ch] BYREF
  vostok::resources::query_result *v48; // [esp+18h] [ebp-228h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v49; // [esp+1Ch] [ebp-224h] BYREF
  survarium::pure_game_effect_emitter_base *v50; // [esp+20h] [ebp-220h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v51; // [esp+24h] [ebp-21Ch] BYREF
  survarium::landing_point *pointer; // [esp+28h] [ebp-218h]
  vostok::resources::managed_resource *v53; // [esp+2Ch] [ebp-214h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v54; // [esp+30h] [ebp-210h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v55; // [esp+34h] [ebp-20Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v56; // [esp+38h] [ebp-208h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v57; // [esp+3Ch] [ebp-204h] BYREF
  __int64 v58; // [esp+40h] [ebp-200h] BYREF
  float z; // [esp+48h] [ebp-1F8h]
  int v60; // [esp+4Ch] [ebp-1F4h]
  vostok::math::float4x4 v61; // [esp+50h] [ebp-1F0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v62; // [esp+90h] [ebp-1B0h] BYREF
  _BYTE v63[12]; // [esp+B4h] [ebp-18Ch] BYREF
  vostok::math::float4x4 v64; // [esp+C0h] [ebp-180h] BYREF
  vostok::math::float4x4 v65; // [esp+100h] [ebp-140h] BYREF
  vostok::math::float4x4 v66; // [esp+140h] [ebp-100h] BYREF
  vostok::math::float4x4 v67; // [esp+180h] [ebp-C0h] BYREF
  _BYTE v68[64]; // [esp+1C0h] [ebp-80h] BYREF
  _BYTE v69[64]; // [esp+200h] [ebp-40h] BYREF

  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  m_result = data->m_result;
  v5 = 0;
  v46 = 0;
  v55 = m_parent_query;
  if ( m_result == 1 )
  {
    v6 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](config, "position")->data.pointer;
    v7 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](config, "rotation")->data.pointer;
    v8 = vostok::math::create_translation(v6, &v66);
    rotation = vostok::math::create_rotation(v7, (int)v7, (int)v68);
    vostok::math::mul4x3(v8, rotation, &v61);
    v58 = *(_QWORD *)&v61.lines[2].x;
    z = v61.k.z;
    v10 = survarium::g_allocator;
    v60 = COERCE_UNSIGNED_INT((float)((float)(v61.k.x * v61.c.x) + (float)(v61.c.y * v61.k.y)) + (float)(v61.c.z * v61.k.z))
        ^ _mask__NegFloat_;
    v11 = type_info::raw_name(&survarium::ladder `RTTI Type Descriptor');
    v13 = vostok::memory::doug_lea_allocator::malloc_impl(v12, (int)v10, 0x178u, v11, v43, v44, v45);
    if ( v13 )
    {
      v5 = 1;
      v46 = 3;
      m_object = vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[0], &v54)->m_object;
      v47.m_object = 0;
      if ( m_object )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v47);
        v47.m_object = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      survarium::ladder::ladder(
        v14,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v13,
        &v47,
        (vostok::resources::managed_resource **)&v58);
      v50 = v16;
    }
    else
    {
      v50 = 0;
    }
    if ( (v46 & 2) != 0 )
    {
      v46 &= ~2u;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v47);
    }
    if ( (v46 & 1) != 0 )
    {
      v46 &= ~1u;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v54);
    }
    v50[1].decrease_quality(&v50[1], (unsigned int)config);
    v17 = vostok::configs::binary_config_value::operator[](config, "landing_points");
    v19 = (vostok::resources::managed_resource *)v17->data.pointer;
    v20 = (int)v17->data.pointer + 24 * v17->count;
    v47.m_object = v19;
    v53 = (vostok::resources::managed_resource *)v20;
    if ( v19 != (vostok::resources::managed_resource *)v20 )
    {
      v48 = &data->m_queries[v5];
      while ( 1 )
      {
        v21 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](
                                              (vostok::configs::binary_config_value *)v19,
                                              "position")->data.pointer;
        v22 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](
                                              (vostok::configs::binary_config_value *)v19,
                                              "rotation")->data.pointer;
        v23 = vostok::math::create_translation(v21, &v67);
        v24 = vostok::math::create_rotation(v22, (int)v23, (int)v69);
        vostok::math::mul4x3(v23, v24, &v65);
        vostok::math::mul4x3(&v61, &v65, &v64);
        v25 = survarium::g_allocator;
        v26 = type_info::raw_name(&survarium::landing_point `RTTI Type Descriptor');
        v29 = vostok::memory::doug_lea_allocator::malloc_impl(v27, (int)v25, 0x24u, v26, v43, v44, v45);
        if ( v29 )
        {
          angles_xyz = vostok::math::float4x4::get_angles_xyz(v28, (int)v63, (int)&v64);
          *(_QWORD *)(v29 + 4) = *(_QWORD *)&v64.lines[3].x;
          *((_DWORD *)v29 + 3) = LODWORD(v64.c.z);
          *(_DWORD *)v29 = 0;
          *(vostok::math::float3 *)(v29 + 16) = *angles_xyz;
          *((_DWORD *)v29 + 7) = 0;
          *((_DWORD *)v29 + 8) = 0;
        }
        else
        {
          v29 = 0;
        }
        pointer = (survarium::landing_point *)v29;
        v31 = (const char **)vostok::configs::binary_config_value::operator[](
                               (vostok::configs::binary_config_value *)v47.m_object,
                               "start_animation");
        if ( vostok::strings::compare(*v31, uri) )
        {
          v32 = v48++;
          v33 = vostok::resources::query_result_for_user::get_managed_resource(v32, &v57)->m_object;
          v49.m_object = 0;
          if ( v33 )
          {
            vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
            v49.m_object = v33;
            _InterlockedExchangeAdd(&v33->m_reference_count, 1u);
          }
          vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
            (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v49,
            (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v29
          + 7);
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v57);
        }
        v34 = (const char **)vostok::configs::binary_config_value::operator[](
                               (vostok::configs::binary_config_value *)v47.m_object,
                               "end_animation");
        if ( vostok::strings::compare(*v34, uri) )
        {
          v35 = v48++;
          v36 = vostok::resources::query_result_for_user::get_managed_resource(v35, &v56)->m_object;
          v51.m_object = 0;
          if ( v36 )
          {
            vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v51);
            v51.m_object = v36;
            _InterlockedExchangeAdd(&v36->m_reference_count, 1u);
          }
          vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
            (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v51,
            (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v29
          + 8);
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v51);
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v56);
        }
        if ( !*((_DWORD *)v29 + 7) && !*((_DWORD *)v29 + 8) )
        {
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(
                                       (vostok::logging::filter_tree *)"game_core",
                                       (const char *)3),
                v18 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v42,
                has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              v18,
              &v62);
            v46 |= 4u;
            vostok::logging::append(
              &v62,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\ladder_cook.cpp",
              0x75u,
              "void __thiscall survarium::ladder_cook::on_animations_loaded(class vostok::resources::queries_result &,con"
              "st class vostok::configs::binary_config_value &)",
              "game_core",
              warning,
              "landing point has no start/end animation, it's useless, hence won't be created");
          }
          if ( (v46 & 4) != 0 )
          {
            v46 &= ~4u;
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v18,
              (int *)&v62);
          }
          __debugbreak();
        }
        p_m_thread_id = &v50[1].m_parent_resources.m_thread_id;
        *(_DWORD *)v29 = 0;
        ++*p_m_thread_id;
        if ( *((_DWORD *)p_m_thread_id + 2) )
        {
          v18 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)*((_DWORD *)p_m_thread_id + 3);
          v18->vtable = (boost::detail::function::vtable_base *)v29;
        }
        else
        {
          *((_DWORD *)p_m_thread_id + 2) = v29;
        }
        *((_DWORD *)p_m_thread_id + 3) = v29;
        v47.m_object = (vostok::resources::managed_resource *)((char *)v47.m_object + 24);
        if ( v47.m_object == v53 )
          break;
        v19 = v47.m_object;
      }
    }
    v42 = 376;
    v41 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v40.m_object = (survarium::pure_game_effect_emitter_base *)v18;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v40,
      v50);
    m_parent_query = v55;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v39,
      v55,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v40.m_object,
      (const vostok::resources::memory_type *)v41,
      v42);
    v42 = result_fail;
    v41 = assert_on_fail_true;
    v40.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    v42 = result_out_of_memory|0x8;
    v41 = assert_on_fail_true;
    v40.m_object = (survarium::pure_game_effect_emitter_base *)1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
    (vostok::resources::cook_base::result_enum)v40.m_object,
    v41,
    v42);
}
