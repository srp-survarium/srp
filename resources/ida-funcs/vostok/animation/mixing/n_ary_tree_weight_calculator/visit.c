void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_addition_node *node)
{
  float v2; // xmm0_4
  vostok::animation::mixing::n_ary_tree_addition_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_addition_node *v5; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float v7; // [esp+0h] [ebp-4h]

  v2 = 0.0;
  v3 = node + 1;
  v7 = 0.0;
  v5 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)node + 4 * node->m_operands_count + 8);
  while ( v3 != v5 )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_addition_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v3->__vftable,
      this);
    m_result = this->m_result;
    v2 = this->m_weight + v7;
    v7 = v2;
    if ( m_result )
      v3->__vftable = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)m_result;
    v3 = (vostok::animation::mixing::n_ary_tree_addition_node *)((char *)v3 + 4);
  }
  this->m_result = 0;
  this->m_weight = v2;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_animation_node *node)
{
  unsigned int m_operands_count; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float v6; // xmm0_4
  float v7; // [esp+0h] [ebp-8h]
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // [esp+4h] [ebp-4h]

  m_operands_count = node->m_operands_count;
  v3 = node + 1;
  v7 = s_bm_current_air_resistance;
  v8 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 4 * m_operands_count + 88);
  if ( m_operands_count
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v3->__vftable) )
  {
    v3 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)node + 92);
  }
  if ( v3 == v8 )
  {
    v6 = v7;
  }
  else
  {
    do
    {
      (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
       + 2))(
        v3->__vftable,
        this);
      m_result = this->m_result;
      v6 = v7 * this->m_weight;
      v7 = v6;
      if ( m_result )
      {
        if ( node->m_operands_count == m_operands_count )
        {
          v3->__vftable = (vostok::animation::mixing::n_ary_tree_animation_node_vtbl *)m_result;
        }
        else
        {
          v3 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v3 - 4);
          v8 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v8 - 4);
        }
      }
      if ( v6 == 0.0 )
        break;
      v3 = (vostok::animation::mixing::n_ary_tree_animation_node *)((char *)v3 + 4);
    }
    while ( v3 != v8 );
  }
  this->m_result = 0;
  this->m_weight = v6;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *node)
{
  float v2; // xmm0_4
  vostok::animation::mixing::n_ary_tree_multiplication_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_multiplication_node *v5; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float v7; // [esp+0h] [ebp-4h]

  v2 = s_bm_current_air_resistance;
  v3 = node + 1;
  v7 = s_bm_current_air_resistance;
  v5 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)node + 4 * node->m_operands_count + 8);
  while ( v3 != v5 )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_multiplication_node
     + 2))(
      v3->__vftable,
      this);
    v7 = this->m_weight * v7;
    v2 = v7;
    if ( v7 == 0.0 )
      break;
    m_result = this->m_result;
    if ( m_result )
      v3->__vftable = (vostok::animation::mixing::n_ary_tree_multiplication_node_vtbl *)m_result;
    v3 = (vostok::animation::mixing::n_ary_tree_multiplication_node *)((char *)v3 + 4);
  }
  this->m_result = 0;
  this->m_weight = v2;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *node)
{
  float m_weight; // xmm0_4
  vostok::animation::mixing::n_ary_tree_subtraction_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_subtraction_node *v5; // ebx
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float v7; // [esp+0h] [ebp-8h]
  char v8; // [esp+7h] [ebp-1h]

  m_weight = 0.0;
  v3 = node + 1;
  v8 = 1;
  v7 = 0.0;
  v5 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)((char *)node + 4 * node->m_operands_count + 8);
  while ( v3 != v5 )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *, vostok::animation::mixing::n_ary_tree_weight_calculator *))v3->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v3->__vftable,
      this);
    if ( v8 )
    {
      m_weight = this->m_weight;
      v8 = 0;
    }
    else
    {
      m_weight = v7 - this->m_weight;
    }
    m_result = this->m_result;
    v7 = m_weight;
    if ( m_result )
      v3->__vftable = (vostok::animation::mixing::n_ary_tree_subtraction_node_vtbl *)m_result;
    v3 = (vostok::animation::mixing::n_ary_tree_subtraction_node *)((char *)v3 + 4);
  }
  this->m_result = 0;
  this->m_weight = m_weight;
}


void __thiscall vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this,
        vostok::animation::mixing::n_ary_tree_weight_node *node)
{
  double m_weight; // st7

  m_weight = node->m_weight;
  this->m_result = 0;
  this->m_weight = m_weight;
  this->m_null_weight_found = this->m_weight == 0.0;
  this->m_weight_transition_ended_time_in_ms = this->m_current_time_in_ms;
}


void __userpurge vostok::animation::mixing::n_ary_tree_weight_calculator::visit(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this@<ecx>,
        int a2@<ebx>,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *node)
{
  char v5; // bl
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float v7; // xmm0_4
  float m_weight; // [esp+Ch] [ebp-4h]
  float v10; // [esp+18h] [ebp+8h]
  float v11; // [esp+18h] [ebp+8h]

  ++this->m_recursion_level;
  v10 = (double)(this->m_current_time_in_ms - node->m_start_time_in_ms) * 0.001;
  if ( v10 >= ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
    || (v11 = ((double (__stdcall *)(_DWORD))node->m_interpolator->interpolated_value)(LODWORD(v10)), v11 == 1.0) )
  {
    node->m_to->accept(node->m_to, this);
  }
  else
  {
    ++this->m_transitions_count;
    v5 = 0;
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_weight_calculator *, int))node->m_from->accept)(
      node->m_from,
      this,
      a2);
    m_result = this->m_result;
    if ( m_result )
    {
      node->m_from = m_result;
      v5 = 1;
    }
    m_weight = this->m_weight;
    node->m_to->accept(node->m_to, this);
    v7 = this->m_weight;
    if ( !v5 || m_weight != v7 )
    {
      this->m_weight = (float)((float)(s_bm_current_air_resistance - v11) * m_weight) + (float)(v7 * v11);
      goto LABEL_10;
    }
  }
  vostok::animation::mixing::n_ary_tree_weight_calculator::remove_transition(this, node);
LABEL_10:
  --this->m_recursion_level;
}
