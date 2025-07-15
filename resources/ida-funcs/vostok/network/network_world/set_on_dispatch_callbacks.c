void __thiscall vostok::network::network_world::set_on_dispatch_callbacks(
        vostok::network::network_world *this,
        boost::function<void __cdecl(void)> callback)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx

  boost::function<void __cdecl (void)>::operator=(
    &callback,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_on_dispatch_callbacks);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&callback);
}
