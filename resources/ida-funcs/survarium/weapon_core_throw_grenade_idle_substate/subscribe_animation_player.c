void __thiscall survarium::weapon_core_throw_grenade_idle_substate::subscribe_animation_player(
        survarium::weapon_core_throw_grenade_idle_substate *this)
{
  vostok::particle::particle_action *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v4; // [esp+4h] [ebp-2Ch] BYREF
  __int64 v5; // [esp+8h] [ebp-28h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v6; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_throw_grenade_base_substate::subscribe_animation_player(this);
  v4.m_object = 0;
  LODWORD(v5) = vostok::collision::geometry::get_custom_data;
  HIDWORD(v5) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v2) )
  {
    v6.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v6.functor.obj_ptr = v5;
    v6.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_throw_grenade_idle_substate,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_throw_grenade_idle_substate *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&v6,
    (vostok::animation::reserved_channel_ids_enum)this->m_weapon->m_user,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)1,
    &v6,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v4,
    this->m_weapon->m_user);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v6);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v4);
}
