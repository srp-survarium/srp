void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  vostok::animation::mixing::n_ary_tree_time_scale_node *v3; // esi
  float m_time_scale; // xmm0_4
  vostok::animation::mixing::n_ary_tree_time_scale_node *v5; // edi
  float v6; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  v3 = left;
  m_time_scale = left->m_time_scale;
  v5 = right;
  v6 = right->m_time_scale;
  if ( v6 > m_time_scale
    || m_time_scale <= v6
    && (left->m_interpolator->accept(
          left->m_interpolator,
          (vostok::animation::interpolator_comparer *)&left,
          right->m_interpolator),
        left == (vostok::animation::mixing::n_ary_tree_time_scale_node *)1) )
  {
    this->result = less;
  }
  else
  {
    v8 = v5->m_time_scale;
    v9 = v3->m_time_scale;
    if ( v9 <= v8 )
    {
      if ( v8 <= v9 )
      {
        v5->m_interpolator->accept(
          v5->m_interpolator,
          (vostok::animation::interpolator_comparer *)&left,
          v3->m_interpolator);
        this->result = left == (vostok::animation::mixing::n_ary_tree_time_scale_node *)1 ? more : equal;
      }
      else
      {
        this->result = equal;
      }
    }
    else
    {
      this->result = more;
    }
  }
}
