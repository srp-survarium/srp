void __usercall survarium::shared_statistics::~shared_statistics(
        survarium::shared_statistics *this@<ecx>,
        int a2@<edi>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)(a2 + 6104));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)(a2 + 5080));
  `vector destructor iterator'(
    (char *)(a2 + 4272),
    0x28u,
    20,
    (void (__thiscall *)(void *))survarium::affect_subscriber::~affect_subscriber);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)(a2 + 4240));
}
