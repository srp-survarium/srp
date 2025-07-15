void __thiscall vostok::render::scene_renderer::register_material_parameter(
        vostok::render::scene_renderer *this,
        vostok::render::material_parameter_host *host,
        int a3)
{
  vostok::memory::base_allocator *m_type; // ecx
  vostok::render::base_command *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,vostok::render::material_parameter_host *>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::render::material_parameter_host *> > > v7; // [esp-10h] [ebp-70h]
  boost::function<void __cdecl(void)> *v8; // [esp-4h] [ebp-64h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-50h] BYREF
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+30h] [ebp-30h] BYREF
  void (__thiscall *v11)(vostok::render::engine::world *, vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *); // [esp+50h] [ebp-10h]
  vostok::render::material_parameter_host *v12; // [esp+54h] [ebp-Ch]
  int v13; // [esp+58h] [ebp-8h]
  vostok::render::functor_command *v14; // [esp+5Ch] [ebp-4h]
  char v15; // [esp+68h] [ebp+8h]

  v15 = 0;
  v14 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                             (vostok::memory::base_allocator *)host->m_type,
                                             "vostok::render::scene_renderer::register_material_parameter",
                                             (const char *const)0x3A1);
  if ( v14 )
  {
    v12 = (vostok::render::material_parameter_host *)host->host;
    v13 = a3;
    v11 = vostok::render::engine::world::register_material_parameter;
    v7.l_.a1_.t_ = (vostok::render::engine::world *)vostok::render::engine::world::register_material_parameter;
    v7.l_.a2_.t_ = v12;
    v7.f_.f_ = (void (__thiscall *)(vostok::render::engine::world *, vostok::render::material_parameter_host *))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, v7, a3);
    m_type = (vostok::memory::base_allocator *)host->m_type;
    on_defer_execution.vtable = 0;
    v15 = 3;
    vostok::render::functor_command::functor_command(
      v14,
      m_type,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      &f);
  }
  else
  {
    v5 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back((vostok::render::one_way_render_channel *)host->m_name, v5);
  if ( (v15 & 2) != 0 )
  {
    v15 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&on_defer_execution);
  }
  if ( (v15 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&f);
}
