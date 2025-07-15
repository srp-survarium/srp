void __usercall vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::n_ary_tree_target_time_scale_calculator(
        vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *this@<edi>,
        vostok::animation::mixing::n_ary_tree_animation_node *node@<eax>)
{
  vostok::animation::mixing::n_ary_tree_animation_node_vtbl *v2; // esi

  this->__vftable = (vostok::animation::mixing::n_ary_tree_target_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_target_time_scale_calculator::`vftable';
  if ( node->m_operands_count
    && (v2 = node[1].__vftable) != 0
    && (*((unsigned __int8 (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *))v2->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
        + 3))(v2) )
  {
    (*((void (__thiscall **)(vostok::animation::mixing::n_ary_tree_animation_node_vtbl *, vostok::animation::mixing::n_ary_tree_target_time_scale_calculator *))v2->~vostok::animation::mixing::n_ary_tree_n_ary_operation_node
     + 2))(
      v2,
      this);
  }
  else
  {
    LODWORD(this->m_result) = clear_value;
  }
}
