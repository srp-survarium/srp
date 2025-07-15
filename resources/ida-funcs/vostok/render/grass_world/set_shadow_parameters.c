void __usercall vostok::render::grass_world::set_shadow_parameters(
        vostok::render::grass_world *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax
  int v3; // ecx
  const char *m_conflicted_key_name; // esi
  int v5; // ecx
  char src_ptr[4]; // [esp+0h] [ebp-4h] BYREF

  *(_DWORD *)src_ptr = this;
  v2 = *(_DWORD *)(a2 + 348);
  v3 = *(_DWORD *)(v2 + 40);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *(_DWORD *)src_ptr = 0;
  if ( v3 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573) )
  {
    v5 = *(unsigned __int16 *)(v2 + 20);
    if ( v5 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v2 + 22),
        (unsigned __int8)*(_WORD *)(v2 + 16),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * v5),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
