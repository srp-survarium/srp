vostok::animation::mixing::n_ary_tree_base_node *__usercall vostok::animation::mixing::n_ary_tree_node_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<esi>)
{
  a2->m_operands_count = 0;
  a2[1].m_operands_count = 0;
  this->visit(this, a2);
  a2[1].m_operands_count = 0;
  return (vostok::animation::mixing::n_ary_tree_base_node *)a2->m_operands_count;
}


unsigned int __usercall vostok::animation::mixing::n_ary_tree_node_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<esi>,
        vostok::animation::mixing::n_ary_tree_addition_node_vtbl *a3@<xmm0>)
{
  unsigned int result; // eax

  a2->m_operands_count = 0;
  a2[2].m_operands_count = 0;
  a2[4].__vftable = a3;
  this->visit(this, a2);
  result = a2->m_operands_count;
  *(float *)&a2[4].__vftable = s_bm_current_air_resistance;
  return result;
}


vostok::animation::mixing::n_ary_tree_base_node *__userpurge vostok::animation::mixing::n_ary_tree_node_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_addition_node *a2@<esi>,
        vostok::animation::mixing::n_ary_tree_base_node *node_to_clone,
        float time_scale_factor,
        float animation_interval_time)
{
  vostok::animation::mixing::n_ary_tree_addition_node_vtbl *v5; // xmm0_4
  vostok::animation::mixing::n_ary_tree_addition_node_vtbl *v6; // xmm0_4
  vostok::animation::mixing::n_ary_tree_base_node *result; // eax

  v5 = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(s_bm_current_air_resistance);
  a2->m_operands_count = 0;
  a2[4].__vftable = v5;
  a2[2].m_operands_count = (unsigned int)&node_to_clone;
  this->visit(this, a2);
  v6 = (vostok::animation::mixing::n_ary_tree_addition_node_vtbl *)LODWORD(s_bm_current_air_resistance);
  a2[2].m_operands_count = 0;
  result = (vostok::animation::mixing::n_ary_tree_base_node *)a2->m_operands_count;
  a2[4].__vftable = v6;
  return result;
}


const vostok::animation::base_interpolator *__userpurge vostok::animation::mixing::n_ary_tree_node_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<ecx>,
        int a2@<eax>,
        const vostok::animation::base_interpolator *interpolator,
        bool assert_on_failure)
{
  const vostok::animation::base_interpolator **v4; // esi
  const vostok::animation::base_interpolator **v5; // edi

  v4 = *(const vostok::animation::base_interpolator ***)(a2 + 16);
  v5 = &v4[*(_DWORD *)(a2 + 28)];
  while ( 1 )
  {
    if ( v4 == v5 )
      return 0;
    if ( !vostok::animation::compare(*v4) )
      break;
    ++v4;
  }
  return *v4;
}
