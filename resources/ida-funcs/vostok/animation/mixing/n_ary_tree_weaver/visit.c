void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_addition_node *node)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::mixing::n_ary_tree_weaver *v4; // ecx
  vostok::animation::mixing::n_ary_tree_weaver *v5; // ecx
  vostok::animation::mixing::n_ary_tree_weaver weaver; // [esp+10h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver v7; // [esp+30h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  weaver.m_buffer = this->m_buffer;
  v7.m_buffer = weaver.m_buffer;
  this->m_new_node = node;
  m_object = node->m_left.m_object;
  weaver.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&weaver.m_animations_root, 0, 20);
  v7.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&v7.m_animations_root, 0, 20);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_base_node>(
    this,
    m_object,
    &weaver);
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(v4, (int)this, &weaver);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_base_node>(
    this,
    node->m_right.m_object,
    &v7);
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(v5, (int)this, &v7);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)weaver.m_new_node,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&node->m_left);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v7.m_new_node,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&node->m_right);
  if ( !weaver.m_animations_root && !v7.m_animations_root )
    this->m_weights_root = node;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_animation_node *node)
{
  vostok::animation::mixing::binary_tree_animation_node *m_current_animations_root; // eax
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::binary_tree_animation_node *m_data; // edi
  vostok::animation::mixing::binary_tree_animation_node *m_weight_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v7; // ecx
  bool v8; // bl
  bool v9; // zf
  vostok::animation::mixing::binary_tree_animation_node *m_time_driving_animation; // eax
  vostok::animation::mixing::binary_tree_animation_node *v11; // ecx
  bool v12; // bl
  vostok::animation::mixing::binary_tree_base_node *m_interpolators_root; // eax

  m_current_animations_root = this->m_current_animations_root;
  if ( node->m_next_weight_animation.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
LABEL_3:
    m_buffer = this->m_buffer;
    m_data = (vostok::animation::mixing::binary_tree_animation_node *)m_buffer->m_data;
    m_buffer->m_data += 120;
    m_buffer->m_size -= 120;
    if ( m_data )
      vostok::animation::mixing::binary_tree_animation_node::binary_tree_animation_node(node, (int)m_data);
  }
  else
  {
    while ( m_current_animations_root )
    {
      if ( m_current_animations_root == node )
        goto LABEL_3;
      m_current_animations_root = m_current_animations_root->m_next_weight_animation.m_object;
    }
    m_data = node;
  }
  this->m_new_node = m_data;
  m_data->m_next_weight = 0;
  m_data->m_unique_weights_count = 0;
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)this->m_animations_root,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&m_data->m_next_weight_animation);
  this->m_animations_root = m_data;
  m_weight_driving_animation = m_data->m_weight_driving_animation;
  v7 = 0;
  if ( m_weight_driving_animation )
  {
    ++m_weight_driving_animation->m_reference_count;
    v7 = m_weight_driving_animation;
  }
  v8 = v7 == 0;
  if ( v7 )
  {
    v9 = v7->m_reference_count-- == 1;
    if ( v9 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))v7->~vostok::animation::mixing::binary_tree_base_node)(
        v7,
        0);
  }
  if ( v8 )
    goto LABEL_21;
  m_time_driving_animation = m_data->m_time_driving_animation;
  v11 = 0;
  if ( m_time_driving_animation )
  {
    ++m_time_driving_animation->m_reference_count;
    v11 = m_time_driving_animation;
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
LABEL_21:
    m_interpolators_root = this->m_interpolators_root;
    ++this->m_interpolators_count;
    m_data->m_next_unique_interpolator = m_interpolators_root;
    this->m_interpolators_root = m_data;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_multiplication_node *node)
{
  vostok::mutable_buffer *m_buffer; // edx
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::mixing::n_ary_tree_weaver *v5; // ecx
  vostok::animation::mixing::n_ary_tree_weaver *v6; // ecx
  vostok::animation::mixing::binary_tree_weight_node *m_animations_root; // eax
  vostok::animation::mixing::binary_tree_base_node *m_weights_root; // edi
  vostok::animation::mixing::n_ary_tree_weaver v9; // [esp+18h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver weaver; // [esp+38h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  m_buffer = this->m_buffer;
  memset(&weaver.m_animations_root, 0, 20);
  memset(&v9.m_animations_root, 0, 20);
  weaver.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  v9.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  this->m_new_node = node;
  m_object = node->m_left.m_object;
  weaver.m_buffer = m_buffer;
  v9.m_buffer = m_buffer;
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_base_node>(
    this,
    m_object,
    &weaver);
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(v5, (int)this, &weaver);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_base_node>(
    this,
    node->m_right.m_object,
    &v9);
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(v6, (int)this, &v9);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)weaver.m_new_node,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&node->m_left);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v9.m_new_node,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&node->m_right);
  m_animations_root = (vostok::animation::mixing::binary_tree_weight_node *)weaver.m_animations_root;
  if ( weaver.m_animations_root )
  {
    m_weights_root = v9.m_weights_root;
  }
  else
  {
    m_animations_root = (vostok::animation::mixing::binary_tree_weight_node *)v9.m_animations_root;
    if ( !v9.m_animations_root )
      return;
    m_weights_root = weaver.m_weights_root;
  }
  update_weights(m_animations_root, m_weights_root);
  this->m_weights_root = 0;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weaver::visit(
        vostok::animation::mixing::n_ary_tree_weaver *this,
        vostok::animation::mixing::binary_tree_subtraction_node *node)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::mixing::n_ary_tree_weaver *v4; // ecx
  vostok::animation::mixing::n_ary_tree_weaver *v5; // ecx
  vostok::animation::mixing::n_ary_tree_weaver weaver; // [esp+10h] [ebp-40h] BYREF
  vostok::animation::mixing::n_ary_tree_weaver v7; // [esp+30h] [ebp-20h] BYREF

  node->m_next_weight = 0;
  weaver.m_buffer = this->m_buffer;
  v7.m_buffer = weaver.m_buffer;
  this->m_new_node = node;
  m_object = node->m_left.m_object;
  weaver.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&weaver.m_animations_root, 0, 20);
  v7.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&v7.m_animations_root, 0, 20);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_base_node>(
    this,
    m_object,
    &weaver);
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(v4, (int)this, &weaver);
  vostok::animation::mixing::n_ary_tree_weaver::propagate<vostok::animation::mixing::binary_tree_base_node>(
    this,
    node->m_right.m_object,
    &v7);
  vostok::animation::mixing::n_ary_tree_weaver::join_animations(v5, (int)this, &v7);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)weaver.m_new_node,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&node->m_left);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)v7.m_new_node,
    (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)&node->m_right);
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
