void __thiscall vostok::render::engine::world::set_model_visible_by_id(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v,
        unsigned int subsurface_id,
        unsigned int flags)
{
  vostok::render::render_model_instance *m_object; // eax
  char v5; // bl
  vostok::resources::unmanaged_resource *v6; // esi
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void **v9; // eax
  void *v10; // esi
  void **M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::render_model_instance *model; // [esp+18h] [ebp-30h]
  vostok::render::vector<vostok::render::render_surface_instance *> list; // [esp+1Ch] [ebp-2Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-20h] BYREF

  m_object = v->m_object;
  v5 = 0;
  v6 = 0;
  model = 0;
  if ( v->m_object )
  {
    model = v->m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    v6 = m_object;
  }
  memset(&list, 0, sizeof(list));
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD, _DWORD, vostok::render::vector<vostok::render::render_surface_instance *> *, _DWORD, int, int))v6->__vftable[2].link_child_resource)(
    v6,
    0,
    0,
    &list,
    0,
    170,
    3);
  if ( subsurface_id < list._M_impl._M_finish - list._M_impl._M_start )
  {
    *((_DWORD *)list._M_impl._M_start[subsurface_id] + 5) = flags;
    M_start = list._M_impl._M_start;
    if ( list._M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
      v6 = model;
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
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
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_engine_world_pc_dx11.cpp",
        0x5C4u,
        "void __thiscall vostok::render::engine::world::set_model_visible_by_id(const class vostok::resources::resource_p"
        "tr<class vostok::render::render_model_instance,class vostok::resources::unmanaged_intrusive_base> &,unsigned int,unsigned int)",
        "render_pc_dx11:",
        error,
        "There is no surface with id[%d]!",
        subsurface_id);
      v6 = model;
    }
    if ( (v5 & 1) != 0 )
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
    v9 = list._M_impl._M_start;
    if ( list._M_impl._M_start )
    {
      v10 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v10, v9);
      v6 = model;
    }
  }
  if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
}
