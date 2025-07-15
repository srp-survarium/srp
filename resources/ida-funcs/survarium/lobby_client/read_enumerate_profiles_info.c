char __thiscall survarium::lobby_client::read_enumerate_profiles_info(
        survarium::lobby_client *this,
        vostok::network_core::buffer_reader *reader,
        int a3)
{
  char *v4; // esi
  char v5; // al
  vostok::network_core::buffer_reader **v6; // esi
  char *v7; // esi
  char v8; // cl
  char *v9; // esi
  const unsigned __int8 **v10; // esi
  const unsigned __int8 **v11; // esi
  const unsigned __int8 **v12; // esi
  const unsigned __int8 **v13; // esi
  const unsigned __int8 *v15; // [esp+Ch] [ebp-1Ch]
  const unsigned __int8 *v16; // [esp+10h] [ebp-18h]
  const unsigned __int8 *v17; // [esp+14h] [ebp-14h]
  const unsigned __int8 *v18; // [esp+18h] [ebp-10h]
  const unsigned __int8 **p_m_pointer; // [esp+1Ch] [ebp-Ch]
  vostok::network_core::buffer_reader *v20; // [esp+20h] [ebp-8h]
  char v21; // [esp+26h] [ebp-2h]
  char v22; // [esp+37h] [ebp+Fh]
  unsigned __int8 v23; // [esp+37h] [ebp+Fh]

  v4 = *(char **)(a3 + 4);
  v22 = *v4;
  *(_DWORD *)(a3 + 4) = v4 + 1;
  v5 = v22;
  LOBYTE(reader[50].m_buffer_size) = v22;
  v23 = 0;
  if ( v5 )
  {
    do
    {
      v6 = *(vostok::network_core::buffer_reader ***)(a3 + 4);
      v20 = *v6;
      *(_DWORD *)(a3 + 4) = v6 + 1;
      p_m_pointer = &reader[126 * v23 + 51].m_pointer;
      reader[126 * v23 + 51].m_buffer_size = (const unsigned int)v20;
      vostok::network_core::buffer_reader::r_string(v20, (char *)a3, (unsigned __int8 *)&reader[126 * v23 + 52]);
      v7 = *(char **)(a3 + 4);
      v8 = *v7;
      *(_DWORD *)(a3 + 4) = v7 + 1;
      *((_BYTE *)p_m_pointer + 1506) = v8;
      v9 = *(char **)(a3 + 4);
      v21 = *v9;
      *(_DWORD *)(a3 + 4) = v9 + 1;
      *((_BYTE *)p_m_pointer + 1507) = v21;
      v10 = *(const unsigned __int8 ***)(a3 + 4);
      v18 = *v10;
      *(_DWORD *)(a3 + 4) = v10 + 1;
      p_m_pointer[372] = v18;
      v11 = *(const unsigned __int8 ***)(a3 + 4);
      v17 = *v11;
      *(_DWORD *)(a3 + 4) = v11 + 1;
      p_m_pointer[374] = v17;
      v12 = *(const unsigned __int8 ***)(a3 + 4);
      v16 = *v12;
      *(_DWORD *)(a3 + 4) = v12 + 1;
      p_m_pointer[373] = v16;
      v13 = *(const unsigned __int8 ***)(a3 + 4);
      ++v23;
      v15 = *v13;
      *(_DWORD *)(a3 + 4) = v13 + 1;
      p_m_pointer[375] = v15;
    }
    while ( v23 < LOBYTE(reader[50].m_buffer_size) );
  }
  return 1;
}
