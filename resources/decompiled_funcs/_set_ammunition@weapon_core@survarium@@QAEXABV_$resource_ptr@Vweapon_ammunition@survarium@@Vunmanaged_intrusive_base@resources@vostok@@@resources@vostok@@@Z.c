void __thiscall survarium::weapon_core::set_ammunition(
        survarium::weapon_core *this,
        const vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *ammunition_to_set)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ammunition,
    ammunition_to_set);
}
