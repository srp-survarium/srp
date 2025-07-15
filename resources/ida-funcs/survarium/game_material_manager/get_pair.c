const survarium::material_pair *__userpurge survarium::game_material_manager::get_pair@<eax>(
        survarium::game_material_manager *this@<ecx>,
        int a2@<eax>,
        unsigned __int16 first_mtrl_id,
        unsigned __int16 second_mtrl_id)
{
  int v4; // ecx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // si
  int v7; // ecx
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // dx
  int v10; // ecx

  v4 = *(_DWORD *)(a2 + 4 * first_mtrl_id + 264);
  if ( v4 )
  {
    v5 = *(_WORD *)(v4 + 102);
    if ( v5 == 0xFFFF )
      v5 = first_mtrl_id;
    v6 = v5;
  }
  else
  {
    v6 = *(_WORD *)((char *)&off_1030C + a2);
  }
  v7 = *(_DWORD *)(a2 + 4 * second_mtrl_id + 264);
  if ( v7 )
  {
    v8 = *(_WORD *)(v7 + 102);
    if ( v8 == 0xFFFF )
      v8 = second_mtrl_id;
    v9 = v8;
  }
  else
  {
    v9 = *(_WORD *)((char *)&off_1030C + a2);
  }
  if ( (v6 << 9) + a2 == -776 )
    v6 = *(_WORD *)((char *)&off_1030C + a2);
  v10 = v6 << 7;
  if ( !*(_DWORD *)(a2 + 4 * (v10 + v9) + 776) )
    v9 = *(_WORD *)((char *)&off_1030C + a2);
  return *(const survarium::material_pair **)(a2 + 4 * (v10 + v9) + 776);
}
