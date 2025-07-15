void __thiscall vostok::animation::mixing::n_ary_tree_node_cloner::visit(
        vostok::animation::mixing::n_ary_tree_node_cloner *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  vostok::animation::mixing::n_ary_tree_node_cloner::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
    this,
    node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_cloner::visit(
        vostok::animation::mixing::n_ary_tree_node_cloner *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  vostok::animation::mixing::n_ary_tree_node_cloner::propagate<vostok::animation::mixing::n_ary_tree_multiplication_node>(
    this,
    node);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_cloner::visit(
        vostok::animation::mixing::n_ary_tree_node_cloner *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  vostok::animation::mixing::n_ary_tree_node_cloner::propagate<vostok::animation::mixing::n_ary_tree_subtraction_node>(
    this,
    node);
}


void __userpurge vostok::animation::mixing::n_ary_tree_node_cloner::visit(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<ecx>,
        bool a2@<bl>,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  char *m_data; // esi
  vostok::animation::mixing::n_ary_tree_node_cloner *m_animation_interval_time; // ecx
  unsigned int m_start_time_in_ms; // ebx
  float m_animation_time_before_scale_starts; // xmm0_4
  const vostok::animation::base_interpolator *v8; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_constructor; // eax
  vostok::mutable_buffer *m_buffer; // eax
  float m_time_scale; // [esp+8h] [ebp-4h]

  m_data = this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    m_animation_interval_time = (vostok::animation::mixing::n_ary_tree_node_cloner *)this->m_animation_interval_time;
    if ( m_animation_interval_time )
      m_start_time_in_ms = this->m_start_time_in_ms;
    else
      m_start_time_in_ms = node->m_time_scale_start_time_in_ms;
    if ( m_animation_interval_time )
      m_animation_time_before_scale_starts = *(float *)&m_animation_interval_time->__vftable;
    else
      m_animation_time_before_scale_starts = node->m_animation_time_before_scale_starts;
    m_time_scale = node->m_time_scale;
    v8 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
           m_animation_interval_time,
           (int)this,
           node->m_interpolator,
           a2);
    *((float *)m_data + 2) = this->m_time_scale_factor * m_time_scale;
    *((_DWORD *)m_data + 4) = m_start_time_in_ms;
    *(_DWORD *)m_data = &vostok::animation::mixing::n_ary_tree_time_scale_node::`vftable';
    *((_DWORD *)m_data + 1) = v8;
    *((float *)m_data + 3) = m_animation_time_before_scale_starts;
  }
  else
  {
    m_data = 0;
  }
  m_constructor = this->m_constructor;
  this->m_result = (vostok::animation::mixing::n_ary_tree_base_node *)m_data;
  m_buffer = m_constructor->m_buffer;
  m_buffer->m_data += 20;
  m_buffer->m_size -= 20;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_cloner::visit(
        vostok::animation::mixing::n_ary_tree_node_cloner *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  vostok::mutable_buffer *m_buffer; // ecx
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node *m_data; // esi
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // ebp
  vostok::animation::mixing::n_ary_tree_node_cloner *v7; // ecx
  unsigned int m_start_time_in_ms; // eax
  const vostok::animation::base_interpolator *v9; // eax
  unsigned int v10; // [esp-4h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_base_node *v11; // [esp+14h] [ebp+4h]

  m_buffer = this->m_constructor->m_buffer;
  m_data = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node *)m_buffer->m_data;
  m_buffer->m_data += 20;
  m_buffer->m_size -= 20;
  node->m_from->accept(node->m_from, this);
  m_result = this->m_result;
  node->m_to->accept(node->m_to, this);
  v11 = this->m_result;
  if ( m_data )
  {
    if ( this->m_animation_interval_time )
      m_start_time_in_ms = this->m_start_time_in_ms;
    else
      m_start_time_in_ms = node->m_start_time_in_ms;
    v9 = vostok::animation::mixing::n_ary_tree_node_cloner::clone(
           v7,
           (int)this,
           node->m_interpolator,
           m_start_time_in_ms);
    vostok::animation::mixing::n_ary_tree_time_scale_transition_node::n_ary_tree_time_scale_transition_node(
      m_data,
      m_result,
      v11,
      v9,
      v10);
  }
  this->m_result = m_data;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_cloner::visit(
        vostok::animation::mixing::n_ary_tree_node_cloner *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  const vostok::animation::base_interpolator *m_interpolator; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // ecx
  float m_weight; // xmm0_4
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_constructor; // eax
  vostok::mutable_buffer *m_buffer; // eax
  bool v8; // [esp+0h] [ebp-8h]

  m_interpolator = vostok::animation::mixing::n_ary_tree_node_cloner::clone(this, (int)this, node->m_interpolator, v8);
  if ( !m_interpolator )
    m_interpolator = node->m_interpolator;
  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)this->m_constructor->m_buffer->m_data;
  if ( m_data )
  {
    m_weight = node->m_weight;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_interpolator;
    *(float *)&m_data[2].__vftable = m_weight;
  }
  else
  {
    m_data = 0;
  }
  m_constructor = this->m_constructor;
  this->m_result = m_data;
  m_buffer = m_constructor->m_buffer;
  m_buffer->m_data += 12;
  m_buffer->m_size -= 12;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_cloner::visit(
        vostok::animation::mixing::n_ary_tree_node_cloner *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  vostok::mutable_buffer *m_buffer; // eax
  vostok::animation::mixing::n_ary_tree_base_node *m_data; // edi
  vostok::animation::mixing::n_ary_tree_node_cloner *v6; // ecx
  const vostok::animation::base_interpolator *m_interpolator; // eax
  unsigned int m_start_time_in_ms; // ebx
  bool v9; // [esp+0h] [ebp-10h]
  vostok::animation::mixing::n_ary_tree_base_node *v10; // [esp+Ch] [ebp-4h]
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // [esp+18h] [ebp+8h]

  m_buffer = this->m_constructor->m_buffer;
  m_data = (vostok::animation::mixing::n_ary_tree_base_node *)m_buffer->m_data;
  m_buffer->m_data += 20;
  m_buffer->m_size -= 20;
  node->m_from->accept(node->m_from, this);
  m_result = this->m_result;
  node->m_to->accept(node->m_to, this);
  v10 = this->m_result;
  m_interpolator = vostok::animation::mixing::n_ary_tree_node_cloner::clone(v6, (int)this, node->m_interpolator, v9);
  if ( !m_interpolator )
    m_interpolator = node->m_interpolator;
  if ( m_data )
  {
    m_start_time_in_ms = node->m_start_time_in_ms;
    m_data[1].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_result;
    m_data->__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_transition_node::`vftable';
    m_data[2].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)v10;
    m_data[3].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_interpolator;
    m_data[4].__vftable = (vostok::animation::mixing::n_ary_tree_base_node_vtbl *)m_start_time_in_ms;
  }
  this->m_result = m_data;
}
