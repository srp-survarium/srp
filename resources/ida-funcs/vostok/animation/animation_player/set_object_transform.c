void __userpurge vostok::animation::animation_player::set_object_transform(
        vostok::animation::animation_player *this@<ecx>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2@<eax>,
        float a3@<xmm4>,
        const vostok::math::float4x4 *object_transform,
        void *animated_object)
{
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  int *v6; // eax
  vostok::animation::mixing::n_ary_tree *v7; // ecx
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v8; // [esp+4h] [ebp-4h] BYREF

  v5 = a2 + 16432;
  if ( v5->m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v6 = (int *)vostok::animation::tree(v5, &v8);
      vostok::animation::mixing::n_ary_tree::set_object_transform(v7, *v6, a3, animated_object, object_transform);
      vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v8);
    }
  }
}
