void __thiscall survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>>(
        survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> > *this)
{
  s_shotgun_reload_start_substate_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> >_vtbl *)&vostok::resources::cook_base::`vftable';
  s_shotgun_reload_start_substate_cook.m_cook_users_count.m_count = 0;
  s_shotgun_reload_start_substate_cook.m_class_id = weapon_shotgun_reload_start_substate_class;
  s_shotgun_reload_start_substate_cook.m_reuse_type = reuse_false;
  s_shotgun_reload_start_substate_cook.m_creation_thread_id = GetCurrentThreadId();
  s_shotgun_reload_start_substate_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_shotgun_reload_start_substate_cook.m_flags.m_flags = 0;
  s_shotgun_reload_start_substate_cook.m_next = 0;
  s_shotgun_reload_start_substate_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>>::`vftable';
  vostok::resources::resources_manager::register_cook(&s_shotgun_reload_start_substate_cook);
}
