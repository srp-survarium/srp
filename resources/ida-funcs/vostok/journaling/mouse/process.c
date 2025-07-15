void __thiscall vostok::journaling::mouse::process(
        vostok::journaling::mouse *this,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  vostok::journaling::reader *v2; // ebx
  int v3; // edi
  unsigned __int8 v4; // al
  void **M_start; // ebx
  bool i; // zf
  unsigned int v7; // eax
  void **v8; // edi
  void **v9; // ebx
  vostok::journaling::data_chunk_type_enum v10; // [esp+0h] [ebp-20h]
  vostok::journaling::reader *v12; // [esp+10h] [ebp-10h] BYREF
  unsigned int v13; // [esp+14h] [ebp-Ch]
  void **M_finish; // [esp+18h] [ebp-8h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  while ( 1 )
  {
    vostok::journaling::journal::try_start_reading(
      (vostok::journaling::journal *)this,
      (int)vostok::core::g_journal.m_variable,
      &v12,
      (vostok::journaling::reader_ptr *)5,
      v10);
    v2 = v12;
    if ( !v12 )
      break;
    if ( vostok::journaling::reader::r<unsigned char>(v12) )
    {
      v3 = vostok::journaling::reader::r<unsigned char>(v2) + 337;
      v4 = vostok::journaling::reader::r<unsigned char>(v2);
      M_start = handlers->_M_impl._M_start;
      v13 = v4;
      M_finish = handlers->_M_impl._M_finish;
      for ( i = M_start == M_finish;
            !i
         && !(*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, unsigned int))(*(_DWORD *)*M_start
                                                                                                  + 8))(
               *M_start,
               this->m_world,
               v3,
               v13);
            i = M_start == M_finish )
      {
        ++M_start;
      }
    }
    else
    {
      v15 = vostok::journaling::reader::r<unsigned int>(v2);
      v13 = vostok::journaling::reader::r<unsigned int>(v2);
      v7 = vostok::journaling::reader::r<unsigned int>(v2);
      v8 = handlers->_M_impl._M_start;
      v9 = handlers->_M_impl._M_finish;
      M_finish = (void **)v7;
      while ( v8 != v9
           && !(*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, unsigned int, unsigned int, void **))(*(_DWORD *)*v8 + 12))(
                 *v8,
                 this->m_world,
                 v15,
                 v13,
                 M_finish) )
        ++v8;
    }
  }
}
