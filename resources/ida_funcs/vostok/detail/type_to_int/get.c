int __cdecl vostok::detail::type_to_int<unsigned char>::get()
{
  if ( !vostok::detail::type_to_int<unsigned char>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<unsigned char>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<unsigned char>::s_id )
      vostok::detail::type_to_int<unsigned char>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                       - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<unsigned char>::s_lock, 0);
  }
  return vostok::detail::type_to_int<unsigned char>::s_id;
}


int __cdecl vostok::detail::type_to_int<unsigned short>::get()
{
  if ( !vostok::detail::type_to_int<unsigned short>::s_id )
  {
    while ( vostok::threading::interlocked_exchange_pointer(&vostok::detail::type_to_int<unsigned short>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<unsigned short>::s_id )
      vostok::detail::type_to_int<unsigned short>::s_id = vostok::threading::interlocked_increment(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                        - 1;
    vostok::threading::interlocked_exchange_pointer(&vostok::detail::type_to_int<unsigned short>::s_lock, 0);
  }
  return vostok::detail::type_to_int<unsigned short>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_id )
      vostok::detail::type_to_int<vostok::render::effect_compile_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
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
      vostok::detail::type_to_int<vostok::particle::engine *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
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
      vostok::detail::type_to_int<vostok::render::grass_loading_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
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
      vostok::detail::type_to_int<survarium::inventory_cooker_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
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
      vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                                               - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::get()
{
  if ( !vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::s_id )
      vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                                    - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id )
      vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                                       - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::particle::world *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::particle::world *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::particle::world *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::particle::world *>::s_id )
      vostok::detail::type_to_int<vostok::particle::world *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                   - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::particle::world *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::particle::world *>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::physics::world *>::get()
{
  if ( !vostok::detail::type_to_int<vostok::physics::world *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::physics::world *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::physics::world *>::s_id )
      vostok::detail::type_to_int<vostok::physics::world *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                  - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::physics::world *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::physics::world *>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::base_game_scene *>::get()
{
  if ( !vostok::detail::type_to_int<survarium::base_game_scene *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::base_game_scene *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::base_game_scene *>::s_id )
      vostok::detail::type_to_int<survarium::base_game_scene *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                      - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::base_game_scene *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::base_game_scene *>::s_id;
}


survarium::game_action_id *__cdecl vostok::detail::type_to_int<vostok::render::engine::world *>::get()
{
  if ( !`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish )
  {
    while ( _InterlockedExchange(
              (volatile __int32 *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_end_of_storage,
              1) )
      ;
    if ( !`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish )
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish = (survarium::game_action_id *)(_InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count) - 1);
    _InterlockedExchange(
      (volatile __int32 *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_end_of_storage,
      0);
  }
  return `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish;
}


int __cdecl vostok::detail::type_to_int<survarium::player_profile const *>::get()
{
  if ( !vostok::detail::type_to_int<survarium::player_profile const *>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_profile const *>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::player_profile const *>::s_id )
      vostok::detail::type_to_int<survarium::player_profile const *>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                           - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_profile const *>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::player_profile const *>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id )
  {
    while ( vostok::threading::interlocked_exchange_pointer(
              &vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id )
      vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id = vostok::threading::interlocked_increment(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                             - 1;
    vostok::threading::interlocked_exchange_pointer(
      &vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_lock,
      0);
  }
  return vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id;
}


survarium::game *__cdecl vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::get()
{
  if ( !`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_game )
  {
    while ( _InterlockedExchange(
              &`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.x,
              1) )
      ;
    if ( !`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_game )
      `vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_game = (survarium::game *)(_InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count) - 1);
    _InterlockedExchange(
      &`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_mouse_pos.x,
      0);
  }
  return `vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_game;
}


int __cdecl vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::get()
{
  if ( !vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::s_id )
      vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                           - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::s_id;
}


int __cdecl vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id )
  {
    while ( vostok::threading::interlocked_exchange_pointer(
              &vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id )
      vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id = vostok::threading::interlocked_increment(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                             - 1;
    vostok::threading::interlocked_exchange_pointer(
      &vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_lock,
      0);
  }
  return vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::get()
{
  if ( !vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::s_id )
      vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                            - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::output_window_configuration>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_id )
      vostok::detail::type_to_int<vostok::render::output_window_configuration>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
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
      vostok::detail::type_to_int<survarium::player_initial_info>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                        - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<survarium::player_initial_info>::s_lock, 0);
  }
  return vostok::detail::type_to_int<survarium::player_initial_info>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::render::scene_configuration>::get()
{
  if ( !vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::scene_configuration>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id )
      vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                             - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::scene_configuration>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::scene_configuration>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::get()
{
  if ( !vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::s_id )
  {
    while ( _InterlockedExchange(
              &vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::s_id )
      vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                                        - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get()
{
  if ( !vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_id )
      vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
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
      vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                                         - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_lock, 0);
  }
  return vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::s_id;
}


int __cdecl vostok::detail::type_to_int<vostok::configs::binary_config_value>::get()
{
  if ( !vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_id )
      vostok::detail::type_to_int<vostok::configs::binary_config_value>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
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
      vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count) - 1;
    _InterlockedExchange(
      &vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_lock,
      0);
  }
  return vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::s_id;
}


int __cdecl vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::get()
{
  if ( !vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::s_id )
  {
    while ( _InterlockedExchange(&vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::s_lock, 1) )
      ;
    if ( !vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::s_id )
      vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::s_id = _InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count)
                                                                                    - 1;
    _InterlockedExchange(&vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::s_lock, 0);
  }
  return vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::s_id;
}
