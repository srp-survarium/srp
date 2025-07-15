void __thiscall survarium::weapon_core_animation_end_aware_state::initialize(
        survarium::weapon_core_animation_end_aware_state *this)
{
  survarium::weapon_core *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v4; // [esp-14h] [ebp-44h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  (&f.vtable)[1] = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_animation_end_aware_state::on_animation_end;
  HIDWORD(v4.f_.f_) = survarium::weapon_core_animation_end_aware_state::on_animation_end;
  *(_QWORD *)&v4.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v4.f_.f_) = &f;
  this->m_animation_has_been_ended = 0;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v4,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::weapon_core::set_animation_callback(
    v2,
    (vostok::animation::reserved_channel_ids_enum)this->m_weapon,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
  this->m_index_of_animation_to_wait = -1;
}
