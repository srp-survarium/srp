void __thiscall survarium::weapon_core::activate(survarium::weapon_core *this, BOOL real_insert)
{
  survarium::base_player *m_user; // ebx
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v4; // eax
  survarium::base_player *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  survarium::weapon_core_vtbl *v7; // esi
  vostok::math::float4x4 *v8; // ecx
  vostok::math::float4x4 *v9; // eax
  const void *v11; // [esp+0h] [ebp-50h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp+Ch] [ebp-44h] BYREF
  vostok::math::float4x4 v13; // [esp+10h] [ebp-40h] BYREF

  v12.m_object = 0;
  m_user = this->m_user;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
    &v13);
  survarium::base_player::subscribe_animation_player(
    v5,
    (int)m_user,
    "shell_extraction",
    v4,
    (void *)this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v12,
    0,
    v11);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&v13);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
  this->m_recoil_calculator.m_weapon = this;
  this->m_recoil_calculator.m_weapon_calculator.m_weapon = this;
  this->m_portable_interactive_object->activate(this->m_portable_interactive_object, &this->m_skeleton);
  v7 = this->survarium::interactive_object::__vftable;
  v9 = vostok::math::float4x4::identity(v8, &v13);
  v7->set_transform(this, v9);
  this->on_show(this, real_insert);
  survarium::base_player::subscribe_on_player_death(
    (survarium::base_player *)&this->m_player_death_subscriber,
    (int)this->m_user);
}
