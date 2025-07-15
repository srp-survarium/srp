void __thiscall vostok::animation::mixing::n_ary_tree_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_calculator *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *node)
{
  this->m_result = 0;
  this->m_time_scale = node->m_time_scale;
  this->m_interpolator = node->m_interpolator;
}


void __userpurge vostok::animation::mixing::n_ary_tree_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_calculator *this@<ecx>,
        int a2@<ebx>,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  char v5; // bl
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float v7; // xmm0_4
  float m_time_scale; // [esp+Ch] [ebp-4h]
  float v10; // [esp+18h] [ebp+8h]
  float v11; // [esp+18h] [ebp+8h]

  ++this->m_recursion_level;
  ++this->m_transitions_count;
  this->m_interpolator = node->m_interpolator;
  v10 = (double)(this->m_current_time_in_ms - node->m_start_time_in_ms) * 0.001;
  if ( v10 >= ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
    || (v11 = ((double (__stdcall *)(_DWORD))node->m_interpolator->interpolated_value)(LODWORD(v10)), v11 == 1.0) )
  {
    node->m_to->accept(node->m_to, this);
  }
  else
  {
    v5 = 0;
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_time_scale_calculator *, int))node->m_from->accept)(
      node->m_from,
      this,
      a2);
    m_result = this->m_result;
    if ( m_result )
    {
      node->m_from = m_result;
      v5 = 1;
    }
    m_time_scale = this->m_time_scale;
    node->m_to->accept(node->m_to, this);
    v7 = this->m_time_scale;
    if ( !v5 || m_time_scale != v7 )
    {
      this->m_time_scale = (float)((float)(s_bm_current_air_resistance - v11) * m_time_scale) + (float)(v7 * v11);
      goto LABEL_10;
    }
  }
  vostok::animation::mixing::n_ary_tree_time_scale_calculator::remove_transition(this, node);
LABEL_10:
  --this->m_recursion_level;
}
