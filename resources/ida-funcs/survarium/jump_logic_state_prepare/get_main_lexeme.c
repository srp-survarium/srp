vostok::animation::mixing::animation_lexeme *__userpurge survarium::jump_logic_state_prepare::get_main_lexeme@<eax>(
        survarium::jump_logic_state_prepare *this@<ecx>,
        int a2@<edi>,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        unsigned int bones_mask)
{
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *move_animation; // eax
  vostok::animation::mixing::animation_lexeme *v6; // ecx
  const vostok::animation::mixing::animation_lexeme_parameters *v7; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v8; // ecx
  vostok::animation::mixing::animation_lexeme *v10; // [esp+0h] [ebp-74h]
  vostok::animation::mixing::animation_lexeme_parameters v11; // [esp+Ch] [ebp-68h] BYREF
  _DWORD v12[2]; // [esp+60h] [ebp-14h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v13; // [esp+68h] [ebp-Ch] BYREF

  move_animation = survarium::jump_logic::get_move_animation((survarium::jump_logic *)this, *(_DWORD *)(a2 + 24), &v13);
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::operator=(
    (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)(a2 + 32),
    move_animation);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v13.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v13.first);
  v12[0] = &vostok::animation::linear_interpolator::`vftable';
  v13.first.m_object = (vostok::resources::managed_resource *)&vostok::animation::linear_interpolator::`vftable';
  *(float *)&v12[1] = g_jump_prepare_interval_length;
  *(float *)&v13.second.m_object = g_jump_prepare_interval_length;
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v11,
    buffer,
    v6,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 32),
    0,
    0,
    v10);
  v7->m_weight_synchronization_group_id = 0;
  v7->m_time_synchronization_group_id = 0;
  v7->m_weight_interpolator = (const vostok::animation::base_interpolator *)&v13;
  v7->m_time_scale_interpolator = (const vostok::animation::base_interpolator *)v12;
  v7->m_time_scale = *(float *)(a2 + 44);
  v7->m_animated_object = *(const void **)(a2 + 28);
  v7->m_bones_mask = bones_mask;
  v7->m_user_data = 1;
  v7->m_unique_animation_id = 0;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v7);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v8, (int)&v11);
  return result;
}
