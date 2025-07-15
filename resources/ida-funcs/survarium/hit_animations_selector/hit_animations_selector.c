void __usercall survarium::hit_animations_selector::hit_animations_selector(
        survarium::hit_animations_selector *this@<ecx>,
        int a2@<edi>)
{
  survarium::hit_animations_selector::hit_body_part *v2; // edx
  int i; // esi
  vostok::particle::particle_action *v4; // ecx
  survarium::hit_animations_selector::hit_body_part *v5; // edx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v7; // [esp+8h] [ebp-28h] BYREF
  __int64 v8; // [esp+28h] [ebp-8h]

  v2 = (survarium::hit_animations_selector::hit_body_part *)a2;
  for ( i = 7; i >= 0; --i )
  {
    survarium::hit_animations_selector::hit_body_part::hit_body_part(v2);
    v2 = v5 + 1;
  }
  *(_DWORD *)(a2 + 192) = 0;
  LODWORD(v8) = survarium::hit_animations_selector::on_damage;
  *(_DWORD *)(a2 + 200) = 0;
  *(_DWORD *)(a2 + 232) = 0;
  *(_DWORD *)(a2 + 240) = 0;
  *(_BYTE *)(a2 + 244) = 0;
  HIDWORD(v8) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v4) )
  {
    v7.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v7.functor.obj_ptr = v8;
    v7.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function4<void,char const *,float,unsigned int,survarium::bullet const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::hit_animations_selector,char const *,float,unsigned int,survarium::bullet const *>,boost::_bi::list5<boost::_bi::value<survarium::hit_animations_selector *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)(a2 + 200),
    &v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&v7);
}
