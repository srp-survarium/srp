char __cdecl vostok::ai::planning::are_targets_similar(
        const vostok::ai::movement_target *first,
        const vostok::ai::planning::movement_target_wrapper *second)
{
  const char *v2; // esi
  const char *v3; // eax
  char v5; // [esp+4h] [ebp-8h]

  v5 = 0;
  if ( vostok::math::operator==(&second->position, &first->target_position) )
  {
    if ( vostok::math::operator==(&second->direction, &first->direction) )
    {
      if ( vostok::math::operator==(&second->velocity, &first->velocity) )
      {
        v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&second->animation_name);
        v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&first->preferable_animation->name);
        if ( vostok::strings::equal(v3, v2) )
          return 1;
      }
    }
  }
  return v5;
}
