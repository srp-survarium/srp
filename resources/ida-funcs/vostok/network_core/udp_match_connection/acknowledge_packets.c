void __userpurge vostok::network_core::udp_match_connection::acknowledge_packets(
        vostok::network_core::udp_match_connection *this@<ecx>,
        _DWORD *a2@<esi>,
        const vostok::network_core::sequence_number<unsigned short> local_sequence_id,
        signed __int64 acknowledgement_bits)
{
  sequence_id_predicate *v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  _DWORD v9[2]; // [esp+8h] [ebp-1Ch] BYREF
  unsigned __int16 v10; // [esp+10h] [ebp-14h]
  int v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+18h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-8h]
  unsigned __int16 m_number; // [esp+20h] [ebp-4h]

  m_number = local_sequence_id.m_number;
  while ( acknowledgement_bits )
  {
    v4 = (sequence_id_predicate *)(HIDWORD(acknowledgement_bits) & 0x80000000);
    if ( acknowledgement_bits < 0 )
    {
      v11 = a2[665];
      v9[0] = a2[696];
      v10 = m_number;
      v5 = a2[667];
      v9[1] = uri;
      if ( v5 )
      {
        v13 = 0;
        v12 = 0;
        v6 = v5;
        do
        {
          v7 = *(_DWORD *)(v6 + 60);
          if ( sequence_id_predicate::operator()(
                 v4,
                 (vostok::network_core::udp_match_packet *)v9,
                 (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node *)v6) )
          {
            if ( !v12 )
              v12 = v6;
            v8 = v13;
            --a2[665];
            if ( v8 )
              *(_DWORD *)(v8 + 60) = v7;
            else
              a2[667] = v7;
          }
          else
          {
            v13 = v6;
          }
          v6 = v7;
        }
        while ( v7 );
        a2[668] = v13;
      }
      a2[656] += a2[665] - v11;
    }
    --m_number;
    acknowledgement_bits *= 2LL;
  }
}
