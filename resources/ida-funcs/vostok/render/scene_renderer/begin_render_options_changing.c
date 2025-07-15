void __thiscall vostok::render::scene_renderer::begin_render_options_changing(
        vostok::render::scene_renderer *this,
        volatile int *waiting_for)
{
  vostok::memory::base_allocator *v3; // ecx
  vostok::render::base_command *v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,long volatile *>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<long volatile *> > > v6; // [esp-10h] [ebp-6Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+Ch] [ebp-50h] BYREF
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+2Ch] [ebp-30h] BYREF
  void (__thiscall *v9)(vostok::render::engine::world *, volatile int *); // [esp+4Ch] [ebp-10h]
  vostok::memory::base_allocator *v10; // [esp+50h] [ebp-Ch]
  int v11; // [esp+54h] [ebp-8h]
  vostok::render::functor_command *v12; // [esp+58h] [ebp-4h]
  char v13; // [esp+64h] [ebp+8h]

  v13 = 0;
  v12 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                             *((vostok::memory::base_allocator **)waiting_for + 2),
                                             "vostok::render::scene_renderer::begin_render_options_changing",
                                             (const char *const)0x453);
  if ( v12 )
  {
    v10 = (vostok::memory::base_allocator *)*waiting_for;
    v11 = 0;
    v9 = vostok::render::engine::world::begin_render_options_changing;
    v6.l_.a1_.t_ = (vostok::render::engine::world *)vostok::render::engine::world::begin_render_options_changing;
    v6.l_.a2_.t_ = (volatile int *)v10;
    v6.f_.f_ = (void (__thiscall *)(vostok::render::engine::world *, volatile int *))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v6, 0);
    v3 = (vostok::memory::base_allocator *)*((_DWORD *)waiting_for + 2);
    on_defer_execution.vtable = 0;
    v13 = 3;
    vostok::render::functor_command::functor_command(
      v12,
      v3,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      &f);
  }
  else
  {
    v4 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(
    *((vostok::render::one_way_render_channel **)waiting_for + 1),
    v4);
  if ( (v13 & 2) != 0 )
  {
    v13 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&on_defer_execution);
  }
  if ( (v13 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
}
