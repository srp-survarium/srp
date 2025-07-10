void __thiscall vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::copy(
        vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  __int16 v4; // si

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&dest_buffer);
  v4 = *(_WORD *)src_buffer.m_data;
  *(_WORD *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)src_buffer.m_data,
              (int)&dest_buffer) = v4;
}
