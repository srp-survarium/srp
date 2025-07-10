vostok::animation::mixing::animation_lexeme *__thiscall survarium::jump_logic_state_landing::get_look_lexeme(
        survarium::jump_logic_state_landing *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        vostok::animation::mixing::animation_lexeme_parameters *look_calculator,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v8; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v9; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v10; // ecx
  vostok::animation::mixing::animation_lexeme *v12; // [esp+0h] [ebp-8Ch]
  vostok::animation::mixing::animation_lexeme_parameters *v14; // [esp+14h] [ebp-78h]
  float m_length; // [esp+1Ch] [ebp-70h]
  vostok::animation::mixing::animation_lexeme_parameters parameters; // [esp+2Ch] [ebp-60h] BYREF
  float start_animation_interval_time; // [esp+84h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> look_animation; // [esp+88h] [ebp-4h] BYREF

  survarium::jump_logic::get_animation(
    this->m_jump_logic,
    &look_animation,
    jump_animations_part_land_run_look,
    is_third_view);
  survarium::jump_logic::get_animation_caption(this->m_jump_logic, jump_animations_part_land_run_look);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)weight_driving_animation,
    (int)&parameters,
    buffer,
    &look_animation,
    0,
    (vostok::animation::mixing::base_lexeme *)weight_driving_animation,
    v12);
  m_length = parameters.m_animation_intervals->m_length;
  start_animation_interval_time = survarium::jump_logic::look_time_factor(this->m_jump_logic) * m_length;
  survarium::weapon_user_dead_state::finalize(v6);
  survarium::weapon_user_dead_state::finalize(v7);
  parameters.m_start_animation_interval_time = start_animation_interval_time;
  v14 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
          (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
          &parameters);
  v14->m_additivity_priority = 4;
  v8 = vostok::animation::mixing::animation_lexeme_parameters::weight_synchronization_group_id(0, v14);
  v9 = vostok::animation::mixing::animation_lexeme_parameters::time_calculator(look_calculator, v8);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v9);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v10, (int)&parameters);
  vostok::animation::mixing::animation_interval::~animation_interval(&look_animation);
  return result;
}
