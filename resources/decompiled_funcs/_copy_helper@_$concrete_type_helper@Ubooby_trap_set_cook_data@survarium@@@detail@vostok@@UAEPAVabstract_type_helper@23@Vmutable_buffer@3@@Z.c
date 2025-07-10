vostok::detail::abstract_type_helper *__thiscall vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::copy_helper(
        vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data> *this,
        vostok::mutable_buffer dest_buffer)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax
  vostok::detail::abstract_type_helper *v4; // ecx
  _DWORD *v7; // [esp+8h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)&dest_buffer);
  v7 = operator new(4u, v3);
  if ( !v7 )
    return 0;
  vostok::detail::abstract_type_helper::abstract_type_helper(v4, v7);
  *v7 = &vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::`vftable';
  return (vostok::detail::abstract_type_helper *)v7;
}
