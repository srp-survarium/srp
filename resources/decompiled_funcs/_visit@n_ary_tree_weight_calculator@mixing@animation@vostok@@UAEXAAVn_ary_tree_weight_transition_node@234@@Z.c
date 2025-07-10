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
