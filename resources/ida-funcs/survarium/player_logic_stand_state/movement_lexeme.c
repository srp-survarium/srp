vostok::animation::mixing::animation_lexeme *__userpurge survarium::player_logic_stand_state::movement_lexeme@<eax>(
        survarium::player_logic_stand_state *this@<ecx>,
        unsigned int animation_index@<eax>,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::mutable_buffer *bones_mask,
        unsigned int is_aimed,
        const bool is_firing,
        char a8)
{
  float move_animation_time_scale; // xmm0_4
  survarium::weapon_user_animations_selector *m_owner; // eax
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *stand_animation; // eax
  vostok::animation::mixing::animation_lexeme *v12; // ecx
  float v13; // xmm0_4
  const vostok::animation::mixing::animation_lexeme_parameters *v14; // eax
  survarium::base_player *m_user; // edi
  vostok::animation::mixing::animation_lexeme_parameters *v16; // ecx
  survarium::weapon_user_animations_container *m_object; // [esp-10h] [ebp-94h]
  vostok::animation::mixing::animation_lexeme *v19; // [esp+0h] [ebp-84h]
  vostok::animation::mixing::animation_lexeme_parameters v20; // [esp+10h] [ebp-74h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v21; // [esp+64h] [ebp-20h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v22; // [esp+6Ch] [ebp-18h] BYREF
  _DWORD v23[2]; // [esp+74h] [ebp-10h] BYREF
  float v24; // [esp+7Ch] [ebp-8h]
  int v25; // [esp+9Ch] [ebp+18h]

  if ( a8 )
    ++animation_index;
  v25 = animation_index;
  move_animation_time_scale = survarium::base_player::get_move_animation_time_scale(
                                this->m_user,
                                (survarium::weapon_user_state_enum)this->m_weapon_user_state_id,
                                animation_index,
                                is_firing);
  m_object = this->m_owner->m_animations.m_object;
  v24 = move_animation_time_scale;
  survarium::weapon_user_animations_container::get_stand_animation(
    (survarium::weapon_user_animations_container *)&v21,
    (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)m_object,
    &v21,
    is_firing,
    v25);
  m_owner = this->m_owner;
  v23[0] = &vostok::animation::linear_interpolator::`vftable';
  *(float *)&v23[1] = s_aim_transition_time;
  stand_animation = survarium::weapon_user_animations_container::get_stand_animation(
                      (survarium::weapon_user_animations_container *)&v22,
                      (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)m_owner->m_animations.m_object,
                      &v22,
                      is_firing,
                      v25);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v20,
    bones_mask,
    v12,
    &stand_animation->first,
    0,
    0,
    v19);
  v13 = v24;
  v14->m_weight_interpolator = (const vostok::animation::base_interpolator *)v23;
  v14->m_time_scale_interpolator = (const vostok::animation::base_interpolator *)v23;
  v14->m_weight_synchronization_group_id = 0;
  v14->m_time_synchronization_group_id = 0;
  v14->m_time_scale = v13;
  m_user = this->m_user;
  v14->m_bones_mask = is_aimed;
  v14->m_animated_object = m_user;
  v14->m_user_data = 1;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(buffer, v14);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v16, (int)&v20);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v22.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v22.first);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v21.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v21.first);
  return buffer;
}
