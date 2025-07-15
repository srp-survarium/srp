void __thiscall survarium::weapon_core_throw_grenade_throw_substate::subscribe_animation_player(
        survarium::weapon_core_throw_grenade_throw_substate *this)
{
  vostok::particle::particle_action *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  const void *v4; // [esp+0h] [ebp-30h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v5; // [esp+4h] [ebp-2Ch] BYREF
  __int64 v6; // [esp+8h] [ebp-28h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v7; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_throw_grenade_base_substate::subscribe_animation_player(this);
  v5.m_object = 0;
  LODWORD(v6) = survarium::weapon_core_throw_grenade_throw_substate::on_shoot_event;
  HIDWORD(v6) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v2) )
  {
    v7.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v7.functor.obj_ptr = v6;
    v7.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_throw_grenade_throw_substate,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_throw_grenade_throw_substate *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&v7,
    (int)this->m_weapon->m_user,
    "shoot",
    &v7,
    this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v5,
    this->m_weapon->m_user,
    v4);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v7);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
}
