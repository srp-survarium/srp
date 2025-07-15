unsigned int __userpurge vostok::render::vertex_buffer::lock@<eax>(
        vostok::render::vertex_buffer *this@<esi>,
        unsigned int v_stride@<edi>,
        unsigned int v_count,
        unsigned int *v_offset)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  survarium::game *m_game; // eax
  _DWORD v8[3]; // [esp+18h] [ebp-Ch] BYREF

  v4 = this->m_position / v_stride;
  this->m_lock_count = v_count;
  this->m_lock_stride = v_stride;
  v5 = v4 + 1;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  if ( v5 + v_count < this->m_size / v_stride )
  {
    this->m_position = v_stride * v5;
    *v_offset = v5;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, int, _DWORD, _DWORD *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y
                                                                              + 56))(
      m_game->m_game_world.m_mouse_pos.y,
      this->m_buffer.m_object->m_hardware_buffer,
      0,
      5,
      0,
      v8);
  }
  else
  {
    ++this->m_discard_id;
    this->m_position = 0;
    *v_offset = 0;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, int, _DWORD, _DWORD *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y
                                                                              + 56))(
      m_game->m_game_world.m_mouse_pos.y,
      this->m_buffer.m_object->m_hardware_buffer,
      0,
      4,
      0,
      v8);
  }
  return v8[0] + this->m_position;
}
