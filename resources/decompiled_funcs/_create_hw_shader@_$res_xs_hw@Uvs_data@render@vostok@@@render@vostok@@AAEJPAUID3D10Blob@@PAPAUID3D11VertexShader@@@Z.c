HRESULT __userpurge vostok::render::res_xs_hw<vostok::render::vs_data>::create_hw_shader@<eax>(
        vostok::render::res_xs_hw<vostok::render::vs_data> *this@<edi>,
        ID3D10Blob *shader_code@<esi>,
        ID3D11VertexShader **hardware_shader)
{
  void *v3; // ebx
  unsigned int v4; // ebp
  vostok::render::resource_manager *signature; // eax
  const vostok::render::res_signature *v6; // ecx
  const vostok::render::res_signature *m_object; // eax

  v3 = shader_code->GetBufferPointer(shader_code);
  v4 = shader_code->GetBufferSize(shader_code);
  signature = vostok::render::resource_manager::create_signature(
                shader_code,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v6 = 0;
  if ( signature )
  {
    ++signature->sh_created;
    v6 = (const vostok::render::res_signature *)signature;
  }
  m_object = this->m_shader_data.signature.m_object;
  this->m_shader_data.signature.m_object = v6;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  return (*(int (__stdcall **)(int, void *, unsigned int, _DWORD, ID3D11VertexShader **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x
                                                                                        + 48))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           v3,
           v4,
           0,
           hardware_shader);
}
