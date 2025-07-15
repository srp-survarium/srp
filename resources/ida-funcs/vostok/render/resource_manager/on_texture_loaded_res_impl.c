vostok::render::res_texture *__thiscall vostok::render::resource_manager::on_texture_loaded_res_impl(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *dds_ptr,
        int dds_size,
        const char *in_name,
        char *num_last_mips_used,
        unsigned int flush_num_mips,
        char a7)
{
  vostok::fixed_string<260> *v7; // ecx
  vostok::buffer_string *v8; // ecx
  int v9; // ecx
  const char *v10; // edi
  char *m_begin; // esi
  bool v12; // cf
  bool v13; // zf
  int v14; // edx
  vostok::render::res_texture *v15; // ebx
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  DXGI_FORMAT v18; // edx
  DXGI_FORMAT v19; // edx
  unsigned int v20; // ebx
  vostok::render::res_texture *v21; // edi
  vostok::render::texture_storage *v22; // esi
  stlp_std::priv::_Rb_tree_node_base *typeless_format; // eax
  char v24; // cl
  unsigned int v25; // eax
  unsigned int v26; // eax
  stlp_std::priv::_Rb_tree_node_base *v27; // edi
  unsigned int v28; // esi
  DXGI_FORMAT v29; // eax
  int v30; // ecx
  unsigned int v31; // ecx
  int v32; // edx
  ID3D11Resource *m_surface; // eax
  int v34; // eax
  stlp_std::priv::_Rb_tree_node_base *num_mips_for_pool_texture; // eax
  HRESULT v36; // eax
  const char *v37; // eax
  unsigned int v38; // edi
  int v39; // ecx
  unsigned int v40; // esi
  int v41; // esi
  ID3D11Resource *v42; // eax
  int v43; // eax
  HRESULT v44; // eax
  const char *v45; // eax
  int v46; // ecx
  unsigned int v47; // esi
  int v48; // esi
  ID3D11Device *m_device; // eax
  HRESULT v50; // eax
  bool *d3d11_error_string; // eax
  unsigned int v52; // esi
  int v53; // esi
  vostok::render::texture_storage *v54; // [esp+34h] [ebp-1E4h]
  char *v55; // [esp+34h] [ebp-1E4h]
  char *v56; // [esp+34h] [ebp-1E4h]
  bool v57; // [esp+34h] [ebp-1E4h]
  bool v58; // [esp+38h] [ebp-1E0h]
  int v59; // [esp+48h] [ebp-1D0h] BYREF
  int v60; // [esp+4Ch] [ebp-1CCh]
  vostok::render::res_texture *v61; // [esp+50h] [ebp-1C8h]
  ID3D11Resource *surface; // [esp+54h] [ebp-1C4h] BYREF
  int v63; // [esp+58h] [ebp-1C0h]
  char *v64; // [esp+5Ch] [ebp-1BCh]
  unsigned int i; // [esp+60h] [ebp-1B8h]
  stlp_std::priv::_Rb_tree_node_base *j; // [esp+64h] [ebp-1B4h]
  int v67; // [esp+68h] [ebp-1B0h]
  unsigned int v68; // [esp+6Ch] [ebp-1ACh]
  char *texture_name; // [esp+70h] [ebp-1A8h]
  const char *v70; // [esp+74h] [ebp-1A4h]
  unsigned int v71; // [esp+78h] [ebp-1A0h]
  unsigned int width[9]; // [esp+7Ch] [ebp-19Ch] BYREF
  bool srgb[4]; // [esp+A0h] [ebp-178h]
  vostok::render::texture_storage key; // [esp+A4h] [ebp-174h] BYREF
  unsigned int v75; // [esp+C4h] [ebp-154h]
  unsigned int v76; // [esp+C8h] [ebp-150h]
  unsigned int v77; // [esp+CCh] [ebp-14Ch]
  stlp_std::priv::_Rb_tree_node_base *v78; // [esp+D0h] [ebp-148h]
  unsigned __int8 dst[44]; // [esp+D4h] [ebp-144h] BYREF
  vostok::fs_new::virtual_path_string v80; // [esp+100h] [ebp-118h] BYREF
  const char *v81; // [esp+228h] [ebp+10h]
  unsigned int v82; // [esp+230h] [ebp+18h]

  v7 = (vostok::fixed_string<260> *)((1 - flush_num_mips) & ((1 - (unsigned __int64)flush_num_mips) >> 32));
  v82 = 1 - (_DWORD)v7;
  vostok::fixed_string<260>::fixed_string<260>(v7, &v80.m_string, num_last_mips_used);
  v80.m_separator = 47;
  vostok::render::fix_texture_name(&v80, v8);
  texture_name = v80.m_string.m_begin;
  if ( !v80.m_string.m_begin )
    goto LABEL_10;
  v10 = "null";
  m_begin = v80.m_string.m_begin;
  v9 = 5;
  v14 = 0;
  v12 = 0;
  v13 = 1;
  do
  {
    if ( !v9 )
      break;
    v12 = (unsigned __int8)*m_begin < (unsigned int)*v10;
    v13 = *m_begin++ == *v10++;
    --v9;
  }
  while ( v13 );
  if ( !v13 )
    v14 = -v12 - (v12 - 1);
  if ( v14 )
  {
LABEL_10:
    texture = vostok::render::resource_manager::find_texture(
                (vostok::render::resource_manager *)v9,
                (int)dds_ptr,
                v80.m_string.m_begin);
    if ( !texture )
    {
      v15 = vostok::render::resource_manager::load_texture(dds_ptr, texture_name, 0, 0, 0, 1, 1, 0xFFFFFFFF, 1, 0);
      v61 = v15;
      goto LABEL_13;
    }
    v15 = (vostok::render::res_texture *)texture;
  }
  else
  {
    v15 = 0;
  }
  v61 = v15;
LABEL_13:
  if ( a7 )
    v15->num_mips = 0;
  if ( &v15->m_name != &v80 )
    vostok::buffer_string::operator=(&v80.m_string, &v15->m_name.m_string);
  if ( vostok::command_line::key::is_set((vostok::command_line::key *)v9, (int)&s_no_srgb_textures_result) )
  {
    srgb[0] = 0;
  }
  else
  {
    LOBYTE(v59) = in_name[dds_size - 1];
    srgb[0] = v59;
  }
  memset(width, 0, sizeof(width));
  v81 = in_name - 1;
  if ( D3DX11GetImageInfoFromMemory(dds_size, (int)v81, 0, (int)width, 0) < 0 )
    return 0;
  v15->m_max_uses_width = width[0];
  v15->m_max_uses_height = width[1];
  v15->m_max_uses_mips = width[4];
  v18 = width[6];
  surface = 0;
  v70 = 0;
  v64 = (char *)(dds_size + 128);
  if ( width[6] == 28 )
  {
    v18 = DXGI_FORMAT_B8G8R8A8_UNORM;
    width[6] = 87;
  }
  if ( v18 == DXGI_FORMAT_B8G8R8A8_UNORM && v81 == (const char *)(width[0] * width[1] + 128) )
  {
    v18 = DXGI_FORMAT_R8_UNORM;
    width[6] = 61;
  }
  v20 = vostok::render::calc_block_size(v18);
  switch ( v19 )
  {
    case DXGI_FORMAT_R8G8B8A8_UNORM:
      goto LABEL_35;
    case DXGI_FORMAT_R8_UNORM:
      v67 = 1;
      goto LABEL_36;
    case DXGI_FORMAT_BC1_UNORM:
      v67 = 8;
      goto LABEL_36;
  }
  if ( v19 != DXGI_FORMAT_BC2_UNORM && v19 != DXGI_FORMAT_BC3_UNORM )
  {
LABEL_35:
    v67 = 4;
    goto LABEL_36;
  }
  v67 = 16;
LABEL_36:
  HIBYTE(v63) = 1;
  if ( v19 == DXGI_FORMAT_BC1_UNORM || (HIBYTE(v60) = 1, v19 == DXGI_FORMAT_BC3_UNORM) )
    HIBYTE(v60) = 0;
  v21 = v61;
  if ( v61->m_streamed )
  {
    v22 = *(vostok::render::texture_storage **)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2);
    if ( v22 )
    {
      typeless_format = (stlp_std::priv::_Rb_tree_node_base *)vostok::render::find_typeless_format(v19);
      if ( !vostok::render::texture_storage::supported(
              v22,
              (stlp_std::priv::_Rb_tree_node_base *)(width[0] >> v24),
              width[1] >> v24,
              (stlp_std::priv::_Rb_tree_node_base *)1,
              typeless_format) )
        HIBYTE(v60) = 1;
    }
  }
  if ( HIBYTE(v60) )
    v61->m_streamed = 0;
  if ( !v21->m_streamed || v82 == -1 || (HIBYTE(v60) = 1, width[2] != 1) )
    HIBYTE(v60) = 0;
  v68 = 0;
  v25 = width[4];
  v76 = width[0];
  v71 = width[4];
  texture_name = (char *)width[1];
  if ( HIBYTE(v60) )
  {
    if ( v82 )
    {
      v68 = width[4] - v82;
      width[0] = (width[0] >> (LOBYTE(width[4]) - v82))
               - (width[0] >> (LOBYTE(width[4]) - v82) < v20 ? (width[0] >> (LOBYTE(width[4]) - v82)) - v20 : 0);
      v26 = (width[1] >> (LOBYTE(width[4]) - v82)) - (width[1] >> v68 < v20 ? (width[1] >> v68) - v20 : 0);
      width[1] = v26;
      if ( width[0] == 4 || v26 == 4 )
        v25 = 1;
      else
        v25 = v82;
      width[4] = v25;
    }
    else
    {
      HIBYTE(v60) = 0;
    }
  }
  v27 = (stlp_std::priv::_Rb_tree_node_base *)width[0];
  v28 = width[1];
  j = (stlp_std::priv::_Rb_tree_node_base *)v25;
  v61->loaded_num_mips = v25;
  v78 = v27;
  v77 = v28;
  v29 = vostok::render::find_typeless_format((DXGI_FORMAT)width[6]);
  *(_DWORD *)(v30 + 80) = v29;
  if ( width[2] != 1 )
  {
    *(_DWORD *)&key.m_calculate_memory_only = 0;
    *(_DWORD *)&key.m_pools._M_t._M_key_compare.gap0 = 8;
    if ( srgb[0] )
    {
      switch ( width[6] )
      {
        case 0x1Cu:
          key.m_pools._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)29;
          goto LABEL_131;
        case 0x47u:
          key.m_pools._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)72;
          goto LABEL_131;
        case 0x4Au:
          key.m_pools._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)75;
          goto LABEL_131;
        case 0x4Du:
          key.m_pools._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)78;
          goto LABEL_131;
        case 0x57u:
          key.m_pools._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)91;
          goto LABEL_131;
      }
    }
    key.m_pools._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)width[6];
LABEL_131:
    key.m_pools._M_t._M_node_count = 0;
    key.mem_not_on_pool = width[0];
    *(_DWORD *)&key.m_pools._M_t._M_header._M_data._M_color = width[1];
    key.m_pools._M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)width[4];
    v75 = width[5];
    m_device = vostok::quasi_singleton<vostok::render::device>::pinst->m_device;
    key.m_pools._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)width[2];
    v50 = m_device->CreateTexture3D(m_device, (const D3D11_TEXTURE3D_DESC *)&key, 0, (ID3D11Texture3D **)&surface);
    if ( !ignore_always_6 && v50 < 0 )
    {
      LOBYTE(v59) = 1;
      d3d11_error_string = (bool *)make_d3d11_error_string(
                                     v50,
                                     (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v31);
      vostok::debug::on_error(
        (bool *)&v59,
        process_error_true,
        d3d11_error_string,
        ".\\resource_manager.cpp",
        "vostok::render::resource_manager::on_texture_loaded_res_impl",
        (const char *)0xB10);
      if ( vostok::debug::is_debugger_present() || (_BYTE)v59 )
        __debugbreak();
    }
    if ( v68 < width[4] )
    {
      i = 0;
      do
      {
        texture_name = (char *)(((width[0] >> i) + v20 - 1) / v20);
        v52 = v67 * width[2] * (_DWORD)texture_name * (((width[1] >> i) + v20 - 1) / v20);
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->UpdateSubresource(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          surface,
          v68,
          0,
          v64,
          v67 * (_DWORD)texture_name,
          (_DWORD)texture_name * v67 * (_DWORD)texture_name);
        v64 += v52;
        ++v68;
        ++i;
      }
      while ( v68 < width[4] );
    }
    v70 = v81 - 128;
    goto LABEL_140;
  }
  memset((int)dst, 0, sizeof(dst));
  *(_DWORD *)&dst[12] = width[3];
  *(_DWORD *)&dst[32] = 8;
  *(_DWORD *)&dst[16] = vostok::render::find_typeless_format((DXGI_FORMAT)width[6]);
  *(_DWORD *)&dst[8] = j;
  *(_DWORD *)&dst[40] = width[5];
  v31 = 0;
  *(_DWORD *)dst = v27;
  *(_DWORD *)&dst[4] = v28;
  *(_DWORD *)&dst[20] = 1;
  *(_DWORD *)&dst[24] = 0;
  *(_DWORD *)&dst[36] = 0;
  *(_DWORD *)&dst[28] = 0;
  if ( v32 != 1 )
    goto LABEL_91;
  v31 = *(unsigned int *)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2);
  if ( v31 )
  {
    if ( v61->m_streamed )
    {
      m_surface = v61->m_surface;
      if ( m_surface )
      {
        if ( !vostok::render::texture_storage::try_release((vostok::render::texture_storage *)v31, m_surface)
          && !vostok::render::texture_storage::is_texture_from_pool(
                *(vostok::render::texture_storage **)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2),
                v61->m_surface) )
        {
          v61->m_surface->Release(v61->m_surface);
        }
      }
    }
  }
  surface = 0;
  if ( v61->m_streamed )
  {
    v34 = *(unsigned int *)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2);
    if ( v34 )
    {
      key.m_pools._M_t._M_node_count = 0;
      key.m_pools._M_t._M_header._M_data._M_left = *(stlp_std::priv::_Rb_tree_node_base **)&dst[16];
      key.m_pools._M_t._M_header._M_data._M_right = j;
      key.mem_not_on_pool = (unsigned int)v27;
      *(_DWORD *)&key.m_pools._M_t._M_header._M_data._M_color = v28;
      key.m_pools._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)1;
      surface = vostok::render::texture_storage::get(&key, v34, (const vostok::render::texture_pool_key *)&key, v58);
    }
  }
  if ( v61->m_streamed )
  {
    v31 = *(unsigned int *)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2);
    if ( v31 )
    {
      if ( vostok::render::texture_storage::supported(
             (vostok::render::texture_storage *)v31,
             v27,
             v28,
             (stlp_std::priv::_Rb_tree_node_base *)1,
             *(stlp_std::priv::_Rb_tree_node_base **)&dst[16]) )
      {
        if ( surface )
          goto LABEL_81;
        if ( *(_DWORD *)&dst[16] != 70 && *(_DWORD *)&dst[16] != 76 )
        {
LABEL_76:
          v36 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateTexture2D(
                  vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
                  (const D3D11_TEXTURE2D_DESC *)dst,
                  0,
                  (ID3D11Texture2D **)&surface);
          if ( !ignore_always_4 && v36 < 0 )
          {
            v55 = v80.m_string.m_begin;
            LOBYTE(v59) = 1;
            v37 = make_d3d11_error_string(
                    v36,
                    (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v31);
            vostok::debug::on_error(
              (bool *)&v59,
              process_error_true,
              0,
              "assertion_failed",
              v37,
              ".\\resource_manager.cpp",
              "vostok::render::resource_manager::on_texture_loaded_res_impl",
              (const char *)0xA60,
              "texture creation failed: %s",
              v55);
            if ( vostok::debug::is_debugger_present() || (_BYTE)v59 )
              __debugbreak();
          }
          goto LABEL_82;
        }
        key.m_pools._M_t._M_header._M_data._M_left = *(stlp_std::priv::_Rb_tree_node_base **)&dst[16];
        key.mem_not_on_pool = (unsigned int)v27;
        *(_DWORD *)&key.m_pools._M_t._M_header._M_data._M_color = v28;
        key.m_pools._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)1;
        num_mips_for_pool_texture = (stlp_std::priv::_Rb_tree_node_base *)vostok::render::get_num_mips_for_pool_texture(
                                                                            (unsigned int)v27,
                                                                            v28);
        key.m_pools._M_t._M_node_count = 0;
        key.m_pools._M_t._M_header._M_data._M_right = num_mips_for_pool_texture;
        surface = vostok::render::texture_storage::get(
                    v54,
                    *(unsigned int *)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2),
                    (const vostok::render::texture_pool_key *)&key,
                    v58);
      }
    }
  }
  if ( !surface )
    goto LABEL_76;
LABEL_81:
  HIBYTE(v63) = 0;
LABEL_82:
  v38 = 0;
  if ( v71 )
  {
    i = -v68;
    do
    {
      v39 = ((v76 >> v38) - (((v76 >> v38) - v20) & (((v76 >> v38) - (unsigned __int64)v20) >> 32)) + v20 - 1) / v20;
      v40 = v39
          * ((((unsigned int)texture_name >> v38)
            - ((unsigned int)texture_name >> v38 < v20 ? ((unsigned int)texture_name >> v38) - v20 : 0)
            + v20
            - 1)
           / v20);
      v31 = v67 * v39;
      v41 = v67 * v40;
      if ( HIBYTE(v60) && v82 < v71 - v38 )
      {
        v64 += v41;
      }
      else
      {
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->UpdateSubresource(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          surface,
          i,
          0,
          v64,
          v31,
          0);
        v64 += v41;
        v70 += v41;
      }
      ++v38;
      ++i;
    }
    while ( v38 < v71 );
  }
  if ( width[3] == 1 )
    goto LABEL_140;
  v27 = v78;
  v28 = v77;
LABEL_91:
  if ( v61->m_streamed )
  {
    v42 = v61->m_surface;
    if ( v42 )
    {
      v31 = *(unsigned int *)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2);
      if ( v31 )
      {
        if ( !vostok::render::texture_storage::try_release((vostok::render::texture_storage *)v31, v42)
          && !vostok::render::texture_storage::is_texture_from_pool(
                *(vostok::render::texture_storage **)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2),
                v61->m_surface) )
        {
          v61->m_surface->Release(v61->m_surface);
        }
      }
    }
  }
  surface = 0;
  if ( v61->m_streamed )
  {
    v43 = *(unsigned int *)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2);
    if ( v43 )
    {
      key.m_pools._M_t._M_node_count = 0;
      key.m_pools._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)width[3];
      key.m_pools._M_t._M_header._M_data._M_left = *(stlp_std::priv::_Rb_tree_node_base **)&dst[16];
      key.m_pools._M_t._M_header._M_data._M_right = j;
      key.mem_not_on_pool = (unsigned int)v27;
      *(_DWORD *)&key.m_pools._M_t._M_header._M_data._M_color = v28;
      surface = vostok::render::texture_storage::get(&key, v43, (const vostok::render::texture_pool_key *)&key, v58);
    }
  }
  if ( v61->m_streamed )
  {
    v31 = *(unsigned int *)((char *)&dds_ptr->sh_created + (_DWORD)&loc_948DA + 2);
    if ( v31 )
      vostok::render::texture_storage::supported(
        (vostok::render::texture_storage *)v31,
        v27,
        v28,
        *(stlp_std::priv::_Rb_tree_node_base **)&dst[12],
        *(stlp_std::priv::_Rb_tree_node_base **)&dst[16]);
  }
  if ( surface )
  {
    HIBYTE(v63) = 0;
  }
  else
  {
    v44 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateTexture2D(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
            (const D3D11_TEXTURE2D_DESC *)dst,
            0,
            (ID3D11Texture2D **)&surface);
    if ( !ignore_always_5 && v44 < 0 )
    {
      v56 = v80.m_string.m_begin;
      LOBYTE(v59) = 1;
      v45 = make_d3d11_error_string(
              v44,
              (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v31);
      vostok::debug::on_error(
        (bool *)&v59,
        process_error_true,
        0,
        "assertion_failed",
        v45,
        ".\\resource_manager.cpp",
        "vostok::render::resource_manager::on_texture_loaded_res_impl",
        (const char *)0xAD9,
        "texture creation failed: %s",
        v56);
      if ( vostok::debug::is_debugger_present() || (_BYTE)v59 )
        __debugbreak();
    }
  }
  for ( i = 0; i < width[3]; ++i )
  {
    for ( j = 0; (unsigned int)j < v71; j = (stlp_std::priv::_Rb_tree_node_base *)((char *)j + 1) )
    {
      v46 = ((v76 >> (char)j) - (((v76 >> (char)j) - v20) & (((v76 >> (char)j) - (unsigned __int64)v20) >> 32)) + v20 - 1)
          / v20;
      v47 = v46
          * ((((unsigned int)texture_name >> (char)j)
            - ((unsigned int)texture_name >> (char)j < v20 ? ((unsigned int)texture_name >> (char)j) - v20 : 0)
            + v20
            - 1)
           / v20);
      v31 = v67 * v46;
      v48 = v67 * v47;
      if ( HIBYTE(v60) && v82 < v71 - (unsigned int)j )
      {
        v64 += v48;
      }
      else
      {
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->UpdateSubresource(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          surface,
          (unsigned int)j + *(_DWORD *)&dst[8] * i - v68,
          0,
          v64,
          v31,
          0);
        v64 += v48;
        v70 += v48;
      }
    }
  }
LABEL_140:
  v57 = srgb[0];
  v53 = (int)v61;
  v61->m_mem_usage = (unsigned int)v70;
  *(_DWORD *)(v53 + 12) = width[4];
  vostok::render::res_texture::set_hw_texture((vostok::render::res_texture *)v31, v53, surface, 0, 0, v57, v58);
  v13 = HIBYTE(v63) == 0;
  *(_BYTE *)(v53 + 8) = 1;
  if ( !v13 )
  {
    if ( surface )
      surface->Release(surface);
  }
  return (vostok::render::res_texture *)v53;
}
