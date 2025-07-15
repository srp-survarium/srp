void __thiscall survarium::shop_items_container::deserialize(
        survarium::shop_items_container *this,
        vostok::network_core::buffer_reader *reader,
        int a3)
{
  const unsigned __int8 **v4; // esi
  const unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  vostok::network_core::buffer_reader **v7; // esi
  vostok::network_core::buffer_reader *v8; // ecx
  char *v9; // esi
  char v10; // cl
  vostok::network_core::buffer_reader *v11; // eax
  _BYTE *v12; // esi
  bool v13; // zf
  vostok::network_core::buffer_reader *v14; // [esp+18h] [ebp+Ch]
  unsigned __int8 v15; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v16; // [esp+1Bh] [ebp+Fh]

  v4 = *(const unsigned __int8 ***)(a3 + 4);
  v5 = *v4;
  *(_DWORD *)(a3 + 4) = v4 + 1;
  reader->m_buffer = v5;
  v6 = *(unsigned __int8 **)(a3 + 4);
  v15 = *v6;
  *(_DWORD *)(a3 + 4) = v6 + 1;
  reader->m_pointer = (const unsigned __int8 *)v15;
  v7 = *(vostok::network_core::buffer_reader ***)(a3 + 4);
  v14 = *v7;
  *(_DWORD *)(a3 + 4) = v7 + 1;
  reader->m_buffer_size = (const unsigned int)v14;
  vostok::network_core::buffer_reader::r_string(v14, (char *)a3, (unsigned __int8 *)&reader[1]);
  vostok::network_core::buffer_reader::r_string(v8, (char *)a3, (unsigned __int8 *)&reader[3].m_buffer_size);
  v9 = *(char **)(a3 + 4);
  v10 = *v9;
  *(_DWORD *)(a3 + 4) = v9 + 1;
  v11 = reader;
  LOBYTE(reader[6].m_pointer) = v10;
  v12 = *(_BYTE **)(a3 + 4);
  HIBYTE(v14) = *v12;
  *(_DWORD *)(a3 + 4) = v12 + 1;
  v13 = LOBYTE(reader[6].m_pointer) == 0;
  reader[21].m_buffer_size = HIBYTE(v14);
  v16 = 0;
  if ( !v13 )
  {
    do
    {
      survarium::shop_item::deserialize(
        (survarium::shop_item *)&v11[3 * v16++ + 6].m_buffer_size,
        (vostok::network_core::buffer_reader *)a3);
      v11 = reader;
    }
    while ( v16 < LOBYTE(reader[6].m_pointer) );
  }
}
