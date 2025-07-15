void __thiscall survarium::weapon_core_fire_state_base::deserialize(
        survarium::weapon_core_fire_state_base *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  survarium::weapon_core *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_fire_state_base,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_fire_state_base *>,boost::arg<1> > > v6; // [esp-14h] [ebp-44h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_animation_end_aware_state::deserialize(this, reader, client_reader);
  this->m_keep_shooting = vostok::network_core::buffer_reader::r<bool>(reader);
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *) __thiscall survarium::weapon_core_fire_state_base::`vcall'{40,{flat}};
  (&f.vtable)[1] = 0;
  HIDWORD(v6.f_.f_) =  __thiscall survarium::weapon_core_fire_state_base::`vcall'{40,{flat}};
  *(_QWORD *)&v6.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v6.f_.f_) = &f;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v6,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::weapon_core::set_animation_callback(
    v4,
    (const char *)this->m_weapon,
    "shoot",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
    &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, (int *)&f);
}
