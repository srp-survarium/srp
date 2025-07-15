void __thiscall vostok::render::tracer_model_instance_cook::translate_query(
        vostok::render::tracer_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // esi
  int v3; // edx
  vostok::particle::particle_action *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  int v6; // [esp+Ch] [ebp-24h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  v6 = v3;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v4) )
  {
    v7[0] = 0;
  }
  else
  {
    v7[2] = (int)vostok::render::tracer_model_instance_cook::on_model_ready;
    v7[3] = v6;
    v7[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::tracer_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::tracer_model_instance_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)0x10,
    vostok::render::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v7);
}
