void __thiscall vostok::render::res_xs<vostok::render::gs_data>::apply(
        vostok::render::res_xs<vostok::render::gs_data> *this,
        const vostok::render::res_xs<vostok::render::gs_data> *thisa)
{
  vostok::render::res_xs_hw<vostok::render::gs_data> *m_object; // eax
  const char *m_conflicted_key_name; // ecx
  bool v4; // zf
  const vostok::render::shader_constant_table *v5; // eax
  const char *v6; // esi
  int v7; // eax
  const vostok::render::res_texture_list *v8; // edi
  const char *v9; // ebx
  const vostok::render::res_sampler_list *v10; // edi
  const char *v11; // ebx
  const char *v12; // eax
  const char *v13; // esi
  int v14; // edx
  const vostok::render::res_texture_list **v15; // esi
  const char *v16; // ebx
  unsigned int v17; // eax
  const vostok::render::res_texture_list *v18; // eax
  const char *v19; // esi
  const vostok::render::res_sampler_list *v20; // ecx
  unsigned int v21; // [esp-10h] [ebp-20h]

  m_object = thisa->m_hardware_shader.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v4 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 48) == (_DWORD)m_object;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 48) = m_object;
    *((_BYTE *)m_conflicted_key_name + 153) |= !v4;
    v5 = thisa->m_constants.m_object;
    v6 = m_conflicted_key_name;
    if ( *((const vostok::render::shader_constant_table **)m_conflicted_key_name + 211) != v5 )
    {
      vostok::render::constants_handler<2>::assign(
        (vostok::render::constants_handler<2> *)(m_conflicted_key_name + 836),
        v5);
      v7 = *((_DWORD *)v6 + 571);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v6 + 154) = 1;
      *((_DWORD *)v6 + 574) = v7;
    }
    v8 = thisa->m_textures.m_object;
    v9 = m_conflicted_key_name;
    if ( *((const vostok::render::res_texture_list **)m_conflicted_key_name + 212) != v8 )
    {
      vostok::render::textures_handler<0>::assign(
        (vostok::render::textures_handler<0> *)(m_conflicted_key_name + 848),
        v8);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v9 + 155) = 1;
    }
    v10 = thisa->m_samplers.m_object;
    v11 = m_conflicted_key_name;
    if ( *((const vostok::render::res_sampler_list **)m_conflicted_key_name + 367) != v10 )
    {
      vostok::render::samplers_handler<0>::assign(
        (vostok::render::samplers_handler<0> *)(m_conflicted_key_name + 1396),
        v10);
      *((_BYTE *)v11 + 156) = 1;
    }
  }
  else
  {
    v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v4 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 48) == 0;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 48) = 0;
    *((_BYTE *)v12 + 153) |= !v4;
    v13 = v12;
    if ( *((_DWORD *)v12 + 211) )
    {
      vostok::render::constants_handler<2>::assign((vostok::render::constants_handler<2> *)(v12 + 836), 0);
      v14 = *((_DWORD *)v13 + 571);
      v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v13 + 154) = 1;
      *((_DWORD *)v13 + 574) = v14;
    }
    v15 = (const vostok::render::res_texture_list **)(v12 + 848);
    v16 = v12;
    if ( *((_DWORD *)v12 + 212) )
    {
      v17 = vostok::math::max((*v15)->m_container._M_impl._M_finish - (*v15)->m_container._M_impl._M_start, 0);
      v21 = (unsigned int)v15[2];
      v15[1] = 0;
      v15[2] = (const vostok::render::res_texture_list *)vostok::math::max(v21, v17);
      v18 = *v15;
      *v15 = 0;
      if ( v18 )
      {
        v4 = v18->m_reference_count-- == 1;
        if ( v4 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v18);
      }
      v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v16 + 155) = 1;
    }
    v19 = v12;
    if ( *((_DWORD *)v12 + 367) )
    {
      *((_DWORD *)v12 + 349) = 0;
      *((_DWORD *)v12 + 350) = 0;
      v20 = (const vostok::render::res_sampler_list *)*((_DWORD *)v12 + 367);
      *((_DWORD *)v12 + 367) = 0;
      if ( v20 )
      {
        v4 = v20->m_reference_count-- == 1;
        if ( v4 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v20);
      }
      *((_BYTE *)v19 + 156) = 1;
    }
  }
}


void __thiscall vostok::render::res_xs<vostok::render::ps_data>::apply(
        vostok::render::res_xs<vostok::render::ps_data> *this,
        const vostok::render::res_xs<vostok::render::ps_data> *thisa)
{
  const char *m_conflicted_key_name; // ecx
  vostok::render::res_xs_hw<vostok::render::ps_data> *m_object; // eax
  bool v4; // dl
  bool v5; // zf
  const vostok::render::shader_constant_table *v6; // eax
  const char *v7; // esi
  int v8; // eax
  const vostok::render::res_texture_list *v9; // edi
  const char *v10; // ebx
  const vostok::render::res_sampler_list *v11; // edi
  const char *v12; // ebx

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_object = thisa->m_hardware_shader.m_object;
  v4 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 47) != (_DWORD)m_object;
  v5 = (v4 | *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 157)) == 0;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 157) |= v4;
  if ( !v5 )
    ++*((_DWORD *)m_conflicted_key_name + 1);
  *((_DWORD *)m_conflicted_key_name + 47) = m_object;
  v6 = thisa->m_constants.m_object;
  v7 = m_conflicted_key_name;
  if ( *((const vostok::render::shader_constant_table **)m_conflicted_key_name + 371) != v6 )
  {
    ++*((_DWORD *)m_conflicted_key_name + 6);
    vostok::render::constants_handler<1>::assign(
      (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
      v6);
    v8 = *((_DWORD *)v7 + 571);
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v7 + 158) = 1;
    *((_DWORD *)v7 + 573) = v8;
  }
  v9 = thisa->m_textures.m_object;
  v10 = m_conflicted_key_name;
  if ( *((const vostok::render::res_texture_list **)m_conflicted_key_name + 372) != v9 )
  {
    ++*((_DWORD *)m_conflicted_key_name + 7);
    vostok::render::textures_handler<0>::assign(
      (vostok::render::textures_handler<0> *)(m_conflicted_key_name + 1488),
      v9);
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v10 + 159) = 1;
  }
  v11 = thisa->m_samplers.m_object;
  v12 = m_conflicted_key_name;
  if ( *((const vostok::render::res_sampler_list **)m_conflicted_key_name + 527) != v11 )
  {
    ++*((_DWORD *)m_conflicted_key_name + 8);
    vostok::render::samplers_handler<0>::assign(
      (vostok::render::samplers_handler<0> *)(m_conflicted_key_name + 2036),
      v11);
    *((_BYTE *)v12 + 160) = 1;
  }
}


void __thiscall vostok::render::res_xs<vostok::render::vs_data>::apply(
        vostok::render::res_xs<vostok::render::vs_data> *this,
        const vostok::render::res_xs<vostok::render::vs_data> *thisa)
{
  const char *m_conflicted_key_name; // ecx
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // eax
  bool v4; // dl
  bool v5; // zf
  char v6; // dl
  int v7; // eax
  const vostok::render::shader_constant_table *v8; // eax
  const char *v9; // esi
  int v10; // eax
  const vostok::render::res_texture_list *v11; // edi
  const char *v12; // ebx
  const vostok::render::res_sampler_list *v13; // edi
  const char *v14; // ebx

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_object = thisa->m_hardware_shader.m_object;
  v4 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 46) != (_DWORD)m_object;
  v5 = (v4 | *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 149)) == 0;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 149) |= v4;
  v6 = m_conflicted_key_name[149];
  *((_DWORD *)m_conflicted_key_name + 46) = m_object;
  if ( !v5 )
    ++*(_DWORD *)m_conflicted_key_name;
  if ( v6 )
    v7 = 0;
  else
    v7 = *((_DWORD *)m_conflicted_key_name + 534);
  *((_DWORD *)m_conflicted_key_name + 534) = v7;
  *((_BYTE *)m_conflicted_key_name + 145) = v6;
  v8 = thisa->m_constants.m_object;
  v9 = m_conflicted_key_name;
  if ( *((const vostok::render::shader_constant_table **)m_conflicted_key_name + 51) != v8 )
  {
    ++*((_DWORD *)m_conflicted_key_name + 3);
    vostok::render::constants_handler<0>::assign(
      (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
      v8);
    v10 = *((_DWORD *)v9 + 571);
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v9 + 150) = 1;
    *((_DWORD *)v9 + 572) = v10;
  }
  v11 = thisa->m_textures.m_object;
  v12 = m_conflicted_key_name;
  if ( *((const vostok::render::res_texture_list **)m_conflicted_key_name + 52) != v11 )
  {
    ++*((_DWORD *)m_conflicted_key_name + 4);
    vostok::render::textures_handler<0>::assign(
      (vostok::render::textures_handler<0> *)(m_conflicted_key_name + 208),
      v11);
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)v12 + 151) = 1;
  }
  v13 = thisa->m_samplers.m_object;
  v14 = m_conflicted_key_name;
  if ( *((const vostok::render::res_sampler_list **)m_conflicted_key_name + 207) != v13 )
  {
    ++*((_DWORD *)m_conflicted_key_name + 5);
    vostok::render::samplers_handler<0>::assign(
      (vostok::render::samplers_handler<0> *)(m_conflicted_key_name + 756),
      v13);
    *((_BYTE *)v14 + 152) = 1;
  }
}
