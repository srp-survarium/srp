void __thiscall vostok::animation::animation_collection_cook::animation_collection_cook(
        vostok::animation::animation_collection_cook *this)
{
  s_animation_collection_cook.m_cook_users_count.m_count = 0;
  s_animation_collection_cook.m_class_id = animation_collection_class;
  s_animation_collection_cook.m_reuse_type = reuse_true;
  s_animation_collection_cook.m_creation_thread_id = -1;
  s_animation_collection_cook.m_allocate_thread_id = -4;
  s_animation_collection_cook.m_flags.m_flags = 8;
  s_animation_collection_cook.m_next = 0;
  s_animation_collection_cook.__vftable = (vostok::animation::animation_collection_cook_vtbl *)&vostok::animation::animation_collection_cook::`vftable';
  vostok::resources::resources_manager::register_cook(&s_animation_collection_cook);
}
