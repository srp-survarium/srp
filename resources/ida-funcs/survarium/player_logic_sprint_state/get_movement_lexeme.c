vostok::animation::mixing::animation_lexeme *__userpurge survarium::player_logic_sprint_state::get_movement_lexeme@<eax>(
        survarium::player_logic_sprint_state *this@<ecx>,
        int a2@<edi>,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        unsigned int animation_index,
        unsigned int bones_mask)
{
  float move_animation_time_scale; // xmm0_4
  int v8; // eax
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *sprint_animation; // eax
  vostok::animation::mixing::animation_lexeme *v10; // ecx
  float v11; // xmm0_4
  const vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v13; // ecx
  vostok::animation::mixing::animation_lexeme *v15; // [esp+0h] [ebp-70h]
  vostok::animation::mixing::animation_lexeme_parameters v16; // [esp+8h] [ebp-68h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v17; // [esp+5Ch] [ebp-14h] BYREF
  _DWORD v18[2]; // [esp+64h] [ebp-Ch] BYREF
  float v19; // [esp+6Ch] [ebp-4h]

  move_animation_time_scale = survarium::base_player::get_move_animation_time_scale(
                                *(survarium::base_player **)(a2 + 28),
                                *(survarium::weapon_user_state_enum *)(a2 + 32),
                                animation_index,
                                0);
  v8 = *(_DWORD *)(a2 + 24);
  v19 = move_animation_time_scale;
  v18[0] = &vostok::animation::linear_interpolator::`vftable';
  *(float *)&v18[1] = s_aim_transition_time;
  sprint_animation = survarium::weapon_user_animations_container::get_sprint_animation(
                       (survarium::weapon_user_animations_container *)&v17,
                       *(stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > **)(v8 + 56),
                       &v17,
                       animation_index);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v16,
    buffer,
    v10,
    &sprint_animation->first,
    0,
    0,
    v15);
  v11 = v19;
  v12->m_weight_interpolator = (const vostok::animation::base_interpolator *)v18;
  v12->m_time_scale_interpolator = (const vostok::animation::base_interpolator *)v18;
  v12->m_weight_synchronization_group_id = 0;
  v12->m_time_synchronization_group_id = 0;
  v12->m_time_scale = v11;
  v12->m_animated_object = *(const void **)(a2 + 28);
  v12->m_bones_mask = bones_mask;
  v12->m_user_data = 1;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v12);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v13, (int)&v16);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.first);
  return result;
}
