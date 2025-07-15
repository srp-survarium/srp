void __thiscall vostok::network::network_world::~network_world(vostok::network::network_world *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx

  this->__vftable = (vostok::network::network_world_vtbl *)&vostok::network::network_world::`vftable';
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>>::owner_finalize(
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *)this,
    (int)&this->m_channel,
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,8> > *)this);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&this->m_on_dispatch_callbacks);
}
