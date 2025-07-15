void __thiscall survarium::player_cook::on_equipment_configs_loaded(
        survarium::player_cook *this,
        vostok::resources::queries_result *data,
        survarium::player_creation_params *params)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  const vostok::configs::binary_config_value *v4; // esi
  survarium::player_profile *profile; // ebx
  survarium::pure_game_effect_emitter_base *slots; // ebx
  vostok::particle::particle_system_instance_impl *v7; // esi
  vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value *v10; // eax
  unsigned __int16 *boots_game_material_ids; // esi
  unsigned __int16 pointer; // ax
  vostok::particle::particle_system_instance_impl *v13; // esi
  survarium::pure_game_effect_emitter_base *v14; // eax
  vostok::particle::particle_system_instance_impl *v15; // esi
  vostok::configs::binary_config_value *v16; // eax
  vostok::particle::particle_system_instance_impl *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  vostok::particle::particle_system_instance_impl *v19; // ebx
  void (__thiscall *v20)(struct vostok::particle::particle_system_instance *); // eax
  vostok::particle::particle_system_instance_impl *v21; // esi
  vostok::configs::binary_config_value *v22; // eax
  vostok::particle::particle_system_instance_impl *v23; // ebx
  void (__thiscall *v24)(struct vostok::particle::particle_system_instance *); // eax
  const vostok::variant<32> **m_parent_query; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v26; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::player_cook,vostok::resources::queries_result &,survarium::player_creation_params *>,boost::_bi::list3<boost::_bi::value<survarium::player_cook *>,boost::arg<1>,boost::_bi::value<survarium::player_creation_params *> > > v27; // [esp-14h] [ebp-144h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+10h] [ebp-120h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v29; // [esp+14h] [ebp-11Ch] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v30; // [esp+18h] [ebp-118h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v31; // [esp+1Ch] [ebp-114h] BYREF
  int v32; // [esp+20h] [ebp-110h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v33; // [esp+24h] [ebp-10Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v34; // [esp+28h] [ebp-108h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v35; // [esp+2Ch] [ebp-104h] BYREF
  vostok::resources::request v36; // [esp+30h] [ebp-100h] BYREF
  survarium::player_creation_params *v37; // [esp+38h] [ebp-F8h]
  survarium::player_creation_params *v38; // [esp+3Ch] [ebp-F4h]
  survarium::player_creation_params *v39; // [esp+44h] [ebp-ECh]
  vostok::configs::binary_config_value v40; // [esp+48h] [ebp-E8h] BYREF
  _DWORD v41[10]; // [esp+60h] [ebp-D0h]
  vostok::configs::binary_config_value f; // [esp+88h] [ebp-A8h] BYREF
  vostok::buffer_vector<vostok::resources::request> v43; // [esp+A8h] [ebp-88h] BYREF
  _BYTE v44[120]; // [esp+B4h] [ebp-7Ch] BYREF
  char v45; // [esp+12Ch] [ebp-4h] BYREF

  v39 = (survarium::player_creation_params *)this;
  v32 = 1;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v31,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v31.m_object;
  v35.m_object = 0;
  if ( v31.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v35);
    v35.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
  v4 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)v35.m_object->m_lods[0].m_template.m_object,
         "body_parts");
  profile = params->initial_info.profile;
  qmemcpy((void *)&f, v4, sizeof(f));
  slots = (survarium::pure_game_effect_emitter_base *)profile->slots;
  v33.m_object = slots;
  v30.m_object = 0;
  vostok::configs::binary_config_value::binary_config_value(0, (int)&v40);
  if ( slots->m_next_in_increase_quality_queue )
  {
    v32 = 2;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v31,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
    v7 = (vostok::particle::particle_system_instance_impl *)v31.m_object;
    v28.m_object = 0;
    if ( v31.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
      v28.m_object = v7;
      _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v28,
      &v30);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
    v8 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)v30.m_object->m_lods[0].m_template.m_object,
           "game_materials");
    vostok::configs::binary_config_value::operator=(v8, &v40);
  }
  else
  {
    v34.m_object = 0;
    v30.m_object = 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
    v9 = vostok::configs::binary_config_value::operator[](&f, (char *)slots_with_sound_options[0].table_name);
    v10 = vostok::configs::binary_config_value::operator[](v9, "game_materials");
    vostok::configs::binary_config_value::operator=(v10, &v40);
  }
  v28.m_object = 0;
  v41[0] = "stand_1st_view_material_id";
  v41[1] = "stand_3rd_view_material_id";
  v41[2] = "crouch_1st_view_material_id";
  v41[3] = "crouch_3rd_view_material_id";
  v41[4] = "sprint_1st_view_material_id";
  v41[5] = "sprint_3rd_view_material_id";
  v41[6] = "jump_1st_view_material_id";
  v41[7] = "jump_3rd_view_material_id";
  v41[8] = "landing_1st_view_material_id";
  v41[9] = "landing_3rd_view_material_id";
  boots_game_material_ids = params->boots_game_material_ids;
  do
  {
    pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](&v40, (char *)v41[(int)v28.m_object++])->data.pointer;
    *boots_game_material_ids++ = pointer;
  }
  while ( v28.m_object != (vostok::particle::particle_system_instance_impl *)10 );
  v43.m_begin = (vostok::resources::request *)v44;
  v43.m_end = (vostok::resources::request *)v44;
  v43.m_max_end = (vostok::resources::request *)&v45;
  v13 = (vostok::particle::particle_system_instance_impl *)&slots_with_sound_options[1];
  v29.m_object = (vostok::particle::particle_system_instance_impl *)&slots_with_sound_options[1];
  v31.m_object = (survarium::pure_game_effect_emitter_base *)&data->m_queries[v32];
  while ( 1 )
  {
    if ( *((_DWORD *)&slots->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
         + 4 * (int)v13->__vftable) )
    {
      v14 = v31.m_object;
      ++v32;
      v31.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v31.m_object + 736);
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v34,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v14->m_sub_fat.m_parent);
      v15 = v34.m_object;
      v28.m_object = 0;
      if ( v34.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
        v28.m_object = v15;
        _InterlockedExchangeAdd(&v15->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v28,
        &v30);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
      v16 = (vostok::configs::binary_config_value *)v30.m_object->m_lods[0].m_template.m_object;
    }
    else
    {
      v17 = v30.m_object;
      v30.m_object = 0;
      v28.m_object = v17;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
      v16 = vostok::configs::binary_config_value::operator[](&f, (char *)v13->type);
    }
    v18 = vostok::configs::binary_config_value::operator[](v16, "sounds");
    vostok::configs::binary_config_value::operator=(v18, &v40);
    v19 = (vostok::particle::particle_system_instance_impl *)((char *)v40.data.pointer + 24 * v40.count);
    v28.m_object = (vostok::particle::particle_system_instance_impl *)v40.data.pointer;
    if ( v40.data.pointer != v19 )
    {
      do
      {
        v20 = v28.m_object->~vostok::particle::particle_system_instance;
        v36.path = (const char *)v28.m_object->is_increasing_quality;
        v36.id = (vostok::resources::class_id_enum)v20;
        vostok::buffer_vector<vostok::resources::request>::push_back(&v43, &v36);
        v28.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v28.m_object + 24);
      }
      while ( v28.m_object != v19 );
    }
    v29.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v29.m_object + 8);
    if ( (const survarium::slot_def *)v29.m_object == &slots_with_sound_options[4] )
      break;
    slots = v33.m_object;
    v13 = v29.m_object;
  }
  if ( v33.m_object->m_children_resources.m_last )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v33,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[v32].m_unmanaged_resource);
    v21 = (vostok::particle::particle_system_instance_impl *)v33.m_object;
    v29.m_object = 0;
    if ( v33.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
      v29.m_object = v21;
      _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v29,
      &v30);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v33);
    v22 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)v30.m_object->m_lods[0].m_template.m_object,
            "sounds");
    vostok::configs::binary_config_value::operator=(v22, &v40);
    v23 = (vostok::particle::particle_system_instance_impl *)((char *)v40.data.pointer + 24 * v40.count);
    v29.m_object = (vostok::particle::particle_system_instance_impl *)v40.data.pointer;
    if ( v40.data.pointer != v23 )
    {
      do
      {
        v24 = v29.m_object->~vostok::particle::particle_system_instance;
        v36.path = (const char *)v29.m_object->is_increasing_quality;
        v36.id = (vostok::resources::class_id_enum)v24;
        vostok::buffer_vector<vostok::resources::request>::push_back(&v43, &v36);
        v29.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v29.m_object + 24);
      }
      while ( v29.m_object != v23 );
    }
  }
  m_parent_query = (const vostok::variant<32> **)data->m_parent_query;
  v36.path = (const char *)survarium::player_cook::on_equipment_sounds_loaded;
  v37 = v39;
  v38 = params;
  v36.id = unknown_data_class;
  HIDWORD(v27.f_.f_) = survarium::player_cook::on_equipment_sounds_loaded;
  v27.l_.a1_.t_ = 0;
  v27.l_.a3_.t_ = v39;
  LODWORD(v27.f_.f_) = &f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v27,
    (int)params);
  vostok::resources::query_resources(
    v43.m_begin,
    v43.m_end - v43.m_begin,
    survarium::g_allocator,
    0,
    m_parent_query,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v26,
    (int *)&f);
  v43.m_end = v43.m_begin;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v30);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v35);
}
