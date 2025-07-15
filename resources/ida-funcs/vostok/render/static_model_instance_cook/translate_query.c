void __userpurge vostok::render::static_model_instance_cook::translate_query(
        vostok::render::static_model_instance_cook *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v6; // ecx
  vostok::variant<32> *m_user_data; // esi
  vostok::configs::binary_config_value *v8; // ecx
  void *v9; // esp
  vostok::buffer_vector<vostok::variant<32> const *> *v10; // ecx
  void *v11; // esp
  int v12; // edi
  vostok::particle::particle_action *v13; // ecx
  vostok::variant<32> *v14; // esi
  vostok::configs::binary_config_value *v15; // ecx
  const vostok::configs::binary_config_value *v16; // eax
  vostok::variant<32> *v17; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  vostok::variant<32> *v19; // ecx
  vostok::variant<32> *v20; // [esp-1ACh] [ebp-1B8h]
  int v21; // [esp-1A8h] [ebp-1B4h] BYREF
  int v22; // [esp-1A4h] [ebp-1B0h]
  _DWORD v23[3]; // [esp-1A0h] [ebp-1ACh] BYREF
  _BYTE v24[260]; // [esp-194h] [ebp-1A0h] BYREF
  char v25; // [esp-90h] [ebp-9Ch] BYREF
  vostok::configs::binary_config_value v26; // [esp-88h] [ebp-94h] BYREF
  int v27; // [esp-60h] [ebp-6Ch]
  int v28; // [esp-5Ch] [ebp-68h]
  int v29[8]; // [esp-58h] [ebp-64h] BYREF
  void (__thiscall *v30)(vostok::render::static_model_instance_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *); // [esp-38h] [ebp-44h]
  int v31; // [esp-34h] [ebp-40h]
  vostok::resources::query_result_for_cook *v32; // [esp-30h] [ebp-3Ch]
  unsigned int v33; // [esp-2Ch] [ebp-38h]
  const vostok::variant<32> *v34; // [esp-28h] [ebp-34h] BYREF
  vostok::sound::world *v35; // [esp-24h] [ebp-30h]
  const vostok::resources::request *v36; // [esp-20h] [ebp-2Ch]
  vostok::render::static_model_instance_user_data v37; // [esp-1Ch] [ebp-28h] BYREF
  vostok::render::static_model_instance_user_data v38; // [esp-10h] [ebp-1Ch] BYREF
  unsigned __int8 v39; // [esp-1h] [ebp-Dh]
  int v40; // [esp+0h] [ebp-Ch]
  void *v41; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v40 = a2;
  v41 = retaddr;
  v22 = a4;
  v23[0] = v24;
  v23[1] = v24;
  v35 = (vostok::sound::world *)this;
  v21 = a3;
  v23[2] = &v25;
  v24[0] = 0;
  v25 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v23, v6, (vostok::buffer_string *)"%s.model/render", requested_path);
  m_user_data = parent->m_user_data;
  v39 = 1;
  if ( m_user_data )
  {
    v38.sound_scene.m_object = 0;
    vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(
      v20,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)m_user_data,
      &v38);
    if ( vostok::configs::binary_config_value::value_exists(v8, (int)v38.config, (unsigned int)"sound_environment")
      && strlen((const char *)vostok::configs::binary_config_value::operator[](v38.config, "sound_environment")->data.pointer) )
    {
      v39 = 2;
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v38.sound_scene);
  }
  v33 = v39;
  v9 = alloca(8 * v39);
  v10 = (vostok::buffer_vector<vostok::variant<32> const *> *)v23[0];
  v36 = (const vostok::resources::request *)&v21;
  v21 = v23[0];
  v22 = 21;
  v11 = alloca(4 * v39);
  v38.config = (const vostok::configs::binary_config_value *)&v21;
  v38.sound_world = (vostok::sound::world *)&v21;
  v38.sound_scene.m_object = (vostok::resources::unmanaged_resource *)(&v21 + v39);
  if ( v39 )
  {
    v34 = 0;
    v12 = v39;
    do
    {
      vostok::buffer_vector<vostok::variant<32> const *>::push_back(v10, (int)&v38, &v34);
      --v12;
    }
    while ( v12 );
  }
  v13 = (vostok::particle::particle_action *)parent;
  v14 = parent->m_user_data;
  v27 = 0;
  v28 = 0;
  if ( v14 )
  {
    v37.sound_scene.m_object = 0;
    vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(
      (vostok::variant<32> *)parent,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v14,
      &v37);
    if ( vostok::configs::binary_config_value::value_exists(v15, (int)v37.config, (unsigned int)"sectors") )
    {
      v16 = vostok::configs::binary_config_value::operator[](v37.config, "sectors");
      vostok::variant<32>::set<vostok::configs::binary_config_value>(v17, &v26, v16);
      v38.config->data.pointer = &v26;
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v37.sound_scene);
  }
  v37.sound_world = v35;
  v37.sound_scene.m_object = (vostok::resources::unmanaged_resource *)parent;
  v37.config = (const vostok::configs::binary_config_value *)vostok::render::static_model_instance_cook::on_subresources_loaded;
  v30 = vostok::render::static_model_instance_cook::on_subresources_loaded;
  v31 = (int)v35;
  v32 = parent;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v13) )
  {
    v29[0] = 0;
  }
  else
  {
    v29[2] = (int)v30;
    v29[3] = v31;
    v29[4] = (int)v32;
    v29[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::static_model_instance_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::render::static_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resources(
    v36,
    v33,
    vostok::render::g_allocator,
    (const vostok::variant<32> *const *)v38.config,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v18, v29);
  vostok::variant<32>::destroy_previous_variable_if_needed(v19, (int)&v26);
}
