void __thiscall survarium::body_part_parameters::serialize(
        survarium::body_part_parameters *this,
        vostok::network_core::udp_match_packet *packet,
        int client_offset)
{
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::udp_match_packet &,stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> const &,int),boost::_bi::list3<boost::reference_wrapper<vostok::network_core::udp_match_packet>,boost::arg<1>,boost::_bi::value<int> > > v4; // [esp+Ch] [ebp-5Ch] BYREF
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *i; // [esp+18h] [ebp-50h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *m_begin; // [esp+38h] [ebp-30h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *m_end; // [esp+3Ch] [ebp-2Ch]
  vostok::fixed_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>,8> *p_m_affects; // [esp+48h] [ebp-20h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::udp_match_packet &,stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> const &,int),boost::_bi::list3<boost::reference_wrapper<vostok::network_core::udp_match_packet>,boost::arg<1>,boost::_bi::value<int> > > result; // [esp+58h] [ebp-10h] BYREF
  boost::reference_wrapper<vostok::network_core::udp_match_packet> a1; // [esp+64h] [ebp-4h]

  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, this->m_health);
  if ( this->m_last_hit_time )
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
      packet,
      COERCE_FLOAT(this->m_last_hit_time - client_offset));
  else
    vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(packet, 0.0);
  p_m_affects = &this->m_affects;
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    packet,
    this->m_affects.m_end - this->m_affects.m_begin);
  a1.t_ = (vostok::network_core::udp_match_packet *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)packet);
  m_end = this->m_affects.m_end;
  m_begin = this->m_affects.m_begin;
  v4 = *boost::bind<void,vostok::network_core::udp_match_packet &,stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> const &,int,boost::reference_wrapper<vostok::network_core::udp_match_packet>,boost::arg<1>,int>(
          &result,
          survarium::serialize_affect,
          a1,
          1_216,
          client_offset);
  for ( i = m_begin; i != m_end; ++i )
    boost::_bi::bind_t<void,void (__cdecl *)(vostok::network_core::udp_match_packet &,stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> const &,int),boost::_bi::list3<boost::reference_wrapper<vostok::network_core::udp_match_packet>,boost::arg<1>,boost::_bi::value<int>>>::operator()<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>(
      &v4,
      i);
}
