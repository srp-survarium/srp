int __cdecl OBJ_find_sigid_algs(int signid, int *pdig_nid, int *ppkey_nid)
{
  int v3; // eax
  int result; // eax
  char data[12]; // [esp+0h] [ebp-Ch] BYREF

  *(_DWORD *)data = signid;
  if ( sig_app && (v3 = sk_find(&sig_app->stack, data), v3 >= 0) && (result = (int)sk_value(&sig_app->stack, v3)) != 0
    || (result = (int)OBJ_bsearch_(data, (char *)sigoid_srt, 29, 12, nid_cmp_BSEARCH_CMP_FN)) != 0 )
  {
    *pdig_nid = *(_DWORD *)(result + 4);
    *ppkey_nid = *(_DWORD *)(result + 8);
    return 1;
  }
  return result;
}
