void __thiscall survarium::player_cook::player_cook(survarium::player_cook *this)
{
  s_player_cook.__vftable = (survarium::player_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_player_cook.m_cook_users_count.m_count = 0;
  s_player_cook.m_class_id = player_class;
  s_player_cook.m_reuse_type = reuse_false;
  s_player_cook.m_creation_thread_id = -1;
  s_player_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_player_cook.m_next = 0;
  s_player_cook.m_flags.m_flags = 8;
  s_player_cook.__vftable = (survarium::player_cook_vtbl *)&survarium::player_cook::`vftable';
}
