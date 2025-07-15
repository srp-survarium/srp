void __thiscall survarium::affect_subscriber::~affect_subscriber(survarium::affect_subscriber *this)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)this);
}
