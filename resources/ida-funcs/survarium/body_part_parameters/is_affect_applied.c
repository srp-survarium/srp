char __userpurge survarium::body_part_parameters::is_affect_applied@<al>(
        survarium::body_part_parameters *this@<ecx>,
        int a2@<eax>,
        const survarium::hit_affects_type_enum affect)
{
  int v3; // edx
  _DWORD *i; // ecx

  v3 = 0;
  if ( !((*(_DWORD *)(a2 + 40) - *(_DWORD *)(a2 + 36)) >> 3) )
    return 0;
  for ( i = *(_DWORD **)(a2 + 36); *i != affect; i += 2 )
  {
    if ( ++v3 >= (unsigned int)((*(_DWORD *)(a2 + 40) - *(_DWORD *)(a2 + 36)) >> 3) )
      return 0;
  }
  return 1;
}
