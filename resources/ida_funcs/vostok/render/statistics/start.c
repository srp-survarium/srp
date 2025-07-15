void __usercall vostok::render::statistics::start(vostok::render::statistics *this@<ecx>, int *a2@<eax>)
{
  int i; // edi
  _DWORD *v3; // esi
  const char *m_conflicted_key_name; // eax

  for ( i = *a2; i; i = *(_DWORD *)(i + 144) )
  {
    v3 = *(_DWORD **)i;
    if ( *(_DWORD *)i )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD *))(*v3 + 4))(v3);
        v3 = (_DWORD *)v3[36];
      }
      while ( v3 );
    }
  }
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 21) = 0;
  *((_DWORD *)m_conflicted_key_name + 22) = 0;
  *((_DWORD *)m_conflicted_key_name + 23) = 0;
  *((_DWORD *)m_conflicted_key_name + 25) = 0;
}
