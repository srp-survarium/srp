vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *__thiscall survarium::booby_trap_set_core::try_place_trap(
        survarium::booby_trap_set_core *this)
{
  const vostok::variant<32> **v2; // eax
  survarium::inventory_item *v3; // ecx
  unsigned __int16 v4; // ax
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *trap_iter; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 place_transform; // [esp+20h] [ebp-40h] BYREF

  if ( !survarium::inventory_item::amount(this, (int)this) )
    return this->m_traps.m_end;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&place_transform);
  if ( !survarium::booby_trap_set_core::get_visible_place_transform(this, &place_transform) )
    return this->m_traps.m_end;
  trap_iter = stlp_std::find_if<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *,bool (__cdecl *)(vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>)>(
                this->m_traps.m_begin,
                this->m_traps.m_end,
                survarium::find_free_trap_predicate);
  if ( trap_iter != this->m_traps.m_end )
  {
    v2 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&place_transform,
           (int)trap_iter);
    this->insert_trap(this, (survarium::booby_trap_core *)v2, &place_transform);
    v4 = survarium::inventory_item::amount(v3, (int)this);
    survarium::inventory_item::set_amount((survarium::inventory_item *)(v4 - 1), (int)this);
  }
  return trap_iter;
}
