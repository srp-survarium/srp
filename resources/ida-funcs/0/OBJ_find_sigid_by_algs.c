int __usercall OBJ_find_sigid_by_algs@<eax>(int a1@<edi>, int *psignid, int dig_nid, int pkey_nid)
{
  int v4; // eax
  int result; // eax
  char *v6; // [esp+0h] [ebp-10h] BYREF
  char v7[4]; // [esp+4h] [ebp-Ch] BYREF
  int v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v6 = v7;
  v8 = dig_nid;
  v9 = pkey_nid;
  if ( sigx_app )
  {
    v4 = sk_find(a1, &sigx_app->stack, v7);
    if ( v4 >= 0 )
    {
      v6 = sk_value(&sigx_app->stack, v4);
      result = (int)&v6;
LABEL_4:
      *psignid = **(_DWORD **)result;
      return 1;
    }
  }
  result = (int)OBJ_bsearch_(&v6, (char *)sigoid_srt_xref, 29, 4, sigx_cmp_BSEARCH_CMP_FN);
  if ( result )
    goto LABEL_4;
  return result;
}
