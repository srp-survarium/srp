void __thiscall vostok::render::game::renderer::end_frame(vostok::render::game::renderer *this, int a2)
{
  vostok::render::base_command *v2; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::world>,boost::_bi::list1<boost::_bi::value<vostok::render::world *> > > v4; // [esp-8h] [ebp-60h]
  int v5; // [esp+0h] [ebp-58h]
  char v6; // [esp+10h] [ebp-48h]
  vostok::render::functor_command *v7; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> on_execute; // [esp+38h] [ebp-20h] BYREF

  v6 = 0;
  v7 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy>>>(
                                            (vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy> > *)((char *)&dword_200038 + a2),
                                            "vostok::render::game::renderer::end_frame",
                                            (const char *const)0x6A);
  if ( v7 )
  {
    v4.l_.a1_.t_ = *(vostok::render::world **)((char *)&dword_200050 + a2);
    v4.f_.f_ = vostok::render::world::end_frame_logic;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::render::world::end_frame_logic,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::world>,boost::_bi::list1<boost::_bi::value<vostok::render::world *> > > *)&on_execute,
      v4,
      v5);
    on_defer_execution.vtable = 0;
    v6 = 3;
    vostok::render::functor_command::functor_command(
      v7,
      (vostok::memory::base_allocator *)((char *)&dword_200038 + a2),
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_execute);
  }
  else
  {
    v2 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(
    *(vostok::render::one_way_render_channel **)((char *)&dword_200050 + a2),
    v2);
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&on_defer_execution);
  }
  if ( (v6 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&on_execute);
}
