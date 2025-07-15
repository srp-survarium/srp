void __usercall vostok::network_core::udp_match_connection::~udp_match_connection(
        vostok::network_core::udp_match_connection *this@<ecx>,
        int a2@<eax>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)(a2 + 2752));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)(a2 + 2720));
  `vector destructor iterator'(
    (char *)(a2 + 2676),
    0x2Cu,
    1,
    (void (__thiscall *)(void *))vostok::network_core::udp_match_connection::channel::~channel);
}
