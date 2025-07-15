vostok::math::float4x4 *__userpurge vostok::animation::animation_player::get_object_transform@<eax>(
        vostok::animation::animation_player *this@<ecx>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2@<eax>,
        vostok::math::float4x4 *result,
        void *animated_object)
{
  int *v4; // eax
  vostok::animation::mixing::n_ary_tree *v5; // ecx
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v7; // [esp+4h] [ebp-4h] BYREF

  v4 = (int *)vostok::animation::tree(a2 + 16432, &v7);
  vostok::animation::mixing::n_ary_tree::get_object_transform(v5, *v4, result, animated_object);
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v7);
  return result;
}
