vostok::animation::mixing::animation_lexeme *__userpurge survarium::weapon_core_reload_state::get_weapon_lexeme@<eax>(
        survarium::weapon_core_reload_state *this@<ecx>,
        float a2@<xmm0>,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::mutable_buffer *a5)
{
  int v6; // eax
  double v7; // st7
  float v8; // xmm0_4
  vostok::resources::managed_resource *v9; // ecx
  vostok::resources::managed_resource *v10; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v11; // eax
  vostok::animation::mixing::animation_lexeme *v12; // ecx
  float v13; // xmm0_4
  int v14; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v15; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v17; // [esp-8h] [ebp-7Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp-4h] [ebp-78h] BYREF
  float v19; // [esp+0h] [ebp-74h]
  float v20; // [esp+4h] [ebp-70h]
  vostok::animation::mixing::animation_lexeme *v21; // [esp+8h] [ebp-6Ch]
  vostok::animation::mixing::animation_lexeme_parameters v22; // [esp+14h] [ebp-60h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v23; // [esp+68h] [ebp-Ch] BYREF
  float v24; // [esp+70h] [ebp-4h]
  char v25; // [esp+7Ch] [ebp+8h]

  v6 = (char *)result - (char *)result[2].m_time_scale_interpolator + 340;
  v19 = *(float *)&this;
  v6 >>= 2;
  v20 = 1.0;
  v7 = *(float *)&result[2].m_time_driving_animation;
  LOBYTE(result[2].m_animated_object) = v6;
  v25 = v6;
  v19 = v7;
  v8 = survarium::player_params_modifiers_container::apply_modifier(
         (survarium::player_params_modifiers_container *)(*(_DWORD *)(*((_DWORD *)result[2].m_time_calculator.m_Closure.m_pFunction
                                                                      + 2)
                                                                    + 69736)
                                                        + 448),
         reload_speed_modifier,
         a2,
         v19,
         v20);
  v20 = 0.0;
  v19 = 0.0;
  v18.m_object = v9;
  v24 = v8;
  LOBYTE(result[2].m_animated_object) = v25;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v18,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result[2].m_start_animation_interval_id);
  v17.m_object = v10;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v17,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result[2].m_start_animation_interval_id);
  v11 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
          &v23,
          v17,
          v18);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v22,
    a5,
    v12,
    &v11->first,
    (vostok::animation::mixing::animation_lexeme *)LODWORD(v19),
    (vostok::animation::mixing::animation_lexeme *const)LODWORD(v20),
    v21);
  v13 = v24;
  *(_DWORD *)(v14 + 32) = result[2].m_time_calculator.m_Closure.m_pFunction;
  *(float *)(v14 + 56) = v13;
  *(_DWORD *)(v14 + 64) = 2;
  *(_DWORD *)(v14 + 60) = 1;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(
    buffer,
    (const vostok::animation::mixing::animation_lexeme_parameters *)v14);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v15, (int)&v22);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v23.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v23.first);
  return buffer;
}
