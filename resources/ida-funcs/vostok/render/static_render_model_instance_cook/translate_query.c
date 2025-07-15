void __thiscall vostok::render::static_render_model_instance_cook::translate_query(
        vostok::render::static_render_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v4; // ecx
  vostok::particle::particle_action *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  int v7[8]; // [esp+10h] [ebp-138h] BYREF
  vostok::buffer_string v8[22]; // [esp+30h] [ebp-118h] BYREF
  char v9; // [esp+140h] [ebp-8h]

  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fixed_string<260>::fixed_string<260>(v4, v8, requested_path);
  v9 = 47;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v5) )
  {
    v7[0] = 0;
  }
  else
  {
    v7[2] = (int)vostok::render::static_render_model_instance_cook::on_sub_resources_loaded;
    v7[3] = (int)this;
    v7[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::static_render_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::static_render_model_instance_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resource(
    v8[0].m_begin,
    (vostok::variant<32> *)0x13,
    vostok::render::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v7);
}
