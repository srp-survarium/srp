vostok::animation::mixing::animation_lexeme *__thiscall survarium::weapon_core_shotgun_reload_base_substate::get_weapon_lexeme(
        survarium::weapon_core_shotgun_reload_base_substate *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::mutable_buffer *time_scale,
        int a5)
{
  vostok::resources::managed_resource *v5; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v6; // eax
  vostok::animation::mixing::animation_lexeme *v7; // ecx
  int v8; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v9; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v11; // [esp-10h] [ebp-78h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp-Ch] [ebp-74h] BYREF
  vostok::animation::mixing::animation_lexeme *v13; // [esp-8h] [ebp-70h]
  vostok::animation::mixing::animation_lexeme *v14; // [esp-4h] [ebp-6Ch]
  vostok::animation::mixing::animation_lexeme *v15; // [esp+0h] [ebp-68h]
  vostok::animation::mixing::animation_lexeme_parameters v16; // [esp+Ch] [ebp-5Ch] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v17; // [esp+60h] [ebp-8h] BYREF

  v14 = 0;
  v13 = 0;
  v12.m_object = (vostok::resources::managed_resource *)this;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result[2].m_animated_object);
  v11.m_object = v5;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v11,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&result[2].m_animated_object);
  v6 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
         &v17,
         v11,
         v12);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v16,
    time_scale,
    v7,
    &v6->first,
    v13,
    v14,
    v15);
  *(_DWORD *)(v8 + 32) = result[2].m_time_calculator.m_Closure.m_pFunction;
  *(_DWORD *)(v8 + 64) = result[2].m_n_ary_animation;
  *(_DWORD *)(v8 + 56) = a5;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(
    buffer,
    (const vostok::animation::mixing::animation_lexeme_parameters *)v8);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v9, (int)&v16);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.first);
  return buffer;
}
