void __thiscall survarium::game_statistics_handler::game_statistics_handler(
        survarium::game_statistics_handler *this,
        unsigned int a2)
{
  boost::function1<void,vostok::physics::contact_point const &> *v2; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::physics::contact_point const &> *v4; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-64h] BYREF
  boost::function1<void,vostok::physics::contact_point const &> v8; // [esp+30h] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v9; // [esp+50h] [ebp-24h] BYREF

  *(_DWORD *)a2 = &survarium::game_statistics_handler::`vftable';
  survarium::shared_statistics::shared_statistics((survarium::shared_statistics *)this, a2 + 8);
  *(_DWORD *)(a2 + 6208) = 0;
  *(_DWORD *)(a2 + 6240) = 0;
  *(_DWORD *)(a2 + 6244) = 0;
  *(_BYTE *)(a2 + 6248) = 0;
  memset((void *)(a2 + 6168), 0, 0x28u);
  v9.functor.vostok_pointer_size_alignment[2] = survarium::game_statistics_handler::on_event;
  *(_QWORD *)(&v9.functor.data + 12) = __PAIR64__(a2, 0);
  v8.functor.vostok_pointer_size_alignment[2] = survarium::game_statistics_handler::on_event;
  *(_QWORD *)(&v8.functor.data + 12) = __PAIR64__(a2, 0);
  v8.functor.vostok_pointer_size_alignment[5] = v9.functor.vostok_pointer_size_alignment[5];
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v9.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v9.functor.obj_ptr = *((_QWORD *)&v8.functor.data + 1);
    *((_QWORD *)&v9.functor.data + 1) = *((_QWORD *)&v8.functor.data + 2);
    v9.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_statistics_handler,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>,boost::_bi::list4<boost::_bi::value<survarium::game_statistics_handler *>,boost::arg<1>,boost::arg<2>,boost::arg<3>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&v9, &f);
  v4 = v2;
  if ( (boost::function1<void,vostok::physics::contact_point const &> *)(a2 + 6112) != v2 )
  {
    v8.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v8,
      v2);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v4,
      (boost::function1<void,vostok::physics::contact_point const &> *)(a2 + 6112));
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      (boost::function1<void,vostok::physics::contact_point const &> *)(a2 + 6112),
      &v8);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&v8);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&v9);
}
