int __cdecl vostok::detail::type_to_int<unsigned short>::get()
{
  if ( !vostok::detail::type_to_int<unsigned short>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<unsigned short>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<unsigned short>::s_id )
      vostok::detail::type_to_int<unsigned short>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                        - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<unsigned short>::s_lock, 0);
  }
  return vostok::detail::type_to_int<unsigned short>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::s_id )
      vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                      - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::s_id )
      vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                   - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_id )
      vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                               - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::particle::engine *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::particle::engine *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::particle::engine *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::particle::engine *>::s_id )
      vostok::detail::type_to_int<vostok::particle::engine *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                    - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::particle::engine *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::particle::engine *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::grass_loading_data *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::grass_loading_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::grass_loading_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::grass_loading_data *>::s_id )
      vostok::detail::type_to_int<vostok::render::grass_loading_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                              - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::grass_loading_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::grass_loading_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::inventory_cooker_data *>::get()
{
  if ( !vostok::detail::type_to_int<survarium::inventory_cooker_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::inventory_cooker_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::inventory_cooker_data *>::s_id )
      vostok::detail::type_to_int<survarium::inventory_cooker_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                            - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::inventory_cooker_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::inventory_cooker_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_id )
      vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                               - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id )
      vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                       - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::physics::world *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::physics::world *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::physics::world *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::physics::world *>::s_id )
      vostok::detail::type_to_int<vostok::physics::world *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                  - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::physics::world *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::physics::world *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::engine::world *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::engine::world *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::engine::world *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::engine::world *>::s_id )
      vostok::detail::type_to_int<vostok::render::engine::world *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                         - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::engine::world *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::engine::world *>::s_id;
}


int __cdecl vostok::detail::type_to_int<void *>::get()
{
  if ( !vostok::detail::type_to_int<void *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<void *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<void *>::s_id )
      vostok::detail::type_to_int<void *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<void *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<void *>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::player_profile const *>::get()
{
  if ( !vostok::detail::type_to_int<survarium::player_profile const *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_profile const *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::player_profile const *>::s_id )
      vostok::detail::type_to_int<survarium::player_profile const *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                           - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_profile const *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::player_profile const *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::s_id )
      vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                      - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::s_id )
      vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                      - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id )
      vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                             - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::get()
{
  if ( !vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::s_id )
      vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                                - 1;
    _InterlockedExchange(
      &vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::s_lock,
      0);
  }
  return vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::anomaly_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::anomaly_cook_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::anomaly_cook_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::anomaly_cook_data>::s_id )
      vostok::detail::type_to_int<survarium::anomaly_cook_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                      - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::anomaly_cook_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::anomaly_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::artefact_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::artefact_cook_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::artefact_cook_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::artefact_cook_data>::s_id )
      vostok::detail::type_to_int<survarium::artefact_cook_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                       - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::artefact_cook_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::artefact_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::s_id )
      vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                               - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id )
      vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                             - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::s_id )
      vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                         - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::grenade_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::grenade_cook_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::grenade_cook_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::grenade_cook_data>::s_id )
      vostok::detail::type_to_int<survarium::grenade_cook_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                      - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::grenade_cook_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::grenade_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::grenade_set_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::grenade_set_cook_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::grenade_set_cook_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::grenade_set_cook_data>::s_id )
      vostok::detail::type_to_int<survarium::grenade_set_cook_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                          - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::grenade_set_cook_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::grenade_set_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::s_id )
      vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                             - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::output_window_configuration>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_id )
      vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                     - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::player_initial_info>::get()
{
  if ( !vostok::detail::type_to_int<survarium::player_initial_info>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_initial_info>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::player_initial_info>::s_id )
      vostok::detail::type_to_int<survarium::player_initial_info>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                        - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_initial_info>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::player_initial_info>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::s_id )
      vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                   - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::s_id )
      vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                   - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::s_id )
      vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                        - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::scene_configuration>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::scene_configuration>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id )
      vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                             - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::scene_configuration>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get()
{
  if ( !vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_id )
      vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                    - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_id )
      vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                         - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::s_id )
      vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                              - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::weapon_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::weapon_cook_data>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::weapon_cook_data>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::weapon_cook_data>::s_id )
      vostok::detail::type_to_int<survarium::weapon_cook_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                     - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::weapon_cook_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::weapon_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::configs::binary_config_value>::get()
{
  if ( !vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_id )
      vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                              - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::get()
{
  if ( !vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_id )
      vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id) - 1;
    _InterlockedExchange(
      &vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_lock,
      0);
  }
  return vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_id;
}
