void __thiscall vostok::ai::selectors::weapon_target_selector::fill_targets_list(
        vostok::ai::selectors::weapon_target_selector *this)
{
  vostok::memory::base_allocator **v1; // eax
  unsigned int v2; // eax
  vostok::ai::weapon_types_enum v4; // [esp+34h] [ebp-54h]
  boost::arg<1> *result; // [esp+44h] [ebp-44h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+54h] [ebp-34h] BYREF
  vostok::vectora_allocator<vostok::ai::weapon *> __a; // [esp+58h] [ebp-30h] BYREF
  const vostok::ai::weapon *v8; // [esp+5Ch] [ebp-2Ch]
  vostok::ai::weapon_types_enum v9; // [esp+60h] [ebp-28h]
  stlp_std::pair<char *,unsigned int> value; // [esp+64h] [ebp-24h] BYREF
  const vostok::ai::weapon *available_weapon; // [esp+6Ch] [ebp-1Ch]
  const void *target_weapon; // [esp+70h] [ebp-18h]
  unsigned int i; // [esp+74h] [ebp-14h]
  vostok::vectora<vostok::ai::weapon *> available_weapons; // [esp+78h] [ebp-10h] BYREF

  this->clear_targets(this);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)vostok::ai::g_allocator,
    &v6);
  __a.m_allocator = *v1;
  stlp_std::vector<vostok::ai::weapon *,vostok::vectora_allocator<void *>>::vector<vostok::ai::weapon *,vostok::vectora_allocator<void *>>(
    &available_weapons,
    &__a);
  vostok::ai::ai_world::get_available_weapons(this->m_world, this->m_brain_unit->m_npc, &available_weapons);
  for ( i = 0; ; ++i )
  {
    v2 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size((stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)&available_weapons);
    if ( i >= v2 )
      break;
    result = (boost::arg<1> *)stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::operator[](
                                (vostok::buffer_vector<unsigned int> *)&available_weapons,
                                i);
    available_weapon = *(const vostok::ai::weapon **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
    target_weapon = available_weapon;
    if ( (unsigned int)(this->m_selected_weapons.m_end - this->m_selected_weapons.m_begin) < 8 )
    {
      v4 = available_weapon->get_type(available_weapon);
      v8 = available_weapon;
      v9 = v4;
      value.first = (char *)available_weapon;
      value.second = v4;
      vostok::buffer_vector<stlp_std::pair<vostok::ai::weapon const *,unsigned int>>::push_back(
        (vostok::buffer_vector<stlp_std::pair<char *,unsigned int> > *)&this->m_selected_weapons,
        &value);
    }
  }
  stlp_std::sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
    this->m_selected_weapons.m_begin,
    this->m_selected_weapons.m_end,
    (bool (__cdecl *)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))vostok::ai::selectors::sort_by_type);
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>((vostok::vectora<vostok::resources::request> *)&available_weapons);
}
