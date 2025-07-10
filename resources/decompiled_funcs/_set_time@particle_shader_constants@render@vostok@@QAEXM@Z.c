void __userpurge vostok::render::particle_shader_constants::set_time(
        vostok::render::particle_shader_constants *this@<ecx>,
        int a2@<eax>,
        float time)
{
  int v3; // eax
  const char *m_conflicted_key_name; // esi
  int v5; // ecx

  v3 = *(_DWORD *)(a2 + 16);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *(_DWORD *)(v3 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                               + 573) )
  {
    v5 = *(unsigned __int16 *)(v3 + 20);
    if ( v5 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v3 + 22),
        (unsigned __int8)*(_WORD *)(v3 + 16),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * v5),
        (const char *)&time);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
