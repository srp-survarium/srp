void __thiscall vostok::animation::animation_player::reset(
        vostok::animation::animation_player *this,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *clear_callbacks)
{
  vostok::animation::animation_player *v2; // ecx

  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    clear_callbacks + 16432,
    0);
  vostok::animation::animation_player::clear_callbacks(v2, clear_callbacks);
}
