void __thiscall survarium::victory_items_container_core::victory_items_container_core(
        survarium::victory_items_container_core *this)
{
  survarium::game_camera *v1; // eax
  vostok::vectora_allocator<void *> __a; // [esp+Ch] [ebp-10h] BYREF
  survarium::game_camera *v4; // [esp+10h] [ebp-Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+14h] [ebp-8h] BYREF
  vostok::memory::base_allocator *v6; // [esp+18h] [ebp-4h]

  survarium::usable_object::usable_object(this);
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::victory_items_container_core_vtbl *)&survarium::victory_items_container_core::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::victory_items_container_core::`vftable'{for `survarium::link_resolver'};
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_,
    &v5);
  v4 = v1;
  v6 = (vostok::memory::base_allocator *)v1->__vftable;
  survarium::weapon_user_dead_state::finalize(v1);
  __a.m_allocator = v6;
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_Impl_vector<void *,vostok::vectora_allocator<void *>>(
    &this->m_victory_items._M_impl,
    &__a);
  this->m_owner_team = team_undefined;
}
