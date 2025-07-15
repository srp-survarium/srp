void __usercall vostok::resources::resources_manager::free_managed_resource(
        vostok::resources::query_result *resource@<edi>,
        vostok::resources::resources_manager *this)
{
  unsigned int v2; // ebx
  const vostok::resources::memory_type *type; // ecx
  vostok::resources::vfs_sub_fat_resource *m_hashset; // ecx
  vostok::resources::query_result *m_destruction_observer; // ebp
  unsigned int size; // edx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::memory::managed_node *m_size; // ecx
  char *v10; // esi
  int v11; // eax
  void (__cdecl *v12)(_BYTE *, _BYTE *, int); // eax
  vostok::resources::class_id_enum class_id; // [esp+10h] [ebp-474h]
  vostok::resources::unmanaged_resource *sub_fat_holder; // [esp+14h] [ebp-470h]
  vostok::resources::memory_usage_type memory_usage; // [esp+18h] [ebp-46Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-464h] BYREF
  _DWORD v17[2]; // [esp+40h] [ebp-444h] BYREF
  _BYTE v18[24]; // [esp+48h] [ebp-43Ch] BYREF
  vostok::fixed_string<512> request_name; // [esp+60h] [ebp-424h] BYREF
  char v20; // [esp+26Ch] [ebp-218h] BYREF
  const char *v21[132]; // [esp+274h] [ebp-210h] BYREF

  v2 = 0;
  class_id = resource->m_class_id;
  request_name.m_begin = request_name.m_buffer;
  type = resource->m_memory_usage_self.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::type;
  request_name.m_max_end = &v20;
  memory_usage.type = type;
  m_hashset = (vostok::resources::vfs_sub_fat_resource *)resource->m_result_iterator.m_hashset;
  m_destruction_observer = resource->m_destruction_observer;
  request_name.m_end = request_name.m_buffer;
  size = resource->m_memory_usage_self.size;
  request_name.m_buffer[0] = 0;
  memory_usage.size = size;
  sub_fat_holder = 0;
  if ( m_hashset )
  {
    sub_fat_holder = m_hashset;
    m_hashset = (vostok::resources::vfs_sub_fat_resource *)((char *)m_hashset + 208);
    _InterlockedExchangeAdd((volatile signed __int32 *)m_hashset, 1u);
  }
  vostok::resources::child_resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>::set_zero(
    (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)m_hashset,
    (vostok::resources::unmanaged_resource **)&resource->m_result_iterator);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
  {
    v7 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v7 )
    {
      log_callback.functor.obj_ptr = v7;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v2 = 1;
    if ( (resource->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
        & 2) != 0 )
      vostok::resources::logging_name_for_query(resource, (int)v21);
    else
      resource->log_string(resource, (vostok::fixed_string<512> *)v21);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\resources_manager_allocation.cpp",
      0x1A7u,
      "void __thiscall vostok::resources::resources_manager::free_managed_resource(class vostok::resources::managed_resource *)",
      "resources:",
      info,
      "deleted %s",
      v21[0]);
  }
  if ( (v2 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  m_size = (vostok::memory::managed_node *)resource->m_creation_data_from_user.m_size;
  resource->m_creation_data_from_user.m_size = 0;
  vostok::memory::managed_allocator::deallocate((vostok::memory::managed_allocator *)m_size, v2);
  v10 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::query_result *, _DWORD))resource->~vostok::resources::query_result_for_cook)(
    resource,
    0);
  if ( v10 )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
    vostok_mspace_free((malloc_state *)vostok::memory::g_resources_helper_allocator.m_arena, v10);
  }
  if ( m_destruction_observer )
    _InterlockedExchangeAdd(&m_destruction_observer->m_observed_resource_destructions_left, 0xFFFFFFFF);
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&s_resource_freed_callback,
    (int)v17);
  v11 = v17[0];
  if ( (v17[0] != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
  {
    boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::operator()(
      (boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *)&memory_usage,
      v17,
      m_destruction_observer,
      &memory_usage,
      class_id);
    v11 = v17[0];
  }
  if ( v11 )
  {
    if ( (v11 & 1) == 0 )
    {
      v12 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v11 & 0xFFFFFFFE);
      if ( v12 )
        v12(v18, v18, 2);
    }
  }
  if ( sub_fat_holder )
  {
    if ( !_InterlockedExchangeAdd(&sub_fat_holder->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &sub_fat_holder->vostok::resources::unmanaged_intrusive_base,
        sub_fat_holder);
  }
}
