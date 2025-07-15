vostok::animation::mixing::animation_lexeme *__thiscall survarium::jump_logic_state_start::get_main_lexeme(
        survarium::jump_logic_state_start *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        vostok::animation::mixing::animation_lexeme_parameters *bones_mask)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *move_animation; // eax
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  const vostok::animation::mixing::animation_interval *animation_interval; // eax
  const vostok::animation::mixing::animation_interval *v10; // eax
  const vostok::animation::mixing::animation_interval *v11; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v12; // esi
  vostok::animation::linear_interpolator *v13; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v14; // edi
  vostok::animation::mixing::animation_lexeme_parameters *v15; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v16; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v17; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v18; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v19; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v20; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v21; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v22; // ecx
  survarium::game_camera *v23; // ecx
  survarium::game_camera *v24; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v26; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v27; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v28; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v29; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v30; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v31; // ecx
  survarium::game_camera *v32; // ecx
  vostok::animation::mixing::animation_lexeme *v33; // [esp+0h] [ebp-19Ch]
  vostok::animation::mixing::animation_interval *animation_intervals_begin; // [esp+40h] [ebp-15Ch]
  vostok::animation::mixing::animation_interval *animation_intervals_end; // [esp+44h] [ebp-158h]
  vostok::animation::mixing::animation_interval *value; // [esp+6Ch] [ebp-130h]
  _BYTE v38[84]; // [esp+7Ch] [ebp-120h] BYREF
  int v39; // [esp+D0h] [ebp-CCh] BYREF
  int v40; // [esp+D8h] [ebp-C4h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v41; // [esp+E0h] [ebp-BCh] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v42; // [esp+134h] [ebp-68h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v43; // [esp+140h] [ebp-5Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v44; // [esp+14Ch] [ebp-50h] BYREF
  unsigned int interval_id[3]; // [esp+158h] [ebp-44h] BYREF
  char v46; // [esp+167h] [ebp-35h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v47; // [esp+168h] [ebp-34h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v48; // [esp+16Ch] [ebp-30h] BYREF
  vostok::animation::linear_interpolator interpolator; // [esp+170h] [ebp-2Ch] BYREF
  vostok::fixed_vector<vostok::animation::mixing::animation_interval,2> intervals; // [esp+178h] [ebp-24h] BYREF
  const char *caption; // [esp+198h] [ebp-4h]

  animation = survarium::jump_logic::get_animation(this->m_jump_logic, &v48, jump_animations_part_start, is_third_view);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_animation,
    animation);
  vostok::animation::mixing::animation_interval::~animation_interval(&v48);
  caption = survarium::jump_logic::get_animation_caption(this->m_jump_logic, jump_animations_part_start);
  if ( this->m_jump_logic->m_jumping_direction )
  {
    move_animation = survarium::jump_logic::get_move_animation(this->m_jump_logic, &v47, is_third_view);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &this->m_preface_animation,
      move_animation);
    vostok::animation::mixing::animation_interval::~animation_interval(&v47);
    v46 = 0;
    survarium::weapon_user_dead_state::finalize(v7);
    vostok::buffer_vector<vostok::animation::mixing::animation_interval>::buffer_vector<vostok::animation::mixing::animation_interval>(
      &intervals,
      (vostok::animation::mixing::animation_interval *)intervals.m_buffer,
      2u,
      0);
    if ( this->m_jump_logic->m_is_jump_from_right_leg )
    {
      value = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
                &this->m_animation,
                (const unsigned int)interval_id);
      survarium::weapon_user_dead_state::finalize(v8);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::construct(intervals.m_end++, value);
      vostok::animation::mixing::animation_interval::~animation_interval((vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)interval_id);
      animation_interval = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
                             &this->m_preface_animation,
                             (const unsigned int)&v44);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(&intervals, animation_interval);
      vostok::animation::mixing::animation_interval::~animation_interval(&v44);
      this->m_interval_id_to_wait_for = 0;
    }
    else
    {
      v10 = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
              &this->m_preface_animation,
              (const unsigned int)&v43);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(&intervals, v10);
      vostok::animation::mixing::animation_interval::~animation_interval(&v43);
      v11 = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
              &this->m_animation,
              (const unsigned int)&v42);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(&intervals, v11);
      vostok::animation::mixing::animation_interval::~animation_interval(&v42);
      this->m_interval_id_to_wait_for = 1;
    }
    animation_intervals_end = intervals.m_end;
    animation_intervals_begin = intervals.m_begin;
    v12 = (vostok::animation::mixing::animation_lexeme_parameters *)vostok::animation::linear_interpolator::linear_interpolator(
                                                                      (vostok::animation::linear_interpolator *)intervals.m_begin,
                                                                      &v39,
                                                                      SLODWORD(s_aim_transition_time));
    v14 = (vostok::animation::mixing::animation_lexeme_parameters *)vostok::animation::linear_interpolator::linear_interpolator(
                                                                      v13,
                                                                      &v40,
                                                                      SLODWORD(s_aim_transition_time));
    vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
      &v41,
      buffer,
      caption,
      animation_intervals_begin,
      animation_intervals_end,
      0,
      0);
    v16 = vostok::animation::mixing::animation_lexeme_parameters::weight_synchronization_group_id(0, v15);
    v17 = vostok::animation::mixing::animation_lexeme_parameters::weight_interpolator(v14, v16);
    v18 = vostok::animation::mixing::animation_lexeme_parameters::time_synchronization_group_id(0, v17);
    v19 = vostok::animation::mixing::animation_lexeme_parameters::time_scale_interpolator(v12, v18);
    v20 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
            (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
            v19);
    v21 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(bones_mask, v20);
    vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v21);
    vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v22, (int)&v41);
    survarium::weapon_user_dead_state::finalize(v23);
    survarium::weapon_user_dead_state::finalize(v24);
    vostok::buffer_vector<vostok::animation::mixing::animation_interval>::~buffer_vector<vostok::animation::mixing::animation_interval>(&intervals);
    return result;
  }
  else
  {
    this->m_interval_id_to_wait_for = 0;
    vostok::animation::linear_interpolator::linear_interpolator(
      (vostok::animation::linear_interpolator *)this,
      &interpolator,
      SLODWORD(s_aim_transition_time));
    vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
      (vostok::animation::mixing::animation_lexeme_parameters *)buffer,
      (int)v38,
      buffer,
      &this->m_animation,
      0,
      0,
      v33);
    v27 = vostok::animation::mixing::animation_lexeme_parameters::weight_synchronization_group_id(0, v26);
    v28 = vostok::animation::mixing::animation_lexeme_parameters::weight_interpolator(
            (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
            v27);
    v29 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
            (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
            v28);
    v30 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(bones_mask, v29);
    vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v30);
    vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v31, (int)v38);
    survarium::weapon_user_dead_state::finalize(v32);
    return result;
  }
}
