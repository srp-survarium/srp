bool __usercall survarium::player::use_third_person_animations_resolver@<al>(
        survarium::player *this@<ecx>,
        int a2@<eax>)
{
  bool result; // al
  int v3; // eax

  result = 0;
  if ( *(_BYTE *)(a2 + 764) )
  {
    if ( !*((_BYTE *)&loc_1143B + a2) )
    {
      v3 = *(_DWORD *)((char *)&loc_11403 + a2 + 5);
      if ( !v3 || !s_first_person_animations_only && *(_DWORD *)(v3 + 864) )
        return 1;
    }
  }
  return result;
}
