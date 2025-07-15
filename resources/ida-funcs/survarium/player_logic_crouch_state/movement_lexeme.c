vostok::animation::mixing::animation_lexeme *__userpurge survarium::player_logic_crouch_state::movement_lexeme@<eax>(
        survarium::player_logic_crouch_state *this@<ecx>,
        int a2@<eax>,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        unsigned int animation_index,
        unsigned int bones_mask,
        const bool is_aimed,
        const bool is_firing)
{
  unsigned int v9; // ebx
  float move_animation_time_scale; // xmm0_4
  int v12; // eax
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *crouch_animation; // eax
  vostok::animation::mixing::animation_lexeme *v14; // ecx
  const vostok::animation::mixing::animation_lexeme_parameters *v15; // eax
  const void *v16; // edi
  vostok::animation::mixing::animation_lexeme_parameters *v17; // ecx
  vostok::animation::mixing::animation_lexeme *v19; // [esp+0h] [ebp-70h]
  vostok::animation::mixing::animation_lexeme_parameters v20; // [esp+Ch] [ebp-64h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v21; // [esp+60h] [ebp-10h] BYREF
  _DWORD v22[2]; // [esp+68h] [ebp-8h] BYREF

  v9 = animation_index;
  if ( is_firing )
    v9 = animation_index + 1;
  move_animation_time_scale = survarium::base_player::get_move_animation_time_scale(
                                *(survarium::base_player **)(a2 + 28),
                                *(survarium::weapon_user_state_enum *)(a2 + 32),
                                v9,
                                is_aimed);
  v12 = *(_DWORD *)(a2 + 24);
  v22[0] = &vostok::animation::linear_interpolator::`vftable';
  *(float *)&v22[1] = s_aim_transition_time;
  crouch_animation = survarium::weapon_user_animations_container::get_crouch_animation(
                       (survarium::weapon_user_animations_container *)&v21,
                       *(_DWORD *)(v12 + 56),
                       &v21,
                       is_aimed,
                       v9);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v20,
    buffer,
    v14,
    &crouch_animation->first,
    0,
    0,
    v19);
  v15->m_weight_synchronization_group_id = 0;
  v15->m_time_scale = move_animation_time_scale;
  v15->m_time_synchronization_group_id = (animation_index != 0) - 1;
  v15->m_weight_interpolator = (const vostok::animation::base_interpolator *)v22;
  v15->m_time_scale_interpolator = (const vostok::animation::base_interpolator *)v22;
  v16 = *(const void **)(a2 + 28);
  v15->m_bones_mask = bones_mask;
  v15->m_animated_object = v16;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v15);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v17, (int)&v20);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v21.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v21.first);
  return result;
}
