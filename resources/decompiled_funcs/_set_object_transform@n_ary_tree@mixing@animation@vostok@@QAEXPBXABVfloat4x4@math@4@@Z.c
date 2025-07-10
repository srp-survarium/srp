void __userpurge vostok::animation::mixing::n_ary_tree::set_object_transform(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm4>,
        const void *animated_object,
        const vostok::math::float4x4 *object_transform)
{
  const void *v5; // ebx
  vostok::animation::mixing::n_ary_tree *v7; // esi
  vostok::animation::mixing::animated_object_holder *v8; // eax

  v5 = animated_object;
  v7 = *(vostok::animation::mixing::n_ary_tree **)(a2 + 4);
  if ( v7 )
  {
    do
    {
      if ( (const void *)v7->m_interpolators_count == v5 )
        vostok::animation::mixing::n_ary_tree::set_object_transform(v7, a3);
      v7 = (vostok::animation::mixing::n_ary_tree *)v7->m_tree_actual_time_in_ms;
    }
    while ( v7 );
    v8 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
           *(vostok::animation::mixing::animated_object_holder **)(a2 + 24),
           (vostok::animation::mixing::animated_object_holder *)(*(_DWORD *)(a2 + 24) + 136 * *(_DWORD *)(a2 + 32)),
           &animated_object);
    qmemcpy(v8, object_transform, 0x40u);
  }
}
