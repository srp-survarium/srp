void __userpurge vostok::console_commands::save_storage::save_to(
        vostok::memory::writer *f@<esi>,
        vostok::console_commands::save_storage *this)
{
  const void **M_start; // ebx
  const void **M_finish; // edi
  int v4; // eax
  int i; // ecx
  const void **v6; // edi
  const void **v7; // ebp

  M_start = this->m_lines._M_impl._M_start;
  M_finish = this->m_lines._M_impl._M_finish;
  if ( this->m_lines._M_impl._M_start != M_finish )
  {
    v4 = M_finish - M_start;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
      (bool (__cdecl *)(const char *, const char *))M_finish,
      (const char **)M_start,
      (const char **)M_finish,
      0,
      2 * i,
      vostok::strings::less);
    stlp_std::priv::__final_insertion_sort<char const * *,bool (__cdecl *)(char const *,char const *)>(
      (const char **)M_start,
      (bool (__cdecl *)(const char *, const char *))M_start,
      (const char **)M_finish);
  }
  v6 = this->m_lines._M_impl._M_start;
  v7 = this->m_lines._M_impl._M_finish;
  if ( this->m_lines._M_impl._M_start != v7 )
  {
    do
    {
      f->write(f, *v6, strlen((const char *)*v6));
      f->write(f, "\r\n", 2u);
      ++v6;
    }
    while ( v6 != v7 );
  }
}
