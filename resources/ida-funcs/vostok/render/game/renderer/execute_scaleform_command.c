void __thiscall vostok::render::game::renderer::execute_scaleform_command(
        vostok::render::game::renderer *this,
        survarium::scaleform_render_command command,
        boost::function<void __cdecl(void)> *a3)
{
  vostok::render::base_command *v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,survarium::scaleform_render_command>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<survarium::scaleform_render_command> > > v6; // [esp-10h] [ebp-6Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+Ch] [ebp-50h] BYREF
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+2Ch] [ebp-30h] BYREF
  void (__thiscall *v9)(vostok::render::engine::world *, survarium::scaleform_render_command); // [esp+4Ch] [ebp-10h]
  Scaleform::Render::ThreadCommand *v10; // [esp+50h] [ebp-Ch]
  boost::function<void __cdecl(void)> *v11; // [esp+54h] [ebp-8h]
  vostok::render::functor_command *v12; // [esp+58h] [ebp-4h]
  char v13; // [esp+64h] [ebp+8h]

  v13 = 0;
  v12 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy>>>(
                                             (vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy> > *)((char *)&dword_200038 + (unsigned int)command.thread_command),
                                             "vostok::render::game::renderer::execute_scaleform_command",
                                             (const char *const)0xE6);
  if ( v12 )
  {
    v10 = *(Scaleform::Render::ThreadCommand **)((char *)&dword_200054 + (unsigned int)command.thread_command);
    v11 = a3;
    v9 = vostok::render::engine::world::execute_scaleform_command;
    v6.l_.a1_.t_ = (vostok::render::engine::world *)vostok::render::engine::world::execute_scaleform_command;
    v6.l_.a2_.t_.thread_command = v10;
    v6.f_.f_ = (void (__thiscall *)(vostok::render::engine::world *, survarium::scaleform_render_command))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(a3, v6, (int)a3);
    on_defer_execution.vtable = 0;
    v13 = 3;
    vostok::render::functor_command::functor_command(
      v12,
      (vostok::memory::base_allocator *)((char *)&dword_200038 + (unsigned int)command.thread_command),
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      &f);
  }
  else
  {
    v4 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(
    *(vostok::render::one_way_render_channel **)((char *)&dword_200050 + (unsigned int)command.thread_command),
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
