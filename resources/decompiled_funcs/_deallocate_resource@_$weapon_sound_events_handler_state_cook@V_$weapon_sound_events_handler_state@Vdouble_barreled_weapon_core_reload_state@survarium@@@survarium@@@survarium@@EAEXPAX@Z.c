void __thiscall survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>>::deallocate_resource(
        survarium::weapon_sound_events_handler_state_cook<survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> > *this,
        void *buffer)
{
  void *v2; // esi

  if ( buffer )
  {
    v2 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v2, buffer);
  }
}
