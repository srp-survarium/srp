void __fastcall vostok::buffer_vector<vostok::resources::request>::resize(
        int a1,
        unsigned int size,
        vostok::buffer_vector<vostok::resources::request> *this)
{
  vostok::resources::request *m_begin; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ebx
  vostok::resources::request *v6; // edi
  vostok::resources::request *v7; // eax
  vostok::resources::request *v8; // esi

  m_begin = this->m_begin;
  v4 = this->m_end - this->m_begin;
  if ( size != v4 )
  {
    if ( size >= v4 )
    {
      v5 = size;
      v6 = &m_begin[size];
      v7 = &m_begin[v4];
      if ( v7 != v6 )
      {
        do
        {
          v8 = v7 + 1;
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_begin);
          v7 = v8;
        }
        while ( v8 != v6 );
      }
      this->m_end = &this->m_begin[v5];
    }
    else
    {
      this->m_end = &m_begin[size];
    }
  }
}
