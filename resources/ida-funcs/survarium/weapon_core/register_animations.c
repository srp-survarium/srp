void __thiscall survarium::weapon_core::register_animations(
        survarium::weapon_core *this,
        survarium::animations_registry *animations_registry)
{
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *m_begin; // esi
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *m_end; // ebx
  survarium::recoil_animation_container *p_m_recoil_animations; // esi
  int v6; // ebx
  int v7; // edi
  int v8; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_animations_container::register_animations(
    (survarium::weapon_user_animations_container *)this,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this->m_portable_interactive_object->m_user_animations_selector.m_animations.m_object,
    animations_registry);
  m_begin = this->m_logic_states.m_begin;
  m_end = this->m_logic_states.m_end;
  while ( m_begin != m_end )
  {
    m_begin->m_object->register_animations(m_begin->m_object, animations_registry);
    ++m_begin;
  }
  p_m_recoil_animations = &this->m_recoil_animations;
  v8 = 2;
  do
  {
    v6 = 2;
    do
    {
      v7 = 3;
      do
      {
        survarium::animations_registry::register_animation(
          (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)p_m_recoil_animations,
          animations_registry,
          p_m_recoil_animations->m_animations[1][0][0]);
        p_m_recoil_animations = (survarium::recoil_animation_container *)((char *)p_m_recoil_animations + 4);
        --v7;
      }
      while ( v7 );
      --v6;
    }
    while ( v6 );
    --v8;
  }
  while ( v8 );
}
