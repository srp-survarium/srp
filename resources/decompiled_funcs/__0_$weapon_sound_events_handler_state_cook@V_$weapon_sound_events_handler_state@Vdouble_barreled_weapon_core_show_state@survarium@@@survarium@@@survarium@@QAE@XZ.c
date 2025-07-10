void __thiscall survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state>>::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state>>(
        survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state> > *this)
{
  s_double_barreled_show_state_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state> >_vtbl *)&vostok::resources::cook_base::`vftable';
  s_double_barreled_show_state_cook.m_cook_users_count.m_count = 0;
  s_double_barreled_show_state_cook.m_class_id = double_barreled_weapon_show_state_class;
  s_double_barreled_show_state_cook.m_reuse_type = reuse_false;
  s_double_barreled_show_state_cook.m_creation_thread_id = GetCurrentThreadId();
  s_double_barreled_show_state_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_double_barreled_show_state_cook.m_flags.m_flags = 0;
  s_double_barreled_show_state_cook.m_next = 0;
  s_double_barreled_show_state_cook.__vftable = (survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state> >_vtbl *)&survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_show_state>>::`vftable';
  vostok::resources::resources_manager::register_cook(&s_double_barreled_show_state_cook);
}
