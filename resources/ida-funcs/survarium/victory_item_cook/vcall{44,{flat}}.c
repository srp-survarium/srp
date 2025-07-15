void __thiscall  __thiscall survarium::victory_item_cook::`vcall'{44,{flat}}(
        survarium::weapon_cook *this,
        vostok::resources::queries_result *a2,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> a3,
        survarium::weapon_core *a4)
{
  ((void (__thiscall *)(survarium::weapon_cook *, vostok::resources::queries_result *, vostok::configs::binary_config *, survarium::weapon_core *))this->cooked_object_size)(
    this,
    a2,
    a3.m_object,
    a4);
}
