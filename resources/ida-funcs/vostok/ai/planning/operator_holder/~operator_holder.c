void __thiscall vostok::ai::planning::operator_holder::~operator_holder(vostok::ai::planning::operator_holder *this)
{
  vostok::ai::planning::operator_holder::clear(this);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::~_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>(&this->m_objects._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
