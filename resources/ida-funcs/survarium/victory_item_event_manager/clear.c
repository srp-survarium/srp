void __usercall survarium::victory_item_event_manager::clear(
        survarium::victory_item_event_manager *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _DWORD *v2; // edx
  int v3; // ebx

  v2 = a2 + 30;
  v3 = 10;
  do
  {
    memset(v2 - 22, 0, 0x50u);
    *v2 = 3;
    v2 += 24;
    --v3;
  }
  while ( v3 );
  a2[254] = 0;
  a2[255] = 0;
}
