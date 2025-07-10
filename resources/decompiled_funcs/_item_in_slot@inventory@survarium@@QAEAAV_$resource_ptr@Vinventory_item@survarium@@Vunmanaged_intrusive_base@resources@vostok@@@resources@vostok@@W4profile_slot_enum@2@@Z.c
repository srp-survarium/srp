vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *__usercall survarium::inventory::item_in_slot@<eax>(
        survarium::inventory *this@<ecx>,
        int a2@<eax>)
{
  return (vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4 * (_DWORD)this + 264);
}
