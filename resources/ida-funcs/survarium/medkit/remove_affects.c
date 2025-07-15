void __userpurge survarium::medkit::remove_affects(
        survarium::medkit *this@<ecx>,
        int a2@<edi>,
        unsigned int current_time_ms)
{
  unsigned int v3; // ebx
  int v4; // esi
  int *v5; // eax
  survarium::damage_model *v6; // ecx
  int v7; // [esp+4h] [ebp-4h]

  v3 = 0;
  if ( *(_BYTE *)(a2 + 316) )
  {
    v7 = 0;
    do
    {
      v4 = v7 + *(_DWORD *)(a2 + 312);
      v5 = (int *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 272) + 376) + 8))(*(_DWORD *)(*(_DWORD *)(a2 + 272) + 376));
      survarium::damage_model::cancel_affect(
        v6,
        *v5,
        current_time_ms,
        (char *)v4,
        *(const survarium::hit_affects_type_enum *)(v4 + 16));
      v7 += 20;
      ++v3;
    }
    while ( v3 < *(unsigned __int8 *)(a2 + 316) );
  }
}
