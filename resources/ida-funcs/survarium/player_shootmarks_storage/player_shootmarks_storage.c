void __usercall survarium::player_shootmarks_storage::player_shootmarks_storage(
        survarium::player_shootmarks_storage *this@<ecx>,
        int a2@<eax>)
{
  int v2; // edx
  int v3; // ecx

  v2 = 19;
  v3 = a2 + 12;
  do
  {
    *(_DWORD *)(v3 - 12) = v3;
    *(_DWORD *)(v3 - 8) = v3;
    *(_DWORD *)(v3 - 4) = v3 + 256;
    v3 += 268;
    --v2;
  }
  while ( v2 >= 0 );
}
