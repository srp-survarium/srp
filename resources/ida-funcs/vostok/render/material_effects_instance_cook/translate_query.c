void __thiscall vostok::render::material_effects_instance_cook::translate_query(
        vostok::render::material_effects_instance_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::render::material_effects_instance_cook *v3; // ecx
  vostok::fs_new::virtual_path_string *requested_path; // eax
  vostok::fs_new::virtual_path_string *v5; // ecx
  vostok::fs_new::virtual_path_string *fixed_request_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::material_effects_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> > > v8; // [esp-10h] [ebp-168h]
  vostok::render::material_effects_instance_cook_data *out_value[4]; // [esp+10h] [ebp-148h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::material_effects_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> > > f; // [esp+20h] [ebp-138h] BYREF
  vostok::buffer_string v11[23]; // [esp+44h] [ebp-114h] BYREF

  out_value[0] = 0;
  vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>(
    (vostok::variant<32> *)this,
    (int)parent[66].m_object,
    out_value);
  if ( out_value[0]->material.m_object )
  {
    vostok::render::material_effects_instance_cook::query_effects(v3, this, parent, (int)out_value[0]);
  }
  else
  {
    out_value[2] = (vostok::render::material_effects_instance_cook_data *)this;
    out_value[3] = out_value[0];
    out_value[1] = (vostok::render::material_effects_instance_cook_data *)vostok::render::material_effects_instance_cook::on_material_ready;
    v8.l_.a1_.t_ = (vostok::render::material_effects_instance_cook *)vostok::render::material_effects_instance_cook::on_material_ready;
    v8.l_.a3_.t_ = (vostok::render::material_effects_instance_cook_data *)this;
    v8.f_.f_ = (void (__thiscall *)(vostok::render::material_effects_instance_cook *, vostok::resources::queries_result *, vostok::render::material_effects_instance_cook_data *))&f;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      (boost::function<void __cdecl(vostok::resources::queries_result &)> *)v3,
      v8,
      (int)out_value[0]);
    requested_path = (vostok::fs_new::virtual_path_string *)vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)parent);
    fixed_request_path = vostok::render::get_fixed_request_path(v5, v11, requested_path);
    vostok::resources::query_resource(
      fixed_request_path->m_string.m_begin,
      (vostok::variant<32> *)0x1F,
      vostok::render::g_allocator,
      0,
      (const vostok::variant<32> **)parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&f);
  }
}
