void __thiscall vostok::render::scene_renderer::reload_modified_textures(vostok::render::scene_renderer *this)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::render::base_command *v3; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *> > > v5; // [esp-8h] [ebp-60h]
  int v6; // [esp+0h] [ebp-58h]
  char v7; // [esp+10h] [ebp-48h]
  vostok::render::functor_command *v8; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> on_execute; // [esp+38h] [ebp-20h] BYREF

  v7 = 0;
  v8 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                            this->m_allocator,
                                            "vostok::render::scene_renderer::reload_modified_textures",
                                            (const char *const)0x393);
  if ( v8 )
  {
    v5.l_.a1_.t_ = this->m_render_engine_world;
    v5.f_.f_ = vostok::render::engine::world::reload_modified_textures;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::render::engine::world::reload_modified_textures,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *> > > *)&on_execute,
      v5,
      v6);
    m_allocator = this->m_allocator;
    on_defer_execution.vtable = 0;
    v7 = 3;
    vostok::render::functor_command::functor_command(
      v8,
      m_allocator,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_execute);
  }
  else
  {
    v3 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(this->m_channel, v3);
  if ( (v7 & 2) != 0 )
  {
    v7 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&on_defer_execution);
  }
  if ( (v7 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&on_execute);
}
