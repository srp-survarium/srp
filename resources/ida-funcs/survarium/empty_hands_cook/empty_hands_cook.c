void __thiscall survarium::empty_hands_cook::empty_hands_cook(survarium::empty_hands_cook *this)
{
  int v1; // ecx

  s_empty_hands_cook.__vftable = (survarium::empty_hands_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_empty_hands_cook.m_cook_users_count.m_count = 0;
  s_empty_hands_cook.m_class_id = empty_hands_class;
  s_empty_hands_cook.m_reuse_type = reuse_false;
  s_empty_hands_cook.m_creation_thread_id = -1;
  s_empty_hands_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_empty_hands_cook.m_flags.m_flags = 8;
  s_empty_hands_cook.m_next = 0;
  s_empty_hands_cook.__vftable = (survarium::empty_hands_cook_vtbl *)&survarium::empty_hands_cook::`vftable';
  vostok::resources::resources_manager::register_cook(v1, &s_empty_hands_cook);
}
