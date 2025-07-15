void __thiscall survarium::artefact_container_core::transfer_artefact(
        survarium::artefact_container_core *this,
        survarium::inventory_holder *holder)
{
  survarium::artefact_base *object; // [esp+1Ch] [ebp-8h]
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp+20h] [ebp-4h] BYREF

  object = this->m_artefact.m_object;
  v4.m_object = 0;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    object);
  holder->take_inventory_item(
    holder,
    (const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *)&v4);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v4);
  vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_artefact,
    0);
}
