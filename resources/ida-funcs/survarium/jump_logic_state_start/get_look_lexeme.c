vostok::animation::mixing::animation_lexeme *__thiscall survarium::jump_logic_state_start::get_look_lexeme(
        survarium::jump_logic_state_start *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        vostok::animation::mixing::animation_lexeme_parameters *look_calculator,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *move_look_animation; // eax
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v10; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v11; // ecx
  vostok::animation::mixing::animation_lexeme *v13; // [esp+0h] [ebp-A0h]
  vostok::animation::mixing::animation_lexeme_parameters *v15; // [esp+10h] [ebp-90h]
  float m_length; // [esp+18h] [ebp-88h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v17; // [esp+34h] [ebp-6Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v18; // [esp+38h] [ebp-68h] BYREF
  const char *look_animation_id; // [esp+3Ch] [ebp-64h]
  vostok::animation::mixing::animation_lexeme_parameters parameters; // [esp+40h] [ebp-60h] BYREF
  float start_animation_interval_time; // [esp+98h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> look_animation; // [esp+9Ch] [ebp-4h] BYREF

  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &look_animation,
    0);
  look_animation_id = 0;
  if ( this->m_preface_interval_ended )
  {
    animation = survarium::jump_logic::get_animation(
                  this->m_jump_logic,
                  &v18,
                  jump_animations_part_start_look,
                  is_third_view);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &look_animation,
      animation);
    vostok::animation::mixing::animation_interval::~animation_interval(&v18);
    look_animation_id = survarium::jump_logic::get_animation_caption(
                          this->m_jump_logic,
                          jump_animations_part_start_look);
  }
  else
  {
    move_look_animation = survarium::jump_logic::get_move_look_animation(this->m_jump_logic, &v17, is_third_view);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &look_animation,
      move_look_animation);
    vostok::animation::mixing::animation_interval::~animation_interval(&v17);
    look_animation_id = survarium::jump_logic::get_move_look_caption(this->m_jump_logic);
  }
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)weight_driving_animation,
    (int)&parameters,
    buffer,
    &look_animation,
    0,
    (vostok::animation::mixing::base_lexeme *)weight_driving_animation,
    v13);
  m_length = parameters.m_animation_intervals->m_length;
  start_animation_interval_time = survarium::jump_logic::look_time_factor(this->m_jump_logic) * m_length;
  survarium::weapon_user_dead_state::finalize(v8);
  survarium::weapon_user_dead_state::finalize(v9);
  parameters.m_start_animation_interval_time = start_animation_interval_time;
  v15 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
          (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
          &parameters);
  v15->m_additivity_priority = 4;
  v10 = vostok::animation::mixing::animation_lexeme_parameters::time_calculator(look_calculator, v15);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v10);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v11, (int)&parameters);
  vostok::animation::mixing::animation_interval::~animation_interval(&look_animation);
  return result;
}
