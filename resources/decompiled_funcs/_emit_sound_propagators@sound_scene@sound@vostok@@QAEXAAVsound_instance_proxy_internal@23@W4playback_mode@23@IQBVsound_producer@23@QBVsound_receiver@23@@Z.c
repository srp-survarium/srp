void __thiscall vostok::sound::sound_scene::emit_sound_propagators(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy_internal *proxy,
        vostok::sound::playback_mode mode,
        unsigned int playback_id,
        const vostok::sound::sound_producer *const producer,
        const vostok::sound::sound_receiver *const ignorable_receiver)
{
  vostok::sound::sound_order *v6; // eax
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v7; // [esp-50h] [ebp-10Ch] BYREF
  vostok::sound::create_sound_propagator_params v8; // [esp-30h] [ebp-ECh] BYREF
  vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *v9; // [esp+8h] [ebp-B4h]
  vostok::sound::sound_order *v10; // [esp+Ch] [ebp-B0h]
  vostok::sound::sound_scene *thisa; // [esp+10h] [ebp-ACh]
  vostok::sound::world_user *v12; // [esp+1Ch] [ebp-A0h]
  vostok::sound::world_user *user; // [esp+20h] [ebp-9Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // [esp+24h] [ebp-98h]
  vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *v15; // [esp+28h] [ebp-94h]
  vostok::memory::base_allocator *allocator; // [esp+2Ch] [ebp-90h]
  vostok::sound::world_user *m_user; // [esp+30h] [ebp-8Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v18; // [esp+34h] [ebp-88h]
  vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *v19; // [esp+48h] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+4Ch] [ebp-70h] BYREF
  void (__thiscall *f)(vostok::sound::sound_scene *, const vostok::sound::create_sound_propagator_params *); // [esp+60h] [ebp-5Ch]
  int f_4; // [esp+64h] [ebp-58h]
  vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *order; // [esp+68h] [ebp-54h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> functor; // [esp+6Ch] [ebp-50h] BYREF
  vostok::sound::create_sound_propagator_params params; // [esp+8Ch] [ebp-30h] BYREF

  thisa = this;
  params.m_playback_id = playback_id;
  params.m_proxy = proxy;
  params.m_producer = producer;
  params.m_ignorable_receiver = ignorable_receiver;
  params.m_mode = mode;
  params.m_type = point;
  f = vostok::sound::sound_scene::emit_sound_propagators_impl;
  f_4 = 0;
  v8.m_type = (unsigned __int8)1_1;
  v18 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::sound_scene::emit_sound_propagators_impl,
           (survarium::weapon_core_animation_end_aware_state *)this);
  functor.vtable = 0;
  boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
    &functor,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1> > >)v18);
  m_user = proxy->m_user;
  allocator = vostok::sound::world_user::get_allocator(m_user);
  v15 = (vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *)vostok::memory::base_allocator::malloc_impl(allocator, 0x88u);
  v19 = v15;
  if ( v15 )
  {
    qmemcpy(&v8, &params, sizeof(v8));
    v14 = &v7;
    v7.vtable = 0;
    boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to_own(&v7, &functor);
    user = proxy->m_user;
    vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params>::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params>(
      v19,
      user,
      proxy,
      v7,
      v8);
    v10 = v6;
    v9 = (vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *)v6;
  }
  else
  {
    v9 = 0;
  }
  order = v9;
  v12 = proxy->m_user;
  vostok::sound::world_user::add_order(v12, v9);
  boost::function1<void,vostok::sound::create_sound_propagator_params const &>::clear(&functor);
}
