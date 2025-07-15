void __thiscall vostok::journaling::keyboard::process(
        vostok::journaling::keyboard *this,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  int v2; // edi
  unsigned __int8 v3; // al
  void **M_start; // esi
  bool i; // zf
  vostok::journaling::data_chunk_type_enum v6; // [esp+0h] [ebp-20h]
  vostok::journaling::reader *v7; // [esp+10h] [ebp-10h] BYREF
  int v8; // [esp+14h] [ebp-Ch]
  vostok::journaling::keyboard *v9; // [esp+18h] [ebp-8h]
  void **M_finish; // [esp+1Ch] [ebp-4h]

  v9 = this;
  while ( 1 )
  {
    vostok::journaling::journal::try_start_reading(
      (vostok::journaling::journal *)this,
      (int)vostok::core::g_journal.m_variable,
      &v7,
      (vostok::journaling::reader_ptr *)3,
      v6);
    if ( !v7 )
      break;
    v2 = vostok::journaling::reader::r<unsigned char>(v7);
    v3 = vostok::journaling::reader::r<unsigned char>(v7);
    M_start = handlers->_M_impl._M_start;
    v8 = v3;
    M_finish = handlers->_M_impl._M_finish;
    for ( i = M_start == M_finish;
          !i
       && !(**(unsigned __int8 (__thiscall ***)(void *, vostok::input::world *, int, int))*M_start)(
             *M_start,
             v9->m_world,
             v2,
             v8);
          i = M_start == M_finish )
    {
      ++M_start;
    }
  }
}
