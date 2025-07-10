bool __thiscall survarium::weapon_core::could_be_used(survarium::weapon_core *this, const survarium::base_player *user)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v7; // [esp+8h] [ebp-8h]

  v2 = user->damage_model(user);
  v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
  return (unsigned __int8)(*((_BYTE *)v7 + 827) + *((_BYTE *)v7 + 826)) != 2 || !this->m_is_double_handed;
}
