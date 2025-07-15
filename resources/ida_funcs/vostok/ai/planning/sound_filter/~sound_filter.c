void __thiscall vostok::ai::planning::sound_filter::~sound_filter(vostok::ai::planning::sound_filter *this)
{
  this->__vftable = (vostok::ai::planning::sound_filter_vtbl *)&vostok::ai::planning::sound_filter::`vftable';
  stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper>>::clear((stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper> > *)&this->m_filtered_items);
  this->__vftable = (vostok::ai::planning::sound_filter_vtbl *)&vostok::ai::planning::base_filter::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
