void __usercall vostok::animation::animation_player::invert_times(
        vostok::animation::mixing::n_ary_tree *tree@<eax>,
        unsigned int time_in_ms@<edi>)
{
  vostok::animation::mixing::n_ary_tree_animation_node *i; // esi

  for ( i = tree->m_weight_root; i; i = i->m_next_weight_animation )
    vostok::animation::invert_animation_times(i, time_in_ms);
}
