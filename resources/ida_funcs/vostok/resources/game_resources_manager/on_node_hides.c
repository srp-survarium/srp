void __thiscall vostok::resources::game_resources_manager::on_node_hides(
        vostok::resources::game_resources_manager *this,
        vostok::vfs::vfs_iterator *it)
{
  vostok::resources::resource_flags *v3; // ecx
  vostok::resources::resource_base *m_object; // edi
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  char v6; // bl
  char *name; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_resource *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  vostok::vfs::vfs_iterator v11[2]; // [esp-10h] [ebp-50h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> managed_resource; // [esp+10h] [ebp-30h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> unmanaged_resource; // [esp+14h] [ebp-2Ch] BYREF
  vostok::resources::releasing_functionality v14; // [esp+18h] [ebp-28h] BYREF
  int v15; // [esp+1Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-20h] BYREF

  v15 = 0;
  vostok::vfs::vfs_iterator::vfs_iterator(v11, it);
  vostok::resources::get_associated_unmanaged_resource_ptr(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&unmanaged_resource,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v11[0].m_hashset);
  vostok::vfs::vfs_iterator::vfs_iterator(v11, it);
  vostok::resources::get_associated_managed_resource_ptr(
    &managed_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v11[0].m_hashset);
  m_object = managed_resource.m_object;
  if ( !managed_resource.m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_object = unmanaged_resource.m_object;
  }
  if ( m_object )
  {
    if ( vostok::resources::resource_flags::is_pinned_by_grm(v3, m_object) )
    {
      v14.m_data = &this->m_data;
      vostok::resources::releasing_functionality::release_resource(&v14, m_object);
    }
    vostok::vfs::vfs_iterator::vfs_iterator(v11, it);
    vostok::resources::set_associated(0, v11[0]);
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "fs:", info) )
    {
      v6 = v15;
    }
    else
    {
      v5 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v5 )
      {
        log_callback.functor.obj_ptr = v5;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v6 = 1;
      name = vostok::vfs::vfs_iterator::get_name(it);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_resman.cpp",
        0x71u,
        "void __thiscall vostok::resources::game_resources_manager::on_node_hides(class vostok::vfs::vfs_iterator &)",
        "fs:",
        info,
        "deassociated resource from node: '%s'",
        name);
    }
    if ( (v6 & 1) != 0 )
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
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&managed_resource);
  v9 = unmanaged_resource.m_object;
  if ( unmanaged_resource.m_object )
  {
    v10 = &unmanaged_resource.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&unmanaged_resource.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v10, v9);
  }
}
