void __userpurge survarium::player_profile::deserialize(
        vostok::network_core::packet_reader *reader@<esi>,
        survarium::player_profile *this)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v3; // cl
  const unsigned __int8 *v5; // eax
  unsigned __int8 v6; // cl
  const unsigned __int8 *v7; // eax
  unsigned int v8; // edi
  const unsigned __int8 *v9; // eax
  survarium::player_profile *v10; // edx
  char v11; // di
  float *p_value; // eax
  int v13; // ebx
  const unsigned __int8 *v14; // edx
  unsigned __int8 v15; // cl
  const unsigned __int8 *v16; // edx
  const unsigned __int8 *v17; // eax
  unsigned __int8 v18; // dl
  const unsigned __int8 *v19; // ecx
  unsigned __int16 v20; // di
  int v21; // eax
  survarium::slot_serialize_mode_enum v22; // edx
  survarium::profile_slot *v23; // eax
  const unsigned __int8 *v24; // ecx
  unsigned int v25; // edi
  const unsigned __int8 *v26; // ecx
  unsigned __int16 v27; // di
  const unsigned __int8 *v28; // ecx
  unsigned int v29; // edx
  int v30; // [esp+Ch] [ebp-4h]
  survarium::player_profile *thisa; // [esp+14h] [ebp+4h]

  m_pointer = reader->m_pointer;
  v3 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  this->team = v3;
  v5 = reader->m_pointer;
  v6 = *v5;
  reader->m_pointer = v5 + 1;
  this->is_local = v6 != 0;
  v7 = reader->m_pointer;
  v8 = *v7;
  reader->m_pointer = v7 + 1;
  memcpy((unsigned __int8 *)this->profile_name, (unsigned __int8 *)v7 + 1, v8);
  reader->m_pointer += v8;
  this->profile_name[v8] = 0;
  v9 = reader->m_pointer;
  v10 = (survarium::player_profile *)*(unsigned __int16 *)v9;
  v11 = 0;
  reader->m_pointer = v9 + 2;
  thisa = v10;
  p_value = &this->boosters[0].value;
  v13 = 11;
  do
  {
    if ( ((1 << v11) & (unsigned int)thisa) != 0 )
    {
      v14 = reader->m_pointer;
      v15 = *v14;
      reader->m_pointer = v14 + 1;
      *((_BYTE *)p_value - 4) = v15;
      v16 = reader->m_pointer;
      v30 = *(_DWORD *)v16;
      reader->m_pointer = v16 + 4;
      *(_DWORD *)p_value = v30;
    }
    else
    {
      *((_BYTE *)p_value - 4) = 0;
      *p_value = 0.0;
    }
    ++v11;
    p_value += 2;
    --v13;
  }
  while ( v13 );
  while ( reader->m_pointer != &reader->m_packet->m_buffer[reader->m_packet->m_buffer_size] )
  {
    v17 = reader->m_pointer;
    v18 = *v17;
    v19 = v17 + 1;
    reader->m_pointer = v17 + 1;
    v20 = *(_WORD *)(v17 + 1);
    v21 = v18;
    v22 = slot_serialize_mode_125[v18];
    reader->m_pointer = v19 + 2;
    v23 = &this->slots[v21];
    v23->item.dict_id = v20;
    v24 = reader->m_pointer;
    v25 = *(_DWORD *)v24;
    reader->m_pointer = v24 + 4;
    v23->item.id = v25;
    if ( v22 == serialize_both_values || v22 == serialize_just_condition_stack_values )
    {
      v26 = reader->m_pointer;
      v27 = *(_WORD *)v26;
      reader->m_pointer = v26 + 2;
      v23->item.condition_or_stack = v27;
    }
    if ( v22 == serialize_both_values || v22 == serialize_just_amount_values )
    {
      v28 = reader->m_pointer;
      v29 = *(_DWORD *)v28;
      reader->m_pointer = v28 + 4;
      v23->item.amount_in_inventory = v29;
    }
  }
}
