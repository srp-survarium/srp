void __thiscall survarium::teammate_cure_event_manager::teammate_cure_event_manager(
        survarium::teammate_cure_event_manager *this,
        const boost::function<void __cdecl(unsigned char)> *event_callback)
{
  boost::detail::function::vtable_base *vtable; // eax
  vostok::particle::particle_action *v4; // ecx
  const boost::function<void __cdecl(unsigned char)> *v5; // eax
  int i; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function<void __cdecl(void)> v8; // [esp+10h] [ebp-3Ch] BYREF
  unsigned __int64 v9; // [esp+30h] [ebp-1Ch]
  boost::function1<void,vostok::physics::contact_point const &> *v10; // [esp+38h] [ebp-14h]
  void (__thiscall *v11)(survarium::teammate_cure_event_manager *, const survarium::curing_event_status *); // [esp+3Ch] [ebp-10h]
  const boost::function<void __cdecl(unsigned char)> *v12; // [esp+40h] [ebp-Ch]
  boost::function1<void,vostok::physics::contact_point const &> *v13; // [esp+44h] [ebp-8h]
  boost::function1<void,vostok::physics::contact_point const &> *v14; // [esp+54h] [ebp+8h]

  event_callback->vtable = 0;
  vtable = this->m_event_callback.vtable;
  if ( this->m_event_callback.vtable )
  {
    event_callback->vtable = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
      qmemcpy((void *)&event_callback->functor, &this->m_event_callback.functor, sizeof(event_callback->functor));
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &this->m_event_callback.functor,
        &event_callback->functor,
        0);
  }
  v4 = (vostok::particle::particle_action *)&event_callback[1];
  v5 = event_callback + 1;
  for ( i = 19; i >= 0; --i )
  {
    v5->vtable = 0;
    v5[1].vtable = 0;
    LOWORD((&v5[1].vtable)[1]) = 0;
    BYTE2((&v5[1].vtable)[1]) = 0;
    v5 = (const boost::function<void __cdecl(unsigned char)> *)((char *)v5 + 40);
  }
  event_callback[26].vtable = 0;
  v14 = (boost::function1<void,vostok::physics::contact_point const &> *)&event_callback[1];
  if ( v4 != (vostok::particle::particle_action *)&event_callback[26] )
  {
    v11 = survarium::teammate_cure_event_manager::on_cured_event;
    do
    {
      v13 = v14;
      v12 = event_callback;
      v9 = __PAIR64__((unsigned int)event_callback, (unsigned int)v11);
      v10 = v14;
      if ( Scaleform::Render::RenderEvent::GetListenerStatus(v4) )
      {
        v8.vtable = 0;
      }
      else
      {
        *(_QWORD *)&v8.functor.obj_ptr = v9;
        v8.functor.vostok_pointer_size_alignment[2] = v10;
        v8.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf1<void,survarium::teammate_cure_event_manager,survarium::curing_event_status const &>,boost::_bi::list2<boost::_bi::value<survarium::teammate_cure_event_manager *>,boost::reference_wrapper<survarium::curing_event_status const>>>>'::`2'::stored_vtable
                                                           + 1);
      }
      boost::function<void __cdecl (void)>::operator=(&v8, v14);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v7,
        (int *)&v8);
      v14 = (boost::function1<void,vostok::physics::contact_point const &> *)((char *)v14 + 40);
    }
    while ( v14 != (boost::function1<void,vostok::physics::contact_point const &> *)&event_callback[26] );
  }
}
