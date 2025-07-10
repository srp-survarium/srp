void __usercall survarium::human_npc::draw_damage_model(survarium::human_npc *this@<ecx>, int a2@<edi>)
{
  int v2; // ecx
  int v3; // esi
  int v4; // ebx

  v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 348) + 276) + 4) - **(_DWORD **)(*(_DWORD *)(a2 + 348) + 276);
  if ( v2 / 112 )
  {
    v3 = 0;
    v4 = v2 / 112;
    do
    {
      survarium::damage_model::get_body_part(
        *(survarium::damage_model **)(*(_DWORD *)(a2 + 348) + 272),
        *(const char **)(**(_DWORD **)(*(_DWORD *)(a2 + 348) + 276) + v3 + 76));
      v3 += 112;
      --v4;
    }
    while ( v4 );
  }
}
