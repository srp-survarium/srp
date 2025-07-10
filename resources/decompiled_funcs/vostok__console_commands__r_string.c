void __fastcall vostok::console_commands::r_string(int a1, vostok::memory::reader *F, char (*dest)[4096])
{
  const unsigned __int8 *m_pointer; // esi
  unsigned int v4; // eax

  m_pointer = F->m_pointer;
  v4 = vostok::console_commands::advance_term_string(a1, F);
  strncpy_s((char *)dest, 0x1000u, (const char *)m_pointer, v4);
}
