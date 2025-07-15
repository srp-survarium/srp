void __thiscall vostok::render::scene_renderer::set_gamma_correction_factor(
        vostok::render::scene_renderer *this,
        boost::function<void __cdecl(void)> *value,
        boost::function<void __cdecl(void)> *a3)
{
  vostok::memory::base_allocator *obj_ptr; // ecx
  vostok::render::base_command *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,float>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<float> > > v7; // [esp-10h] [ebp-6Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+Ch] [ebp-50h] BYREF
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+2Ch] [ebp-30h] BYREF
  void (__thiscall *v10)(vostok::render::engine::world *, float); // [esp+4Ch] [ebp-10h]
  boost::detail::function::vtable_base *vtable; // [esp+50h] [ebp-Ch]
  boost::function<void __cdecl(void)> *v12; // [esp+54h] [ebp-8h]
  vostok::render::functor_command *v13; // [esp+58h] [ebp-4h]
  char v14; // [esp+64h] [ebp+8h]

  v14 = 0;
  v13 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                             (vostok::memory::base_allocator *)value->functor.obj_ptr,
                                             "vostok::render::scene_renderer::set_gamma_correction_factor",
                                             (const char *const)0x115);
  if ( v13 )
  {
    vtable = value->vtable;
    v12 = a3;
    v10 = vostok::render::engine::world::set_gamma_correction_factor;
    v7.l_.a1_.t_ = (vostok::render::engine::world *)vostok::render::engine::world::set_gamma_correction_factor;
    LODWORD(v7.l_.a2_.t_) = vtable;
    v7.f_.f_ = (void (__thiscall *)(vostok::render::engine::world *, float))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(a3, v7, (int)a3);
    obj_ptr = (vostok::memory::base_allocator *)value->functor.obj_ptr;
    on_defer_execution.vtable = 0;
    v14 = 3;
    vostok::render::functor_command::functor_command(
      v13,
      obj_ptr,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      &f);
  }
  else
  {
    v5 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(
    (vostok::render::one_way_render_channel *)(&value->vtable)[1],
    v5);
  if ( (v14 & 2) != 0 )
  {
    v14 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&on_defer_execution);
  }
  if ( (v14 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&f);
}
