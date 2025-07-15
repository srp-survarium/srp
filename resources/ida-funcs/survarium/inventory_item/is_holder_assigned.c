BOOL __usercall survarium::inventory_item::is_holder_assigned@<eax>(
        survarium::inventory_item *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 272);
  return v2 && *(_DWORD *)(v2 + 376);
}
