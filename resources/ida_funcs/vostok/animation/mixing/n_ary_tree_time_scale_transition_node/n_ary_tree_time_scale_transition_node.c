void __userpurge vostok::animation::mixing::n_ary_tree_time_scale_transition_node::n_ary_tree_time_scale_transition_node(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *from@<eax>,
        vostok::animation::mixing::n_ary_tree_base_node *to@<ecx>,
        const vostok::animation::base_interpolator *interpolator,
        unsigned int current_time_in_ms)
{
  const vostok::animation::base_interpolator *v5; // edx
  unsigned int v6; // eax

  v5 = interpolator;
  this->m_to = to;
  this->m_from = from;
  v6 = current_time_in_ms;
  this->m_interpolator = v5;
  this->m_start_time_in_ms = v6;
  this->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`vftable';
  interpolator = (const vostok::animation::base_interpolator *)&vostok::animation::mixing::time_scale_transition_debug::`vftable';
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
    this,
    (vostok::animation::mixing::n_ary_tree_visitor *)&interpolator);
}
