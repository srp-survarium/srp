char __userpurge vostok::network_core::udp_match_connection::update_acknowledgements@<al>(
        vostok::network_core::udp_match_connection *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::sequence_number<unsigned short> remote_sequence_id,
        vostok::network_core::sequence_number<unsigned short> local_sequence_id,
        signed __int64 local_acknowledgement_bits)
{
  unsigned __int16 m_number; // bx
  vostok::network_core::sequence_number<unsigned short> *v7; // edi
  unsigned int v9; // eax
  __int64 v10; // rax
  unsigned int v11; // eax
  __int64 v12; // rax
  unsigned int v13; // eax
  unsigned int v14; // ebx
  vostok::network_core::udp_match_connection *v15; // ecx
  __int64 v16; // rax
  unsigned int v17; // eax
  signed __int64 v18; // kr00_8
  unsigned __int16 v19; // bx
  __int16 v20; // [esp-2h] [ebp-22h]
  __int64 v21; // [esp+10h] [ebp-10h]

  m_number = remote_sequence_id.m_number;
  v7 = (vostok::network_core::sequence_number<unsigned short> *)(a2 + 2842);
  if ( remote_sequence_id.m_number == *(_WORD *)(a2 + 2842) )
    return 0;
  if ( vostok::network_core::sequence_number<unsigned short>::operator<(
         (vostok::network_core::sequence_number<unsigned short> *)(a2 + 2842),
         &remote_sequence_id.m_number) )
  {
    v9 = vostok::network_core::operator-<unsigned short>(v7, &remote_sequence_id);
    if ( v9 >= 0x40 )
      v10 = 0;
    else
      v10 = 1LL << (63 - (unsigned __int8)v9);
    if ( v10 && (v10 | *(_QWORD *)(a2 + 2824)) == v10 )
      return 0;
    *(_QWORD *)(a2 + 2824) |= v10;
  }
  else
  {
    v11 = vostok::network_core::operator-<unsigned short>(&remote_sequence_id, v7);
    if ( v11 >= 0x40 )
      v12 = 0;
    else
      v12 = *(_QWORD *)(a2 + 2824) >> v11;
    *(_DWORD *)(a2 + 2828) = HIDWORD(v12);
    *(_DWORD *)(a2 + 2828) |= 0x80000000;
    *(_DWORD *)(a2 + 2824) = v12;
    v7->m_number = m_number;
  }
  if ( !vostok::network_core::sequence_number<unsigned short>::operator<(
          &local_sequence_id,
          (unsigned __int16 *)(a2 + 2840)) )
  {
    if ( (unsigned __int8)vostok::network_core::sequence_number<unsigned short>::operator<=(
                            (vostok::network_core::sequence_number<unsigned short> *)(a2 + 2844),
                            &local_sequence_id.m_number) )
    {
      v13 = vostok::network_core::operator-<unsigned short>(
              (vostok::network_core::sequence_number<unsigned short> *)(a2 + 2844),
              &local_sequence_id);
      v14 = v13;
      HIWORD(v15) = v20;
      if ( v13 )
      {
        if ( v13 < 0x40 )
        {
          HIWORD(v15) = HIWORD(v13);
          v16 = *(_QWORD *)(a2 + 2832) << v13;
        }
        else
        {
          v16 = 0;
        }
        local_acknowledgement_bits ^= v16;
        if ( v14 < 0x40 )
        {
          v15 = (vostok::network_core::udp_match_connection *)(63 - v14);
          *(_QWORD *)(a2 + 2832) |= 1LL << (63 - (unsigned __int8)v14);
        }
        LOWORD(v15) = local_sequence_id;
        vostok::network_core::udp_match_connection::acknowledge_packets(
          v15,
          (_DWORD *)a2,
          local_sequence_id,
          local_acknowledgement_bits);
      }
    }
    else
    {
      v17 = vostok::network_core::operator-<unsigned short>(
              &local_sequence_id,
              (const vostok::network_core::sequence_number<unsigned short> *)(a2 + 2844));
      if ( v17 >= 0x40 )
        v21 = 0;
      else
        v21 = *(_QWORD *)(a2 + 2832) >> v17;
      v18 = local_acknowledgement_bits;
      if ( (local_acknowledgement_bits & v21) == v21 )
      {
        *(_DWORD *)(a2 + 2620) -= *(_DWORD *)(a2 + 2620) < v17 ? *(_DWORD *)(a2 + 2620) - v17 : 0;
        *(_DWORD *)(a2 + 2832) = v18;
        v19 = local_sequence_id.m_number;
        *(_DWORD *)(a2 + 2836) = HIDWORD(v18);
        *(_WORD *)(a2 + 2844) = v19;
        vostok::network_core::udp_match_connection::acknowledge_packets(
          (vostok::network_core::udp_match_connection *)(HIDWORD(v21) ^ *(_DWORD *)(a2 + 2836)),
          (_DWORD *)a2,
          (const vostok::network_core::sequence_number<unsigned short>)v19,
          v21 ^ *(_QWORD *)(a2 + 2832));
      }
    }
  }
  return 1;
}
