void __thiscall survarium::weapon::activate(survarium::weapon *this, BOOL real_insert)
{
  survarium::portable_interactive_object_core *m_portable_interactive_object; // esi
  vostok::animation::hand_to_weapon_ik_solver *v4; // ecx
  bool m_is_double_handed; // al
  bool v6; // al
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  int i; // esi
  int v9; // eax
  boost::function1<void,vostok::physics::contact_point const &> *v10; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  survarium::breath_holding_sound_effect *v12; // ecx
  survarium::player *m_user; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  _BYTE v15[28]; // [esp-1Ch] [ebp-A4h] BYREF
  const void *v16; // [esp+0h] [ebp-88h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation; // [esp+Ch] [ebp-7Ch] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> callback; // [esp+10h] [ebp-78h] BYREF
  _QWORD v19[3]; // [esp+30h] [ebp-58h] BYREF
  boost::function<void __cdecl(void)> v20; // [esp+48h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+68h] [ebp-20h] BYREF

  survarium::weapon_core::activate(this, real_insert);
  m_portable_interactive_object = this->m_portable_interactive_object;
  *(_DWORD *)&v15[24] = this->m_model.m_object->m_render_model.m_object;
  animation.m_object = (vostok::resources::managed_resource *)m_portable_interactive_object;
  vostok::animation::hand_to_weapon_ik_solver::initialize_locators(
    v4,
    (vostok::render::model_locator_item *)&m_portable_interactive_object[1],
    *(vostok::render::render_model_instance **)&v15[24]);
  m_is_double_handed = this->m_is_double_handed;
  callback.vtable = (boost::detail::function::vtable_base *)m_portable_interactive_object;
  LOBYTE((&callback.vtable)[1]) = m_is_double_handed;
  HIDWORD(v19[0]) = 0;
  LODWORD(v19[0]) = survarium::portable_interactive_object::on_weapon_user_sprint;
  callback.functor.data = 0;
  v19[1] = __PAIR64__((unsigned int)(&callback.vtable)[1], (unsigned int)m_portable_interactive_object);
  LODWORD(v19[2]) = callback.functor.obj_ptr;
  *(_DWORD *)v15 = &f;
  qmemcpy(&v15[4], v19, 0x18u);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    0,
    *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::portable_interactive_object,bool,bool>,boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object *>,boost::_bi::value<bool>,boost::_bi::value<bool> > > *)v15,
    *(int *)&v15[24]);
  v6 = this->m_is_double_handed;
  callback.vtable = (boost::detail::function::vtable_base *)animation.m_object;
  LOBYTE((&callback.vtable)[1]) = v6;
  LODWORD(v19[0]) = survarium::portable_interactive_object::on_weapon_user_sprint;
  HIDWORD(v19[0]) = 0;
  callback.functor.data = 1;
  v19[1] = __PAIR64__((unsigned int)(&callback.vtable)[1], (unsigned int)animation.m_object);
  LODWORD(v19[2]) = callback.functor.obj_ptr;
  *(_DWORD *)v15 = &v20;
  qmemcpy(&v15[4], v19, 0x18u);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    0,
    *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::portable_interactive_object,bool,bool>,boost::_bi::list3<boost::_bi::value<survarium::portable_interactive_object *>,boost::_bi::value<bool>,boost::_bi::value<bool> > > *)v15,
    *(int *)&v15[24]);
  for ( i = animation.m_object->m_reconstruction_info_actuality_tick; i; i = *(_DWORD *)(i + 4) )
  {
    v9 = *(_DWORD *)(i + 32);
    if ( v9 == 2 )
    {
      boost::function<void __cdecl (void)>::operator=(
        &v20,
        (boost::function1<void,vostok::physics::contact_point const &> *)(i + 48));
      v10 = (boost::function1<void,vostok::physics::contact_point const &> *)(i + 80);
    }
    else
    {
      if ( v9 != 3 )
        continue;
      boost::function<void __cdecl (void)>::operator=(
        &v20,
        (boost::function1<void,vostok::physics::contact_point const &> *)(i + 384));
      v10 = (boost::function1<void,vostok::physics::contact_point const &> *)(i + 416);
    }
    boost::function<void __cdecl (void)>::operator=(&f, v10);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v20);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&f);
  m_user = (survarium::player *)this->m_user;
  this->m_breath_holding_sound_effect.m_user = m_user;
  if ( !m_user )
    survarium::breath_holding_sound_effect::set_user(
      v12,
      (vostok::sound::sound_instance_proxy *)&this->m_breath_holding_sound_effect);
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)v12,
    (int)this->m_user,
    "shell_extraction",
    this);
  animation.m_object = 0;
  callback.vtable = (boost::detail::function::vtable_base *)survarium::weapon::on_shell_extraction_event;
  (&callback.vtable)[1] = 0;
  callback.functor.obj_ptr = this;
  LODWORD(v19[0]) = survarium::weapon::on_shell_extraction_event;
  HIDWORD(v19[0]) = 0;
  v19[1] = __PAIR64__((unsigned int)callback.functor.vostok_pointer_size_alignment[1], (unsigned int)this);
  *(_DWORD *)&v15[24] = v19;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = v19[0];
    *((_QWORD *)&callback.functor.data + 1) = v19[1];
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &>::assign_to<boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  survarium::base_player::subscribe_animation_player(
    *(survarium::base_player **)&v15[24],
    "shell_extraction",
    &callback,
    this,
    &animation,
    0,
    v16);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&callback);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
}
