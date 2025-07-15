void __userpurge vostok::animation::mixing::n_ary_tree_time_scale_transition_node::n_ary_tree_time_scale_transition_node(
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *this@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *from@<eax>,
        vostok::animation::mixing::n_ary_tree_base_node *to,
        const vostok::animation::base_interpolator *interpolator,
        unsigned int current_time_in_ms)
{
  this->m_from = from;
  this->m_to = to;
  this->m_interpolator = interpolator;
  this->m_start_time_in_ms = current_time_in_ms;
  this->__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_transition_node_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_transition_node::`vftable';
  to = (vostok::animation::mixing::n_ary_tree_base_node *)&vostok::animation::mixing::time_scale_transition_debug::`vftable';
  vostok::animation::mixing::n_ary_tree_time_scale_transition_node::accept(
    this,
    (vostok::animation::mixing::n_ary_tree_visitor *)&to);
}
