void __thiscall vostok::ai::planning::weapon_filter::add_filtered_id(
        vostok::ai::planning::weapon_filter *this,
        unsigned int id)
{
  const unsigned int *v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int>>::push_back(
    &this->m_filtered_ids._M_impl,
    v2);
}
