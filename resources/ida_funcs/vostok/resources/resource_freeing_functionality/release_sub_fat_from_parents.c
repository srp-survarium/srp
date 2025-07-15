void __userpurge vostok::resources::resource_freeing_functionality::release_sub_fat_from_parents(
        vostok::resources::vfs_sub_fat_resource *sub_fat@<eax>,
        vostok::threading::simple_lock *a2@<ecx>,
        vostok::resources::resource_freeing_functionality *this)
{
  int v3; // ebx
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // esi
  vostok::threading::simple_lock *v5; // edi
  const vostok::resources::resource_link *m_first; // eax
  const vostok::resources::resource_link *v7; // ebp
  vostok::resources::resource_base *resource; // esi
  vostok::resources::resource_base *v9; // ecx
  void (__cdecl *v10)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  const char **v11; // eax
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const vostok::resources::resource_link *i; // eax
  vostok::threading::simple_lock *v15; // [esp+14h] [ebp-234h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-230h] BYREF
  vostok::fixed_string<512> v17; // [esp+3Ch] [ebp-20Ch] BYREF

  v3 = 0;
  p_m_parent_resources = &sub_fat->m_parent_resources;
  if ( sub_fat == (vostok::resources::vfs_sub_fat_resource *)-60 )
  {
    v15 = 0;
    v5 = 0;
  }
  else
  {
    v5 = &sub_fat->m_parent_resources.vostok::threading::simple_lock;
    v15 = &sub_fat->m_parent_resources.vostok::threading::simple_lock;
  }
  vostok::threading::simple_lock::lock(a2, v5);
  m_first = p_m_parent_resources->m_first;
  if ( m_first && (m_first->resource->m_flags.m_flags & 0x800) != 0 )
    m_first = vostok::resources::resource_link_list_next_no_dying(m_first);
  v7 = m_first;
  if ( m_first )
  {
    do
    {
      if ( !vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(this, v7->resource) )
      {
        resource = v7->resource;
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", warning) )
        {
          v10 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v10 )
          {
            log_callback.functor.obj_ptr = v10;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          v3 |= 1u;
          v11 = (const char **)resource->log_string(resource, &v17);
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_resman_free.cpp",
            0x9Eu,
            "void __thiscall vostok::resources::resource_freeing_functionality::release_sub_fat_from_parents(class vostok"
            "::resources::vfs_sub_fat_resource *)",
            "resources:",
            warning,
            "LEAK: %s or one of its parents is held by userwhen its sub-fat being unmounted, leak?",
            *v11);
          v5 = v15;
        }
        if ( (v3 & 1) != 0 )
        {
          v3 &= ~1u;
          if ( log_callback.vtable )
          {
            if ( ((int)log_callback.vtable & 1) == 0 )
            {
              v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
              if ( v12 )
                v12(&log_callback.functor, &log_callback.functor, 2);
            }
          }
        }
        vostok::resources::resource_base::clean_sub_fat_and_fat_it(v9, (int)resource);
      }
      for ( i = v7->next_link; i; i = i->next_link )
      {
        if ( (i->resource->m_flags.m_flags & 0x800) == 0 )
          break;
      }
      v7 = i;
    }
    while ( i );
  }
  if ( v5->m_lock-- == 1 )
    _InterlockedExchange(&v5->m_thread_id, 0);
}
