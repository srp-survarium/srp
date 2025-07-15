vostok::animation::mixing::animation_lexeme *__thiscall survarium::pistol_weapon_core_fire_state::get_weapon_lexeme(
        survarium::pistol_weapon_core_fire_state *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::mutable_buffer *a4)
{
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // edi
  int v5; // eax
  vostok::resources::managed_resource *v6; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v7; // eax
  vostok::animation::mixing::animation_lexeme *v8; // ecx
  const vostok::animation::mixing::animation_lexeme_parameters *v9; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v10; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp-10h] [ebp-78h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v13; // [esp-Ch] [ebp-74h] BYREF
  vostok::animation::mixing::animation_lexeme *v14; // [esp-8h] [ebp-70h]
  vostok::animation::mixing::animation_lexeme *v15; // [esp-4h] [ebp-6Ch]
  vostok::animation::mixing::animation_lexeme *v16; // [esp+0h] [ebp-68h]
  vostok::animation::mixing::animation_lexeme_parameters v17; // [esp+Ch] [ebp-5Ch] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v18; // [esp+60h] [ebp-8h] BYREF

  v4 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(&result[2].m_playback_type + LOBYTE(result[2].m_weight_synchronization_group_id));
  v15 = 0;
  v5 = (char *)v4 - (char *)result[2].m_time_scale_interpolator;
  v14 = 0;
  v13.m_object = (vostok::resources::managed_resource *)this;
  LOBYTE(result[2].m_animated_object) = v5 >> 2;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v13,
    v4);
  v12.m_object = v6;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    v4);
  v7 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
         &v18,
         v12,
         v13);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v17,
    a4,
    v8,
    &v7->first,
    v14,
    v15,
    v16);
  v9->m_animated_object = result[2].m_time_calculator.m_Closure.m_pFunction;
  v9->m_time_synchronization_group_id = 1;
  v9->m_time_scale = *(float *)&result[2].m_weight_driving_animation;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(buffer, v9);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v10, (int)&v17);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v18.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v18.first);
  return buffer;
}
