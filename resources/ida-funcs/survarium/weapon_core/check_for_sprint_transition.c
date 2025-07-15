void __thiscall survarium::weapon_core::check_for_sprint_transition(
        survarium::weapon_core *this,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::resources::managed_resource *m_object; // ebx
  _BYTE *v3; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > v5; // [esp-14h] [ebp-48h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-24h] BYREF

  m_object = a2.m_object;
  v3 = (char *)&a2.m_object[4].grm_satisfaction_tree_hook.color_ + 2;
  if ( !BYTE2(a2.m_object[4].grm_satisfaction_tree_hook.color_) )
  {
    if ( ((unsigned __int8 (__thiscall *)(vostok::resources::managed_resource *))a2.m_object->__vftable[2].unlink_child_resource)(a2.m_object) )
    {
      *v3 = 1;
      f.functor.vostok_pointer_size_alignment[3] = 0;
      f.functor.bound_memfunc_ptr.obj_ptr = m_object;
      f.functor.vostok_pointer_size_alignment[2] = survarium::weapon_core::on_sprint_animation_ended;
      HIDWORD(v5.f_.f_) = survarium::weapon_core::on_sprint_animation_ended;
      *(_QWORD *)&v5.l_.a1_.t_ = __PAIR64__((unsigned int)m_object, 0);
      LODWORD(v5.f_.f_) = &f;
      a2.m_object = 0;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        0,
        v5,
        (int)f.functor.vostok_pointer_size_alignment[5]);
      survarium::base_player::subscribe_animation_player(
        (survarium::base_player *)&f,
        (vostok::animation::reserved_channel_ids_enum)m_object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
        (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)3,
        &f,
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)m_object,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&a2,
        (const void *)m_object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v4,
        (int *)&f);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
    }
  }
}
