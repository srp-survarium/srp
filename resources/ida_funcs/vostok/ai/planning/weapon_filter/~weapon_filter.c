void __thiscall vostok::ai::planning::weapon_filter::~weapon_filter(vostok::ai::planning::weapon_filter *this)
{
  this->__vftable = (vostok::ai::planning::weapon_filter_vtbl *)&vostok::ai::planning::weapon_filter::`vftable';
  stlp_std::priv::_List_base<unsigned int,vostok::ai::std_allocator<unsigned int>>::clear(&this->m_filtered_ids._M_impl);
  this->__vftable = (vostok::ai::planning::weapon_filter_vtbl *)&vostok::ai::planning::base_filter::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
