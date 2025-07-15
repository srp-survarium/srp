void __thiscall vostok::engine::engine_world::load_level(
        vostok::engine::engine_world *this,
        boost::function<void __cdecl(void)> *project_resource_name)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine_user::world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::engine_user::world *>,boost::_bi::value<char const *> > > v4; // [esp-10h] [ebp-48h]
  boost::function<void __cdecl(void)> f; // [esp+18h] [ebp-20h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(float *))(LODWORD(this[-1].m_timer.m_time_factor) + 104))(&this[-1].m_timer.m_time_factor) )
  {
    ((void (__thiscall *)(vostok::sound::world *volatile, boost::function<void __cdecl(void)> *))this->m_sound_world->~vostok::sound::world)(
      this->m_sound_world,
      project_resource_name);
  }
  else
  {
    v4.l_.a1_.t_ = (vostok::engine_user::world *) __thiscall vostok::engine_user::world::`vcall'{20,{flat}};
    v4.l_.a2_.t_ = (const char *)this->m_sound_world;
    v4.f_.f_ = (void (__thiscall *)(vostok::engine_user::world *, const char *))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      project_resource_name,
      v4,
      (int)project_resource_name);
    run(logic, &f, continue_process_loop, wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&f);
  }
}
