vostok::particle::base_particle *__usercall vostok::particle::particle_world::allocate_particle@<eax>(
        vostok::particle::particle_world *this@<ecx>,
        unsigned int a2@<ebx>)
{
  vostok::particle::base_particle *v3; // eax
  survarium::game_world *v4; // ecx
  _BYTE *v5; // eax
  vostok::particle::base_particle *v7; // [esp+0h] [ebp-BCh]
  void *_Where; // [esp+A8h] [ebp-14h]
  vostok::particle::base_particle *v10; // [esp+B0h] [ebp-Ch]
  bool do_debug_break; // [esp+B7h] [ebp-5h] BYREF
  vostok::particle::base_particle *particle; // [esp+B8h] [ebp-4h]

  if ( this->m_num_particles + 1 > this->m_max_particles )
    return 0;
  _Where = vostok::memory::base_allocator::malloc_impl(&this->m_allocator, 0xD0u);
  v10 = (vostok::particle::base_particle *)operator new(0xD0u, _Where);
  if ( v10 )
  {
    vostok::particle::base_particle::base_particle(v10);
    v7 = v3;
  }
  else
  {
    v7 = 0;
  }
  particle = v7;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v7);
  if ( !*v5 || debug_macro_helper_ignore_always_23 || particle )
  {
    vostok::particle::base_particle::set_defaults(particle);
    ++this->m_num_particles;
    return particle;
  }
  else
  {
    if ( occurances_left_23 == -1 )
      occurances_left_23 = vostok::ui::ui_dialog::input_priority(v4);
    if ( occurances_left_23-- )
    {
      if ( !debug_macro_helper_ignore_always_23 )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          a2,
          &do_debug_break,
          process_error_false,
          &debug_macro_helper_ignore_always_23,
          assert_untyped,
          "assertion_failed",
          "particle",
          ".\\particle_world.cpp",
          "vostok::particle::particle_world::allocate_particle",
          0x5Bu);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
