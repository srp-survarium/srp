void __usercall nc_match(GENERAL_NAME_st *gen@<ebx>, NAME_CONSTRAINTS_st *nc@<edi>)
{
  int v2; // ebp
  int v3; // esi
  char *v4; // eax
  int v5; // eax
  int i; // esi
  char *v7; // eax
  int v8; // eax

  v2 = 0;
  v3 = 0;
  if ( sk_num(&nc->permittedSubtrees->stack) <= 0 )
    goto LABEL_15;
  do
  {
    v4 = sk_value(&nc->permittedSubtrees->stack, v3);
    if ( gen->type == **(_DWORD **)v4 )
    {
      if ( *((_DWORD *)v4 + 1) || *((_DWORD *)v4 + 2) )
        return;
      if ( v2 != 2 )
      {
        if ( !v2 )
          v2 = 1;
        nc_match_single(gen, (unsigned int)gen, *(GENERAL_NAME_st **)v4);
        if ( v5 )
        {
          if ( v5 != 47 )
            return;
        }
        else
        {
          v2 = 2;
        }
      }
    }
    ++v3;
  }
  while ( v3 < sk_num(&nc->permittedSubtrees->stack) );
  if ( v2 != 1 )
  {
LABEL_15:
    for ( i = 0; i < sk_num(&nc->excludedSubtrees->stack); ++i )
    {
      v7 = sk_value(&nc->excludedSubtrees->stack, i);
      if ( gen->type == **(_DWORD **)v7 )
      {
        if ( *((_DWORD *)v7 + 1) )
          break;
        if ( *((_DWORD *)v7 + 2) )
          break;
        nc_match_single(gen, (unsigned int)gen, *(GENERAL_NAME_st **)v7);
        if ( v8 != 47 )
          break;
      }
    }
  }
}
