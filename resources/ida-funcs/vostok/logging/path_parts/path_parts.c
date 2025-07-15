void __usercall vostok::logging::path_parts::path_parts(vostok::logging::path_parts *this@<ecx>, _DWORD *a2@<esi>)
{
  a2[7] = 0;
  a2[8] = 0;
  *a2 = a2 + 3;
  a2[1] = a2 + 3;
  a2[2] = a2 + 7;
  if ( LOBYTE(this->m_parts.m_begin) != 58 )
    vostok::logging::path_parts::add_part(this, a2, (char *)this);
  vostok::logging::path_parts::add_part(this, a2, 0);
}
