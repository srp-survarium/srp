void __thiscall vostok::ai::planning::cover_filter::~cover_filter(vostok::ai::planning::cover_filter *this)
{
  this->__vftable = (vostok::ai::planning::cover_filter_vtbl *)&vostok::ai::planning::cover_filter::`vftable';
  stlp_std::priv::_List_base<unsigned int,vostok::ai::std_allocator<unsigned int>>::clear(&this->m_filtered_ids._M_impl);
  this->__vftable = (vostok::ai::planning::cover_filter_vtbl *)&vostok::ai::planning::base_filter::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
