void __usercall survarium::player_stamina::~player_stamina(survarium::player_stamina *this@<ecx>, int a2@<eax>)
{
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)(a2 + 88));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
}
