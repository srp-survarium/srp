void __usercall survarium::shared_statistics::shared_statistics(survarium::shared_statistics *this@<ecx>, int a2@<edi>)
{
  survarium::player_shared_statistics *v2; // esi
  int i; // ebx
  vostok::particle::particle_action *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::particle::particle_action *v6; // ecx
  int v7; // ecx
  _BYTE *v8; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v10; // [esp+8h] [ebp-28h] BYREF
  __int64 v11; // [esp+28h] [ebp-8h]

  v2 = (survarium::player_shared_statistics *)a2;
  for ( i = 19; i >= 0; --i )
    survarium::player_shared_statistics::player_shared_statistics(v2++);
  LODWORD(v11) = survarium::shared_statistics::on_teammate_cured_event;
  HIDWORD(v11) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v4) )
  {
    v10.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v10.functor.obj_ptr = v11;
    v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,unsigned char>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::shared_statistics,unsigned char>,boost::_bi::list2<boost::_bi::value<survarium::shared_statistics *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  survarium::teammate_cure_event_manager::teammate_cure_event_manager(
    (survarium::teammate_cure_event_manager *)&v10,
    (const boost::function<void __cdecl(unsigned char)> *)(a2 + 4240));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&v10);
  LODWORD(v11) = survarium::shared_statistics::on_victory_item_event_impl;
  HIDWORD(v11) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v6) )
  {
    v10.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v10.functor.obj_ptr = v11;
    v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::shared_statistics,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>,boost::_bi::list4<boost::_bi::value<survarium::shared_statistics *>,boost::arg<1>,boost::arg<2>,boost::arg<3>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    &v10,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(a2 + 5080));
  v7 = 9;
  v8 = (_BYTE *)(a2 + 5204);
  do
  {
    *v8 = 0;
    v8 += 96;
    --v7;
  }
  while ( v7 >= 0 );
  survarium::victory_item_event_manager::clear((survarium::victory_item_event_manager *)v7, (_DWORD *)(a2 + 5080));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&v10);
  *(_DWORD *)(a2 + 6104) = 0;
  *(_DWORD *)(a2 + 6136) = 0;
  *(_DWORD *)(a2 + 6140) = 0;
  *(_BYTE *)(a2 + 6152) = 0;
  *(_BYTE *)(a2 + 6144) = 0;
  *(_BYTE *)(a2 + 6145) = 0;
  *(_DWORD *)(a2 + 6148) = 255;
}
