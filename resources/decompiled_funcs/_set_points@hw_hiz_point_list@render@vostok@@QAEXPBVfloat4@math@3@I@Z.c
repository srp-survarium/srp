void __thiscall vostok::render::hw_hiz_point_list::set_points(
        vostok::render::hw_hiz_point_list *this,
        vostok::render::hw_hiz_point_list *in_data,
        const vostok::math::float4 *culling_results_buffer_width,
        unsigned int culling_results_buffer_widtha)
{
  unsigned int v4; // esi
  int v5; // ecx
  float v7; // [esp+18h] [ebp-14h]
  float v8; // [esp+1Ch] [ebp-10h]
  _DWORD v9[3]; // [esp+20h] [ebp-Ch] BYREF

  (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, int, _DWORD, _DWORD *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                            + 56))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    in_data->m_vertex_buffer.m_object->m_hardware_buffer,
    0,
    4,
    0,
    v9);
  v4 = 0;
  if ( in_data->m_num_points )
  {
    v5 = v9[0];
    do
    {
      *(_QWORD *)v5 = *(_QWORD *)&culling_results_buffer_width->x;
      *(_QWORD *)(v5 + 8) = *(_QWORD *)&culling_results_buffer_width->elements[2];
      v7 = (float)(v4 % culling_results_buffer_widtha);
      v8 = (float)(v4 / culling_results_buffer_widtha);
      *(float *)(v5 + 16) = v7;
      *(float *)(v5 + 20) = v8;
      ++v4;
      ++culling_results_buffer_width;
      v5 += 24;
    }
    while ( v4 < in_data->m_num_points );
  }
  (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                     + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    in_data->m_vertex_buffer.m_object->m_hardware_buffer,
    0);
}
