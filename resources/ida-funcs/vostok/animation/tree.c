vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::animation::tree@<eax>(
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *pointer@<eax>,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2@<edi>)
{
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // esi

  a2->m_object = 0;
  m_object = pointer->m_object;
  if ( pointer->m_object )
  {
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(a2);
    ++m_object->m_reference_count;
    a2->m_object = m_object;
  }
  return a2;
}
