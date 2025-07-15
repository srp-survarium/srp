void __usercall survarium::weapon_user_animations_selector::activate(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v4; // [esp+8h] [ebp-30h] BYREF
  __int64 v5; // [esp+2Ch] [ebp-Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v6; // [esp+34h] [ebp-4h] BYREF

  v6.m_object = 0;
  LODWORD(v5) = survarium::weapon_user_animations_selector::on_interval_ended;
  HIDWORD(v5) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v4.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v4.functor.obj_ptr = v5;
    v4.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_user_animations_selector,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_user_animations_selector *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&v4,
    *(vostok::animation::reserved_channel_ids_enum *)(a2 + 60),
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)2,
    &v4,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)a2,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v6,
    *(const void **)(a2 + 60));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v4);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
}
