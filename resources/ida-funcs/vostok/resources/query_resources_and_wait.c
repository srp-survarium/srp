void __usercall vostok::resources::query_resources_and_wait(
        const vostok::resources::query_resource_params *in_params@<eax>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  vostok::resources::resources_manager *v4; // ecx
  vostok::command_line::key *v5; // ecx
  vostok::command_line::key *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::resources::query_resource_params params; // [esp+8h] [ebp-B8h] BYREF
  char v9; // [esp+70h] [ebp-50h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v10; // [esp+78h] [ebp-48h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+98h] [ebp-28h] BYREF
  __int64 v12; // [esp+B8h] [ebp-8h]

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&in_params->callback,
    &f);
  v9 = 0;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&f, &v10);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v2, (int *)&f);
  vostok::resources::query_resource_params::query_resource_params(&params, in_params);
  HIDWORD(v12) = &v9;
  LODWORD(v12) = vostok::resources::query_resources_and_wait_callback_proxy_pred::callback;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)vostok::resources::query_resources_and_wait_callback_proxy_pred::callback) )
  {
    f.vtable = 0;
  }
  else
  {
    *(_QWORD *)&f.functor.obj_ptr = v12;
    f.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::query_resources_and_wait_callback_proxy_pred,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::resources::query_resources_and_wait_callback_proxy_pred *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                      + 1);
  }
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)&params.callback,
    (boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
  vostok::resources::resources_manager::query_resources_impl(v4, &params);
  while ( !v9 )
  {
    if ( vostok::command_line::key::is_set(v5, (int)&vostok::threading::g_debug_single_thread) )
      vostok::resources::tick(v6);
    vostok::resources::dispatch_callbacks(v6);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
    (int *)&params.callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v10);
}
