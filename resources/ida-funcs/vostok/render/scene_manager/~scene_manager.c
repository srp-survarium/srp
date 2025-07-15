void __thiscall vostok::render::scene_manager::~scene_manager(
        vostok::render::scene_manager *this,
        vostok::render::scene_manager *thisa)
{
  vostok::render::scene_manager *v2; // edx
  vostok::render::scene **M_finish; // esi
  void ***M_start; // edi
  char v5; // bl
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::grass_render_model *m_object; // ecx
  vostok::render::grass_render_model *v9; // ebp
  char *v10; // esi
  char *v11; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  void ***v13; // edi
  void ***v14; // ebx
  vostok::render::grass_render_model *v15; // ebp
  char *v16; // esi
  char *v17; // eax
  malloc_state *v18; // esi
  char *v19; // eax
  malloc_state *v20; // esi
  char *v21; // eax
  malloc_state *v22; // esi
  char *v23; // eax
  malloc_state *v24; // esi
  vostok::render::scene **en_c; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v2 = thisa;
  M_finish = (vostok::render::scene **)thisa->m_scenes._M_impl._M_finish;
  M_start = (void ***)thisa->m_scenes._M_impl._M_start;
  v5 = 0;
  en_c = M_finish;
  if ( (vostok::render::scene **)thisa->m_scenes._M_impl._M_start == M_finish )
  {
    m_object = vostok::render::g_allocator.m_object;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
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
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\scene_manager.cpp",
        0x1Cu,
        "__thiscall vostok::render::scene_manager::~scene_manager(void)",
        "render_pc_dx11:",
        error,
        "Some scenes were not deleted before render engine destruction.");
    }
    if ( (v5 & 1) != 0 )
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
    m_object = vostok::render::g_allocator.m_object;
    do
    {
      v9 = m_object;
      if ( *M_start )
      {
        v10 = __RTCastToVoid(*M_start);
        (*(void (__thiscall **)(void **, _DWORD))**M_start)(*M_start, 0);
        if ( v10 )
        {
          v11 = v10;
          m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(v9->m_reconstruction_info_actuality_tick);
          BYTE2(v9->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v11);
        }
        M_finish = en_c;
        *M_start = 0;
        m_object = vostok::render::g_allocator.m_object;
      }
      ++M_start;
    }
    while ( M_start != (void ***)M_finish );
    v2 = thisa;
  }
  v13 = (void ***)v2->m_views._M_impl._M_start;
  v14 = (void ***)v2->m_views._M_impl._M_finish;
  if ( v13 != v14 )
  {
    do
    {
      v15 = m_object;
      if ( *v13 )
      {
        v16 = __RTCastToVoid(*v13);
        (*(void (__thiscall **)(void **, _DWORD))**v13)(*v13, 0);
        if ( v16 )
        {
          v17 = v16;
          v18 = (malloc_state *)HIDWORD(v15->m_reconstruction_info_actuality_tick);
          BYTE2(v15->m_children_resources.m_lock) = 0;
          vostok_mspace_free(v18, v17);
        }
        *v13 = 0;
        m_object = vostok::render::g_allocator.m_object;
      }
      ++v13;
    }
    while ( v13 != v14 );
    v2 = thisa;
  }
  v19 = (char *)v2->m_output_windows._M_impl._M_start;
  if ( v19 )
  {
    v20 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v20, v19);
    m_object = vostok::render::g_allocator.m_object;
    v2 = thisa;
  }
  v21 = (char *)v2->m_views._M_impl._M_start;
  if ( v21 )
  {
    v22 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v22, v21);
    m_object = vostok::render::g_allocator.m_object;
    v2 = thisa;
  }
  v23 = (char *)v2->m_scenes._M_impl._M_start;
  if ( v2->m_scenes._M_impl._M_start )
  {
    v24 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v24, v23);
  }
  vostok::quasi_singleton<vostok::render::scene_manager>::pinst = 0;
}
