void __thiscall vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::addition_lexeme *this,
        vostok::animation::mixing::expression *left,
        vostok::animation::mixing::expression *right)
{
  const vostok::variant<32> **v3; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  vostok::animation::mixing::expression *v6; // ecx
  vostok::mutable_buffer *v7; // eax
  survarium::game_camera *v8; // ecx

  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)right);
  v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)left);
  vostok::animation::mixing::binary_tree_addition_node::binary_tree_addition_node(
    this,
    (vostok::animation::mixing::binary_tree_base_node *const)v5,
    (vostok::animation::mixing::binary_tree_base_node *const)v3);
  v7 = vostok::animation::mixing::expression::buffer(v6, (int)left);
  vostok::animation::mixing::binary_operation_lexeme::binary_operation_lexeme(
    (vostok::animation::mixing::binary_operation_lexeme *)v7,
    (int)&this->vostok::animation::mixing::binary_operation_lexeme);
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
  survarium::weapon_user_dead_state::finalize(v8);
}
