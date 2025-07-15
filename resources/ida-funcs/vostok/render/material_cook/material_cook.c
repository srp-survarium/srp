void __thiscall vostok::render::material_cook::material_cook(vostok::render::material_cook *this)
{
  material_cook.__vftable = (vostok::render::material_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  material_cook.m_cook_users_count.m_count = 0;
  material_cook.m_class_id = material_class;
  material_cook.m_reuse_type = reuse_true;
  material_cook.m_creation_thread_id = -1;
  material_cook.m_allocate_thread_id = GetCurrentThreadId();
  material_cook.m_flags.m_flags = 8;
  material_cook.m_next = 0;
  material_cook.__vftable = (vostok::render::material_cook_vtbl *)&vostok::render::material_cook::`vftable';
}
