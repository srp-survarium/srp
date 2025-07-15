void __usercall survarium::medkit::medkit(survarium::medkit *this@<ecx>, int a2@<eax>)
{
  survarium::inventory_item::inventory_item(&this->survarium::inventory_item, a2, use_silent, 1);
  *(_DWORD *)(a2 + 288) = &survarium::tickable_object::`vftable';
  *(_DWORD *)(a2 + 288) = &survarium::medkit::`vftable'{for `survarium::tickable_object'};
  *(_DWORD *)a2 = &survarium::medkit::`vftable'{for `survarium::inventory_item'};
  *(_DWORD *)(a2 + 300) = 0;
  *(_BYTE *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = 0;
  *(_BYTE *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_BYTE *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 1;
  *(_DWORD *)(a2 + 332) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_BYTE *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 352) = 0;
}
