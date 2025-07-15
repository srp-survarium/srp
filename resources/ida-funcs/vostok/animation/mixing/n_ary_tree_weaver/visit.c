void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_weaver left; // [esp+10h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver right; // [esp+30h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  left.m_buffer = this->m_buffer;
  right.m_buffer = left.m_buffer;
  left.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  right.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&left.m_animations_root, 0, 20);
  memset(&right.m_animations_root, 0, 20);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_addition_node>(
    &left,
    this,
    node,
    &left,
    &right);
  if ( !left.m_animations_root && !right.m_animations_root )
    this->m_weights_root = node;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::binary_tree_animation_node *m_current_animations_root; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_data; // esi
  vostok::animation::mixing::binary_tree_animation_node *m_animations_root; // eax
  vostok::animation::mixing::binary_tree_animation_node *v6; // ecx
  vostok::animation::mixing::binary_tree_animation_node *v7; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_object; // ecx
  bool v9; // zf
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v11; // ecx
  bool v12; // bl
  vostok::animation::mixing::binary_tree_base_node *m_interpolators_root; // eax
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v16; // ecx
  bool v17; // bl
  vostok::animation::mixing::binary_tree_base_node *v18; // ecx

  m_current_animations_root = this->m_current_animations_root;
  if ( !node->m_next_weight_animation.m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( !m_current_animations_root )
    {
LABEL_6:
      m_data = node;
      goto LABEL_7;
    }
    while ( m_current_animations_root != node )
    {
      m_current_animations_root = m_current_animations_root->m_next_weight_animation.m_object;
      if ( !m_current_animations_root )
        goto LABEL_6;
    }
  }
  m_buffer = this->m_buffer;
  m_data = (vostok::animation::mixing::binary_tree_animation_node *)m_buffer->m_data;
  m_buffer->m_data += 120;
  m_buffer->m_size -= 120;
  if ( m_data )
    vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(node, (int)m_data);
LABEL_7:
  this->m_new_node = m_data;
  m_data->m_next_weight = 0;
  m_data->m_unique_weights_count = 0;
  m_animations_root = this->m_animations_root;
  v6 = 0;
  if ( m_animations_root )
  {
    ++m_animations_root->m_reference_count;
    v6 = m_animations_root;
  }
  v7 = v6;
  m_object = m_data->m_next_weight_animation.m_object;
  m_data->m_next_weight_animation.m_object = v7;
  if ( m_object )
  {
    v9 = m_object->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
        m_object,
        0);
  }
  this->m_animations_root = m_data;
  m_weight_driving_animation = m_data->m_weight_driving_animation;
  v11 = 0;
  if ( m_weight_driving_animation )
  {
    ++m_weight_driving_animation->m_reference_count;
    v11 = m_weight_driving_animation;
  }
  v12 = v11 == 0;
  if ( v11 )
  {
    v9 = v11->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v11->~vostok::animation::mixing::binary_tree_base_node)(
        v11,
        0);
  }
  if ( v12 )
  {
    m_interpolators_root = this->m_interpolators_root;
    ++this->m_interpolators_count;
    m_data->m_next_unique_interpolator = m_interpolators_root;
    this->m_interpolators_root = m_data;
  }
  else
  {
    m_time_driving_animation = m_data->m_time_driving_animation;
    v16 = 0;
    if ( m_time_driving_animation )
    {
      ++m_time_driving_animation->m_reference_count;
      v16 = m_time_driving_animation;
    }
    v17 = v16 == 0;
    if ( v16 )
    {
      v9 = v16->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v16->~vostok::animation::mixing::binary_tree_base_node)(
          v16,
          0);
    }
    if ( v17 )
    {
      v18 = this->m_interpolators_root;
      ++this->m_interpolators_count;
      m_data->m_next_unique_interpolator = v18;
      this->m_interpolators_root = m_data;
    }
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  vostok::animation::mixing::n_ary_tree_weaver right; // [esp+8h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver left; // [esp+28h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  left.m_buffer = this->m_buffer;
  right.m_buffer = left.m_buffer;
  left.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  right.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&left.m_animations_root, 0, 20);
  memset(&right.m_animations_root, 0, 20);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_addition_node>(
    (vostok::animation::mixing::n_ary_tree_weaver *)node,
    this,
    (vostok::animation::mixing::binary_tree_addition_node *)node,
    &left,
    &right);
  if ( left.m_animations_root )
  {
    update_weights(left.m_animations_root, right.m_weights_root);
    this->m_weights_root = 0;
  }
  else if ( right.m_animations_root )
  {
    update_weights(right.m_animations_root, left.m_weights_root);
    this->m_weights_root = 0;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  vostok::mutable_buffer *m_buffer; // ecx
  vostok::animation::mixing::n_ary_tree_weaver right; // [esp+8h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver left; // [esp+28h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  m_buffer = this->m_buffer;
  memset(&left.m_animations_root, 0, 20);
  memset(&right.m_animations_root, 0, 20);
  left.m_buffer = m_buffer;
  right.m_buffer = m_buffer;
  left.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  right.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_addition_node>(
    &left,
    this,
    (vostok::animation::mixing::binary_tree_addition_node *)node,
    &left,
    &right);
  this->m_weights_root = node;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_weight_node *node)
{
  vostok::animation::mixing::binary_tree_base_node *m_weights_root; // edx
  vostok::animation::mixing::binary_tree_base_node *m_interpolators_root; // edx

  m_weights_root = this->m_weights_root;
  this->m_new_node = node;
  node->m_next_weight = m_weights_root;
  m_interpolators_root = this->m_interpolators_root;
  ++this->m_interpolators_count;
  this->m_weights_root = node;
  node->m_next_unique_interpolator = m_interpolators_root;
  this->m_interpolators_root = node;
}
