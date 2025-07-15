void __thiscall vostok::render::resource_manager::on_texture_loaded(
        vostok::render::resource_manager *this,
        vostok::resources::queries_result *data,
        unsigned int mip_level_cut,
        bool use_converter,
        unsigned int num_last_mips_used,
        volatile int *ready_flag)
{
  char v6; // bl
  char *requested_path; // eax
  vostok::fixed_string<260> *v9; // ecx
  vostok::buffer_string *v10; // ecx
  volatile int m_result; // eax
  bool has_passed_filters; // al
  vostok::fs_new::virtual_path_string *v13; // esi
  vostok::fs_new::virtual_path_string **v14; // edi
  vostok::fs_new::virtual_path_string *v15; // eax
  int m_object; // ecx
  const char *v17; // edi
  char *m_begin; // esi
  bool v19; // cf
  bool v20; // zf
  int v21; // eax
  vostok::fs_new::virtual_path_string *texture; // eax
  vostok::resources::managed_resource *v23; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v24; // ecx
  D3DX11_IMAGE_LOAD_INFO *v25; // ecx
  HRESULT ImageInfoFromMemory; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // ecx
  bool *d3d11_error_string; // eax
  HRESULT TextureFromMemory; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // ecx
  bool *v31; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v32; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v33; // [esp-2h] [ebp-1D0h] BYREF
  char *v34; // [esp+2h] [ebp-1CCh]
  unsigned int v35; // [esp+6h] [ebp-1C8h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v36; // [esp+Ah] [ebp-1C4h] BYREF
  BOOL v37; // [esp+Eh] [ebp-1C0h]
  char v38; // [esp+1Ch] [ebp-1B2h] BYREF
  char v39; // [esp+1Dh] [ebp-1B1h] BYREF
  vostok::fs_new::virtual_path_string *where; // [esp+1Eh] [ebp-1B0h] BYREF
  vostok::resources::query_result_for_user *m_queries; // [esp+22h] [ebp-1ACh]
  vostok::render::resource_manager *v42; // [esp+26h] [ebp-1A8h]
  ID3D11Resource *surface; // [esp+2Ah] [ebp-1A4h] BYREF
  _BYTE v44[4]; // [esp+2Eh] [ebp-1A0h] BYREF
  int v45; // [esp+32h] [ebp-19Ch]
  int v46; // [esp+36h] [ebp-198h]
  _DWORD v47[9]; // [esp+3Ah] [ebp-194h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v48; // [esp+5Eh] [ebp-170h] BYREF
  D3DX11_IMAGE_LOAD_INFO v49; // [esp+82h] [ebp-14Ch] BYREF
  vostok::fs_new::virtual_path_string __val; // [esp+B6h] [ebp-118h] BYREF

  v6 = 0;
  v42 = this;
  m_queries = 0;
  if ( ready_flag )
    _InterlockedExchange(ready_flag, 1);
  m_queries = data->m_queries;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(&data->m_queries[0]);
  vostok::fixed_string<260>::fixed_string<260>(v9, &__val.m_string, requested_path);
  m_result = data->m_result;
  __val.m_separator = 47;
  if ( m_result == 1 )
  {
    vostok::render::fix_texture_name(&__val, v10);
    v13 = *(vostok::fs_new::virtual_path_string **)((char *)&loc_948F0 + (_DWORD)this);
    v14 = (vostok::fs_new::virtual_path_string **)((char *)this + (_DWORD)&loc_948EB + 1);
    v15 = stlp_std::priv::__find<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string>(
            *v14,
            v13,
            &__val);
    m_object = (int)v36.m_object;
    where = v15;
    if ( v15 != v13 )
      vostok::buffer_vector<vostok::fs_new::virtual_path_string>::erase(
        (vostok::buffer_vector<vostok::fs_new::virtual_path_string> *)v36.m_object,
        v14,
        &where);
    where = (vostok::fs_new::virtual_path_string *)__val.m_string.m_begin;
    if ( !__val.m_string.m_begin )
      goto LABEL_19;
    v17 = "null";
    m_begin = __val.m_string.m_begin;
    m_object = 5;
    v21 = 0;
    v19 = 0;
    v20 = 1;
    do
    {
      if ( !m_object )
        break;
      v19 = (unsigned __int8)*m_begin < (unsigned int)*v17;
      v20 = *m_begin++ == *v17++;
      --m_object;
    }
    while ( v20 );
    if ( !v20 )
      v21 = -v19 - (v19 - 1);
    if ( v21 )
    {
LABEL_19:
      texture = (vostok::fs_new::virtual_path_string *)vostok::render::resource_manager::find_texture(
                                                         (vostok::render::resource_manager *)m_object,
                                                         (int)v42,
                                                         __val.m_string.m_begin);
      if ( !texture )
        texture = (vostok::fs_new::virtual_path_string *)vostok::render::resource_manager::load_texture(
                                                           v42,
                                                           (char *)where,
                                                           0,
                                                           0,
                                                           0,
                                                           1,
                                                           1,
                                                           0xFFFFFFFF,
                                                           1,
                                                           0);
      where = texture;
    }
    else
    {
      where = 0;
    }
    if ( use_converter )
    {
      v36.m_object = 0;
      v35 = num_last_mips_used;
      v34 = (char *)vostok::resources::query_result_for_user::get_requested_path(m_queries);
      v33.m_object = v23;
      vostok::resources::query_result_for_user::get_managed_resource(
        (vostok::resources::query_result_for_user *)v23,
        &v33);
      vostok::render::resource_manager::on_texture_loaded_res(v42, v33, v34, v35, v36.m_object);
    }
    else
    {
      v36.m_object = (vostok::resources::managed_resource *)m_object;
      vostok::resources::query_result_for_user::get_managed_resource(m_queries, &v36);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v24,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v44,
        v36);
      memset(v47, 0, sizeof(v47));
      v25 = 0;
      if ( !ignore_always_7 && D3DX11GetImageInfoFromMemory(v45, v46, 0, (int)v47, 0) < 0 )
      {
        v36.m_object = (vostok::resources::managed_resource *)2970;
        v39 = 1;
        ImageInfoFromMemory = D3DX11GetImageInfoFromMemory(v45, v46, 0, (int)v47, 0);
        d3d11_error_string = (bool *)make_d3d11_error_string(ImageInfoFromMemory, v27);
        vostok::debug::on_error(
          (bool *)&v39,
          process_error_true,
          d3d11_error_string,
          ".\\resource_manager.cpp",
          "vostok::render::resource_manager::on_texture_loaded",
          (const char *)v36.m_object);
        if ( vostok::debug::is_debugger_present() || v39 )
          __debugbreak();
      }
      D3DX11_IMAGE_LOAD_INFO::D3DX11_IMAGE_LOAD_INFO(v25, &v49);
      v49.Usage = D3D11_USAGE_DEFAULT;
      v49.BindFlags = 8;
      surface = 0;
      TextureFromMemory = D3DX11CreateTextureFromMemory(
                            (int)vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
                            v45,
                            v46,
                            (int)&v49,
                            0,
                            (int)&surface,
                            0);
      if ( !ignore_always_8 && TextureFromMemory < 0 )
      {
        v36.m_object = (vostok::resources::managed_resource *)2996;
        v38 = 1;
        v31 = (bool *)make_d3d11_error_string(TextureFromMemory, v30);
        vostok::debug::on_error(
          (bool *)&v38,
          process_error_true,
          v31,
          ".\\resource_manager.cpp",
          "vostok::render::resource_manager::on_texture_loaded",
          (const char *)v36.m_object);
        if ( vostok::debug::is_debugger_present() || v38 )
          __debugbreak();
      }
      vostok::render::res_texture::set_hw_texture(
        (vostok::render::res_texture *)v30,
        (int)where,
        surface,
        mip_level_cut,
        0,
        0,
        v37);
      surface->Release(surface);
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
        v32,
        (int)v44);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                 (const char *)2),
          v10 = (vostok::buffer_string *)v36.m_object,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v10,
        &v48);
      v6 = 1;
      vostok::logging::append(
        &v48,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resource_manager.cpp",
        0xB85u,
        "void __thiscall vostok::render::resource_manager::on_texture_loaded(class vostok::resources::queries_result &,un"
        "signed int,bool,unsigned int,volatile long *)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "Texture %s was not found!",
        __val.m_string.m_begin);
    }
    if ( (v6 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v48);
  }
}
