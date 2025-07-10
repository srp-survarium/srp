void __thiscall vostok::resources::game_resources_manager::on_node_unmount(
        vostok::resources::game_resources_manager *this,
        vostok::vfs::vfs_iterator *it)
{
  char v2; // bl
  void *m_object; // edi
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  char *m_begin; // esi
  _DWORD *v6; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_resource *v8; // eax
  vostok::resources::unmanaged_intrusive_base *v9; // ecx
  vostok::vfs::vfs_iterator v10[2]; // [esp-10h] [ebp-368h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> unmanaged_resource; // [esp+10h] [ebp-348h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> managed_resource; // [esp+14h] [ebp-344h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-340h] BYREF
  vostok::fs_new::virtual_path_string result; // [esp+38h] [ebp-320h] BYREF
  _BYTE v15[524]; // [esp+14Ch] [ebp-20Ch] BYREF

  v2 = 0;
  unmanaged_resource.m_object = 0;
  vostok::vfs::vfs_iterator::vfs_iterator(v10, it);
  vostok::resources::get_associated_unmanaged_resource_ptr(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&unmanaged_resource,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v10[0].m_hashset);
  vostok::vfs::vfs_iterator::vfs_iterator(v10, it);
  vostok::resources::get_associated_managed_resource_ptr(
    &managed_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v10[0].m_hashset);
  m_object = unmanaged_resource.m_object;
  if ( !unmanaged_resource.m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_object = managed_resource.m_object;
  }
  if ( m_object )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "core:", error) )
    {
      v4 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v4 )
      {
        log_callback.functor.obj_ptr = v4;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v2 = 1;
      m_begin = vostok::vfs::vfs_iterator::get_virtual_path(it, &result)->m_string.m_begin;
      v6 = (_DWORD *)(*(int (__thiscall **)(void *, _BYTE *))(*(_DWORD *)m_object + 4))(m_object, v15);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_resman.cpp",
        0x4Fu,
        &stru_95BE78.m_string.m_buffer[220],
        "core:",
        error,
        &stru_95BE78.m_string.m_buffer[164],
        *v6,
        m_begin);
    }
    if ( (v2 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v7 )
            v7(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&managed_resource);
  v8 = unmanaged_resource.m_object;
  if ( unmanaged_resource.m_object )
  {
    v9 = &unmanaged_resource.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&unmanaged_resource.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v9, v8);
  }
}
