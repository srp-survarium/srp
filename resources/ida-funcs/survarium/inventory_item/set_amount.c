void __fastcall survarium::inventory_item::set_amount(survarium::inventory_item *this, int a2)
{
  _WORD *v2; // eax
  int v3; // edx

  v2 = (_WORD *)(a2 + 280);
  if ( *(_WORD *)(a2 + 280) != (_WORD)this )
  {
    v3 = *(_DWORD *)(a2 + 272);
    *v2 = (_WORD)this;
    if ( v3 )
      *(_BYTE *)(v3 + 396) = 1;
  }
}
