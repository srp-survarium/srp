BOOL __thiscall survarium::weapon_core::could_be_aimed(
        survarium::weapon_core *this,
        const survarium::base_player *user)
{
  int v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v5; // [esp+4h] [ebp-8h]

  v2 = ((int (__thiscall *)(const survarium::base_player *, survarium::weapon_core *))user->damage_model)(user, this);
  v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, v2);
  return (unsigned __int8)(*((_BYTE *)v5 + 827) + *((_BYTE *)v5 + 826)) != 2;
}
