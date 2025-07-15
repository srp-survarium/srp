void __userpurge survarium::breath_holding_sound_effect::breath_holding_sound_effect(
        survarium::breath_holding_sound_effect *this@<edi>,
        survarium::base_game_scene *game_scene@<eax>,
        vostok::particle::particle_action *a3@<ecx>,
        boost::function1<void,vostok::physics::contact_point const &> *breath_calculator)
{
  boost::function1<void,vostok::physics::contact_point const &> *v4; // esi
  boost::function1<void,vostok::physics::contact_point const &> *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+8h] [ebp-6Ch] BYREF
  boost::function1<void,vostok::physics::contact_point const &> v10; // [esp+28h] [ebp-4Ch] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v11; // [esp+48h] [ebp-2Ch] BYREF
  __int64 v12; // [esp+68h] [ebp-Ch]
  boost::function1<void,vostok::physics::contact_point const &> *v13; // [esp+7Ch] [ebp+8h]

  this->m_game_scene = game_scene;
  LODWORD(v12) = survarium::breath_holding_sound_effect::on_breath_held;
  this->m_sound_instance.m_object = 0;
  this->m_user = 0;
  this->m_breath_held = 0;
  HIDWORD(v12) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(a3) )
  {
    v11.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v11.functor.obj_ptr = v12;
    v11.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::breath_holding_sound_effect,bool>,boost::_bi::list2<boost::_bi::value<survarium::breath_holding_sound_effect *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  v4 = (boost::function1<void,vostok::physics::contact_point const &> *)(*((_DWORD *)breath_calculator->functor.obj_ptr
                                                                         + 1)
                                                                       + 40);
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&v11, &f);
  v13 = v5;
  if ( v4 != v5 )
  {
    v10.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v10,
      v5);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v13,
      v4);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v4,
      &v10);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&v10);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, (int *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v11);
}
