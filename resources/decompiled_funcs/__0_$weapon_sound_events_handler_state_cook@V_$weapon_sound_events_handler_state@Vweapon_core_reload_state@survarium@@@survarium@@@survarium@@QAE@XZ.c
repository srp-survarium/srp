void __thiscall survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>>(
        survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> > *this)
{
  s_reload_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> >_vtbl *)&vostok::resources::cook_base::`vftable';
  s_reload_cook.m_cook_users_count.m_count = 0;
  s_reload_cook.m_class_id = weapon_reload_state_class;
  s_reload_cook.m_reuse_type = reuse_false;
  s_reload_cook.m_creation_thread_id = GetCurrentThreadId();
  s_reload_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_reload_cook.m_flags.m_flags = 0;
  s_reload_cook.m_next = 0;
  s_reload_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>>::`vftable';
  vostok::resources::resources_manager::register_cook(&s_reload_cook);
}
