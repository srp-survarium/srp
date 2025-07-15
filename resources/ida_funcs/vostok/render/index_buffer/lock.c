unsigned __int16 *__userpurge vostok::render::index_buffer::lock@<eax>(
        vostok::render::index_buffer *this@<esi>,
        unsigned int *i_offset@<edi>,
        unsigned int i_count)
{
  unsigned int v3; // eax
  int v4; // ecx
  unsigned int m_position; // eax
  int v6; // ecx
  _DWORD v8[3]; // [esp+18h] [ebp-Ch] BYREF

  v3 = 2 * (i_count + this->m_position);
  *i_offset = 0;
  v4 = 5;
  if ( v3 >= this->m_size )
  {
    ++this->m_discard_id;
    this->m_position = 0;
    v4 = 4;
  }
  (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, int, _DWORD, _DWORD *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                            + 56))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    this->m_buffer.m_object->m_hardware_buffer,
    0,
    v4,
    0,
    v8);
  m_position = this->m_position;
  v6 = v8[0];
  *i_offset = m_position;
  this->m_lock_size = i_count;
  return (unsigned __int16 *)(v6 + 2 * m_position);
}
