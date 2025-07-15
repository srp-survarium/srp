void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  float v2; // xmm0_4
  vostok::animation::mixing::n_ary_tree_addition_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float weight; // [esp+4h] [ebp-4h]

  v2 = 0.0;
  v3 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + 4 * node->m_operands_count + 8);
  weight = 0.0;
  if ( &node[1] != v4 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v3->__vftable,
        this);
      m_result = this->m_result;
      v2 = this->m_weight + weight;
      weight = v2;
      if ( m_result )
        v3->__vftable = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)m_result;
      v3 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v3 + 4);
    }
    while ( v3 != v4 );
  }
  this->m_weight = v2;
  this->m_result = 0;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  float v2; // xmm0_4
  unsigned int m_operands_count; // ebp
  vostok::animation::mixing::n_ary_tree_animation_node *v4; // esi
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  const vostok::math::float4x4 *weight; // [esp+4h] [ebp-4h]

  v2 = *(float *)&clear_value;
  m_operands_count = node->m_operands_count;
  v4 = node + 1;
  weight = clear_value;
  v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 4 * m_operands_count + 88);
  if ( m_operands_count )
  {
    v2 = *(float *)&clear_value;
    if ( (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
          + 3))(v4->__vftable) )
      v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 92);
  }
  for ( ; v4 != v6; v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 + 4) )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v4->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v4->__vftable,
      this);
    m_result = this->m_result;
    v2 = *(float *)&weight * this->m_weight;
    *(float *)&weight = v2;
    if ( m_result )
    {
      if ( node->m_operands_count == m_operands_count )
      {
        v4->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)m_result;
      }
      else
      {
        v4 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v4 - 4);
        v6 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v6 - 4);
      }
    }
    if ( v2 == 0.0 )
      break;
  }
  this->m_weight = v2;
  this->m_result = 0;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  vostok::animation::mixing::n_ary_tree_multiplication_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_multiplication_node *v4; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float weight; // [esp+4h] [ebp-4h]

  v2 = clear_value;
  v3 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)node + 4 * node->m_operands_count + 8);
  weight = *(float *)&clear_value;
  if ( &node[1] != v4 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_multiplication_node
       + 2))(
        v3->__vftable,
        this);
      weight = this->m_weight * weight;
      *(float *)&v2 = weight;
      if ( weight == 0.0 )
        break;
      m_result = this->m_result;
      if ( m_result )
        v3->__vftable = (vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *)m_result;
      v3 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)v3 + 4);
    }
    while ( v3 != v4 );
  }
  this->m_weight = *(float *)&v2;
  this->m_result = 0;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  float m_weight; // xmm0_4
  vostok::animation::mixing::n_ary_tree_subtraction_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_subtraction_node *v4; // ebp
  char v6; // bl
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float weight; // [esp+4h] [ebp-4h]

  m_weight = 0.0;
  v3 = node + 1;
  v4 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)((char *)node + 4 * node->m_operands_count + 8);
  v6 = 1;
  weight = 0.0;
  if ( &node[1] != v4 )
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v3->__vftable,
        this);
      if ( v6 )
      {
        m_weight = this->m_weight;
        v6 = 0;
      }
      else
      {
        m_weight = weight - this->m_weight;
      }
      m_result = this->m_result;
      weight = m_weight;
      if ( m_result )
        v3->__vftable = (vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *)m_result;
      v3 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)((char *)v3 + 4);
    }
    while ( v3 != v4 );
  }
  this->m_weight = m_weight;
  this->m_result = 0;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CF11);
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  __debugbreak();
  JUMPOUT(0x56CF21);
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  double m_weight; // st7
  unsigned int m_current_time_in_ms; // edx

  m_weight = node->m_weight;
  this->m_result = 0;
  this->m_weight = m_weight;
  m_current_time_in_ms = this->m_current_time_in_ms;
  this->m_null_weight_found = this->m_weight == 0.0;
  this->m_weight_transition_ended_time_in_ms = m_current_time_in_ms;
}


void __userpurge vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this@<ecx>,
        int a2@<ebx>,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  double v5; // st7
  char v6; // bl
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float m_weight; // xmm0_4
  float v9; // xmm2_4
  float interpolated_value; // [esp+Ch] [ebp-4h]
  float weight_from; // [esp+14h] [ebp+4h]

  ++this->m_recursion_level;
  weight_from = (double)(this->m_current_time_in_ms - node->m_start_time_in_ms) * 0.001;
  if ( weight_from >= ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
    || (v5 = ((double (__stdcall *)(_DWORD))node->m_interpolator->interpolated_value)(LODWORD(weight_from)),
        interpolated_value = v5,
        v5 == 1.0) )
  {
    node->m_to->accept(node->m_to, this);
  }
  else
  {
    v6 = 0;
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_weight_calculator *, int))node->m_from->accept)(
      node->m_from,
      this,
      a2);
    m_result = this->m_result;
    if ( m_result )
    {
      node->m_from = m_result;
      v6 = 1;
    }
    node->m_to->accept(node->m_to, this);
    m_weight = this->m_weight;
    if ( !v6 || weight_from != m_weight )
    {
      v9 = (float)(*(float *)&clear_value - interpolated_value) * weight_from;
      this->m_null_weight_found = 0;
      this->m_weight = v9 + (float)(m_weight * interpolated_value);
      --this->m_recursion_level;
      return;
    }
  }
  vostok::animation::mixing::n_ary_tree_weight_calculator::remove_transition(this, node);
  --this->m_recursion_level;
}
