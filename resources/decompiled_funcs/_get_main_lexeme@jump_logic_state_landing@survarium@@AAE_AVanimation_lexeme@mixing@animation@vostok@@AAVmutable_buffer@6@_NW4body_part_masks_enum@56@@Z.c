vostok::animation::mixing::animation_lexeme *__thiscall survarium::jump_logic_state_landing::get_main_lexeme(
        survarium::jump_logic_state_landing *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        vostok::animation::mixing::animation_lexeme_parameters *bones_mask)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation; // eax
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  const vostok::animation::mixing::animation_interval *animation_interval; // eax
  vostok::animation::linear_interpolator *v9; // ecx
  const vostok::animation::mixing::animation_interval *v10; // eax
  const vostok::animation::mixing::animation_interval *v11; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v12; // esi
  vostok::animation::instant_interpolator *v13; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v14; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v15; // edi
  vostok::animation::mixing::animation_lexeme_parameters *v16; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v17; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v18; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v19; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v20; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v21; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v22; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v23; // ecx
  survarium::game_camera *v24; // ecx
  survarium::game_camera *v25; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v27; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v28; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v29; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v30; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v31; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v32; // ecx
  vostok::animation::mixing::animation_lexeme *v33; // [esp+0h] [ebp-18Ch]
  vostok::animation::mixing::animation_interval *animation_intervals_begin; // [esp+3Ch] [ebp-150h]
  vostok::animation::mixing::animation_interval *animation_intervals_end; // [esp+40h] [ebp-14Ch]
  vostok::animation::mixing::animation_interval *value; // [esp+68h] [ebp-124h]
  _BYTE v38[84]; // [esp+74h] [ebp-118h] BYREF
  int v39; // [esp+C8h] [ebp-C4h] BYREF
  int v40; // [esp+D0h] [ebp-BCh] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v41; // [esp+D4h] [ebp-B8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v42; // [esp+128h] [ebp-64h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v43; // [esp+134h] [ebp-58h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v44; // [esp+140h] [ebp-4Ch] BYREF
  unsigned int interval_id[3]; // [esp+14Ch] [ebp-40h] BYREF
  char v46; // [esp+15Bh] [ebp-31h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v47; // [esp+15Ch] [ebp-30h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> move_animation; // [esp+160h] [ebp-2Ch] BYREF
  vostok::fixed_vector<vostok::animation::mixing::animation_interval,2> intervals; // [esp+164h] [ebp-28h] BYREF
  const char *caption; // [esp+188h] [ebp-4h]

  animation = survarium::jump_logic::get_animation(
                this->m_jump_logic,
                &v47,
                (const survarium::jump_animation_parts)this->m_landing_type,
                is_third_view);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_animation,
    animation);
  vostok::animation::mixing::animation_interval::~animation_interval(&v47);
  caption = survarium::jump_logic::get_animation_caption(
              this->m_jump_logic,
              (const survarium::jump_animation_parts)this->m_landing_type);
  if ( this->m_landing_type == jump_animations_part_land_run )
  {
    survarium::jump_logic::get_move_animation(this->m_jump_logic, &move_animation, is_third_view);
    v46 = 0;
    survarium::weapon_user_dead_state::finalize(v6);
    vostok::buffer_vector<vostok::animation::mixing::animation_interval>::buffer_vector<vostok::animation::mixing::animation_interval>(
      &intervals,
      (vostok::animation::mixing::animation_interval *)intervals.m_buffer,
      2u,
      0);
    if ( this->m_jump_logic->m_is_jump_from_right_leg )
    {
      value = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
                &move_animation,
                (const unsigned int)interval_id);
      survarium::weapon_user_dead_state::finalize(v7);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::construct(intervals.m_end++, value);
      vostok::animation::mixing::animation_interval::~animation_interval((vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)interval_id);
      animation_interval = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
                             &this->m_animation,
                             (const unsigned int)&v44);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(&intervals, animation_interval);
      vostok::animation::mixing::animation_interval::~animation_interval(&v44);
      v9 = (vostok::animation::linear_interpolator *)this;
      this->m_interval_id_to_wait_for = 1;
    }
    else
    {
      v10 = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
              &this->m_animation,
              (const unsigned int)&v43);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(&intervals, v10);
      vostok::animation::mixing::animation_interval::~animation_interval(&v43);
      v11 = vostok::animation::mixing::animation_lexeme_parameters::create_animation_interval(
              &move_animation,
              (const unsigned int)&v42);
      vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(&intervals, v11);
      vostok::animation::mixing::animation_interval::~animation_interval(&v42);
      v9 = (vostok::animation::linear_interpolator *)this;
      this->m_interval_id_to_wait_for = 0;
    }
    animation_intervals_end = intervals.m_end;
    animation_intervals_begin = intervals.m_begin;
    v12 = (vostok::animation::mixing::animation_lexeme_parameters *)vostok::animation::linear_interpolator::linear_interpolator(
                                                                      v9,
                                                                      &v39,
                                                                      SLODWORD(s_aim_transition_time));
    vostok::animation::instant_interpolator::instant_interpolator(v13, &v40);
    v15 = v14;
    vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
      &v41,
      buffer,
      caption,
      animation_intervals_begin,
      animation_intervals_end,
      0,
      0);
    v17 = vostok::animation::mixing::animation_lexeme_parameters::weight_synchronization_group_id(0, v16);
    v18 = vostok::animation::mixing::animation_lexeme_parameters::weight_interpolator(v15, v17);
    v19 = vostok::animation::mixing::animation_lexeme_parameters::time_synchronization_group_id(0, v18);
    v20 = vostok::animation::mixing::animation_lexeme_parameters::time_scale_interpolator(v12, v19);
    v21 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
            (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
            v20);
    v22 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(bones_mask, v21);
    vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v22);
    vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v23, (int)&v41);
    survarium::weapon_user_dead_state::finalize(v24);
    survarium::weapon_user_dead_state::finalize(v25);
    vostok::buffer_vector<vostok::animation::mixing::animation_interval>::~buffer_vector<vostok::animation::mixing::animation_interval>(&intervals);
    vostok::animation::mixing::animation_interval::~animation_interval(&move_animation);
    return result;
  }
  else
  {
    this->m_interval_id_to_wait_for = 0;
    vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
      (vostok::animation::mixing::animation_lexeme_parameters *)&this->m_animation,
      (int)v38,
      buffer,
      &this->m_animation,
      0,
      0,
      v33);
    v28 = vostok::animation::mixing::animation_lexeme_parameters::weight_synchronization_group_id(0, v27);
    v29 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
            (vostok::animation::mixing::animation_lexeme_parameters *)this->m_user,
            v28);
    v30 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(bones_mask, v29);
    v31 = vostok::animation::mixing::animation_lexeme_parameters::playback_type(
            (vostok::animation::mixing::animation_lexeme_parameters *)1,
            v30);
    vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v31);
    vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v32, (int)v38);
    return result;
  }
}
