void __thiscall vostok::resources::unmanaged_resource::~unmanaged_resource(vostok::resources::unmanaged_resource *this)
{
  char v2; // bl
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v5; // ecx
  vostok::resources::resource_children *v6; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-230h] BYREF
  int v8; // [esp+30h] [ebp-210h]
  const char *v9[131]; // [esp+34h] [ebp-20Ch] BYREF

  v2 = 0;
  v8 = 0;
  this->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::resources::unmanaged_resource::`vftable';
  vostok::resources::resource_children::unlink_from_children(this);
  if ( this->m_deleter )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
    {
      v3 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v3 )
      {
        log_callback.functor.obj_ptr = v3;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v2 = 1;
      if ( (this->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
          & 2) != 0 )
        vostok::resources::logging_name_for_query((vostok::resources::query_result *)this, (int)v9);
      else
        this->log_string(this, (vostok::fixed_string<512> *)v9);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_unmanaged_resource.cpp",
        0x30u,
        "__thiscall vostok::resources::unmanaged_resource::~unmanaged_resource(void)",
        "resources:",
        info,
        "deleted %s",
        v9[0]);
    }
    if ( (v2 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v4 )
            v4(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->m_raw_resource_ptr);
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::~child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>(
    v5,
    (vostok::resources::unmanaged_intrusive_base **)&this->m_sub_fat);
  this->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::resources::resource_base::`vftable';
  vostok::resources::resource_children::unlink_from_parents(v6);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink(&this->grm_satisfaction_tree_hook.boost::intrusive::rbtree_node<void *>);
  this->grm_satisfaction_tree_hook.parent_ = 0;
  this->grm_satisfaction_tree_hook.left_ = 0;
  this->grm_satisfaction_tree_hook.right_ = 0;
  this->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::resources::resource_flags::`vftable';
  vostok::vfs::vfs_association::~vfs_association(this);
}
