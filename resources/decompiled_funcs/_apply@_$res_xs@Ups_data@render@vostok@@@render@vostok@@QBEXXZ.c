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
