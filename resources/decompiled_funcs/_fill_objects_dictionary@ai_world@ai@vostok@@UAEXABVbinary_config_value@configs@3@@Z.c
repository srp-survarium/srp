void __thiscall vostok::ai::ai_world::fill_objects_dictionary(
        vostok::ai::ai_world *this,
        vostok::configs::binary_config_value *dictionary)
{
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v2; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v9; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v10; // eax

  if ( vostok::configs::binary_config_value::value_exists(dictionary, "characters") )
  {
    v2 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "characters");
    vostok::ai::fill_characters(v2, &this->m_npc_characters);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "groups") )
  {
    v3 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "groups");
    vostok::ai::fill_objects_names(v3, (vostok::buffer_vector<void const *> *)&this->m_npc_groups);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "classes") )
  {
    v4 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "classes");
    vostok::ai::fill_objects_names(v4, (vostok::buffer_vector<void const *> *)&this->m_npc_classes);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "outfits") )
  {
    v5 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "outfits");
    vostok::ai::fill_objects_names(v5, (vostok::buffer_vector<void const *> *)&this->m_npc_outfits);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "melee_weapons") )
  {
    v6 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "melee_weapons");
    vostok::ai::fill_objects_names(v6, (vostok::buffer_vector<void const *> *)&this->m_melee_weapons);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "sniper_weapons") )
  {
    v7 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "sniper_weapons");
    vostok::ai::fill_objects_names(v7, (vostok::buffer_vector<void const *> *)&this->m_sniper_weapons);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "heavy_weapons") )
  {
    v8 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "heavy_weapons");
    vostok::ai::fill_objects_names(v8, (vostok::buffer_vector<void const *> *)&this->m_heavy_weapons);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "light_weapons") )
  {
    v9 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "light_weapons");
    vostok::ai::fill_objects_names(v9, (vostok::buffer_vector<void const *> *)&this->m_light_weapons);
  }
  if ( vostok::configs::binary_config_value::value_exists(dictionary, "energy_weapons") )
  {
    v10 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](dictionary, "energy_weapons");
    vostok::ai::fill_objects_names(v10, (vostok::buffer_vector<void const *> *)&this->m_energy_weapons);
  }
}
