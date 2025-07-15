void __thiscall survarium::project_cooker_simple::project_cooker_simple(
        survarium::project_cooker_simple *this,
        bool editor_present)
{
  s_simple_project_cook.m_cook_users_count.m_count = 0;
  s_simple_project_cook.m_next = 0;
  s_simple_project_cook.m_class_id = client_game_project_class;
  s_simple_project_cook.m_reuse_type = reuse_true;
  s_simple_project_cook.m_creation_thread_id = -1;
  s_simple_project_cook.m_allocate_thread_id = -5;
  s_simple_project_cook.m_flags.m_flags = 8;
  s_simple_project_cook.__vftable = (survarium::project_cooker_simple_vtbl *)&survarium::project_cooker_simple::`vftable';
  s_simple_project_cook.m_editor_present = editor_present;
  vostok::resources::resources_manager::register_cook(&s_simple_project_cook);
}
