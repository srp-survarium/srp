void __thiscall survarium::inventory::unset_holder(survarium::inventory *this)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v1; // ecx
  const vostok::variant<32> **v2; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( i = 0; i < 0x13; ++i )
  {
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
           v1,
           &this->m_slots[i].item.m_object) )
    {
      v2 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)i,
             (int)&this->m_slots[i]);
      (*(void (__thiscall **)(const vostok::variant<32> **, const vostok::variant<32> **))(*v2)[2].m_storage)(v2, v2);
    }
    v1 = (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(i + 1);
  }
  this->m_holder = 0;
}
