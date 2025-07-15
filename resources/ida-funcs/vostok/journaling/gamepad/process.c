void __thiscall vostok::journaling::gamepad::process(
        vostok::journaling::gamepad *this,
        vostok::input::vector<vostok::input::handler *> *handlers)
{
  unsigned __int8 v2; // al
  void **M_start; // esi
  void **M_finish; // edi
  vostok::journaling::data_chunk_type_enum v5; // [esp+0h] [ebp-20h]
  vostok::journaling::reader *v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+14h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-8h]
  vostok::journaling::gamepad *v9; // [esp+1Ch] [ebp-4h]

  v9 = this;
  while ( 1 )
  {
    vostok::journaling::journal::try_start_reading(
      (vostok::journaling::journal *)this,
      (int)vostok::core::g_journal.m_variable,
      &v6,
      (vostok::journaling::reader_ptr *)4,
      v5);
    if ( !v6 )
      break;
    v8 = vostok::journaling::reader::r<unsigned char>(v6);
    v2 = vostok::journaling::reader::r<unsigned char>(v6);
    M_start = handlers->_M_impl._M_start;
    M_finish = handlers->_M_impl._M_finish;
    v7 = v2;
    while ( M_start != M_finish
         && !(*(unsigned __int8 (__thiscall **)(void *, vostok::input::world *, int, int))(*(_DWORD *)*M_start + 4))(
               *M_start,
               v9->m_world,
               v8,
               v7) )
      ++M_start;
  }
}
