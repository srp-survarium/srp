void __thiscall stlp_std::vector<vostok::ai::weapon *,vostok::vectora_allocator<void *>>::vector<vostok::ai::weapon *,vostok::vectora_allocator<void *>>(
        stlp_std::vector<vostok::ai::weapon *,vostok::vectora_allocator<void *> > *this,
        const vostok::vectora_allocator<vostok::ai::weapon *> *__a)
{
  vostok::vectora_allocator<void *> v3; // [esp+4h] [ebp-4h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3.m_allocator = __a->m_allocator;
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_Impl_vector<void *,vostok::vectora_allocator<void *>>(
    &this->_M_impl,
    &v3);
}


void __thiscall stlp_std::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *>>::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *>>(
        stlp_std::vector<survarium::zone_group *,survarium::std_allocator<survarium::zone_group *> > *this,
        const survarium::std_allocator<survarium::zone_group *> *__a)
{
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    (survarium::vector<vostok::resources::request> *)this,
    this);
}
