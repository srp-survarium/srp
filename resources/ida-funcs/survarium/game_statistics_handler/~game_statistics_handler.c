void __usercall survarium::game_statistics_handler::~game_statistics_handler(
        survarium::game_statistics_handler *this@<ecx>,
        int a2@<eax>)
{
  survarium::shared_statistics *v3; // ecx

  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)(a2 + 6208));
  survarium::shared_statistics::~shared_statistics(v3, a2 + 8);
}
