void __thiscall vostok::ai::behaviour_cook::on_behaviour_options_received(
        vostok::ai::behaviour_cook *this,
        vostok::resources::queries_result *data)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  vostok::resources::query_result_for_cook *v3; // ecx
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  vostok::resources::query_result *v6; // eax
  vostok::resources::query_result_for_user *v7; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  vostok::configs::binary_config *v12; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v13; // ecx
  vostok::resources::query_result *v14; // eax
  vostok::resources::query_result_for_user *v15; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v16; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v17; // eax
  const vostok::variant<32> **v18; // eax
  vostok::configs::binary_config *v19; // ecx
  vostok::ai::behaviour *v20; // eax
  vostok::ai::behaviour *v21; // [esp+4h] [ebp-70h]
  vostok::configs::binary_config_value *behaviour_config; // [esp+8h] [ebp-6Ch]
  vostok::ai::behaviour *v24; // [esp+2Ch] [ebp-48h]
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> v25; // [esp+34h] [ebp-40h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v26; // [esp+38h] [ebp-3Ch] BYREF
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> v27; // [esp+3Ch] [ebp-38h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v28; // [esp+40h] [ebp-34h] BYREF
  char v29; // [esp+45h] [ebp-2Fh]
  char v30; // [esp+46h] [ebp-2Eh]
  bool user_data_result; // [esp+47h] [ebp-2Dh]
  const vostok::configs::binary_config_value *behaviour_value; // [esp+48h] [ebp-2Ch]
  unsigned int behaviour_buffer_size; // [esp+4Ch] [ebp-28h]
  vostok::ai::behaviour_cook_params cook_params; // [esp+50h] [ebp-24h] BYREF
  unsigned __int8 *behaviour_buffer; // [esp+54h] [ebp-20h]
  vostok::variant<32> *user_data; // [esp+58h] [ebp-1Ch]
  unsigned int sounds_count; // [esp+5Ch] [ebp-18h]
  vostok::ai::behaviour *new_behaviour; // [esp+60h] [ebp-14h]
  vostok::resources::query_result_for_cook *parent; // [esp+64h] [ebp-10h]
  unsigned int animations_count; // [esp+68h] [ebp-Ch]
  const vostok::configs::binary_config_value *persistent_value; // [esp+6Ch] [ebp-8h]
  unsigned int movement_targets_count; // [esp+70h] [ebp-4h]

  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &cook_params);
    user_data = vostok::resources::query_result_for_cook::user_data(v3, (int)parent);
    user_data_result = vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>(user_data, &cook_params);
    v29 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    if ( *v5 )
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)user_data_result);
    v6 = vostok::resources::queries_result::operator[](data, 0);
    unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                           v7,
                           (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v6,
                           (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28);
    v9 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
           (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
           (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v27);
    v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)v9);
    persistent_value = vostok::configs::binary_config::get_root(v12, (int)v11);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&v27);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
    if ( !cook_params.behaviour_config )
    {
      v14 = vostok::resources::queries_result::operator[](data, 1u);
      v16 = vostok::resources::query_result_for_user::get_unmanaged_resource(
              v15,
              (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v14,
              (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
      v17 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
              (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v16,
              (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v25);
      vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
        &this->m_loaded_binary_config,
        v17);
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&v25);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    }
    if ( cook_params.behaviour_config )
    {
      behaviour_config = (vostok::configs::binary_config_value *)cook_params.behaviour_config;
    }
    else
    {
      v18 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              v13,
              (int)&this->m_loaded_binary_config);
      behaviour_config = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v19, (int)v18);
    }
    behaviour_value = behaviour_config;
    animations_count = vostok::ai::get_count_of_needed_resources(behaviour_config, resource_type_animation);
    sounds_count = vostok::ai::get_count_of_needed_resources(
                     (vostok::configs::binary_config_value *)behaviour_value,
                     resource_type_sound);
    movement_targets_count = vostok::ai::get_count_of_needed_resources(
                               (vostok::configs::binary_config_value *)behaviour_value,
                               resource_type_movement_target);
    behaviour_buffer_size = 96 * movement_targets_count + 280 * animations_count + 280 * sounds_count + 616;
    behaviour_buffer = (unsigned __int8 *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(
                                            vostok::ai::g_allocator,
                                            behaviour_buffer_size);
    v24 = (vostok::ai::behaviour *)operator new(0x268u, behaviour_buffer);
    if ( v24 )
    {
      vostok::ai::behaviour::behaviour(
        v24,
        persistent_value,
        (vostok::configs::binary_config_value *)behaviour_value,
        this->m_ai_world,
        animations_count,
        sounds_count,
        movement_targets_count);
      v21 = v20;
    }
    else
    {
      v21 = 0;
    }
    new_behaviour = v21;
    vostok::ai::behaviour_cook::load_behaviour_data(
      this,
      parent,
      (vostok::configs::binary_config_value *)behaviour_value,
      v21);
  }
  else
  {
    v30 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
