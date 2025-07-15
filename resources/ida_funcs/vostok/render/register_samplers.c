void __thiscall vostok::render::register_samplers(
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *ecx0)
{
  survarium::options_tab *v1; // edi
  stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *m_movie; // eax
  stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *m_game; // ecx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  ID3D11SamplerState *state; // eax
  ID3D11SamplerState *v7; // eax
  ID3D11SamplerState *v8; // eax
  ID3D11SamplerState *v9; // eax
  ID3D11SamplerState *v10; // eax
  ID3D11SamplerState *v11; // eax
  ID3D11SamplerState *v12; // eax
  ID3D11SamplerState *v13; // eax
  ID3D11SamplerState *v14; // eax
  ID3D11SamplerState *v15; // eax
  ID3D11SamplerState *v16; // eax
  ID3D11SamplerState *v17; // eax
  ID3D11SamplerState *v18; // eax
  ID3D11SamplerState *v19; // eax
  ID3D11SamplerState *v20; // eax
  ID3D11SamplerState *v21; // eax
  ID3D11SamplerState *v22; // eax
  vostok::render::resource_manager *v23; // ecx
  vostok::render::sampler_state_descriptor sampler_sim_anisotropic; // [esp+10h] [ebp-3Ch] BYREF

  v1 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::clear_state_array(
    ecx0,
    &`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  m_movie = (stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *)v1[29].m_movie;
  m_game = (stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *)v1[29].m_game;
  if ( m_game != m_movie )
    v1[29].m_movie = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)stlp_std::priv::__copy<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *,stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *,int>(m_movie, m_game, (stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *)v1[29].m_movie);
  v4 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 46);
  if ( v4 )
  {
    v5 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 46);
    if ( v4 > 4 )
      v5 = 4;
  }
  else
  {
    v5 = 0;
  }
  switch ( v4 )
  {
    case 0u:
      v5 = 0;
      break;
    case 1u:
      v5 = 2;
      break;
    case 2u:
      v5 = 4;
      break;
    case 3u:
      v5 = 8;
      break;
    case 4u:
      v5 = 16;
      break;
    default:
      break;
  }
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[0]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[1]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[2]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[3]) = clear_value;
  sampler_sim_anisotropic.m_desc.MaxAnisotropy = v5;
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.ComparisonFunc = D3D11_COMPARISON_NEVER;
  sampler_sim_anisotropic.m_desc.Filter = v5 != 0 ? D3D11_FILTER_ANISOTROPIC : D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  state = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
            &sampler_sim_anisotropic.m_desc,
            (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    state);
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[0]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[1]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[2]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[3]) = clear_value;
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.MaxAnisotropy = 1;
  sampler_sim_anisotropic.m_desc.ComparisonFunc = D3D11_COMPARISON_NEVER;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v7 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
         &sampler_sim_anisotropic.m_desc,
         (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.sl_created,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v7);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v8 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
         &sampler_sim_anisotropic.m_desc,
         (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_render_target_video_memory,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v8);
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v9 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
         &sampler_sim_anisotropic.m_desc,
         (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)((char *)&stru_962594.m_num_bytes_of_texture_video_memory + 4),
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v9);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v10 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_vs_hw_registry._M_t._M_header._M_data._M_parent,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v10);
  v11 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_vs_hw_registry._M_t._M_node_count,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v11);
  v12 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_gs_hw_registry._M_t._M_header._M_data._M_parent,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v12);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v13 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_gs_hw_registry._M_t._M_key_compare,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v13);
  v14 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_ps_hw_registry._M_t._M_header._M_data._M_left,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v14);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v15 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_ps_hw_registry._M_t._M_key_compare,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v15);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v16 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_rt_registry._M_t._M_header._M_data._M_left,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v16);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v17 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_rt_registry._M_t._M_key_compare,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v17);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v18 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_texture_registry._M_t._M_header._M_data._M_left,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v18);
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  v19 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_texture_registry._M_t._M_key_compare,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v19);
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  memset(sampler_sim_anisotropic.m_desc.BorderColor, 0, 20);
  v20 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_const_tables._M_t._M_header._M_data._M_left,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v20);
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[0]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[1]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[2]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[3]) = clear_value;
  sampler_sim_anisotropic.m_desc.ComparisonFunc = D3D11_COMPARISON_LESS_EQUAL;
  v21 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_const_tables._M_t._M_key_compare,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v21);
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[0]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[1]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[2]) = clear_value;
  LODWORD(sampler_sim_anisotropic.m_desc.BorderColor[3]) = clear_value;
  sampler_sim_anisotropic.m_desc.MipLODBias = 0.0;
  sampler_sim_anisotropic.m_desc.MinLOD = 0.0;
  sampler_sim_anisotropic.m_desc.MaxAnisotropy = 1;
  sampler_sim_anisotropic.m_desc.Filter = D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR;
  sampler_sim_anisotropic.m_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
  sampler_sim_anisotropic.m_desc.MaxLOD = float_max_9;
  sampler_sim_anisotropic.m_desc.ComparisonFunc = D3D11_COMPARISON_LESS_EQUAL;
  v22 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
          &sampler_sim_anisotropic.m_desc,
          (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][22].m_type);
  vostok::render::resource_manager::register_sampler(
    (vostok::render::resource_manager *)&stru_962594.m_const_buffers._M_t._M_header._M_data._M_parent,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    v22);
  vostok::render::resource_manager::bind_samplers_to_shaders(
    v23,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
}
