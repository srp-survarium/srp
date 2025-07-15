vostok::animation::mixing::expression *__thiscall survarium::weapon_core::selected_animations(
        survarium::weapon_core *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view)
{
  survarium::weapon_core *v4; // ecx
  survarium::weapon_user_state_enum current_state_id; // eax
  stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> *v6; // ecx
  float max; // [esp+0h] [ebp-128h]
  unsigned int v9; // [esp+8h] [ebp-120h]
  float v11; // [esp+40h] [ebp-E8h]
  __int64 v12; // [esp+44h] [ebp-E4h]
  vostok::ai::fsm_state_transition *body_part_mask_for_user; // [esp+4Ch] [ebp-DCh]
  __int16 v14; // [esp+51h] [ebp-D7h]
  survarium::game_camera v15[2]; // [esp+78h] [ebp-B0h] BYREF

  this->m_is_third_view = is_third_view;
  if ( s_recoil_enable_value && s_recoil_back_enable_value )
  {
    max = *(float *)&clear_value - epsilon;
    *(float *)&v9 = survarium::recoil_calculator::get_back_coeff(&this->m_recoil_calculator);
    HIDWORD(v12) = vostok::math::clamp_r<float>((__m128)LODWORD(epsilon), v9, max).m128_u32[0];
  }
  else
  {
    HIDWORD(v12) = *(_DWORD *)&FLOAT_0_0;
  }
  if ( s_recoil_enable_value && s_recoil_vertical_enable_value )
    *(float *)&v12 = survarium::weapon_core::vertical_recoil_value(this);
  else
    LODWORD(v12) = *(_DWORD *)&FLOAT_0_0;
  if ( s_recoil_enable_value && s_recoil_horizontal_enable_value )
    v11 = survarium::weapon_core::horizontal_recoil_value(this);
  else
    v11 = *(float *)&FLOAT_0_0;
  HIBYTE(v14) = this->m_is_firing;
  body_part_mask_for_user = survarium::weapon_core::get_body_part_mask_for_user(this);
  LOBYTE(v14) = survarium::weapon_core::is_aimed(v4, (int)this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)v15);
  *(float *)&v15[0].__vftable = v11;
  *(_QWORD *)&v15[0].m_inverted_view_matrix.i.x = v12;
  LODWORD(v15[0].m_inverted_view_matrix.i.z) = body_part_mask_for_user;
  LOWORD(v15[0].m_inverted_view_matrix.lines[0].elements[3]) = v14;
  survarium::weapon_user_animations_selector::selected_animations(
    &this->m_user_animations_selector,
    (stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> *)&v15[0].m_inverted_view_matrix.lines[1].elements[3],
    buffer,
    (const survarium::weapon_animation_parameters *)v15,
    is_third_view);
  survarium::weapon_user_dead_state::finalize(v15);
  current_state_id = survarium::weapon_user_animations_selector::get_current_state_id(&this->m_user_animations_selector);
  survarium::weapon_core::get_weapon_and_hands_animation_expression(
    this,
    (vostok::animation::mixing::expression *)&v15[0].m_inverted_view_matrix.lines[1],
    buffer,
    is_third_view,
    current_state_id,
    (vostok::animation::mixing::animation_lexeme *)&v15[0].m_inverted_view_matrix.lines[2].elements[1]);
  LODWORD(v15[0].m_inverted_view_matrix.j.z) = &v15[0].m_inverted_view_matrix.j.0;
  vostok::animation::mixing::operator+(
    result,
    (vostok::animation::mixing::expression *)&v15[0].m_inverted_view_matrix.lines[1].elements[3],
    (vostok::animation::mixing::expression *)&v15[0].m_inverted_view_matrix.lines[1]);
  vostok::animation::mixing::expression::~expression((vostok::animation::mixing::expression *)&v15[0].m_inverted_view_matrix.lines[1]);
  stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme>::~pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme>(
    v6,
    &v15[0].m_inverted_view_matrix.j.w);
  return result;
}
