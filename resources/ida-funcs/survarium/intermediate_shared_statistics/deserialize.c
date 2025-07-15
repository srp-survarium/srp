void __fastcall survarium::intermediate_shared_statistics::deserialize(
        int a1,
        vostok::network_core::buffer_reader *reader,
        survarium::intermediate_shared_statistics *this,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  bool v6; // zf
  const unsigned __int8 *v7; // esi
  float v8; // xmm0_4
  const unsigned __int8 *v9; // esi
  const unsigned __int8 *v10; // esi
  int v11; // [esp+Ch] [ebp-8h]
  unsigned __int8 v12; // [esp+13h] [ebp-1h]
  char v13; // [esp+13h] [ebp-1h]
  unsigned __int8 v14; // [esp+13h] [ebp-1h]
  int v15; // [esp+1Ch] [ebp+8h]
  unsigned __int8 v16; // [esp+1Fh] [ebp+Bh]
  unsigned __int8 v17; // [esp+1Fh] [ebp+Bh]
  char v18; // [esp+1Fh] [ebp+Bh]
  unsigned __int8 v19; // [esp+23h] [ebp+Fh]

  m_pointer = reader->m_pointer;
  v16 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  v12 = v16;
  memset(this, 0, 0x50u);
  if ( v16 )
  {
    do
    {
      v6 = v12-- == 1;
      v7 = reader->m_pointer;
      v17 = *v7;
      reader->m_pointer = v7 + 1;
      v8 = *(float *)(v7 + 1);
      reader->m_pointer = v7 + 5;
      this->received_damage.elems[v17] = v8;
    }
    while ( !v6 );
  }
  v13 = *reader->m_pointer++;
  v18 = v13;
  memset(&this->last_hit_ms, 0, sizeof(this->last_hit_ms));
  if ( v13 )
  {
    do
    {
      --v18;
      v9 = reader->m_pointer;
      v14 = *v9;
      reader->m_pointer = v9 + 1;
      v11 = *(_DWORD *)(v9 + 1);
      reader->m_pointer = v9 + 5;
      this->last_hit_ms.elems[v14] = v11 != 0 ? time_offset + v11 : 0;
    }
    while ( v18 );
  }
  v10 = reader->m_pointer;
  v15 = *(_DWORD *)v10;
  reader->m_pointer = v10 + 4;
  this->last_killed_enemy_ms = v15 != 0 ? time_offset + v15 : 0;
  v19 = *reader->m_pointer++;
  this->last_hit_enemy_id = v19;
}
