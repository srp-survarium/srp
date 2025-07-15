survarium::inventory *__usercall survarium::inventory_item::get_inventory@<eax>(
        survarium::inventory_item *this@<ecx>,
        int a2@<eax>)
{
  return *(survarium::inventory **)(a2 + 268);
}
