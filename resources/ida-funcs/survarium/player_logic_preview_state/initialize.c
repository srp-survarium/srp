void __thiscall survarium::player_logic_preview_state::initialize(survarium::player_logic_preview_state *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  __int64 v3; // [esp+8h] [ebp-28h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v4; // [esp+10h] [ebp-20h] BYREF

  LODWORD(v3) = survarium::player_logic_preview_state::on_animation_end;
  HIDWORD(v3) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v4.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v4.functor.obj_ptr = v3;
    v4.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::player_logic_preview_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::player_logic_preview_state *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  survarium::weapon_user_animations_selector::set_animation_callback(
    (survarium::weapon_user_animations_selector *)&v3,
    (vostok::animation::reserved_channel_ids_enum)this->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)1,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v4);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v4);
}
