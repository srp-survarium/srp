void __thiscall vostok::ai::planning::position_filter::~position_filter(vostok::ai::planning::position_filter *this)
{
  this->__vftable = (vostok::ai::planning::position_filter_vtbl *)&vostok::ai::planning::position_filter::`vftable';
  stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper>>::clear(&this->m_filtered_items._M_impl);
  this->__vftable = (vostok::ai::planning::position_filter_vtbl *)&vostok::ai::planning::base_filter::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
