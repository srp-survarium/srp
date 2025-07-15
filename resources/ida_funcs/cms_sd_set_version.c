void __usercall cms_sd_set_version(CMS_SignedData_st *sd@<esi>)
{
  int i; // edi
  int v2; // eax
  int j; // edi
  int k; // edi
  char *v5; // eax

  for ( i = 0; i < sk_num(&sd->certificates->stack); ++i )
  {
    v2 = *(_DWORD *)sk_value(&sd->certificates->stack, i);
    if ( v2 == 4 )
    {
      if ( sd->version < 5 )
        sd->version = 5;
    }
    else if ( v2 == 3 )
    {
      if ( sd->version < 4 )
        sd->version = 4;
    }
    else if ( v2 == 2 && sd->version < 3 )
    {
      sd->version = 3;
    }
  }
  for ( j = 0; j < sk_num(&sd->crls->stack); ++j )
  {
    if ( *(_DWORD *)sk_value(&sd->crls->stack, j) == 1 && sd->version < 5 )
      sd->version = 5;
  }
  if ( OBJ_obj2nid(sd->encapContentInfo->eContentType) != 21 && sd->version < 3 )
    sd->version = 3;
  for ( k = 0; k < sk_num(&sd->signerInfos->stack); ++k )
  {
    v5 = sk_value(&sd->signerInfos->stack, k);
    if ( **((_DWORD **)v5 + 1) == 1 )
    {
      if ( *(int *)v5 < 3 )
        *(_DWORD *)v5 = 3;
      if ( sd->version < 3 )
        sd->version = 3;
    }
    else
    {
      sd->version = 1;
    }
  }
  if ( sd->version < 1 )
    sd->version = 1;
}
