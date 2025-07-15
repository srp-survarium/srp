void __thiscall survarium::base_player::set_resolvers(
        survarium::base_player *this,
        vostok::animation::animation_player *animation_player,
        boost::function1<void,vostok::physics::contact_point const &> *registry)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  const boost::function<void const * __cdecl(unsigned char)> *v9; // [esp+0h] [ebp-E0h]
  boost::function<fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> __cdecl(unsigned char)> time_calculator_resolver; // [esp+10h] [ebp-D0h] BYREF
  boost::function<unsigned char __cdecl(fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> const &)> time_calculator_id_resolver; // [esp+30h] [ebp-B0h] BYREF
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> animation_resolver; // [esp+50h] [ebp-90h] BYREF
  boost::function<unsigned short __cdecl(vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &)> animation_id_resolver; // [esp+70h] [ebp-70h] BYREF
  boost::function<unsigned char __cdecl(void const *)> animated_object_id_resolver; // [esp+90h] [ebp-50h] BYREF
  int v15[2]; // [esp+B0h] [ebp-30h] BYREF
  __int64 v16; // [esp+B8h] [ebp-28h]
  __int64 v17; // [esp+C0h] [ebp-20h]
  unsigned __int64 v18; // [esp+C8h] [ebp-18h]
  unsigned __int8 (__thiscall *v19)(survarium::base_player *, const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *); // [esp+D0h] [ebp-10h]
  int v20; // [esp+D4h] [ebp-Ch]
  __int64 v21; // [esp+D8h] [ebp-8h]

  v19 = (unsigned __int8 (__thiscall *)(survarium::base_player *, const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *))survarium::base_player::animated_object_resolver;
  v20 = 0;
  LODWORD(v21) = animation_player;
  LODWORD(v17) = survarium::base_player::animated_object_resolver;
  HIDWORD(v17) = 0;
  v18 = __PAIR64__(HIDWORD(v21), (unsigned int)animation_player);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    time_calculator_resolver.vtable = 0;
  }
  else
  {
    *(_QWORD *)&time_calculator_resolver.functor.obj_ptr = v17;
    *((_QWORD *)&time_calculator_resolver.functor.data + 1) = v18;
    time_calculator_resolver.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void const *,unsigned char>::assign_to<boost::_bi::bind_t<void const *,boost::_mfi::mf1<void const *,survarium::base_player,unsigned char>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                             + 1);
  }
  v19 = (unsigned __int8 (__thiscall *)(survarium::base_player *, const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *))survarium::base_player::time_calculator_resolver;
  v20 = 0;
  LODWORD(v21) = animation_player;
  LODWORD(v17) = survarium::base_player::time_calculator_resolver;
  HIDWORD(v17) = 0;
  v18 = __PAIR64__(HIDWORD(v21), (unsigned int)animation_player);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    animation_resolver.vtable = 0;
  }
  else
  {
    *(_QWORD *)&animation_resolver.functor.obj_ptr = v17;
    *((_QWORD *)&animation_resolver.functor.data + 1) = v18;
    animation_resolver.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::assign_to<boost::_bi::bind_t<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,boost::_mfi::cmf1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,survarium::base_player,unsigned char>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                       + 1);
  }
  LODWORD(v21) = survarium::base_player::animation_resolver;
  HIDWORD(v21) = &survarium::g_animations_registry;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)&survarium::g_animations_registry) )
  {
    animated_object_id_resolver.vtable = 0;
  }
  else
  {
    *(_QWORD *)&animated_object_id_resolver.functor.obj_ptr = v21;
    animated_object_id_resolver.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned short>::assign_to<boost::_bi::bind_t<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (__cdecl *)(survarium::animations_registry &,unsigned short),boost::_bi::list2<boost::reference_wrapper<survarium::animations_registry>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                                + 1);
  }
  v19 = (unsigned __int8 (__thiscall *)(survarium::base_player *, const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *))survarium::base_player::animated_object_id_resolver;
  v20 = 0;
  LODWORD(v21) = animation_player;
  LODWORD(v17) = survarium::base_player::animated_object_id_resolver;
  HIDWORD(v17) = 0;
  v18 = __PAIR64__(HIDWORD(v21), (unsigned int)animation_player);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    time_calculator_id_resolver.vtable = 0;
  }
  else
  {
    *(_QWORD *)&time_calculator_id_resolver.functor.obj_ptr = v17;
    *((_QWORD *)&time_calculator_id_resolver.functor.data + 1) = v18;
    time_calculator_id_resolver.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<unsigned char,void const *>::assign_to<boost::_bi::bind_t<unsigned char,boost::_mfi::mf1<unsigned char,survarium::base_player,void const *>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                                + 1);
  }
  v19 = survarium::base_player::time_calculator_id_resolver;
  v20 = 0;
  LODWORD(v21) = animation_player;
  LODWORD(v17) = survarium::base_player::time_calculator_id_resolver;
  HIDWORD(v17) = 0;
  v18 = __PAIR64__(HIDWORD(v21), (unsigned int)animation_player);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    animation_id_resolver.vtable = 0;
  }
  else
  {
    *(_QWORD *)&animation_id_resolver.functor.obj_ptr = v17;
    *((_QWORD *)&animation_id_resolver.functor.data + 1) = v18;
    animation_id_resolver.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<unsigned char,fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)> const &>::assign_to<boost::_bi::bind_t<unsigned char,boost::_mfi::cmf1<unsigned char,survarium::base_player,fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)> const &>,boost::_bi::list2<boost::_bi::value<survarium::base_player *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                          + 1);
  }
  LODWORD(v21) = survarium::base_player::animation_id_resolver;
  HIDWORD(v21) = &survarium::g_animations_registry;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)&survarium::g_animations_registry) )
  {
    v15[0] = 0;
  }
  else
  {
    v16 = v21;
    v15[0] = (int)&`boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &>::assign_to<boost::_bi::bind_t<unsigned short,unsigned short (__cdecl *)(survarium::animations_registry &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &),boost::_bi::list3<boost::reference_wrapper<survarium::animations_registry>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::animation::animation_player::set_resolvers(
    (vostok::animation::animation_player *)v15,
    registry,
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&animation_id_resolver,
    (boost::function<void __cdecl(float)> *)&time_calculator_id_resolver,
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&animated_object_id_resolver,
    (boost::function<void __cdecl(float)> *)&animation_resolver,
    (boost::function<void __cdecl(float)> *)&time_calculator_resolver,
    v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, v15);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&animation_id_resolver);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&time_calculator_id_resolver);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&animated_object_id_resolver);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&animation_resolver);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&time_calculator_resolver);
}
