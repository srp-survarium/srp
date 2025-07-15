vostok::animation::mixing::animation_lexeme *__thiscall survarium::player_logic_stand_state::movement_lexeme(
        survarium::player_logic_stand_state *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        unsigned int animation_index,
        vostok::animation::mixing::animation_lexeme_parameters *bones_mask,
        bool is_aimed,
        bool is_third_view,
        bool is_firing)
{
  vostok::animation::linear_interpolator *v8; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v9; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v10; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v11; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  struct vostok::animation::mixing::animation_lexeme_parameters *v13; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v14; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v15; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v16; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v17; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v18; // ecx
  vostok::animation::mixing::animation_lexeme *v19; // ecx
  survarium::game_camera *v20; // ecx
  vostok::animation::mixing::animation_lexeme *v22; // [esp+0h] [ebp-140h]
  survarium::weapon_user_animations_container *m_aimed_stand_animations; // [esp+8h] [ebp-138h]
  survarium::weapon_user_animations_container *m_aimed_stand_hands_only_animations; // [esp+Ch] [ebp-134h]
  unsigned int v25; // [esp+10h] [ebp-130h]
  survarium::player_logic_stand_state *thisa; // [esp+14h] [ebp-12Ch]
  survarium::game_camera *v27; // [esp+34h] [ebp-10Ch]
  survarium::weapon_user_animations_selector *m_owner; // [esp+40h] [ebp-100h]
  survarium::weapon_user_animations_container *m_object; // [esp+44h] [ebp-FCh]
  float m_movement_speed_factor; // [esp+4Ch] [ebp-F4h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v31; // [esp+50h] [ebp-F0h] BYREF
  _BYTE v32[88]; // [esp+54h] [ebp-ECh] BYREF
  vostok::animation::linear_interpolator interpolator; // [esp+ACh] [ebp-94h] BYREF
  unsigned int main_animation_index; // [esp+B4h] [ebp-8Ch]
  vostok::animation::mixing::animation_lexeme movement_lexeme; // [esp+B8h] [ebp-88h] BYREF

  thisa = this;
  if ( is_firing )
  {
    this = (survarium::player_logic_stand_state *)(animation_index + 1);
    v25 = animation_index + 1;
  }
  else
  {
    v25 = animation_index;
  }
  main_animation_index = v25;
  v32[87] = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::animation::linear_interpolator::linear_interpolator(v8, &interpolator, SLODWORD(s_aim_transition_time));
  m_movement_speed_factor = thisa->m_user->m_movement_speed_factor;
  m_owner = thisa->m_owner;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)thisa);
  m_object = m_owner->m_animations.m_object;
  if ( is_aimed )
    m_aimed_stand_hands_only_animations = (survarium::weapon_user_animations_container *)m_object->m_aimed_stand_hands_only_animations;
  else
    m_aimed_stand_hands_only_animations = (survarium::weapon_user_animations_container *)m_object->m_stand_hands_only_animations;
  if ( is_aimed )
    m_aimed_stand_animations = (survarium::weapon_user_animations_container *)m_object->m_aimed_stand_animations;
  else
    m_aimed_stand_animations = (survarium::weapon_user_animations_container *)m_object->m_stand_animations;
  survarium::weapon_user_animations_container::get_animation_impl<27,6>(
    &v31,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])((const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)m_aimed_stand_animations + is_third_view),
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])((const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)m_aimed_stand_hands_only_animations + is_third_view),
    main_animation_index);
  v27 = (survarium::game_camera *)thisa->m_owner;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)thisa);
  survarium::weapon_user_dead_state::finalize(v27);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)buffer,
    (int)v32,
    buffer,
    &v31,
    0,
    0,
    v22);
  v10 = vostok::animation::mixing::animation_lexeme_parameters::weight_synchronization_group_id(0, v9);
  v11 = vostok::animation::mixing::animation_lexeme_parameters::time_synchronization_group_id(
          (vostok::animation::mixing::animation_lexeme_parameters *)((animation_index != 0) - 1),
          v10);
  v12 = vostok::animation::mixing::animation_lexeme_parameters::weight_interpolator(
          (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
          v11);
  v13 = vostok::animation::mixing::animation_lexeme_parameters::time_scale_interpolator(
          (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
          v12);
  v15 = vostok::animation::mixing::animation_lexeme_parameters::time_scale(v14, v13, m_movement_speed_factor);
  v16 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
          (vostok::animation::mixing::animation_lexeme_parameters *)thisa->m_user,
          v15);
  v17 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(bones_mask, v16);
  v17->m_user_data = 1;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&movement_lexeme, v17);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v18, (int)v32);
  vostok::animation::mixing::animation_interval::~animation_interval(&v31);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, &movement_lexeme);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v19, (int)&movement_lexeme);
  survarium::weapon_user_dead_state::finalize(v20);
  return result;
}
