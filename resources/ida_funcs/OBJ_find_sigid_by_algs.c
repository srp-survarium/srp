int __cdecl OBJ_find_sigid_by_algs(int *psignid, int dig_nid, int pkey_nid)
{
  int v3; // eax
  int result; // eax
  char *key; // [esp+0h] [ebp-10h] BYREF
  char data[4]; // [esp+4h] [ebp-Ch] BYREF
  int v7; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]

  key = data;
  v7 = dig_nid;
  v8 = pkey_nid;
  if ( sigx_app )
  {
    v3 = sk_find(&sigx_app->stack, data);
    if ( v3 >= 0 )
    {
      key = sk_value(&sigx_app->stack, v3);
      result = (int)&key;
LABEL_4:
      *psignid = **(_DWORD **)result;
      return 1;
    }
  }
  result = (int)OBJ_bsearch_(&key, (char *)sigoid_srt_xref, 29, 4, sigx_cmp_BSEARCH_CMP_FN);
  if ( result )
    goto LABEL_4;
  return result;
}
