void __thiscall vostok::render::skeleton_combined_render_model_instance_cook::translate_query(
        vostok::render::skeleton_combined_render_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  char *requested_path; // eax
  vostok::fixed_string<260> *v5; // ecx
  vostok::particle::particle_action *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::render::skeleton_combined_cook_data *out_value[4]; // [esp+Ch] [ebp-154h] BYREF
  __int64 v9; // [esp+1Ch] [ebp-144h]
  vostok::resources::query_result_for_cook *v10; // [esp+24h] [ebp-13Ch]
  int v11; // [esp+28h] [ebp-138h] BYREF
  __int64 v12; // [esp+30h] [ebp-130h]
  vostok::resources::query_result_for_cook *v13; // [esp+38h] [ebp-128h]
  vostok::buffer_string v14[22]; // [esp+48h] [ebp-118h] BYREF
  char v15; // [esp+158h] [ebp-8h]

  m_user_data = parent->m_user_data;
  if ( m_user_data )
  {
    out_value[0] = 0;
    vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>(
      (vostok::variant<32> *)this,
      (int)m_user_data,
      out_value);
  }
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fixed_string<260>::fixed_string<260>(v5, v14, requested_path);
  out_value[2] = (vostok::render::skeleton_combined_cook_data *)this;
  out_value[1] = (vostok::render::skeleton_combined_cook_data *)vostok::render::skeleton_combined_render_model_instance_cook::on_resources_loaded;
  out_value[3] = (vostok::render::skeleton_combined_cook_data *)parent;
  LODWORD(v9) = vostok::render::skeleton_combined_render_model_instance_cook::on_resources_loaded;
  HIDWORD(v9) = this;
  v15 = 47;
  v10 = parent;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v6) )
  {
    v11 = 0;
  }
  else
  {
    v12 = v9;
    v13 = v10;
    v11 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_combined_render_model_instance_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_combined_render_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
        + 1;
  }
  vostok::resources::query_resource(
    v14[0].m_begin,
    (vostok::variant<32> *)0x18,
    vostok::render::g_allocator,
    parent->m_user_data,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, &v11);
}
