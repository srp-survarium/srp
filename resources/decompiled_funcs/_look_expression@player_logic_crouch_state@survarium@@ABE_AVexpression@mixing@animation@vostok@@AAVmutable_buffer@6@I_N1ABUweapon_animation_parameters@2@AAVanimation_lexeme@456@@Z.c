vostok::animation::mixing::expression *__thiscall survarium::player_logic_crouch_state::look_expression(
        survarium::player_logic_crouch_state *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        unsigned int movement_animation_index,
        bool is_aimed,
        bool is_third_view,
        const survarium::weapon_animation_parameters *weapon_parameters,
        vostok::animation::mixing::base_lexeme *weight_driving_animation)
{
  vostok::animation::linear_interpolator *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v12; // esi
  vostok::animation::mixing::animation_lexeme_parameters *v13; // eax
  vostok::animation::mixing::animation_lexeme *v14; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v15; // eax
  const vostok::animation::mixing::expression *v16; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v17; // eax
  const vostok::animation::mixing::expression *v18; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v19; // eax
  const vostok::animation::mixing::expression *v20; // eax
  vostok::animation::mixing::animation_lexeme *v21; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v22; // ecx
  survarium::game_camera *v23; // ecx
  survarium::game_camera *v24; // ecx
  vostok::animation::mixing::animation_lexeme *v26; // [esp+18h] [ebp-1B4h]
  char *p_m_sub_fat; // [esp+20h] [ebp-1ACh]
  char *p_m_next_in_memory_type; // [esp+24h] [ebp-1A8h]
  vostok::animation::mixing::expression v30; // [esp+38h] [ebp-194h] BYREF
  vostok::animation::mixing::expression v31; // [esp+40h] [ebp-18Ch] BYREF
  vostok::animation::mixing::expression v32; // [esp+48h] [ebp-184h] BYREF
  survarium::base_player *m_user; // [esp+50h] [ebp-17Ch]
  vostok::animation::mixing::animation_lexeme_parameters *v34; // [esp+58h] [ebp-174h]
  char v35; // [esp+5Eh] [ebp-16Eh]
  char v36; // [esp+5Fh] [ebp-16Dh]
  float m_length; // [esp+60h] [ebp-16Ch]
  const vostok::animation::mixing::animation_interval *m_animation_intervals; // [esp+64h] [ebp-168h]
  vostok::physics::bt_collision_shape *v39; // [esp+6Ch] [ebp-160h]
  survarium::weapon_user_animations_selector *v40; // [esp+70h] [ebp-15Ch]
  char v41; // [esp+77h] [ebp-155h]
  vostok::physics::bt_collision_shape *v42; // [esp+78h] [ebp-154h]
  survarium::weapon_user_animations_selector *m_owner; // [esp+7Ch] [ebp-150h]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v44; // [esp+80h] [ebp-14Ch] BYREF
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v45; // [esp+88h] [ebp-144h] BYREF
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v46; // [esp+90h] [ebp-13Ch] BYREF
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v47; // [esp+98h] [ebp-134h] BYREF
  survarium::weapon_core *v48; // [esp+9Ch] [ebp-130h]
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v49; // [esp+A0h] [ebp-12Ch] BYREF
  vostok::animation::mixing::expression v50; // [esp+A8h] [ebp-124h] BYREF
  vostok::animation::mixing::expression right; // [esp+B0h] [ebp-11Ch] BYREF
  vostok::animation::mixing::expression expression; // [esp+B8h] [ebp-114h] BYREF
  vostok::animation::mixing::expression resulta; // [esp+C0h] [ebp-10Ch] BYREF
  const char *look_animation_id; // [esp+C8h] [ebp-104h]
  survarium::weapon_core *weapon; // [esp+CCh] [ebp-100h]
  vostok::animation::instant_interpolator interpolator; // [esp+D0h] [ebp-FCh] BYREF
  vostok::animation::mixing::animation_lexeme_parameters look_lexeme_parameters; // [esp+D4h] [ebp-F8h] BYREF
  float start_animation_interval_time; // [esp+130h] [ebp-9Ch]
  vostok::animation::mixing::animation_lexeme look_lexeme; // [esp+134h] [ebp-98h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> look_animation; // [esp+1BCh] [ebp-10h] BYREF
  vostok::animation::linear_interpolator l_interpolator; // [esp+1C0h] [ebp-Ch] BYREF
  survarium::animation_type_enum animation_type; // [esp+1C8h] [ebp-4h]

  vostok::animation::instant_interpolator::instant_interpolator(
    (vostok::animation::instant_interpolator *)this,
    &interpolator);
  vostok::animation::linear_interpolator::linear_interpolator(v8, &l_interpolator, SLODWORD(s_aim_transition_time));
  animation_type = movement_animation_index + 2;
  m_owner = this->m_owner;
  v42 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->((vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_owner->m_animations);
  v41 = 0;
  survarium::weapon_user_dead_state::finalize(v9);
  look_animation_id = survarium::crouch_animations_captions[animation_type];
  v40 = this->m_owner;
  v39 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->((vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v40->m_animations);
  if ( is_aimed )
    p_m_next_in_memory_type = (char *)&v39[4].m_next_in_memory_type;
  else
    p_m_next_in_memory_type = (char *)&v39[3].m_fat_it.m_link_target;
  if ( is_aimed )
    p_m_sub_fat = (char *)&v39[3].m_sub_fat;
  else
    p_m_sub_fat = (char *)&v39[2].232;
  survarium::weapon_user_animations_container::get_animation_impl<27,6>(
    &look_animation,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])&p_m_sub_fat[108 * is_third_view],
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])&p_m_next_in_memory_type[24 * is_third_view],
    animation_type);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)&look_animation,
    (int)&look_lexeme_parameters,
    buffer,
    &look_animation,
    0,
    weight_driving_animation,
    v26);
  m_animation_intervals = look_lexeme_parameters.m_animation_intervals;
  m_length = look_lexeme_parameters.m_animation_intervals->m_length;
  start_animation_interval_time = survarium::weapon_user_animations_selector::look_time_factor(this->m_owner) * m_length;
  v36 = 0;
  survarium::weapon_user_dead_state::finalize(v10);
  v35 = 0;
  survarium::weapon_user_dead_state::finalize(v11);
  look_lexeme_parameters.m_start_animation_interval_time = start_animation_interval_time;
  v34 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
          (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
          &look_lexeme_parameters);
  v34->m_additivity_priority = 4;
  v12 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_user_animations_selector::look_time_calculator(
                                                                    this->m_owner,
                                                                    &v49);
  v13 = vostok::animation::mixing::animation_lexeme_parameters::time_scale_interpolator(
          (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
          v34);
  vostok::animation::mixing::animation_lexeme_parameters::time_calculator(v12, v13);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&look_lexeme, &look_lexeme_parameters);
  vostok::animation::mixing::expression::expression(
    &resulta,
    (vostok::animation::mixing::base_lexeme *)&look_lexeme,
    v14);
  m_user = this->m_user;
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_user->m_current_active_object,
    (survarium::inventory **)&v47);
  v48 = (survarium::weapon_core *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(&v47);
  weapon = v48;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v47);
  if ( weapon_parameters->recoil_backward != 0.0 )
  {
    v15 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_core::backward_recoil_time_calculator(
                                                                      weapon,
                                                                      &v46);
    survarium::player_logic_crouch_state::get_recoil_animation_lexeme(
      this,
      &expression,
      recoil_back_anim,
      is_aimed,
      weapon_parameters->recoil_backward,
      (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
      buffer,
      is_third_view,
      2u,
      v15);
    v16 = vostok::animation::mixing::operator+(&v32, &resulta, &expression);
    vostok::animation::mixing::expression::operator=(&resulta, v16);
    vostok::animation::mixing::expression::~expression(&v32);
    vostok::animation::mixing::expression::~expression(&expression);
  }
  if ( weapon_parameters->recoil_horizontal != 0.0 )
  {
    v17 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_core::horizontal_recoil_time_calculator(
                                                                      weapon,
                                                                      &v45);
    survarium::player_logic_crouch_state::get_recoil_animation_lexeme(
      this,
      &right,
      recoil_horizontal,
      is_aimed,
      weapon_parameters->recoil_horizontal,
      (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
      buffer,
      is_third_view,
      3u,
      v17);
    v18 = vostok::animation::mixing::operator+(&v31, &resulta, &right);
    vostok::animation::mixing::expression::operator=(&resulta, v18);
    vostok::animation::mixing::expression::~expression(&v31);
    vostok::animation::mixing::expression::~expression(&right);
  }
  if ( weapon_parameters->recoil_vertical != 0.0 )
  {
    v19 = (vostok::animation::mixing::animation_lexeme_parameters *)survarium::weapon_core::vertical_recoil_time_calculator(
                                                                      weapon,
                                                                      &v44);
    survarium::player_logic_crouch_state::get_recoil_animation_lexeme(
      this,
      &v50,
      recoil_vertical,
      is_aimed,
      weapon_parameters->recoil_vertical,
      (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
      buffer,
      is_third_view,
      3u,
      v19);
    v20 = vostok::animation::mixing::operator+(&v30, &resulta, &v50);
    vostok::animation::mixing::expression::operator=(&resulta, v20);
    vostok::animation::mixing::expression::~expression(&v30);
    vostok::animation::mixing::expression::~expression(&v50);
  }
  vostok::animation::mixing::expression::expression(result, &resulta);
  vostok::animation::mixing::expression::~expression(&resulta);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v21, (int)&look_lexeme);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(
    v22,
    (int)&look_lexeme_parameters);
  vostok::animation::mixing::animation_interval::~animation_interval(&look_animation);
  survarium::weapon_user_dead_state::finalize(v23);
  survarium::weapon_user_dead_state::finalize(v24);
  return result;
}
