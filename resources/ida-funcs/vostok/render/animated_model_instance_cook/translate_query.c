void __thiscall vostok::render::animated_model_instance_cook::translate_query(
        vostok::render::animated_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  int v5[8]; // [esp+10h] [ebp-20h] BYREF

  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v5[0] = 0;
  }
  else
  {
    v5[2] = (int)vostok::render::animated_model_instance_cook::on_config_loaded;
    v5[3] = (int)this;
    v5[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::animated_model_instance_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)0x20,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, v5);
}
