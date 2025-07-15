void __userpurge vostok::animation::mixing::n_ary_tree_weight_calculator::n_ary_tree_weight_calculator(
        vostok::animation::mixing::n_ary_tree_weight_calculator *this@<eax>,
        vostok::animation::mixing::n_ary_tree_animation_node *const animation@<ecx>,
        unsigned int current_time_in_ms)
{
  this->m_animation = animation;
  this->__vftable = (vostok::animation::mixing::n_ary_tree_weight_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_calculator::`vftable';
  this->m_result = 0;
  this->m_recursion_level = 0;
  this->m_current_time_in_ms = current_time_in_ms;
  this->m_weight = 0.0;
  this->m_weight_transition_ended_time_in_ms = 0;
  this->m_transitions_count = 0;
  this->m_null_weight_found = 0;
}
