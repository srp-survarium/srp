void __thiscall vostok::render::res_geometry::apply(vostok::render::res_geometry *this)
{
  vostok::render::res_declaration *m_object; // edx
  const char *m_conflicted_key_name; // eax
  vostok::render::untyped_buffer *v3; // esi
  unsigned int m_vb_stride; // edi
  bool v5; // dl
  vostok::render::untyped_buffer *v6; // ecx
  bool v7; // dl

  m_object = this->m_dcl.m_object;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((vostok::render::res_declaration **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 533) == m_object )
  {
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 145) = 0;
  }
  else
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) = m_object;
    *((_BYTE *)m_conflicted_key_name + 144) = 1;
    *((_DWORD *)m_conflicted_key_name + 534) = 0;
    *((_BYTE *)m_conflicted_key_name + 145) = 1;
  }
  v3 = this->m_vb.m_object;
  m_vb_stride = this->m_vb_stride;
  v5 = *((vostok::render::untyped_buffer **)m_conflicted_key_name + 42) != v3
    || m_vb_stride != *((_DWORD *)m_conflicted_key_name + 548)
    || *((_DWORD *)m_conflicted_key_name + 549);
  *((_BYTE *)m_conflicted_key_name + 140) |= v5;
  *((_DWORD *)m_conflicted_key_name + 42) = v3;
  *((_DWORD *)m_conflicted_key_name + 548) = m_vb_stride;
  *((_DWORD *)m_conflicted_key_name + 549) = 0;
  v6 = this->m_ib.m_object;
  v7 = *((vostok::render::untyped_buffer **)m_conflicted_key_name + 45) != v6
    || *((_DWORD *)m_conflicted_key_name + 554);
  *((_BYTE *)m_conflicted_key_name + 143) |= v7;
  *((_DWORD *)m_conflicted_key_name + 45) = v6;
  *((_DWORD *)m_conflicted_key_name + 554) = 0;
}
