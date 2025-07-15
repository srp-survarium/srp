void __thiscall vostok::render::skeleton_combined_model_instance_cook::translate_query(
        vostok::render::skeleton_combined_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::particle::particle_action *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::variant<32> *v5; // ecx
  vostok::render::skeleton_combined_cook_data *out_value; // [esp+10h] [ebp-88h] BYREF
  vostok::render::skeleton_combined_model_instance_cook *v7; // [esp+14h] [ebp-84h]
  const vostok::variant<32> *v8[2]; // [esp+18h] [ebp-80h] BYREF
  vostok::resources::request v9; // [esp+20h] [ebp-78h] BYREF
  char *m_begin; // [esp+28h] [ebp-70h]
  int v11; // [esp+2Ch] [ebp-6Ch]
  void (__thiscall *v12)(vostok::render::skeleton_combined_model_instance_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *); // [esp+30h] [ebp-68h]
  vostok::render::skeleton_combined_model_instance_cook *v13; // [esp+34h] [ebp-64h]
  vostok::resources::query_result_for_cook *v14; // [esp+38h] [ebp-60h]
  void (__thiscall *v15)(vostok::render::skeleton_combined_model_instance_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *); // [esp+3Ch] [ebp-5Ch]
  int v16; // [esp+40h] [ebp-58h]
  vostok::resources::query_result_for_cook *v17; // [esp+44h] [ebp-54h]
  int v18[8]; // [esp+48h] [ebp-50h] BYREF
  _BYTE v19[40]; // [esp+68h] [ebp-30h] BYREF
  int v20; // [esp+90h] [ebp-8h]
  int v21; // [esp+94h] [ebp-4h]

  m_user_data = parent->m_user_data;
  v7 = this;
  v20 = 0;
  v21 = 0;
  out_value = 0;
  if ( m_user_data )
    vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>(
      (vostok::variant<32> *)this,
      (int)m_user_data,
      &out_value);
  vostok::variant<32>::set<vostok::render::skeleton_combined_cook_data *>(
    (vostok::variant<32> *)this,
    (int)v19,
    &out_value);
  v8[0] = (const vostok::variant<32> *)v19;
  v8[1] = 0;
  v9.path = vostok::resources::query_result_for_user::get_requested_path(parent);
  v9.id = skeleton_combined_render_model_instance_class;
  if ( out_value )
    m_begin = out_value->skeleton_name.m_string.m_begin;
  else
    m_begin = "resources/animations/skeletons/scavengers_01";
  v13 = v7;
  v12 = vostok::render::skeleton_combined_model_instance_cook::on_resources_loaded;
  v14 = parent;
  v15 = vostok::render::skeleton_combined_model_instance_cook::on_resources_loaded;
  v16 = (int)v7;
  v11 = 45;
  v17 = parent;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v3) )
  {
    v18[0] = 0;
  }
  else
  {
    v18[2] = (int)v15;
    v18[3] = v16;
    v18[4] = (int)v17;
    v18[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_combined_model_instance_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_combined_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resources(
    &v9,
    2u,
    vostok::render::g_allocator,
    v8,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v18);
  vostok::variant<32>::destroy_previous_variable_if_needed(v5, (int)v19);
}
