void __thiscall survarium::damage_model::deserialize(
        survarium::damage_model *this,
        vostok::network_core::packet_reader *reader)
{
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::body_part_parameters,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader> > > *pred; // [esp+4h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::body_part_parameters,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader> > > result; // [esp+30h] [ebp-Ch] BYREF
  boost::reference_wrapper<vostok::network_core::packet_reader> a2; // [esp+38h] [ebp-4h]

  a2.t_ = (vostok::network_core::packet_reader *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)reader);
  pred = boost::bind<void,survarium::body_part_parameters,vostok::network_core::packet_reader &,boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader>>(
           &result,
           (void (__thiscall *)(survarium::body_part_parameters *, vostok::network_core::packet_reader *))survarium::body_part_parameters::deserialize,
           *(_BYTE *)&1_169,
           a2);
  vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::body_part_parameters,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::arg<1>,boost::reference_wrapper<vostok::network_core::packet_reader>>>>(
    &this->m_body_parts,
    pred);
}
