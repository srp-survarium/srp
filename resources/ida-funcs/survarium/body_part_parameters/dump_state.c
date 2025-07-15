void __thiscall survarium::body_part_parameters::dump_state(
        survarium::body_part_parameters *this,
        vostok::ai::npc_statistics *stats,
        unsigned int current_time_in_ms)
{
  vostok::ai::statistics_item<46,16> *v3; // ecx
  vostok::ai::statistics_item<46,16> new_stats_item; // [esp+44h] [ebp-3F8h] BYREF

  vostok::fixed_string<32>::fixed_string<32>(&new_stats_item.caption);
  vostok::fixed_vector<vostok::fixed_string<46>,16>::fixed_vector<vostok::fixed_string<46>,16>(&new_stats_item.content);
  survarium::body_part_parameters::fill_new_stats_item<vostok::ai::statistics_item<46,16>>(
    this,
    &new_stats_item,
    current_time_in_ms);
  vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::push_back(&stats->body_state, &new_stats_item);
  vostok::ai::statistics_item<46,16>::~statistics_item<46,16>(v3, (int)&new_stats_item);
}


void __thiscall survarium::body_part_parameters::dump_state(
        survarium::body_part_parameters *this,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> callback,
        unsigned int index)
{
  survarium::game_camera *v3; // ecx
  const vostok::variant<32> **v4; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  unsigned int i; // [esp+154h] [ebp-214h]
  vostok::fixed_string<512> affects_str; // [esp+158h] [ebp-210h] BYREF

  vostok::fixed_string<512>::fixed_string<512>((vostok::fixed_string<512> *)this, (int)&affects_str);
  for ( i = 0; ; ++i )
  {
    v3 = (survarium::game_camera *)(this->m_affects.m_end - this->m_affects.m_begin);
    if ( i >= (unsigned int)v3 )
      break;
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::buffer_string::appendf(
      (vostok::buffer_string *)&stru_977D0C,
      affects_captions_16[this->m_affects.m_begin[i].first]);
  }
  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v3,
         (int)&affects_str);
  boost::function4<void,unsigned int,float,float,char const *>::operator()(
    &callback,
    index,
    this->m_health,
    this->m_max_health,
    (boost::function4<void,unsigned int,float,float,char const *> *)v4);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    (int *)&callback);
}
