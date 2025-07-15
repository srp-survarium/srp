vostok::animation::mixing::animation_lexeme *__thiscall survarium::double_barreled_weapon_core_idle_state::get_weapon_lexeme(
        survarium::double_barreled_weapon_core_idle_state *this,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer)
{
  int m_ammo_in_magazine; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // edi
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

  m_ammo_in_magazine = this->m_weapon->m_ammo_in_magazine;
  v15 = 0;
  v14 = 0;
  v13.m_object = (vostok::resources::managed_resource *)this;
  v5 = &this->m_weapon_animations[m_ammo_in_magazine];
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v13,
    v5);
  v12.m_object = v6;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    v5);
  v7 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
         &v18,
         v12,
         v13);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v17,
    buffer,
    v8,
    &v7->first,
    v14,
    v15,
    v16);
  v9->m_animated_object = this->m_weapon;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, v9);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v10, (int)&v17);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v18.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v18.first);
  return result;
}
