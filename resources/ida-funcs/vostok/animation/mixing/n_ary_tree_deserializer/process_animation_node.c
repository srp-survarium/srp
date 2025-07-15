void __usercall vostok::animation::mixing::n_ary_tree_deserializer::process_animation_node(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<eax>,
        vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *node@<edi>)
{
  unsigned int v3; // eax
  vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *v4; // ebx
  vostok::animation::mixing::n_ary_tree_deserializer *v5; // ecx
  vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *v6; // [esp+8h] [ebp-4h]

  node->time_calculator = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 4u);
  v3 = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u) + 1;
  node->animation_intervals_count = v3;
  v4 = node;
  v6 = (vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *)((char *)node + 8 * v3);
  if ( node != v6 )
  {
    do
    {
      v4->intervals.elems[0].animation = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 0xAu);
      v4->intervals.elems[0].animation_interval = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u);
      v4 = (vostok::animation::mixing::n_ary_tree_deserializer::n_ary_tree_animation_node_helper *)((char *)v4 + 8);
    }
    while ( v4 != v6 );
  }
  node->is_time_driving_animation = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u);
  node->weight_interpolator = vostok::animation::mixing::n_ary_tree_deserializer::get_interpolator(v5, this);
  node->animated_object = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u);
  node->user_data = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u);
  node->time_synchronization_group_id = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 4u);
  node->weight_synchronization_group_id = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 2u);
  node->playback_type = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u);
  node->additivity_priority = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 3u);
  node->bones_mask = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 2u);
  node->unique_animation_id = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 2u);
  node->can_generate_events = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u);
  node->operands_count = vostok::animation::mixing::n_ary_tree_deserializer::r(this, 2u);
}
