void __thiscall survarium::damage_model_cook::translate_query(
        survarium::damage_model_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // [esp-10h] [ebp-40h]
  int v6[8]; // [esp+10h] [ebp-20h] BYREF

  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v6[0] = 0;
  }
  else
  {
    v6[2] = (int)survarium::damage_model_cook::on_hit_params_received;
    v6[3] = (int)this;
    v6[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::damage_model_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::damage_model_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  v4 = survarium::g_allocator;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)0x20,
    v4,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, v6);
}
