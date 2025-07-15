void __thiscall vostok::network_core::udp_match_connection::update_acknowledgements(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::sequence_number<unsigned short> remote_sequence_id,
        vostok::network_core::sequence_number<unsigned short> local_sequence_id,
        unsigned __int16 local_acknowledgement_bits)
{
  survarium::game_camera *v4; // ecx
  vostok::network_core::udp_match_connection *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  survarium::game_camera *v8; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  const vostok::variant<32> **v10; // eax
  int v11; // [esp+4h] [ebp-CCh]
  int v12; // [esp+Ch] [ebp-C4h]
  const char *v14; // [esp+38h] [ebp-98h]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *v15; // [esp+3Ch] [ebp-94h]
  unsigned __int16 v16; // [esp+42h] [ebp-8Eh] BYREF
  const vostok::network_core::sequence_number<unsigned short> *v17; // [esp+44h] [ebp-8Ch]
  unsigned __int16 *v18; // [esp+48h] [ebp-88h]
  survarium::game_camera *p_m_received_local_sequence_id; // [esp+4Ch] [ebp-84h]
  unsigned int v20; // [esp+50h] [ebp-80h]
  unsigned int max_local_sequence_difference; // [esp+54h] [ebp-7Ch]
  const char *m_logging_id; // [esp+70h] [ebp-60h]
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *m_packets_allocator; // [esp+74h] [ebp-5Ch]
  unsigned __int16 m_number; // [esp+7Ah] [ebp-56h] BYREF
  const vostok::network_core::sequence_number<unsigned short> *p_m_sequence_id; // [esp+7Ch] [ebp-54h]
  unsigned __int16 *v26; // [esp+80h] [ebp-50h]
  vostok::network_core::sequence_number<unsigned short> *p_m_remote_sequence_id; // [esp+84h] [ebp-4Ch]
  sequence_id_predicate v28; // [esp+8Ch] [ebp-44h] BYREF
  char v29; // [esp+9Ah] [ebp-36h]
  char v30; // [esp+9Bh] [ebp-35h]
  sequence_id_predicate v31; // [esp+A0h] [ebp-30h] BYREF
  char v32; // [esp+AEh] [ebp-22h]
  char v33; // [esp+AFh] [ebp-21h]
  const vostok::variant<32> **v34; // [esp+B0h] [ebp-20h]
  vostok::network_core::sequence_number<unsigned short> sequence_id; // [esp+B4h] [ebp-1Ch]
  unsigned int unacknowledged_packets_size; // [esp+B8h] [ebp-18h]
  unsigned int difference; // [esp+BCh] [ebp-14h]
  unsigned int local_sequence_difference; // [esp+C0h] [ebp-10h]
  unsigned int remote_sequence_difference; // [esp+C4h] [ebp-Ch]
  unsigned __int16 acknowledgement_bits; // [esp+C8h] [ebp-8h]
  unsigned __int16 last_local_acknowledgement_bits; // [esp+CCh] [ebp-4h]

  v33 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  remote_sequence_difference = vostok::network_core::operator-<unsigned short>(
                                 &remote_sequence_id,
                                 &this->m_remote_sequence_id);
  if ( remote_sequence_difference >= 0x10 )
    LOWORD(v12) = 0;
  else
    v12 = (int)this->m_remote_acknowledgement_bits >> remote_sequence_difference;
  this->m_remote_acknowledgement_bits = v12;
  this->m_remote_acknowledgement_bits |= 0x8000u;
  p_m_remote_sequence_id = &this->m_remote_sequence_id;
  this->m_remote_sequence_id = remote_sequence_id;
  if ( !vostok::network_core::sequence_number<unsigned short>::operator<(&this->m_local_sequence_id, &local_sequence_id) )
  {
    v32 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    if ( vostok::network_core::sequence_number<unsigned short>::operator<=(
           &local_sequence_id,
           &this->m_received_local_sequence_id) )
    {
      difference = vostok::network_core::operator-<unsigned short>(
                     &this->m_received_local_sequence_id,
                     &local_sequence_id);
      if ( difference )
      {
        if ( difference <= 0xF )
        {
          v5 = this;
          this->m_received_local_acknowledgement_bits |= 1 << (15 - difference);
        }
        unacknowledged_packets_size = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                      (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v5,
                                                      (int)&this->m_unacknowledged_packets);
        v26 = &m_number;
        m_number = local_sequence_id.m_number;
        m_logging_id = this->m_logging_id;
        m_packets_allocator = this->m_packets_allocator;
        survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v31);
        v31.m_packets_allocator = m_packets_allocator;
        v31.m_logging_id = m_logging_id;
        p_m_sequence_id = &v31.m_sequence_id;
        v31.m_sequence_id.m_number = m_number;
        vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<sequence_id_predicate>(
          &this->m_unacknowledged_packets,
          &v31);
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v31);
        v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
               v6,
               (int)&this->m_unacknowledged_packets);
        this->m_stats.unacknowledged_packets -= unacknowledged_packets_size - (_DWORD)v7;
      }
    }
    else
    {
      local_sequence_difference = vostok::network_core::operator-<unsigned short>(
                                    &local_sequence_id,
                                    &this->m_received_local_sequence_id);
      if ( local_sequence_difference >= 0x10 )
        LOWORD(v11) = 0;
      else
        v11 = (int)this->m_received_local_acknowledgement_bits >> local_sequence_difference;
      last_local_acknowledgement_bits = v11;
      if ( (unsigned __int16)(local_acknowledgement_bits & v11) == (unsigned __int16)v11 )
      {
        v20 = local_sequence_difference;
        max_local_sequence_difference = this->m_stats.max_local_sequence_difference;
        v8 = (survarium::game_camera *)(max_local_sequence_difference
                                      - (max_local_sequence_difference < local_sequence_difference
                                       ? max_local_sequence_difference - local_sequence_difference
                                       : 0));
        this->m_stats.max_local_sequence_difference = (unsigned int)v8;
        LOWORD(v8) = local_acknowledgement_bits;
        this->m_received_local_acknowledgement_bits = local_acknowledgement_bits;
        v30 = 0;
        survarium::weapon_user_dead_state::finalize(v8);
        p_m_received_local_sequence_id = (survarium::game_camera *)&this->m_received_local_sequence_id;
        this->m_received_local_sequence_id = local_sequence_id;
        v29 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_received_local_sequence_id);
        acknowledgement_bits = last_local_acknowledgement_bits ^ this->m_received_local_acknowledgement_bits;
        sequence_id.m_number = local_sequence_id.m_number;
        while ( acknowledgement_bits )
        {
          if ( (acknowledgement_bits & 0x8000) != 0 )
          {
            v34 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                    (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)acknowledgement_bits,
                    (int)&this->m_unacknowledged_packets);
            v18 = &v16;
            v16 = sequence_id.m_number;
            v14 = this->m_logging_id;
            v15 = this->m_packets_allocator;
            survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v28);
            v28.m_packets_allocator = v15;
            v28.m_logging_id = v14;
            v17 = &v28.m_sequence_id;
            v28.m_sequence_id.m_number = v16;
            vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<sequence_id_predicate>(
              &this->m_unacknowledged_packets,
              &v28);
            survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v28);
            v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                    v9,
                    (int)&this->m_unacknowledged_packets);
            this->m_stats.unacknowledged_packets -= (char *)v34 - (char *)v10;
          }
          --sequence_id.m_number;
          acknowledgement_bits *= 2;
        }
      }
    }
  }
}
