char __userpurge vostok::animation::animation_player::tick_impl@<al>(
        vostok::animation::animation_player *this@<ecx>,
        int a2@<esi>,
        float a3@<xmm4>,
        vostok::animation::subscribed_channel **current_time_in_ms,
        const unsigned int ignore_callbacks_time_in_ms,
        const bool __formal)
{
  vostok::animation::mixing::n_ary_tree **v6; // eax
  char v7; // bl
  vostok::animation::animation_player *v8; // ecx
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v10; // [esp+Ch] [ebp-4h] BYREF

  vostok::animation::animation_player::skip_time_if_needed(
    (unsigned int)current_time_in_ms,
    this,
    (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)a2);
  ++*(_WORD *)(a2 + 65748);
  v6 = (vostok::animation::mixing::n_ary_tree **)vostok::animation::tree(
                                                   (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 65728),
                                                   &v10);
  v7 = vostok::animation::mixing::n_ary_tree::tick(
         (vostok::animation::mixing::n_ary_tree *)(a2 + 65736),
         a3,
         *v6,
         current_time_in_ms,
         (vostok::animation::subscribed_channel **)(a2 + 65736),
         (vostok::resources::pinned_ptr_const<unsigned char> *)(a2 + 65750));
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v10);
  if ( !--*(_WORD *)(a2 + 65748) && !*(_BYTE *)(a2 + 65750) )
    vostok::animation::animation_player::compact_callbacks(v8, a2);
  return v7;
}
