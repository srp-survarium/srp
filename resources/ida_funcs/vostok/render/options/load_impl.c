void __usercall vostok::render::options::load_impl(
        vostok::memory::reader *F@<esi>,
        int a2@<ecx>,
        vostok::render::options *this)
{
  const unsigned __int8 *m_pointer; // edi
  unsigned int v4; // eax
  char _Dst[4096]; // [esp+8h] [ebp-1000h] BYREF

  while ( 1 )
  {
    m_pointer = F->m_pointer;
    if ( m_pointer - F->m_data >= F->m_size )
      break;
    v4 = vostok::render::advance_term_string(a2, F);
    strncpy_s(_Dst, 0x1000u, (const char *)m_pointer, v4);
    vostok::console_commands::execute(_Dst, execution_filter_all);
  }
}
