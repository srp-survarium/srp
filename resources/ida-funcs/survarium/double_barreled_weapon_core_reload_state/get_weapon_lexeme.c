vostok::animation::mixing::animation_lexeme *__userpurge survarium::double_barreled_weapon_core_reload_state::get_weapon_lexeme@<eax>(
        survarium::double_barreled_weapon_core_reload_state *this@<ecx>,
        float a2@<xmm0>,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::mutable_buffer *a5)
{
  survarium::weapon_core *m_pFunction; // esi
  survarium::base_player *m_user; // eax
  int v8; // ecx
  float v9; // xmm0_4
  unsigned __int16 m_ammo_in_magazine; // ax
  BOOL v11; // esi
  unsigned int v12; // ecx
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v13; // edi
  vostok::resources::managed_resource *v14; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v15; // eax
  vostok::animation::mixing::animation_lexeme *v16; // ecx
  float v17; // xmm0_4
  const vostok::animation::mixing::animation_lexeme_parameters *v18; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v19; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v21; // [esp-8h] [ebp-7Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v22; // [esp-4h] [ebp-78h] BYREF
  vostok::animation::mixing::animation_lexeme *v23; // [esp+0h] [ebp-74h]
  float v24; // [esp+4h] [ebp-70h]
  vostok::animation::mixing::animation_lexeme *v25; // [esp+8h] [ebp-6Ch]
  vostok::animation::mixing::animation_lexeme_parameters v26; // [esp+14h] [ebp-60h] BYREF
  float v27; // [esp+68h] [ebp-Ch]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v28; // [esp+6Ch] [ebp-8h] BYREF
  char v29; // [esp+7Ch] [ebp+8h]

  v29 = 0;
  m_pFunction = (survarium::weapon_core *)result[2].m_time_calculator.m_Closure.m_pFunction;
  m_user = m_pFunction->m_user;
  v24 = *(float *)&this;
  v23 = (vostok::animation::mixing::animation_lexeme *)this;
  v8 = *(int *)((char *)&m_user->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
              + (_DWORD)&loc_11066
              + 2);
  v24 = 1.0;
  v9 = survarium::player_params_modifiers_container::apply_modifier(
         (survarium::player_params_modifiers_container *)(v8 + 448),
         reload_speed_modifier,
         a2,
         *(float *)&result[2].m_time_driving_animation,
         1.0);
  m_ammo_in_magazine = m_pFunction->m_ammo_in_magazine;
  v27 = v9;
  v11 = 0;
  if ( m_ammo_in_magazine != 1 )
  {
    v29 = 1;
    if ( LOWORD(survarium::weapon_core::ammunition(
                  m_pFunction,
                  (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28.second)->m_object->m_lods[0].m_emitter_instance_list.m_last) != 1 )
      v11 = 1;
  }
  if ( (v29 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28.second);
  v12 = 4 * v11 + 356 - (unsigned int)result[2].m_time_scale_interpolator;
  v24 = 0.0;
  v23 = 0;
  v22.m_object = (vostok::resources::managed_resource *)((int)((int)result + v12) >> 2);
  v13 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(&result[2].m_playback_type + v11);
  LOBYTE(result[2].m_animated_object) = v22.m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v22,
    v13);
  v21.m_object = v14;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v21,
    v13);
  v15 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
          &v28,
          v21,
          v22);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v26,
    a5,
    v16,
    &v15->first,
    v23,
    (vostok::animation::mixing::animation_lexeme *const)LODWORD(v24),
    v25);
  v17 = v27;
  v18->m_animated_object = result[2].m_time_calculator.m_Closure.m_pFunction;
  v18->m_time_synchronization_group_id = 2;
  v18->m_time_scale = v17;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(buffer, v18);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v19, (int)&v26);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v28.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v28.first);
  return buffer;
}
