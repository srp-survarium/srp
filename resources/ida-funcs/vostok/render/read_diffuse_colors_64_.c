char __cdecl vostok::render::read_diffuse_colors_64_(
        vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> m_materail_effects_instance,
        vostok::math::color (*results)[64][64])
{
  vostok::render::resource_manager *v2; // ecx
  vostok::render::material_effects_instance *m_object; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *m_effects; // esi
  vostok::render::render_target *render_target; // eax
  const char *v6; // ebx
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  vostok::render::res_texture *v8; // ebp
  unsigned int v9; // ecx
  vostok::render::backend *v10; // ecx
  vostok::render::res_texture *texture2d; // eax
  vostok::render::resource_manager *v12; // esi
  vostok::render::backend *v13; // ecx
  char *v14; // eax
  vostok::render::res_texture *v15; // ecx
  bool v16; // zf
  int v19; // ebp
  unsigned int v20; // ecx
  vostok::math::color *v21; // edx
  vostok::render::res_texture *v22; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v23; // [esp-1Ch] [ebp-48h]
  unsigned int v24; // [esp+10h] [ebp-1Ch]
  unsigned int v25; // [esp+10h] [ebp-1Ch]
  unsigned int v26; // [esp+10h] [ebp-1Ch]
  unsigned int *v27; // [esp+10h] [ebp-1Ch]
  unsigned int v28; // [esp+14h] [ebp-18h]
  bool v29; // [esp+14h] [ebp-18h]
  unsigned int v30; // [esp+14h] [ebp-18h]
  bool v31; // [esp+14h] [ebp-18h]
  vostok::render::res_texture *v32; // [esp+18h] [ebp-14h]
  unsigned int v33; // [esp+1Ch] [ebp-10h]
  unsigned int tex; // [esp+20h] [ebp-Ch]
  const vostok::render::res_texture *texa; // [esp+20h] [ebp-Ch]
  unsigned int rt; // [esp+24h] [ebp-8h]
  const char *rta; // [esp+24h] [ebp-8h]
  unsigned int row_pitch; // [esp+28h] [ebp-4h] BYREF

  m_object = m_materail_effects_instance.m_object;
  if ( !m_materail_effects_instance.m_object )
    return 0;
  m_effects = m_materail_effects_instance.m_object->m_material_effects.m_effects;
  if ( !m_materail_effects_instance.m_object->m_material_effects.m_effects[0].m_object )
  {
LABEL_24:
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_materail_effects_instance.m_object->vostok::resources::unmanaged_intrusive_base,
        m_materail_effects_instance.m_object);
    return 0;
  }
  render_target = vostok::render::resource_manager::create_render_target(
                    v2,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    "$user$diffuse_color",
                    (vostok::render::res_texture *)0x40,
                    (ID3D11Texture2D **)0x40,
                    (const char *)0x1C,
                    enum_rt_usage_render_target,
                    0,
                    0,
                    v24,
                    v28);
  v6 = 0;
  rt = 0;
  if ( render_target )
  {
    ++render_target->m_reference_count;
    v6 = (const char *)render_target;
    rt = (unsigned int)render_target;
  }
  texture = vostok::render::resource_manager::create_texture(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              "$user$diffuse_color",
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF);
  v8 = 0;
  tex = 0;
  if ( texture )
  {
    ++texture->_M_parent;
    v8 = (vostok::render::res_texture *)texture;
    tex = (unsigned int)texture;
  }
  v9 = m_effects->m_object->m_techniques._M_impl._M_finish - m_effects->m_object->m_techniques._M_impl._M_start;
  if ( v9 > 3 )
  {
    m_effects->m_object->m_cur_technique = 3;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v9, v25);
  }
  v23.m_object = 0;
  if ( v6 )
  {
    v23.m_object = (vostok::render::render_target *)v6;
    ++*(_DWORD *)v6;
  }
  vostok::render::system_renderer::fill_surface(
    (vostok::render::system_renderer *)v9,
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
    v23,
    0,
    0,
    0,
    0,
    0,
    0.0,
    0.0,
    0.0,
    1.0);
  (*(void (__stdcall **)(int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                             + 444))(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
  vostok::render::backend::flush(
    v10,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  texture2d = vostok::render::resource_manager::create_texture2d(
                D3D11_USAGE_STAGING,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                "$user$diffuse_color_lockable",
                (vostok::render::resource_manager *)0x40,
                0x40u,
                (ID3D11Texture2D *)0x1C,
                (const D3D11_SUBRESOURCE_DATA *)1,
                DXGI_FORMAT_UNKNOWN,
                v25,
                v29);
  v12 = 0;
  if ( texture2d )
  {
    ++texture2d->m_reference_count;
    v12 = (vostok::render::resource_manager *)texture2d;
  }
  vostok::render::resource_manager::copy2D(0x40u, 0x40u, v12, v8, v26, v30, v32, v33, tex, rt, row_pitch);
  (*(void (__stdcall **)(int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                             + 444))(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
  vostok::render::backend::flush(
    v13,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v14 = (char *)vostok::render::res_texture::map2D(
                  (vostok::render::res_texture *)&row_pitch,
                  (int)v12,
                  &row_pitch,
                  0,
                  v27,
                  v31);
  if ( !v14 )
  {
    if ( v12 )
    {
      v16 = v12->sh_returned-- == 1;
      if ( v16 )
        vostok::render::res_texture::destroy_impl(v15, (const vostok::render::res_texture *)v12);
    }
    if ( v8 )
    {
      v16 = v8->m_reference_count-- == 1;
      if ( v16 )
        vostok::render::res_texture::destroy_impl(v15, v8);
    }
    if ( v6 )
    {
      v16 = (*(_DWORD *)v6)-- == 1;
      if ( v16 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v15,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v6);
    }
    m_object = m_materail_effects_instance.m_object;
    goto LABEL_24;
  }
  v19 = 64;
  do
  {
    v20 = 0;
    v21 = (vostok::math::color *)results;
    do
    {
      *v21 = *(vostok::math::color *)&v14[4 * v20++];
      v21 += 64;
    }
    while ( v20 < 0x40 );
    v14 += row_pitch;
    results = (vostok::math::color (*)[64][64])((char *)results + 4);
    --v19;
  }
  while ( v19 );
  (*(void (__stdcall **)(int, vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v12->m_rs_cache.states._M_impl._M_end_of_storage._M_data,
    0);
  v16 = v12->sh_returned-- == 1;
  if ( v16 )
    vostok::render::res_texture::destroy_impl(v22, (const vostok::render::res_texture *)v12);
  if ( texa )
  {
    v16 = texa->m_reference_count-- == 1;
    if ( v16 )
      vostok::render::res_texture::destroy_impl(v22, texa);
  }
  if ( rta )
  {
    v16 = (*(_DWORD *)rta)-- == 1;
    if ( v16 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        rta);
  }
  if ( !_InterlockedExchangeAdd(&m_materail_effects_instance.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_materail_effects_instance.m_object->vostok::resources::unmanaged_intrusive_base,
      m_materail_effects_instance.m_object);
  return 1;
}
