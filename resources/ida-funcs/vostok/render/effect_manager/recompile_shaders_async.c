void __thiscall vostok::render::effect_manager::recompile_shaders_async(
        vostok::render::effect_manager *this,
        vostok::render::effect_manager *in_changed_defines,
        const vostok::render::vector<vostok::fs_new::virtual_path_string> *in_changed_definesa)
{
  vostok::fs_new::virtual_path_string *M_start; // edi
  vostok::fs_new::virtual_path_string *M_finish; // eax
  vostok::render::effect_manager::effect_to_recompile_struct *v5; // ecx
  vostok::render::effect_manager::effect_to_recompile_struct *v6; // esi
  volatile signed __int32 *m_end; // eax
  char *m_max_end; // eax
  vostok::render::effect_descriptor *m_begin; // edx
  const vostok::render::effect_manager::effect_to_recompile_struct *v10; // eax
  vostok::render::effect_manager::effect_to_recompile_struct *v11; // ecx
  char *m_object; // esi
  vostok::render::custom_config *v13; // ebx
  vostok::render::grass_render_model *v14; // ecx
  unsigned int v15; // edi
  void *v16; // esp
  const vostok::variant<32> **v17; // ebx
  void *v18; // esp
  void *v19; // esp
  const stlp_std::__false_type **v20; // edi
  const stlp_std::__false_type **v21; // esi
  int *v22; // ebx
  volatile signed __int32 **v23; // eax
  volatile signed __int32 *v24; // esi
  int v25; // ecx
  vostok::render::grass_render_model *v26; // ecx
  const stlp_std::__false_type *v27; // ecx
  _DWORD *v28; // ecx
  const stlp_std::__false_type **v29; // eax
  const stlp_std::__false_type *v30; // ecx
  const stlp_std::__false_type *v31; // eax
  __int64 v32; // xmm0_8
  vostok::resources::resources_manager *m_initialized; // ecx
  void (__cdecl *v34)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::tasks::thread_pool *v35; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> v36; // [esp-8h] [ebp-88h]
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> v37; // [esp-4h] [ebp-84h]
  const stlp_std::__false_type *v38[2]; // [esp+0h] [ebp-80h] BYREF
  bool v39; // [esp+8h] [ebp-78h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-70h] BYREF
  vostok::render::effect_manager::effect_to_recompile_struct v41; // [esp+34h] [ebp-4Ch] BYREF
  vostok::vectora<vostok::render::effect_manager::effect_to_recompile_struct> effects_to_recompile; // [esp+44h] [ebp-3Ch] BYREF
  __int64 v43; // [esp+54h] [ebp-2Ch]
  vostok::vectora<vostok::render::effect_manager::effect_to_recompile_struct> *p_effects_to_recompile; // [esp+5Ch] [ebp-24h]
  vostok::mutable_buffer v45; // [esp+60h] [ebp-20h] BYREF
  const vostok::resources::creation_request *requests; // [esp+68h] [ebp-18h]
  unsigned int v47; // [esp+6Ch] [ebp-14h]
  const stlp_std::__false_type **v48; // [esp+70h] [ebp-10h]
  const stlp_std::__false_type **v49; // [esp+74h] [ebp-Ch]
  volatile signed __int32 **p_config; // [esp+78h] [ebp-8h]
  const stlp_std::__false_type **v51; // [esp+7Ch] [ebp-4h]
  const vostok::render::vector<vostok::fs_new::virtual_path_string> *in_changed_definesb; // [esp+8Ch] [ebp+Ch]

  M_start = (vostok::fs_new::virtual_path_string *)in_changed_defines->m_effects._M_impl._M_start;
  M_finish = (vostok::fs_new::virtual_path_string *)in_changed_defines->m_effects._M_impl._M_finish;
  v5 = 0;
  v6 = 0;
  effects_to_recompile._M_impl._M_start = 0;
  effects_to_recompile._M_impl._M_finish = 0;
  effects_to_recompile._M_impl._M_end_of_storage.m_allocator = &vostok::memory::g_mt_allocator;
  effects_to_recompile._M_impl._M_end_of_storage._M_data = 0;
  if ( M_start != M_finish )
  {
    do
    {
      if ( (*(unsigned __int8 (__thiscall **)(char *, const vostok::render::vector<vostok::fs_new::virtual_path_string> *))(*(_DWORD *)M_start->m_string.m_begin + 4))(
             M_start->m_string.m_begin,
             in_changed_definesa) )
      {
        v37.m_object = 0;
        m_end = (volatile signed __int32 *)M_start->m_string.m_end;
        if ( m_end )
        {
          v37.m_object = (vostok::render::custom_config *)M_start->m_string.m_end;
          _InterlockedExchangeAdd(m_end, 1u);
        }
        m_max_end = M_start->m_string.m_max_end;
        m_begin = (vostok::render::effect_descriptor *)M_start->m_string.m_begin;
        v36.m_object = 0;
        if ( m_max_end )
        {
          v36.m_object = (vostok::render::res_effect *)M_start->m_string.m_max_end;
          _InterlockedExchangeAdd((volatile signed __int32 *)m_max_end + 52, 1u);
        }
        vostok::render::effect_manager::effect_to_recompile_struct::effect_to_recompile_struct(
          &v41,
          m_begin,
          v36,
          v37,
          (unsigned int)v38[0]);
        v11 = effects_to_recompile._M_impl._M_finish;
        if ( effects_to_recompile._M_impl._M_finish == effects_to_recompile._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_to_recompile_struct,vostok::vectora_allocator<vostok::render::effect_manager::effect_to_recompile_struct>>::_M_insert_overflow_aux(
            (stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_to_recompile_struct,vostok::vectora_allocator<vostok::render::effect_manager::effect_to_recompile_struct> > *)effects_to_recompile._M_impl._M_finish,
            (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_to_recompile_struct *> *)&effects_to_recompile,
            effects_to_recompile._M_impl._M_finish,
            v10,
            v38[0],
            (unsigned int)v38[1],
            v39);
        }
        else
        {
          if ( effects_to_recompile._M_impl._M_finish )
          {
            vostok::render::effect_manager::effect_to_recompile_struct::effect_to_recompile_struct(
              effects_to_recompile._M_impl._M_finish,
              v10);
            v11 = effects_to_recompile._M_impl._M_finish;
          }
          effects_to_recompile._M_impl._M_finish = v11 + 1;
        }
        if ( v41.config.m_object && !_InterlockedExchangeAdd(&v41.config.m_object->m_reference_count, 0xFFFFFFFF) )
        {
          m_object = (char *)v41.config.m_object;
          v13 = v41.config.m_object;
          if ( v41.config.m_object->call_destructors )
            vostok::render::custom_config_value::call_data_destructor(&v41.config.m_object->m_root);
          if ( v13->own_buffer )
          {
            v14 = vostok::render::g_allocator.m_object;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free((malloc_state *)HIDWORD(v14->m_reconstruction_info_actuality_tick), m_object);
          }
        }
        if ( v41.effect.m_object && !_InterlockedExchangeAdd(&v41.effect.m_object->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &v41.effect.m_object->vostok::resources::unmanaged_intrusive_base,
            v41.effect.m_object);
      }
      M_start = (vostok::fs_new::virtual_path_string *)((char *)M_start + 12);
    }
    while ( M_start != (vostok::fs_new::virtual_path_string *)in_changed_defines->m_effects._M_impl._M_finish );
    v6 = effects_to_recompile._M_impl._M_start;
    v5 = effects_to_recompile._M_impl._M_finish;
  }
  v15 = v5 - v6;
  v47 = v15;
  if ( v15 )
  {
    v16 = alloca(4 * v15);
    v17 = (const vostok::variant<32> **)v38;
    v48 = v38;
    v18 = alloca(48 * v15);
    in_changed_definesb = (const vostok::render::vector<vostok::fs_new::virtual_path_string> *)v38;
    v19 = alloca(16 * v15);
    requests = (const vostok::resources::creation_request *)v38;
    if ( v6 != effects_to_recompile._M_impl._M_finish )
    {
      v20 = v38;
      p_config = (volatile signed __int32 **)&v6->config;
      v21 = v38;
      v49 = v38;
      v51 = v38;
      while ( 1 )
      {
        if ( v20 )
        {
          v20[10] = 0;
          v20[11] = 0;
        }
        else
        {
          v20 = 0;
        }
        v22 = vostok::memory::doug_lea_allocator::malloc_impl(
                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                0x10u);
        if ( v22 )
        {
          v23 = p_config;
          v24 = 0;
          if ( *p_config )
          {
            v24 = *p_config;
            _InterlockedExchangeAdd(*p_config, 1u);
          }
          v25 = (int)v23[1];
          *v22 = (int)*(v23 - 1);
          v22[1] = 0;
          if ( v24 )
          {
            v22[1] = (int)v24;
            _InterlockedExchangeAdd(v24, 1u);
          }
          v22[2] = v25;
          *((_BYTE *)v22 + 12) = 0;
          if ( v24 && !_InterlockedExchangeAdd(v24, 0xFFFFFFFF) )
          {
            if ( *((_BYTE *)v24 + 9) )
              vostok::render::custom_config_value::call_data_destructor((vostok::render::custom_config_value *)(v24 + 3));
            if ( *((_BYTE *)v24 + 8) )
            {
              v26 = vostok::render::g_allocator.m_object;
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free((malloc_state *)HIDWORD(v26->m_reconstruction_info_actuality_tick), (char *)v24);
            }
          }
          v21 = v49;
        }
        else
        {
          v22 = 0;
        }
        v27 = v20[10];
        if ( v27 )
        {
          (*(void (__thiscall **)(const stlp_std::__false_type *, const stlp_std::__false_type **))(*(_DWORD *)v27 + 4))(
            v27,
            v20 + 2);
          v20[10] = 0;
        }
        v20[11] = (const stlp_std::__false_type *)vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get();
        if ( v20 != (const stlp_std::__false_type **)-8 )
          v20[2] = (const stlp_std::__false_type *)v22;
        v28 = v51;
        *v20 = (const stlp_std::__false_type *)&vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *>::`vftable';
        v20[10] = (const stlp_std::__false_type *)v20;
        *v28 = v20;
        if ( v21 )
        {
          boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
            &v45,
            (unsigned __int8 *)&buf,
            1u);
          v30 = *v29;
          v31 = v29[1];
          *v21 = (const stlp_std::__false_type *)&buf;
          v21[1] = v30;
          v21[2] = v31;
          v21[3] = (const stlp_std::__false_type *)13;
        }
        in_changed_definesb += 4;
        ++v51;
        p_config += 4;
        v21 += 4;
        v49 = v21;
        if ( p_config - 2 == (volatile signed __int32 **)effects_to_recompile._M_impl._M_finish )
          break;
        v20 = (const stlp_std::__false_type **)in_changed_definesb;
      }
      v17 = (const vostok::variant<32> **)v48;
      v15 = v47;
    }
    LODWORD(v43) = vostok::render::effect_manager::on_effects_recompiled;
    HIDWORD(v43) = in_changed_defines;
    v32 = v43;
    in_changed_defines->m_is_effects_query_processing = 1;
    v43 = v32;
    p_effects_to_recompile = &effects_to_recompile;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      callback.vtable = 0;
    }
    else
    {
      *(_QWORD *)&callback.functor.obj_ptr = v43;
      callback.functor.vostok_pointer_size_alignment[2] = p_effects_to_recompile;
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::effect_manager,vostok::vectora<vostok::render::effect_manager::effect_to_recompile_struct> *,vostok::resources::queries_result &>,boost::_bi::list3<boost::_bi::value<vostok::render::effect_manager *>,boost::_bi::value<vostok::vectora<vostok::render::effect_manager::effect_to_recompile_struct> *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    vostok::resources::query_create_resources(
      requests,
      v15,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      v17,
      0,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v34 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v34 )
          v34(&callback.functor, &callback.functor, 2);
      }
    }
    while ( in_changed_defines->m_is_effects_query_processing )
    {
      vostok::resources::dispatch_callbacks(m_initialized);
      if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_locks(v35, s_thread_pool.m_variable);
      Sleep(1u);
      m_initialized = (vostok::resources::resources_manager *)s_thread_pool.m_initialized;
      if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_unlocks(
          (vostok::tasks::thread_pool *)m_initialized,
          s_thread_pool.m_variable);
    }
    stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::effect_manager::effect_to_recompile_struct *>,vostok::render::effect_manager::effect_to_recompile_struct>(
      (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_to_recompile_struct *>)effects_to_recompile._M_impl._M_finish,
      (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_to_recompile_struct *>)effects_to_recompile._M_impl._M_start);
  }
  else
  {
    stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::effect_manager::effect_to_recompile_struct *>,vostok::render::effect_manager::effect_to_recompile_struct>(
      (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_to_recompile_struct *>)v5,
      (stlp_std::reverse_iterator<vostok::render::effect_manager::effect_to_recompile_struct *>)v6);
  }
  if ( effects_to_recompile._M_impl._M_start )
    effects_to_recompile._M_impl._M_end_of_storage.m_allocator->call_free(
      effects_to_recompile._M_impl._M_end_of_storage.m_allocator,
      effects_to_recompile._M_impl._M_start);
}
