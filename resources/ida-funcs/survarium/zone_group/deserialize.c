void __thiscall survarium::zone_group::deserialize(
        survarium::zone_group *this,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  vostok::network_core::buffer_reader *v4; // edx
  const unsigned __int8 *m_pointer; // esi
  unsigned int v6; // eax
  const unsigned __int8 *v7; // esi
  survarium::damage_zone_core *v8; // esi
  void **M_start; // esi
  void **M_finish; // ebx
  int v11; // [esp+8h] [ebp-14h]
  int v12; // [esp+Ch] [ebp-10h]
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]
  unsigned __int8 v16; // [esp+1Ah] [ebp-2h]
  char v17; // [esp+1Bh] [ebp-1h]

  if ( this->keep_all_zones_active )
    goto LABEL_14;
  v4 = reader;
  m_pointer = reader->m_pointer;
  v12 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_next_recharge_time = v12 != 0 ? time_offset + v12 : 0;
  v6 = this->zones._M_impl._M_finish - this->zones._M_impl._M_start;
  v13 = v6;
  v15 = 0;
  v14 = 0;
  v11 = (v6 >> 3) + ((v6 & 7) != 0);
  if ( !v11 )
    goto LABEL_14;
  while ( v15 != v6 )
  {
    v7 = v4->m_pointer;
    v16 = *v7;
    v4->m_pointer = v7 + 1;
    v17 = 0;
    while ( v15 != v6 )
    {
      v8 = (survarium::damage_zone_core *)this->zones._M_impl._M_start[v15];
      if ( ((unsigned __int8)(1 << v17) & v16) != 0 )
      {
        if ( !v8->m_is_active )
        {
          this->owner->owner->activate_damage_zone(this->owner->owner, v8, 1);
LABEL_11:
          v6 = v13;
        }
      }
      else if ( v8->m_is_active )
      {
        this->owner->owner->deactivate_damage_zone(this->owner->owner, v8, 1);
        goto LABEL_11;
      }
      ++v17;
      ++v15;
      v4 = reader;
      if ( v17 == 8 )
        break;
    }
    if ( ++v14 == v11 )
      break;
  }
LABEL_14:
  M_start = this->zones._M_impl._M_start;
  M_finish = this->zones._M_impl._M_finish;
  while ( M_start != M_finish )
  {
    if ( *((_BYTE *)*M_start + 292) )
      (*(void (__thiscall **)(int, vostok::network_core::buffer_reader *, unsigned int))(*((_DWORD *)*M_start + 82) + 4))(
        (int)*M_start + 328,
        reader,
        time_offset);
    ++M_start;
  }
}
