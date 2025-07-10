void __usercall vostok::render::query_materials_and_wait(
        const vostok::render::vector<vostok::fs_new::virtual_path_string> *in_material_names@<eax>)
{
  vostok::fs_new::virtual_path_string *M_start; // edx
  unsigned int v2; // edx
  int v3; // ebx
  const vostok::resources::request *v4; // esi
  vostok::variant<32> *v5; // eax
  int v6; // edi
  vostok::variant<32> *v7; // ebx
  unsigned int *v8; // eax
  vostok::variant<32> *v9; // esi
  vostok::detail::abstract_type_helper *m_helper; // ecx
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::grass_render_model *m_object; // ecx
  const vostok::resources::request *v13; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::variant<32> *v15; // eax
  void *v16; // esi
  void *v17; // esi
  vostok::resources::resources_manager *m_initialized; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v20; // ecx
  vostok::tasks::thread_pool *v21; // ecx
  vostok::tasks::thread_pool *v22; // ecx
  const vostok::fs_new::virtual_path_string *name_it; // [esp+Ch] [ebp-4Ch]
  vostok::variant<32> **user_data_variants_ptrs; // [esp+10h] [ebp-48h]
  unsigned int vi_type; // [esp+14h] [ebp-44h]
  vostok::resources::request *requests; // [esp+18h] [ebp-40h]
  int waiting_for; // [esp+1Ch] [ebp-3Ch] BYREF
  __int64 v28; // [esp+20h] [ebp-38h]
  vostok::command_line::key_initializator predicate[4]; // [esp+28h] [ebp-30h]
  vostok::variant<32> *user_data_variants; // [esp+2Ch] [ebp-2Ch]
  unsigned int num_resuests; // [esp+30h] [ebp-28h]
  int v32; // [esp+34h] [ebp-24h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+38h] [ebp-20h] BYREF

  M_start = in_material_names->_M_impl._M_start;
  *(_DWORD *)predicate = in_material_names->_M_impl._M_finish;
  name_it = M_start;
  v2 = (int)((unsigned __int64)(1991868891LL * (*(_DWORD *)predicate - (int)M_start)) >> 32) >> 7;
  v3 = 15 * (v2 + (v2 >> 31));
  num_resuests = v3;
  v4 = (const vostok::resources::request *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                             120 * (v2 + (v2 >> 31)));
  requests = v4;
  user_data_variants = (vostok::variant<32> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                48 * v3);
  user_data_variants_ptrs = (vostok::variant<32> **)vostok::memory::doug_lea_allocator::malloc_impl(
                                                      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                      4 * v3);
  v5 = 0;
  v6 = 0;
  if ( name_it != *(const vostok::fs_new::virtual_path_string **)predicate )
  {
    v7 = user_data_variants;
    for ( vi_type = 0; ; vi_type = 0 )
    {
      while ( 1 )
      {
        v4[v6].id = material_effects_instance_class;
        v4[v6].path = name_it->m_string.m_begin;
        if ( v7 )
        {
          v7->m_helper = 0;
          v7->m_type_id = 0;
          v5 = v7;
        }
        user_data_variants_ptrs[v6] = v5;
        v8 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(
                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                               0x10u);
        if ( v8 )
        {
          *v8 = vi_type;
          v8[1] = 0;
          v32 = 0;
          v8[2] = 2;
          *((_BYTE *)v8 + 12) = 1;
          LODWORD(v28) = v8;
        }
        else
        {
          LODWORD(v28) = 0;
        }
        v9 = user_data_variants_ptrs[v6];
        m_helper = v9->m_helper;
        if ( m_helper )
        {
          m_helper->destroy(m_helper, v9->m_storage);
          v9->m_helper = 0;
        }
        v9->m_type_id = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
        if ( v9 != (vostok::variant<32> *)-8 )
          *(_DWORD *)v9->m_storage = v28;
        ++v6;
        ++v7;
        *(_DWORD *)v9->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
        v9->m_helper = (vostok::detail::abstract_type_helper *)v9;
        v4 = requests;
        if ( ++vi_type >= 0xF )
          break;
        v5 = 0;
      }
      if ( ++name_it == *(const vostok::fs_new::virtual_path_string **)predicate )
        break;
      v5 = 0;
      v7 = &user_data_variants[v6];
    }
    v3 = num_resuests;
  }
  waiting_for = 1;
  LODWORD(v28) = vostok::render::on_material_loaded;
  HIDWORD(v28) = &waiting_for;
  if ( survarium::generate_shaders_world::is_loading() )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = v28;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::resources::queries_result &,long volatile *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<long volatile *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resources(
    v4,
    v3,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    (const vostok::variant<32> **)user_data_variants_ptrs,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v11 )
        v11(&callback.functor, &callback.functor, 2);
    }
  }
  m_object = vostok::render::g_allocator.m_object;
  if ( v4 )
  {
    v13 = v4;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)v13);
    m_object = vostok::render::g_allocator.m_object;
  }
  v15 = user_data_variants;
  if ( user_data_variants )
  {
    v16 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v16, v15);
    m_object = vostok::render::g_allocator.m_object;
  }
  if ( user_data_variants_ptrs )
  {
    v17 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v17, user_data_variants_ptrs);
  }
  while ( waiting_for )
  {
    m_initialized = (vostok::resources::resources_manager *)vostok::resources::g_resources_manager.m_initialized;
    if ( vostok::resources::g_resources_manager.m_initialized )
    {
      m_type = vostok::threading::g_debug_single_thread.m_type;
      if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
      {
        LOBYTE(num_resuests) = 0;
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        m_type = vostok::threading::g_debug_single_thread.m_type;
      }
      if ( m_type != type_recursive )
      {
        if ( m_type == type_unset )
        {
          predicate[0] = 0;
          vostok::threading::g_debug_single_thread.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          m_type = vostok::threading::g_debug_single_thread.m_type;
        }
        if ( m_type != type_recursive )
        {
          vostok::resources::resources_manager::resources_thread_tick(m_initialized);
          vostok::resources::resources_manager::cooker_thread_tick(v20);
        }
      }
      vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
    }
    if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
      vostok::tasks::thread_pool::on_current_thread_locks(v21);
    Sleep(1u);
    if ( s_thread_pool.m_initialized )
    {
      if ( TlsGetValue(s_thread_affinity_tls_key) )
        vostok::tasks::thread_pool::on_current_thread_unlocks(v22);
    }
  }
}
