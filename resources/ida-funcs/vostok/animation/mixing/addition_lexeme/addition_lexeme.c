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


void __userpurge vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::addition_lexeme *this@<edi>,
        vostok::animation::mixing::base_lexeme *right@<eax>,
        vostok::animation::mixing::animation_lexeme *a3@<ecx>,
        vostok::animation::mixing::expression *left)
{
  vostok::animation::mixing::binary_tree_base_node *v4; // eax
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx

  v4 = (vostok::animation::mixing::binary_tree_base_node *)vostok::animation::mixing::animation_lexeme::cloned_in_buffer(
                                                             a3,
                                                             right);
  m_object = left->m_node.m_object;
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
  this->m_left.m_object = 0;
  if ( m_object )
  {
    this->m_left.m_object = m_object;
    ++m_object->m_reference_count;
  }
  this->m_right.m_object = 0;
  if ( v4 )
  {
    this->m_right.m_object = v4;
    ++v4->m_reference_count;
  }
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
  this->m_buffer = left->m_lexeme->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
}


void __thiscall vostok::animation::mixing::addition_lexeme::addition_lexeme(
        vostok::animation::mixing::multiplication_lexeme *right,
        vostok::animation::mixing::addition_lexeme *this,
        vostok::animation::mixing::multiplication_lexeme *left)
{
  vostok::animation::mixing::multiplication_lexeme *v3; // ebx
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::multiplication_lexeme *m_data; // esi
  vostok::animation::mixing::multiplication_lexeme *v6; // ecx
  vostok::animation::mixing::multiplication_lexeme *v7; // esi
  vostok::mutable_buffer *v8; // eax

  if ( right->m_cloned )
  {
    v3 = right;
  }
  else
  {
    m_buffer = right->m_buffer;
    m_data = (vostok::animation::mixing::multiplication_lexeme *)m_buffer->m_data;
    m_buffer->m_size -= 36;
    m_buffer->m_data = (char *)&m_data[1];
    if ( m_data )
      vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(m_data, right);
    m_data->m_cloned = 1;
    v3 = m_data;
  }
  v6 = left;
  if ( left->m_cloned )
  {
    v7 = left;
  }
  else
  {
    v8 = left->m_buffer;
    v7 = (vostok::animation::mixing::multiplication_lexeme *)v8->m_data;
    v8->m_size -= 36;
    v8->m_data = (char *)&v7[1];
    if ( v7 )
    {
      vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(v7, left);
      v6 = left;
    }
    v7->m_cloned = 1;
  }
  this->m_next_weight = 0;
  this->m_same_weight = 0;
  this->m_next_unique_interpolator = 0;
  this->m_reference_count = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_binary_operation_node::`vftable';
  this->m_left.m_object = 0;
  if ( v7 )
  {
    this->m_left.m_object = v7;
    ++v7->m_reference_count;
  }
  this->m_right.m_object = 0;
  if ( v3 )
  {
    this->m_right.m_object = v3;
    ++v3->m_reference_count;
  }
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
  this->m_buffer = v6->m_buffer;
  this->m_cloned = 0;
  this->__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
}
