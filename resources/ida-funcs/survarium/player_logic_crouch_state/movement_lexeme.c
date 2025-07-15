vostok::animation::mixing::animation_lexeme *__thiscall survarium::player_logic_crouch_state::movement_lexeme(
        survarium::player_logic_crouch_state *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        unsigned int animation_index,
        vostok::animation::mixing::animation_lexeme_parameters *bones_mask,
        bool is_aimed,
        bool is_third_view,
        bool is_firing)
{
  vostok::animation::mixing::animation_lexeme_parameters *v8; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v9; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v10; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v11; // eax
  struct vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v13; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v14; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v15; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v16; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v17; // ecx
  vostok::animation::mixing::animation_lexeme *v18; // ecx
  survarium::game_camera *v19; // ecx
  vostok::animation::mixing::animation_lexeme *v21; // [esp+0h] [ebp-138h]
  survarium::weapon_user_animations_container *m_aimed_crouch_animations; // [esp+8h] [ebp-130h]
  survarium::weapon_user_animations_container *m_aimed_crouch_hands_only_animations; // [esp+Ch] [ebp-12Ch]
  unsigned int v24; // [esp+10h] [ebp-128h]
  survarium::player_logic_crouch_state *thisa; // [esp+14h] [ebp-124h]
  survarium::weapon_user_animations_selector *v26; // [esp+30h] [ebp-108h]
  survarium::weapon_user_animations_selector *m_owner; // [esp+3Ch] [ebp-FCh]
  survarium::weapon_user_animations_container *m_object; // [esp+40h] [ebp-F8h]
  float m_movement_speed_factor; // [esp+48h] [ebp-F0h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v30; // [esp+4Ch] [ebp-ECh] BYREF
  _BYTE v31[84]; // [esp+50h] [ebp-E8h] BYREF
  unsigned int move_animation_index; // [esp+A4h] [ebp-94h]
  vostok::animation::linear_interpolator interpolator; // [esp+A8h] [ebp-90h] BYREF
  vostok::animation::mixing::animation_lexeme movement_lexeme; // [esp+B0h] [ebp-88h] BYREF

  thisa = this;
  if ( is_firing )
  {
    this = (survarium::player_logic_crouch_state *)(animation_index + 1);
    v24 = animation_index + 1;
  }
  else
  {
    v24 = animation_index;
  }
  move_animation_index = v24;
  vostok::animation::linear_interpolator::linear_interpolator(
    (vostok::animation::linear_interpolator *)this,
    &interpolator,
    SLODWORD(s_aim_transition_time));
  m_movement_speed_factor = thisa->m_user->m_movement_speed_factor;
  m_owner = thisa->m_owner;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_owner);
  m_object = m_owner->m_animations.m_object;
  if ( is_aimed )
    m_aimed_crouch_hands_only_animations = (survarium::weapon_user_animations_container *)m_object->m_aimed_crouch_hands_only_animations;
  else
    m_aimed_crouch_hands_only_animations = (survarium::weapon_user_animations_container *)m_object->m_crouch_hands_only_animations;
  if ( is_aimed )
    m_aimed_crouch_animations = (survarium::weapon_user_animations_container *)m_object->m_aimed_crouch_animations;
  else
    m_aimed_crouch_animations = (survarium::weapon_user_animations_container *)m_object->m_crouch_animations;
  survarium::weapon_user_animations_container::get_animation_impl<27,6>(
    &v30,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[27])((const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)m_aimed_crouch_animations + is_third_view),
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[6])((const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)m_aimed_crouch_hands_only_animations + is_third_view),
    move_animation_index);
  v26 = thisa->m_owner;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v26);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v26->m_animations.m_object);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    (vostok::animation::mixing::animation_lexeme_parameters *)survarium::crouch_animations_captions[move_animation_index],
    (int)v31,
    buffer,
    &v30,
    0,
    0,
    v21);
  v9 = vostok::animation::mixing::animation_lexeme_parameters::weight_synchronization_group_id(0, v8);
  v10 = vostok::animation::mixing::animation_lexeme_parameters::time_synchronization_group_id(
          (vostok::animation::mixing::animation_lexeme_parameters *)((animation_index != 0) - 1),
          v9);
  v11 = vostok::animation::mixing::animation_lexeme_parameters::weight_interpolator(
          (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
          v10);
  v12 = vostok::animation::mixing::animation_lexeme_parameters::time_scale_interpolator(
          (vostok::animation::mixing::animation_lexeme_parameters *)&interpolator,
          v11);
  v14 = vostok::animation::mixing::animation_lexeme_parameters::time_scale(v13, v12, m_movement_speed_factor);
  v15 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
          (vostok::animation::mixing::animation_lexeme_parameters *)thisa->m_user,
          v14);
  v16 = vostok::animation::mixing::animation_lexeme_parameters::bones_mask(bones_mask, v15);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&movement_lexeme, v16);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v17, (int)v31);
  vostok::animation::mixing::animation_interval::~animation_interval(&v30);
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, &movement_lexeme);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v18, (int)&movement_lexeme);
  survarium::weapon_user_dead_state::finalize(v19);
  return result;
}
