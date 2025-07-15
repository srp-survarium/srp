void __thiscall survarium::inventory::deserialize(
        survarium::inventory *this,
        vostok::network_core::packet_reader *reader)
{
  boost::_bi::bind_t<void,void (__cdecl*)(survarium::inventory_slot &,vostok::network_core::packet_reader &),boost::_bi::list2<boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader> > > v3; // [esp+4h] [ebp-34h] BYREF
  survarium::inventory_slot *a1; // [esp+Ch] [ebp-2Ch]
  boost::_bi::bind_t<void,void (__cdecl*)(survarium::inventory_slot &,vostok::network_core::packet_reader &),boost::_bi::list2<boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader> > > result; // [esp+2Ch] [ebp-Ch] BYREF
  boost::reference_wrapper<vostok::network_core::packet_reader> a2; // [esp+34h] [ebp-4h]

  a2.t_ = (vostok::network_core::packet_reader *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)reader);
  v3 = *boost::bind<void,survarium::inventory_slot &,vostok::network_core::packet_reader &,boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader>>(
          &result,
          survarium::call_item_deserialize,
          *(_BYTE *)&1_168,
          a2);
  for ( a1 = this->m_slots; a1 != (survarium::inventory_slot *)&this->m_active_slot; ++a1 )
    boost::_bi::bind_t<void,void (__cdecl *)(survarium::inventory_slot &,vostok::network_core::packet_reader &),boost::_bi::list2<boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader>>>::operator()<survarium::inventory_slot>(
      &v3,
      a1);
}
