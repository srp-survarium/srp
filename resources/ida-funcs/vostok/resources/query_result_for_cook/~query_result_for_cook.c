void __thiscall vostok::resources::query_result_for_cook::~query_result_for_cook(
        vostok::resources::query_result_for_cook *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx

  this->__vftable = (vostok::resources::query_result_for_cook_vtbl *)&vostok::resources::query_result_for_cook::`vftable';
  vostok::resources::query_result_for_cook::clear_user_data(this, (int)this);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&this->m_tasks_finished_callback);
  vostok::resources::query_result_for_user::~query_result_for_user(this);
}
