void __thiscall vostok::render::scene_view_cook::scene_view_cook(vostok::render::scene_view_cook *this)
{
  scene_view_cook.__vftable = (vostok::render::scene_view_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  scene_view_cook.m_cook_users_count.m_count = 0;
  scene_view_cook.m_class_id = scene_view_class;
  scene_view_cook.m_reuse_type = reuse_false;
  scene_view_cook.m_creation_thread_id = -1;
  scene_view_cook.m_allocate_thread_id = GetCurrentThreadId();
  scene_view_cook.m_next = 0;
  scene_view_cook.m_flags.m_flags = 8;
  scene_view_cook.__vftable = (vostok::render::scene_view_cook_vtbl *)&vostok::render::scene_view_cook::`vftable';
}
