void __thiscall vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::addition_lexeme *this,
        vostok::animation::mixing::addition_lexeme *left,
        vostok::animation::mixing::base_lexeme *right)
{
  vostok::animation::mixing::animation_lexeme *v3; // ecx
  vostok::mutable_buffer *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  survarium::game_camera *v7; // ecx
  vostok::animation::mixing::addition_lexeme *v9; // [esp+Ch] [ebp-20h]

  v9 = vostok::animation::mixing::addition_lexeme::cloned_in_buffer(left);
  v4 = vostok::animation::mixing::binary_operation_lexeme::cloned_in_buffer<vostok::animation::mixing::animation_lexeme>(
         right,
         v3);
  vostok::animation::mixing::binary_tree_addition_node::binary_tree_addition_node(
    this,
    v9,
    (vostok::animation::mixing::binary_tree_base_node *const)v4);
  v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         v5,
         (int)&left->vostok::animation::mixing::binary_operation_lexeme);
  vostok::animation::mixing::binary_operation_lexeme::binary_operation_lexeme(
    (vostok::animation::mixing::binary_operation_lexeme *)v6,
    (int)&this->vostok::animation::mixing::binary_operation_lexeme);
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
  survarium::weapon_user_dead_state::finalize(v7);
}
