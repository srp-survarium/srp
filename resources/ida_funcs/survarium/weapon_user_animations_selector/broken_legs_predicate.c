BOOL __thiscall survarium::weapon_user_animations_selector::broken_legs_predicate(
        survarium::weapon_user_animations_selector *this)
{
  int v1; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v4; // [esp+4h] [ebp-8h]

  v1 = ((int (__thiscall *)(survarium::base_player *, survarium::weapon_user_animations_selector *))this->m_user->damage_model)(
         this->m_user,
         this);
  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, v1);
  return (unsigned __int8)(*((_BYTE *)v4 + 825) + *((_BYTE *)v4 + 824)) == 2;
}
