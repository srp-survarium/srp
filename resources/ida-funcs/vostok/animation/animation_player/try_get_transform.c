char __thiscall vostok::animation::animation_player::try_get_transform(
        vostok::animation::animation_player *this,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *animated_object,
        vostok::math::float4x4 *result,
        vostok::animation::mixing::animated_object_holder *a5)
{
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v5; // ebx
  unsigned int v7; // esi
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v8; // eax
  unsigned int v9; // esi
  bool v10; // bl
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v11; // [esp+4h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v12; // [esp+8h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v13; // [esp+Ch] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v14; // [esp+10h] [ebp-4h] BYREF
  unsigned int m_reference_count; // [esp+1Ch] [ebp+8h]
  vostok::animation::mixing::animated_object_holder *v16; // [esp+1Ch] [ebp+8h]

  v11.m_object = 0;
  v5 = animated_object + 16432;
  if ( !animated_object[16432].m_object )
    return 0;
  m_reference_count = vostok::animation::tree(animated_object + 16432, &v12)->m_object[6].m_reference_count;
  v7 = vostok::animation::tree(v5, &v13)->m_object[9].m_reference_count;
  v8 = vostok::animation::tree(v5, &v14);
  v16 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
          (vostok::animation::mixing::animated_object_holder *)v8->m_object[6].m_reference_count,
          (const void **)&result,
          (vostok::animation::mixing::animated_object_holder *)(m_reference_count + 136 * v7));
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v14);
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v13);
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v12);
  v9 = vostok::animation::tree(v5, &v11)->m_object[6].m_reference_count;
  v10 = v16 != (vostok::animation::mixing::animated_object_holder *)(v9
                                                                   + 136
                                                                   * vostok::animation::tree(
                                                                       v5,
                                                                       (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&result)->m_object[9].m_reference_count)
     && !v16->need_new_transform;
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&result);
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v11);
  if ( !v10 )
    return 0;
  qmemcpy(a5, v16, 0x40u);
  return 1;
}
