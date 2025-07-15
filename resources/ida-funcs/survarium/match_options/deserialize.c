void __thiscall survarium::match_options::deserialize(
        survarium::match_options *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *a3)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // esi
  unsigned int v6; // ecx
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // esi
  const unsigned __int8 *v9; // esi
  unsigned __int16 v10; // ax
  const unsigned __int8 *v12; // esi
  const unsigned __int8 *v13; // esi
  const unsigned __int8 *v14; // xmm0_4
  const unsigned __int8 *v15; // esi
  const unsigned __int8 *v16; // esi
  const unsigned __int8 *v17; // esi
  vostok::network_core::buffer_reader *v18; // eax
  vostok::network_core::buffer_reader *v19; // edx
  const unsigned __int8 *v20; // esi
  const unsigned __int8 *v21; // eax
  vostok::network_core::buffer_reader *v22; // esi
  const unsigned __int8 *v23; // [esp+14h] [ebp+8h]
  __int16 v24; // [esp+14h] [ebp+8h]
  unsigned __int8 v25; // [esp+17h] [ebp+Bh]
  vostok::network_core::buffer_reader *i; // [esp+18h] [ebp+Ch]
  unsigned __int8 v27; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v28; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v29; // [esp+1Bh] [ebp+Fh]

  m_pointer = a3->m_pointer;
  LOBYTE(this) = *m_pointer;
  a3->m_pointer = m_pointer + 1;
  LOBYTE(reader[2480].m_pointer) = (_BYTE)this;
  vostok::network_core::buffer_reader::r_string(
    (vostok::network_core::buffer_reader *)this,
    (char *)a3,
    (unsigned __int8 *)&reader[2482].m_pointer);
  v5 = a3->m_pointer;
  v6 = *v5;
  a3->m_pointer = v5 + 1;
  reader[2480].m_buffer_size = v6;
  v7 = a3->m_pointer;
  v27 = *v7;
  a3->m_pointer = v7 + 1;
  LOBYTE(reader[2481].m_buffer) = v27;
  v8 = a3->m_pointer;
  v28 = *v8;
  a3->m_pointer = v8 + 1;
  HIBYTE(reader[2481].m_buffer_size) = v28;
  v9 = a3->m_pointer;
  v29 = *v9;
  a3->m_pointer = v9 + 1;
  BYTE1(reader[2481].m_buffer) = v29;
  v10 = vostok::network_core::buffer_reader::r<unsigned short>(a3);
  HIWORD(reader[2481].m_buffer) = v10;
  v12 = a3->m_pointer;
  v23 = *(const unsigned __int8 **)v12;
  a3->m_pointer = v12 + 4;
  reader[2480].m_buffer = v23;
  v13 = a3->m_pointer;
  v14 = *(const unsigned __int8 **)v13;
  a3->m_pointer = v13 + 4;
  reader[2481].m_pointer = v14;
  v15 = a3->m_pointer;
  HIBYTE(v23) = *v15;
  a3->m_pointer = v15 + 1;
  LOBYTE(reader[2481].m_buffer_size) = HIBYTE(v23);
  v16 = a3->m_pointer;
  HIBYTE(v23) = *v16;
  a3->m_pointer = v16 + 1;
  BYTE1(reader[2481].m_buffer_size) = HIBYTE(v23);
  v17 = a3->m_pointer;
  HIBYTE(v23) = *v17;
  a3->m_pointer = v17 + 1;
  BYTE2(reader[2481].m_buffer_size) = HIBYTE(v23);
  v18 = reader + 2485;
  v19 = (vostok::network_core::buffer_reader *)((char *)reader + 29862);
  while ( v18 != v19 )
  {
    v24 = *(_WORD *)a3->m_pointer;
    a3->m_pointer += 2;
    LOWORD(v18->m_buffer) = v24;
    v18 = (vostok::network_core::buffer_reader *)((char *)v18 + 2);
  }
  for ( i = 0; (unsigned int)i < LOBYTE(reader[2481].m_buffer); *((_BYTE *)&v22->m_buffer + (_DWORD)v19) = v25 )
  {
    v20 = a3->m_pointer;
    v21 = v20 + 1;
    v25 = *v20;
    v22 = i;
    i = (vostok::network_core::buffer_reader *)((char *)i + 1);
    a3->m_pointer = v21;
  }
}
