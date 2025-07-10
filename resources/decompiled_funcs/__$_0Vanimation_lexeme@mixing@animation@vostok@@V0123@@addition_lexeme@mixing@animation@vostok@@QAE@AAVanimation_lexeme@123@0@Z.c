void __thiscall vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::addition_lexeme *this,
        vostok::animation::mixing::base_lexeme *left,
        vostok::animation::mixing::base_lexeme *right)
{
  vostok::mutable_buffer *v3; // edi
  vostok::animation::mixing::animation_lexeme *v4; // ecx
  vostok::mutable_buffer *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  survarium::game_camera *v8; // ecx

  v3 = vostok::animation::mixing::binary_operation_lexeme::cloned_in_buffer<vostok::animation::mixing::animation_lexeme>(
         right,
         (vostok::animation::mixing::animation_lexeme *)this);
  v5 = vostok::animation::mixing::binary_operation_lexeme::cloned_in_buffer<vostok::animation::mixing::animation_lexeme>(
         left,
         v4);
  vostok::animation::mixing::binary_tree_addition_node::binary_tree_addition_node(
    this,
    (vostok::animation::mixing::binary_tree_base_node *const)v5,
    (vostok::animation::mixing::binary_tree_base_node *const)v3);
  v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)&left[15]);
  vostok::animation::mixing::binary_operation_lexeme::binary_operation_lexeme(
    (vostok::animation::mixing::binary_operation_lexeme *)v7,
    (int)&this->vostok::animation::mixing::binary_operation_lexeme);
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
  survarium::weapon_user_dead_state::finalize(v8);
}
