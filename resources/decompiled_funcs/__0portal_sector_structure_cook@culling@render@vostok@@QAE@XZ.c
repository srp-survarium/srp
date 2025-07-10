void __thiscall vostok::render::culling::portal_sector_structure_cook::portal_sector_structure_cook(
        vostok::render::culling::portal_sector_structure_cook *this)
{
  s_portal_system_cook.__vftable = (vostok::render::culling::portal_sector_structure_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_portal_system_cook.m_cook_users_count.m_count = 0;
  s_portal_system_cook.m_class_id = portal_sector_structure_class;
  s_portal_system_cook.m_reuse_type = reuse_false;
  s_portal_system_cook.m_creation_thread_id = -1;
  s_portal_system_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_portal_system_cook.m_next = 0;
  s_portal_system_cook.m_flags.m_flags = 8;
  s_portal_system_cook.__vftable = (vostok::render::culling::portal_sector_structure_cook_vtbl *)&vostok::render::culling::portal_sector_structure_cook::`vftable';
}
