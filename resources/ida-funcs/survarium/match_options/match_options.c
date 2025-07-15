void __usercall survarium::match_options::match_options(survarium::match_options *this@<ecx>, int a2@<esi>)
{
  survarium::player_profile *v2; // edi
  int i; // ebx
  _WORD *v4; // edi
  int j; // ecx

  v2 = (survarium::player_profile *)a2;
  for ( i = 19; i >= 0; --i )
    survarium::player_profile::player_profile(v2++);
  *(_DWORD *)(a2 + 29760) = -1;
  *(_WORD *)(a2 + 29774) = 0;
  *(_DWORD *)(a2 + 29768) = 255;
  *(_BYTE *)(a2 + 29772) = -1;
  *(_BYTE *)(a2 + 29773) = 0;
  *(_DWORD *)(a2 + 29776) = 0;
  *(_BYTE *)(a2 + 29780) = 0;
  *(_BYTE *)(a2 + 29781) = 0;
  *(_BYTE *)(a2 + 29782) = 0;
  *(_BYTE *)(a2 + 29783) = 0;
  *(_BYTE *)(a2 + 29788) = 0;
  memset((void *)(a2 + 29820), 0, 0x28u);
  v4 = (_WORD *)(a2 + 29860);
  for ( j = 1; j; --j )
    *v4++ = 0;
}
