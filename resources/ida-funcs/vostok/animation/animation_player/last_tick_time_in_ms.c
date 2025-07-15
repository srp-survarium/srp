unsigned int __usercall vostok::animation::animation_player::last_tick_time_in_ms@<eax>(
        vostok::animation::animation_player *this@<ecx>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2@<eax>)
{
  unsigned int m_reference_count; // esi
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v5; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h]

  m_reference_count = 0;
  v3 = a2 + 16432;
  v6 = 0;
  if ( v3->m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v6 = 1;
    m_reference_count = vostok::animation::tree(v3, &v5)->m_object[11].m_reference_count;
  }
  if ( (v6 & 1) != 0 )
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v5);
  return m_reference_count;
}
