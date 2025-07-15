survarium::gather_victory_items_rule *__thiscall survarium::gather_victory_items_rule::`scalar deleting destructor'(
        survarium::gather_victory_items_rule *this,
        char a2)
{
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v3; // ecx
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v4; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> > > *v5; // ecx

  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>>>(
    (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> > > *)this,
    (int *)&this->m_containers);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v3,
    (int)&this->m_selected_spawners);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v4,
    (int)&this->m_spawners);
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>>>(
    v5,
    (int *)&this->m_victory_items);
  survarium::game_match_rule_base::~game_match_rule_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
