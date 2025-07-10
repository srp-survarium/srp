void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  vostok::animation::mixing::animation_comparer_predicate v3; // [esp+6h] [ebp-2h] BYREF

  v3.m_use_synchronized_animations = 1;
  v3.m_use_overriding_animations = 1;
  this->result = vostok::animation::mixing::animation_comparer_predicate::operator()(&v3, left, right);
}
