void __thiscall vostok::resources::query_result::end_query_might_destroy_this_impl(
        vostok::resources::query_result *this,
        vostok::resources::query_result *thisa)
{
  vostok::resources::query_result *m_parent; // ecx
  unsigned int m_uid; // eax
  unsigned __int8 m_out_of_memory_retries_count; // al
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::fixed_string<512> *(__thiscall *log_string)(struct vostok::resources::query_result_for_cook *, vostok::fixed_string<512> *); // edx
  const char **v8; // eax
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::fixed_string<512> *(__thiscall *v10)(struct vostok::resources::query_result_for_cook *, vostok::fixed_string<512> *); // edx
  const char **v11; // eax
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  vostok::resources::query_result *m_object; // esi
  void (__cdecl *v15)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  volatile int m_flags; // eax
  vostok::resources::resources_manager *m_variable; // edi
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *p_m_name_registry; // esi
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *v19; // ecx
  vostok::vfs::vfs_iterator v20[2]; // [esp-10h] [ebp-6C0h] BYREF
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-6A0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v22; // [esp+18h] [ebp-698h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-678h] BYREF
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator it; // [esp+5Ch] [ebp-654h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v25; // [esp+68h] [ebp-648h] BYREF
  const char *v26[131]; // [esp+8Ch] [ebp-624h] BYREF
  vostok::fixed_string<512> v27; // [esp+298h] [ebp-418h] BYREF
  vostok::fixed_string<512> v28; // [esp+4A4h] [ebp-20Ch] BYREF

  raii.m_lock = 0;
  if ( thisa->m_out_of_memory_type || thisa->m_out_of_memory_sub_queries )
  {
    m_parent = (vostok::resources::query_result *)thisa->m_parent;
    m_uid = m_parent->m_uid;
    if ( m_uid )
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)(m_uid + 316), 1u);
    }
    else
    {
      m_out_of_memory_retries_count = thisa->m_out_of_memory_retries_count;
      if ( m_out_of_memory_retries_count < 5u )
      {
        thisa->m_out_of_memory_retries_count = m_out_of_memory_retries_count + 1;
        vostok::resources::query_result::requery_on_out_of_memory(m_parent, thisa);
        return;
      }
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "grm:", info) )
      {
        v6 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v6 )
        {
          log_callback.functor.obj_ptr = v6;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        log_string = thisa->log_string;
        raii.m_lock = (const vostok::threading::mutex *)1;
        v8 = (const char **)log_string(thisa, &v27);
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resources_query_result_finalization.cpp",
          0x5Fu,
          "void __thiscall vostok::resources::query_result::end_query_might_destroy_this_impl(void)",
          "grm:",
          info,
          "failed out of memory query: '%s'",
          *v8);
      }
      if ( ((int)raii.m_lock & 1) != 0 )
      {
        raii.m_lock = (const vostok::threading::mutex *)((int)raii.m_lock & ~1u);
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v5,
          (int *)&log_callback);
      }
    }
  }
  if ( thisa->m_out_of_memory_retries_count )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "grm:", info) )
    {
      v9 = vostok::core::g_log_callback;
      v22.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &v22.functor,
          &v22.functor,
          destroy_functor_tag);
      if ( v9 )
      {
        v22.functor.obj_ptr = v9;
        v22.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                            + 1);
      }
      else
      {
        v22.vtable = 0;
      }
      v10 = thisa->log_string;
      raii.m_lock = (const vostok::threading::mutex *)((int)raii.m_lock | 2);
      v11 = (const char **)v10(thisa, &v28);
      vostok::logging::append(
        &v22,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_query_result_finalization.cpp",
        0x64u,
        "void __thiscall vostok::resources::query_result::end_query_might_destroy_this_impl(void)",
        "grm:",
        info,
        "successfully requeried out of memory query: '%s'",
        *v11);
    }
    if ( ((int)raii.m_lock & 2) != 0 )
    {
      raii.m_lock = (const vostok::threading::mutex *)((int)raii.m_lock & ~2u);
      if ( v22.vtable )
      {
        if ( ((int)v22.vtable & 1) == 0 )
        {
          v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v22.vtable & 0xFFFFFFFE);
          if ( v12 )
            v12(&v22.functor, &v22.functor, 2);
        }
      }
    }
  }
  if ( thisa->m_error_type == error_type_unset
    && thisa->m_create_resource_result != result_error
    && (((unsigned int)&loc_3FFFF + 1) & thisa->m_flags) != 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
    {
      if ( !thisa->m_managed_resource.m_object
        || (m_object = (vostok::resources::query_result *)thisa->m_managed_resource.m_object,
            !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
      {
        m_object = (vostok::resources::query_result *)thisa->m_unmanaged_resource.m_object;
      }
      v15 = vostok::core::g_log_callback;
      v25.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &v25.functor,
          &v25.functor,
          destroy_functor_tag);
      if ( v15 )
      {
        v25.functor.obj_ptr = v15;
        v25.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                            + 1);
      }
      else
      {
        v25.vtable = 0;
      }
      m_flags = m_object->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
      raii.m_lock = (const vostok::threading::mutex *)((int)raii.m_lock | 4);
      if ( (m_flags & 2) != 0 && m_object )
        vostok::resources::logging_name_for_query(m_object, (int)v26);
      else
        m_object->log_string(m_object, (vostok::fixed_string<512> *)v26);
      vostok::logging::append(
        &v25,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_query_result_finalization.cpp",
        0x6Bu,
        "void __thiscall vostok::resources::query_result::end_query_might_destroy_this_impl(void)",
        "resources:",
        info,
        "reused resource: %s",
        v26[0]);
    }
    if ( ((int)raii.m_lock & 4) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v13,
        (int *)&v25);
  }
  if ( (thisa->m_flags & 2) != 0 )
    _InterlockedExchangeAdd(&vostok::resources::g_resources_manager.m_variable->m_uncooked_queries_count, 0xFFFFFFFF);
  vostok::threading::interlocked_and(&thisa->m_flags, 0xFFFDFFFF);
  if ( thisa->m_fat_it.m_node )
  {
    vostok::vfs::vfs_iterator::vfs_iterator(v20, &thisa->m_fat_it);
    if ( vostok::resources::get_associated_query_result(v20[0]) )
    {
      vostok::vfs::vfs_iterator::vfs_iterator(v20, &thisa->m_fat_it);
      vostok::resources::set_associated(0, v20[0]);
    }
  }
  if ( thisa->m_fat_it.m_node )
  {
    vostok::threading::interlocked_and(&thisa->m_flags, 0xFFFFFFEF);
    vostok::threading::interlocked_exchange_add(
      (int *)((char *)&dword_201B8 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      0xFFFFFFFF);
  }
  if ( (thisa->m_flags & 0x20) != 0 )
  {
    m_variable = vostok::resources::g_resources_manager.m_variable;
    vostok::threading::interlocked_and(&thisa->m_flags, 0xFFFFFFDF);
    vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::erase(
      (vostok::intrusive_double_linked_list<vostok::resources::query_result,vostok::resources::query_result *,616,612,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)((char *)m_variable + (_DWORD)&loc_201D7 + 1),
      thisa);
  }
  vostok::threading::interlocked_or(&thisa->m_flags, 0x200u);
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[5574200] & thisa->m_flags) != 0 )
  {
    p_m_name_registry = &vostok::resources::g_resources_manager.m_variable->m_name_registry;
    raii.m_lock = (const vostok::threading::mutex *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable];
    vostok::threading::mutex::lock((vostok::threading::mutex *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable]);
    vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::find(
      v19,
      (int)&it,
      p_m_name_registry,
      &thisa->m_name_registry_entry);
    vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::erase(
      p_m_name_registry,
      it.m_index,
      it.m_value);
    vostok::threading::interlocked_and(&thisa->m_flags, 0xFEFFFFFF);
    LeaveCriticalSection((LPCRITICAL_SECTION)raii.m_lock);
  }
  if ( thisa->m_parent )
    vostok::resources::queries_result::on_child_query_end(thisa->m_parent, thisa);
}
