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
