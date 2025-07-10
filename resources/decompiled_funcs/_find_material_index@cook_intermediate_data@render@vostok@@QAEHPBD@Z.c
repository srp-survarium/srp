unsigned int __userpurge vostok::render::cook_intermediate_data::find_material_index@<eax>(
        vostok::render::cook_intermediate_data *this@<ecx>,
        int a2@<eax>,
        const char *surface_name)
{
  unsigned int v4; // edi
  const char **v5; // ebp
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  char v9; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v4 = 0;
  v9 = 0;
  if ( (*(_DWORD *)(a2 + 304) - *(_DWORD *)(a2 + 300)) >> 2 )
  {
    v5 = *(const char ***)(a2 + 300);
    while ( strcmp(*v5, surface_name) )
    {
      ++v4;
      ++v5;
      if ( v4 >= (*(_DWORD *)(a2 + 304) - *(_DWORD *)(a2 + 300)) >> 2 )
        goto LABEL_5;
    }
    return v4;
  }
  else
  {
LABEL_5:
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", warning) )
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
      v9 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_model_cooker.cpp",
        0xCBu,
        "int __thiscall vostok::render::cook_intermediate_data::find_material_index(const char *)",
        "render_pc_dx11:",
        warning,
        "material not found %s",
        surface_name);
    }
    if ( (v9 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(&log_callback.functor, &log_callback.functor, 2);
    }
    return -1;
  }
}
