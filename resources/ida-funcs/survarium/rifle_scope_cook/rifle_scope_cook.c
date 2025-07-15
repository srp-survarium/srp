void __thiscall survarium::rifle_scope_cook::rifle_scope_cook(survarium::rifle_scope_cook *this)
{
  int v1; // ecx

  s_rifle_scope_cook.__vftable = (survarium::rifle_scope_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_rifle_scope_cook.m_cook_users_count.m_count = 0;
  s_rifle_scope_cook.m_class_id = rifle_scope_class;
  s_rifle_scope_cook.m_reuse_type = reuse_false;
  s_rifle_scope_cook.m_creation_thread_id = -1;
  s_rifle_scope_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_rifle_scope_cook.m_flags.m_flags = 8;
  s_rifle_scope_cook.m_next = 0;
  s_rifle_scope_cook.__vftable = (survarium::rifle_scope_cook_vtbl *)&survarium::rifle_scope_cook::`vftable';
  vostok::resources::resources_manager::register_cook(v1, &s_rifle_scope_cook);
}
