void __usercall survarium::application::initialize(survarium::application *this@<ecx>, int a2@<eax>)
{
  vostok::particle::particle_action *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  __int64 v5; // [esp+8h] [ebp-28h] BYREF
  boost::function<void __cdecl(void)> v6; // [esp+10h] [ebp-20h] BYREF

  *(_DWORD *)(a2 + 8) = 0;
  survarium::application::preinitialize(this, a2);
  LODWORD(v5) = survarium::application::postinitialize;
  HIDWORD(v5) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v3) )
  {
    v6.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v6.functor.obj_ptr = v5;
    v6.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::application>,boost::_bi::list1<boost::_bi::value<survarium::application *>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  vostok::engine::engine_world::initialize(
    (vostok::engine::engine_world *)&v5,
    (boost::function<void __cdecl(void)> *)s_world_0.m_variable,
    &v6);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v6);
}
