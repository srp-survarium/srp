HRESULT __userpurge vostok::render::res_xs_hw<vostok::render::gs_data>::create_hw_shader@<eax>(
        ID3D10Blob *shader_code@<eax>,
        vostok::render::res_xs_hw<vostok::render::gs_data> *this,
        ID3D11GeometryShader **hardware_shader)
{
  void *v4; // edi
  unsigned int v5; // eax

  v4 = shader_code->GetBufferPointer(shader_code);
  v5 = shader_code->GetBufferSize(shader_code);
  return (*(int (__stdcall **)(int, void *, unsigned int, _DWORD, vostok::render::res_xs_hw<vostok::render::gs_data> *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x + 52))(
           `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
           v4,
           v5,
           0,
           this);
}
