void __thiscall survarium::weapon_user_animations_selector::set_animations(
        survarium::weapon_user_animations_selector *this,
        const vostok::resources::resource_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base> *value)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_animations,
    value);
}
