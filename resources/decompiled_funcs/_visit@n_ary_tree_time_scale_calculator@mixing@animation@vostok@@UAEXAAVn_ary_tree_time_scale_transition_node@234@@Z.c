void __userpurge vostok::animation::mixing::n_ary_tree_time_scale_calculator::visit(
        vostok::animation::mixing::n_ary_tree_time_scale_calculator *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *node)
{
  unsigned int m_current_time_in_ms; // ecx
  double v7; // st7
  char v8; // bl
  vostok::animation::mixing::n_ary_tree_base_node *m_result; // eax
  float m_time_scale; // xmm0_4
  int v12; // [esp+4h] [ebp-Ch]
  float v13; // [esp+8h] [ebp-8h]
  float interpolated_value; // [esp+Ch] [ebp-4h]
  float time_scale_from; // [esp+14h] [ebp+4h]

  ++this->m_recursion_level;
  ++this->m_transitions_count;
  m_current_time_in_ms = this->m_current_time_in_ms;
  this->m_interpolator = node->m_interpolator;
  time_scale_from = (double)(m_current_time_in_ms - node->m_start_time_in_ms) * 0.001;
  if ( time_scale_from >= ((double (__thiscall *)(const vostok::animation::base_interpolator *))node->m_interpolator->transition_time)(node->m_interpolator)
    || (v7 = ((double (__stdcall *)(_DWORD))node->m_interpolator->interpolated_value)(LODWORD(time_scale_from)),
        v7 == 1.0) )
  {
    node->m_to->accept(node->m_to, this);
  }
  else
  {
    v8 = 0;
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_base_node *, vostok::animation::mixing::n_ary_tree_time_scale_calculator *, int))node->m_from->accept)(
      node->m_from,
      this,
      a2);
    m_result = this->m_result;
    if ( m_result )
    {
      node->m_from = m_result;
      v8 = 1;
    }
    node->m_to->accept(node->m_to, this);
    m_time_scale = this->m_time_scale;
    if ( !v8 || time_scale_from != m_time_scale )
    {
      interpolated_value = v7;
      this->m_time_scale = (float)((float)(*(float *)&clear_value - interpolated_value) * time_scale_from)
                         + (float)(m_time_scale * interpolated_value);
      --this->m_recursion_level;
      return;
    }
  }
  vostok::animation::mixing::n_ary_tree_time_scale_calculator::remove_transition(node, a3, (int)node, this, v12, v13);
  --this->m_recursion_level;
}
