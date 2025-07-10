BOOL __usercall survarium::dictionary_item::is_ammo@<eax>(survarium::dictionary_item *this@<ecx>, int a2@<eax>)
{
  char v2; // al

  v2 = *(_BYTE *)(a2 + 280);
  return v2 == 9 || v2 == 18 || v2 == 19 || v2 == 20 || v2 == 21;
}
