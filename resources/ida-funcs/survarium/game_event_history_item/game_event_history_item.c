void __usercall survarium::game_event_history_item::game_event_history_item(
        survarium::game_event_history_item *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // edx
  _DWORD *v3; // ecx
  _DWORD *v4; // edi
  _DWORD *v5; // ecx
  int v6; // edx
  _DWORD *v7; // edi

  v2 = 20;
  v3 = a2;
  do
  {
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v4 = v3 + 3;
    v3 += 4;
    --v2;
    *v4 = 0;
  }
  while ( v2 >= 0 );
  v5 = a2;
  v6 = 21;
  do
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v7 = v5 + 3;
    v5 += 4;
    --v6;
    *v7 = 0;
  }
  while ( v6 );
  a2[84] = 0;
  a2[85] = 0;
  a2[86] = 0;
}
