void __usercall survarium::game::toggle_pause(survarium::game *this@<ecx>, survarium::game *a2@<edi>)
{
  bool v2; // al
  vostok::sound::world_user *v3; // eax
  float factor; // [esp+0h] [ebp-8h]

  v2 = !a2->m_is_paused;
  a2->m_is_paused = v2;
  if ( v2 )
  {
    survarium::game::pause(a2);
  }
  else
  {
    a2->m_is_paused = 0;
    vostok::timing::timer::resume((vostok::timing::timer *)this, (int)&a2->m_timer);
    factor = a2->m_last_sound_timescale_factor;
    v3 = (vostok::sound::world_user *)((int (*)(void))a2->m_sound_world->get_logic_world_user)();
    vostok::sound::world_user::set_time_scale_factor(v3, factor);
  }
}
