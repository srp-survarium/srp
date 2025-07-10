void __usercall survarium::inventory_item::set_amount(survarium::inventory_item *this@<ecx>, int a2@<eax>)
{
  *(_WORD *)(a2 + 276) = (_WORD)this;
}
