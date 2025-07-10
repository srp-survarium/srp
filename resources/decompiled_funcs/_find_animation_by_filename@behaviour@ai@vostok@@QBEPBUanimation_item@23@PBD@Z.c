const vostok::ai::animation_item *__thiscall vostok::ai::behaviour::find_animation_by_filename(
        vostok::ai::behaviour *this,
        const char *animation_filename)
{
  const char *v2; // eax
  const vostok::ai::animation_item *it; // [esp+10h] [ebp-Ch]
  const vostok::ai::animation_item *it_end; // [esp+18h] [ebp-4h]

  it_end = (const vostok::ai::animation_item *)((char *)&this[1] + 280 * this->m_animations_count);
  for ( it = (const vostok::ai::animation_item *)&this[1]; it != it_end; ++it )
  {
    v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&it->name);
    if ( vostok::strings::equal(v2, animation_filename) )
      return it;
  }
  return 0;
}
