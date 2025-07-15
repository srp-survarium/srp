vostok::animation::mixing::animation_lexeme *__userpurge survarium::pistol_weapon_core_reload_state::get_weapon_lexeme@<eax>(
        survarium::pistol_weapon_core_reload_state *this@<ecx>,
        float a2@<xmm0>,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::mutable_buffer *a5)
{
  void (__thiscall *m_pFunction)(fastdelegate::detail::GenericClass *); // esi
  int v6; // eax
  int v7; // ecx
  float v8; // xmm0_4
  BOOL v9; // ecx
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v10; // edi
  vostok::resources::managed_resource *v11; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v12; // eax
  vostok::animation::mixing::animation_lexeme *v13; // ecx
  int v14; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v15; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v17; // [esp-8h] [ebp-78h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp-4h] [ebp-74h] BYREF
  vostok::animation::mixing::animation_lexeme *v19; // [esp+0h] [ebp-70h]
  float v20; // [esp+4h] [ebp-6Ch]
  vostok::animation::mixing::animation_lexeme *v21; // [esp+8h] [ebp-68h]
  vostok::animation::mixing::animation_lexeme_parameters v22; // [esp+14h] [ebp-5Ch] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v23; // [esp+68h] [ebp-8h] BYREF

  m_pFunction = result[2].m_time_calculator.m_Closure.m_pFunction;
  v6 = *((_DWORD *)m_pFunction + 2);
  v20 = *(float *)&this;
  v19 = (vostok::animation::mixing::animation_lexeme *)this;
  v7 = *(_DWORD *)((char *)&loc_11066 + v6 + 2);
  v20 = 1.0;
  v8 = survarium::player_params_modifiers_container::apply_modifier(
         (survarium::player_params_modifiers_container *)(v7 + 448),
         reload_speed_modifier,
         a2,
         *(float *)&result[2].m_time_driving_animation,
         1.0);
  v9 = *((_WORD *)m_pFunction + 551) == 0;
  v20 = 0.0;
  v19 = 0;
  v10 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(&result[2].m_playback_type + v9);
  v18.m_object = (vostok::resources::managed_resource *)((int)((int)result
                                                             + 4 * v9
                                                             + 356
                                                             - (unsigned int)result[2].m_time_scale_interpolator) >> 2);
  LOBYTE(result[2].m_animated_object) = v18.m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v18,
    v10);
  v17.m_object = v11;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v17,
    v10);
  v12 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
          &v23,
          v17,
          v18);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v22,
    a5,
    v13,
    &v12->first,
    v19,
    (vostok::animation::mixing::animation_lexeme *const)LODWORD(v20),
    v21);
  *(_DWORD *)(v14 + 32) = result[2].m_time_calculator.m_Closure.m_pFunction;
  *(float *)(v14 + 56) = v8;
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
