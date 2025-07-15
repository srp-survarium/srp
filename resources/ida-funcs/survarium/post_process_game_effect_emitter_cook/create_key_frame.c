void __userpurge survarium::post_process_game_effect_emitter_cook::create_key_frame(
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *buffer@<eax>,
        vostok::render::environment_properties *a2@<ecx>,
        const vostok::configs::binary_config_value *this,
        survarium::pure_game_effect_emitter_base *props_cfg,
        float time,
        bool use_defaults)
{
  vostok::render::environment_properties *v7; // ecx
  vostok::render::environment_properties *v8; // [esp-4h] [ebp-278h]
  vostok::render::environment_properties set_defaults; // [esp+8h] [ebp-26Ch] BYREF

  vostok::render::environment_properties::environment_properties(a2, (int)&set_defaults, SLOBYTE(time));
  vostok::render::load_environment_properties_impl<vostok::configs::binary_config_value const>(&set_defaults, this);
  v7 = v8;
  if ( buffer )
  {
    vostok::render::environment_properties::environment_properties(
      v8,
      buffer,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&set_defaults);
    buffer[154].m_object = props_cfg;
  }
  vostok::render::environment_properties::~environment_properties(
    v7,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&set_defaults);
}
