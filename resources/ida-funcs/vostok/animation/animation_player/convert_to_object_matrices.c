void __userpurge vostok::animation::animation_player::convert_to_object_matrices(
        vostok::animation::animation_player *this@<ecx>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *a2@<eax>,
        const vostok::animation::skeleton *skeleton,
        vostok::math::float4x4 *local_begin,
        vostok::math::float4x4 *local_end,
        vostok::math::float4x4 *animated_object,
        const unsigned __int8 calc_mask)
{
  vostok::animation::mixing::n_ary_tree **v7; // eax
  unsigned __int8 v8; // [esp+0h] [ebp-8h]
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v9; // [esp+4h] [ebp-4h] BYREF

  v7 = (vostok::animation::mixing::n_ary_tree **)vostok::animation::tree(a2 + 16432, &v9);
  vostok::animation::mixing::n_ary_tree::convert_to_object_matrices(
    *v7,
    local_end,
    skeleton,
    local_begin,
    animated_object,
    v8);
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v9);
}
