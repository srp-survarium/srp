void __userpurge vostok::variant<32>::set<vostok::render::binary_shader_cook_data *>(
        vostok::variant<32> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::render::binary_shader_cook_data **value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)a2);
  a2[11] = vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::get();
  if ( a2 != (_DWORD *)-8 )
    a2[2] = *value;
  *a2 = &vostok::detail::concrete_type_helper<vostok::render::binary_shader_cook_data *>::`vftable';
  a2[10] = a2;
}


void __userpurge vostok::variant<32>::set<vostok::render::effect_compile_data *>(
        vostok::variant<32> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::render::effect_compile_data **value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)a2);
  a2[11] = vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get();
  if ( a2 != (_DWORD *)-8 )
    a2[2] = *value;
  *a2 = &vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *>::`vftable';
  a2[10] = a2;
}


void __userpurge vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
        vostok::variant<32> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::render::material_effects_instance_cook_data **value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)a2);
  a2[11] = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
  if ( a2 != (_DWORD *)-8 )
    a2[2] = *value;
  *a2 = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
  a2[10] = a2;
}


void __userpurge vostok::variant<32>::set<vostok::render::skeleton_combined_cook_data *>(
        vostok::variant<32> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::render::skeleton_combined_cook_data **value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)a2);
  a2[11] = vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::get();
  if ( a2 != (_DWORD *)-8 )
    a2[2] = *value;
  *a2 = &vostok::detail::concrete_type_helper<vostok::render::skeleton_combined_cook_data *>::`vftable';
  a2[10] = a2;
}


void __userpurge vostok::variant<32>::set<vostok::physics::world *>(
        vostok::variant<32> *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::physics::world **value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)a2);
  a2[11] = vostok::detail::type_to_int<vostok::physics::world *>::get();
  if ( a2 != (_DWORD *)-8 )
    a2[2] = *value;
  *a2 = &vostok::detail::concrete_type_helper<vostok::physics::world *>::`vftable';
  a2[10] = a2;
}


void __userpurge vostok::variant<32>::set<void *>(vostok::variant<32> *this@<ecx>, _DWORD *a2@<eax>, void **value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)a2);
  a2[11] = vostok::detail::type_to_int<void *>::get();
  if ( a2 != (_DWORD *)-8 )
    a2[2] = *value;
  *a2 = &vostok::detail::concrete_type_helper<void *>::`vftable';
  a2[10] = a2;
}


void __userpurge vostok::variant<32>::set<vostok::configs::binary_config_value const *>(
        vostok::variant<32> *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::configs::binary_config_value **value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)a2);
  a2[11] = vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::get();
  if ( a2 != (_DWORD *)-8 )
    a2[2] = *value;
  *a2 = &vostok::detail::concrete_type_helper<vostok::configs::binary_config_value const *>::`vftable';
  a2[10] = a2;
}


void __userpurge vostok::variant<32>::set<survarium::booby_trap_core_query_data>(
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *value@<eax>,
        vostok::variant<32> *a2@<ecx>,
        vostok::detail::abstract_type_helper *this)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(a2, (int)this);
  this[11].__vftable = (vostok::detail::abstract_type_helper_vtbl *)vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::get();
  if ( this != (vostok::detail::abstract_type_helper *)-8 )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this[2],
      value);
    this[3].__vftable = (vostok::detail::abstract_type_helper_vtbl *)value[1].m_object;
    this[4].__vftable = (vostok::detail::abstract_type_helper_vtbl *)value[2].m_object;
  }
  this->__vftable = (vostok::detail::abstract_type_helper_vtbl *)&vostok::detail::concrete_type_helper<survarium::booby_trap_core_query_data>::`vftable';
  this[10].__vftable = (vostok::detail::abstract_type_helper_vtbl *)this;
}


void __thiscall vostok::variant<32>::set<survarium::player_initial_info>(
        vostok::variant<32> *this,
        survarium::player_profile *value,
        const void *a3)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)value);
  *(_DWORD *)&value->profile_name[36] = vostok::detail::type_to_int<survarium::player_initial_info>::get();
  if ( value != (survarium::player_profile *)-8 )
    qmemcpy(value->profile_name, a3, 0x14u);
  value->account_id = (unsigned int)&vostok::detail::concrete_type_helper<survarium::player_initial_info>::`vftable';
  *(_DWORD *)&value->profile_name[32] = value;
}


void __thiscall vostok::variant<32>::set<vostok::render::render_texture_cook_parameters>(
        vostok::variant<32> *this,
        const vostok::render::render_texture_cook_parameters *value,
        _DWORD *a3)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)value);
  *(_DWORD *)&value[2].force_query = vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::get();
  if ( value != (const vostok::render::render_texture_cook_parameters *)-8 )
  {
    *(_DWORD *)&value->use_pool = *a3;
    *(_DWORD *)&value->force_query = a3[1];
    value[1].mip_level_cut = a3[2];
    value[1].num_last_mips_used = a3[3];
  }
  value->mip_level_cut = (unsigned int)&vostok::detail::concrete_type_helper<vostok::render::render_texture_cook_parameters>::`vftable';
  *(_DWORD *)&value[2].use_pool = value;
}


void __userpurge vostok::variant<32>::set<vostok::render::scene_configuration>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        const vostok::render::scene_configuration *value)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, a2);
  *(_DWORD *)(a2 + 44) = vostok::detail::type_to_int<vostok::render::scene_configuration>::get();
  if ( a2 != -8 )
    *(vostok::render::scene_configuration *)(a2 + 8) = *value;
  *(_DWORD *)a2 = &vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::`vftable';
  *(_DWORD *)(a2 + 40) = a2;
}


void __thiscall vostok::variant<32>::set<vostok::sound::sound_scene_creation_params>(
        vostok::variant<32> *this,
        const vostok::sound::sound_scene_creation_params *value,
        unsigned int *a3)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)value);
  value[3].receivers_count = vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get();
  if ( value != (const vostok::sound::sound_scene_creation_params *)-8 )
  {
    value->receivers_count = *a3;
    value[1].proxies_count = a3[1];
    value[1].propagators_count = a3[2];
  }
  value->proxies_count = (unsigned int)&vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params>::`vftable';
  value[3].propagators_count = (unsigned int)value;
}


void __thiscall vostok::variant<32>::set<vostok::configs::binary_config_value>(
        vostok::variant<32> *this,
        const vostok::configs::binary_config_value *value,
        const void *a3)
{
  vostok::variant<32>::destroy_previous_variable_if_needed(this, (int)value);
  *(_DWORD *)&value[1].type = vostok::detail::type_to_int<vostok::configs::binary_config_value>::get();
  if ( value != (const vostok::configs::binary_config_value *)-8 )
    qmemcpy(&value->id, a3, sizeof(const vostok::configs::binary_config_value));
  value->data.pointer = &vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::`vftable';
  value[1].id_crc = (unsigned int)value;
}
