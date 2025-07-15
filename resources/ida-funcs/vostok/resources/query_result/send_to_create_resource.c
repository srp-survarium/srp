void __usercall vostok::resources::query_result::send_to_create_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::vfs::base_node<1> *v3; // eax
  vostok::resources::cook_base *cook; // eax
  vostok::resources::managed_resource *m_object; // eax
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  vostok::resources::query_result *v7; // ebp
  volatile int m_flags; // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v10; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v11; // [esp+10h] [ebp-23Ch] BYREF
  int v12; // [esp+14h] [ebp-238h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-234h] BYREF
  const char *v14[132]; // [esp+3Ch] [ebp-210h] BYREF

  v12 = 0;
  if ( *(_DWORD *)(a2 + 164) )
  {
    v3 = vostok::vfs::vfs_iterator::data_node((vostok::vfs::vfs_iterator *)(a2 + 160));
    if ( vostok::vfs::base_node<1>::is_inlined(v3) )
      vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160));
  }
  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( !cook || (cook->m_flags.m_flags & 8) != 0 )
  {
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 632));
    m_object = v11.m_object;
    v11.m_object = *(vostok::resources::managed_resource **)(a2 + 216);
    *(_DWORD *)(a2 + 216) = m_object;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v11);
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
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
      v7 = *(vostok::resources::query_result **)(a2 + 216);
      m_flags = v7->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
      v12 = 1;
      if ( (m_flags & 2) != 0 && v7 )
        vostok::resources::logging_name_for_query(v7, (int)v14);
      else
        v7->log_string(v7, (vostok::fixed_string<512> *)v14);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_query_result_cook.cpp",
        0x22u,
        "void __thiscall vostok::resources::query_result::send_to_create_resource(void)",
        "resources:",
        info,
        "created %s",
        v14[0]);
    }
    if ( (v12 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v9 )
        v9(&log_callback.functor, &log_callback.functor, 2);
    }
    v10 = *(_DWORD *)(a2 + 216);
    *(_DWORD *)(a2 + 256) = 0;
    *(_DWORD *)(a2 + 260) = 3;
    *(_DWORD *)(a2 + 696) = *(_DWORD *)(v10 + 92);
    vostok::resources::query_result::on_create_resource_end((vostok::resources::query_result *)a2);
  }
  else
  {
    vostok::resources::resources_manager::add_resource_to_create(
      vostok::resources::g_resources_manager.m_variable,
      (vostok::resources::query_result *)a2);
  }
}
