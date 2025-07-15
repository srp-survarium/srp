bool __cdecl vostok::ai::selectors::sort_by_name(
        const vostok::ai::sound_item *object1,
        const vostok::ai::sound_item *object2)
{
  const char *v2; // eax
  const char *v4; // [esp-4h] [ebp-8h]

  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object2->name);
  v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object1->name);
  return vostok::strings::less(v2, v4);
}
