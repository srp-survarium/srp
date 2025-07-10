void __thiscall survarium::weapon_core::set_skeleton(
        survarium::weapon_core *this,
        const vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *skeleton)
{
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
    skeleton,
    &this->m_skeleton.m_object);
}
