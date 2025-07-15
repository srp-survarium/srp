vostok::animation::mixing::expression *__thiscall survarium::player_logic_stand_state::look_expression(
        survarium::player_logic_stand_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        unsigned int movement_animation_index,
        bool is_aimed,
        bool is_third_view,
        const survarium::weapon_animation_parameters *weapon_parameters,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  vostok::animation::linear_interpolator *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v13; // esi
  vostok::animation::mixing::animation_lexeme_parameters *v14; // eax
  vostok::animation::mixing::animation_lexeme *v15; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v16; // eax
  const vostok::animation::mixing::expression *v17; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v18; // eax
  const vostok::animation::mixing::expression *v19; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v20; // eax
  const vostok::animation::mixing::expression *v21; // eax
  vostok::animation::mixing::animation_lexeme *v22; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v23; // ecx
  survarium::game_camera *v24; // ecx
  survarium::game_camera *v25; // ecx
  vostok::animation::mixing::animation_lexeme *v27; // [esp+18h] [ebp-1B8h]
  btCollisionShape **p_m_prev_in_global_delay_delete_list; // [esp+20h] [ebp-1B0h]
  char *p_m_next_for_grm_observer_list; // [esp+24h] [ebp-1ACh]
  vostok::animation::mixing::expression v31; // [esp+38h] [ebp-198h] BYREF
  vostok::animation::mixing::expression v32; // [esp+40h] [ebp-190h] BYREF
  vostok::animation::mixing::expression v33; // [esp+48h] [ebp-188h] BYREF
  survarium::base_player *m_user; // [esp+50h] [ebp-180h]
  vostok::animation::mixing::animation_lexeme_parameters *v35; // [esp+58h] [ebp-178h]
  char v36; // [esp+5Eh] [ebp-172h]
  char v37; // [esp+5Fh] [ebp-171h]
  float m_length; // [esp+60h] [ebp-170h]
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // [esp+64h] [ebp-16Ch]
  vostok::physics::bt_collision_shape *v40; // [esp+6Ch] [ebp-164h]
  survarium::weapon_user_animations_selector *v41; // [esp+70h] [ebp-160h]
  char v42; // [esp+77h] [ebp-159h]
  vostok::physics::bt_collision_shape *v43; // [esp+78h] [ebp-158h]
  survarium::weapon_user_animations_selector *m_owner; // [esp+7Ch] [ebp-154h]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v45; // [esp+80h] [ebp-150h] BYREF
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v46; // [esp+88h] [ebp-148h] BYREF
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v47; // [esp+90h] [ebp-140h] BYREF
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v48; // [esp+98h] [ebp-138h] BYREF
  survarium::weapon_core *v49; // [esp+9Ch] [ebp-134h]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v50; // [esp+A0h] [ebp-130h] BYREF
  char v51; // [esp+ABh] [ebp-125h]
  vostok::animation::mixing::expression v52; // [esp+ACh] [ebp-124h] BYREF
  vostok::animation::mixing::expression right; // [esp+B4h] [ebp-11Ch] BYREF
  vostok::animation::mixing::expression expression; // [esp+BCh] [ebp-114h] BYREF
  vostok::animation::mixing::expression resulta; // [esp+C4h] [ebp-10Ch] BYREF
  const char *look_animation_id; // [esp+CCh] [ebp-104h]
  survarium::weapon_core *weapon; // [esp+D0h] [ebp-100h]
  vostok::animation::instant_interpolator interpolator; // [esp+D4h] [ebp-FCh] BYREF
  vostok::animation::mixing::animation_lexeme_parameters look_lexeme_parameters; // [esp+D8h] [ebp-F8h] BYREF
  float start_animation_interval_time; // [esp+134h] [ebp-9Ch]
  vostok::animation::mixing::animation_lexeme look_lexeme; // [esp+138h] [ebp-98h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> look_animation; // [esp+1C0h] [ebp-10h] BYREF
  vostok::animation::linear_interpolator l_interpolator; // [esp+1C4h] [ebp-Ch] BYREF
  survarium::animation_type_enum animation_type; // [esp+1CCh] [ebp-4h]

  vostok::animation::instant_interpolator::instant_interpolator(
    (vostok::animation::instant_interpolator *)this,
    &interpolator);
  vostok::animation::linear_interpolator::linear_interpolator(v8, &l_interpolator, SLODWORD(s_aim_transition_time));
  animation_type = movement_animation_index + 2;
  m_owner = this->m_owner;
  v43 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->((vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_owner->m_animations);
  v42 = 0;
  survarium::weapon_user_dead_state::finalize(v9);
  look_animation_id = survarium::stand_animations_captions[animation_type];
  v41 = this->m_owner;
  v40 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->((vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v41->m_animations);
  if ( is_aimed )
    p_m_next_for_grm_observer_list = (char *)&v40[2].m_next_for_grm_observer_list;
  else
    p_m_next_for_grm_observer_list = (char *)&v40[1].m_memory_type_data;
  if ( is_aimed )
    p_m_prev_in_global_delay_delete_list = (btCollisionShape **)&v40[1].m_prev_in_global_delay_delete_list;
  else
    p_m_prev_in_global_delay_delete_list = &v40->m_bt_shape;
  survarium::weapon_user_animations_container::get_animation_impl<27,6>(
    &look_animation,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])&p_m_prev_in_global_delay_delete_list[27 * is_third_view],
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])&p_m_next_for_grm_observer_list[24 * is_third_view],
    animation_type);
  v51 = 0;
  survarium::weapon_user_dead_state::finalize(v10);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)weight_driving_animation,
    (int)&look_lexeme_parameters,
    buffer,
    &look_animation,
    0,
    (vostok::animation::mixing::base_lexeme *)weight_driving_animation,
    v27);
  m_animation_intervals = look_lexeme_parameters.m_animation_intervals;
  m_length = look_lexeme_parameters.m_animation_intervals->m_length;
  start_animation_interval_time = survarium::weapon_user_animations_selector::look_time_factor(this->m_owner) * m_length;
  v37 = 0;
  survarium::weapon_user_dead_state::finalize(v11);
  v36 = 0;
  survarium::weapon_user_dead_state::finalize(v12);
  look_lexeme_parameters.m_start_animation_interval_time = start_animation_interval_time;
  v35 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
          (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
          &look_lexeme_parameters);
  v35->m_additivity_priority = 4;
  v13 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_user_animations_selector::look_time_calculator(
                                                                    this->m_owner,
                                                                    &v50);
  v14 = vostok::animation::mixing::animation_lexeme_parameters::time_scale_interpolator(
          (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
          v35);
  vostok::animation::mixing::animation_lexeme_parameters::time_calculator(v13, v14);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&look_lexeme, &look_lexeme_parameters);
  vostok::animation::mixing::expression::expression(
    &resulta,
    (vostok::animation::mixing::base_lexeme *)&look_lexeme,
    v15);
  m_user = this->m_user;
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_user->m_current_active_object,
    (survarium::inventory **)&v48);
  v49 = (survarium::weapon_core *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(&v48);
  weapon = v49;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v48);
  if ( weapon_parameters->recoil_backward != 0.0 )
  {
    v16 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_core::backward_recoil_time_calculator(
                                                                      weapon,
                                                                      &v47);
    survarium::player_logic_stand_state::get_recoil_animation_lexeme(
      this,
      &expression,
      recoil_back_anim,
      is_aimed,
      weapon_parameters->recoil_backward,
      (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
      buffer,
      is_third_view,
      2u,
      v16);
    v17 = vostok::animation::mixing::operator+(&v33, &resulta, &expression);
    vostok::animation::mixing::expression::operator=(&resulta, v17);
    vostok::animation::mixing::expression::~expression(&v33);
    vostok::animation::mixing::expression::~expression(&expression);
  }
  if ( weapon_parameters->recoil_horizontal != 0.0 )
  {
    v18 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_core::horizontal_recoil_time_calculator(
                                                                      weapon,
                                                                      &v46);
    survarium::player_logic_stand_state::get_recoil_animation_lexeme(
      this,
      &right,
      recoil_horizontal,
      is_aimed,
      weapon_parameters->recoil_horizontal,
      (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
      buffer,
      is_third_view,
      3u,
      v18);
    v19 = vostok::animation::mixing::operator+(&v32, &resulta, &right);
    vostok::animation::mixing::expression::operator=(&resulta, v19);
    vostok::animation::mixing::expression::~expression(&v32);
    vostok::animation::mixing::expression::~expression(&right);
  }
  if ( weapon_parameters->recoil_vertical != 0.0 )
  {
    v20 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_core::vertical_recoil_time_calculator(
                                                                      weapon,
                                                                      &v45);
    survarium::player_logic_stand_state::get_recoil_animation_lexeme(
      this,
      &v52,
      recoil_vertical,
      is_aimed,
      weapon_parameters->recoil_vertical,
      (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
      buffer,
      is_third_view,
      3u,
      v20);
    v21 = vostok::animation::mixing::operator+(&v31, &resulta, &v52);
    vostok::animation::mixing::expression::operator=(&resulta, v21);
    vostok::animation::mixing::expression::~expression(&v31);
    vostok::animation::mixing::expression::~expression(&v52);
  }
  vostok::animation::mixing::expression::expression(result, &resulta);
  vostok::animation::mixing::expression::~expression(&resulta);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v22, (int)&look_lexeme);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(
    v23,
    (int)&look_lexeme_parameters);
  vostok::animation::mixing::animation_interval::~animation_interval(&look_animation);
  survarium::weapon_user_dead_state::finalize(v24);
  survarium::weapon_user_dead_state::finalize(v25);
  return result;
}
