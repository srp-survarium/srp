unsigned int __userpurge vostok::render::cook_intermediate_data::find_material_index@<eax>(
        vostok::render::cook_intermediate_data *this@<ecx>,
        int a2@<eax>,
        char *surface_name)
{
  unsigned int v4; // ebx
  int v5; // eax
  const char **v6; // edi
  bool has_passed_filters; // al
  vostok::render::cook_intermediate_data *v9; // [esp-4h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+10h] [ebp-2Ch] BYREF
  int v11; // [esp+34h] [ebp-8h]

  v4 = 0;
  v5 = (*(_DWORD *)(a2 + 304) - *(_DWORD *)(a2 + 300)) >> 2;
  v11 = 0;
  if ( v5 )
  {
    v6 = *(const char ***)(a2 + 300);
    while ( vostok::strings::compare(*v6, surface_name) )
    {
      ++v4;
      ++v6;
      if ( v4 >= (*(_DWORD *)(a2 + 304) - *(_DWORD *)(a2 + 300)) >> 2 )
        goto LABEL_5;
    }
    return v4;
  }
  else
  {
LABEL_5:
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)3),
          this = v9,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v10);
      v11 = 1;
      vostok::logging::append(
        &v10,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_model_cooker.cpp",
        0xCAu,
        "int __thiscall vostok::render::cook_intermediate_data::find_material_index(const char *)",
        "render_pc_dx11",
        warning,
        "material not found %s",
        surface_name);
    }
    if ( (v11 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v10);
    return -1;
  }
}
