int __usercall OBJ_find_sigid_algs@<eax>(int a1@<edi>, int signid, int *pdig_nid, int *ppkey_nid)
{
  int v4; // eax
  int result; // eax
  char v6[12]; // [esp+0h] [ebp-Ch] BYREF

  *(_DWORD *)v6 = signid;
  if ( sig_app && (v4 = sk_find(a1, &sig_app->stack, v6), v4 >= 0) && (result = (int)sk_value(&sig_app->stack, v4)) != 0
    || (result = (int)OBJ_bsearch_(
                        v6,
                        (char *)sigoid_srt,
                        29,
                        12,
                        (int (__cdecl *)(const void *, const void *))nid_cmp_BSEARCH_CMP_FN)) != 0 )
  {
    *pdig_nid = *(_DWORD *)(result + 4);
    *ppkey_nid = *(_DWORD *)(result + 8);
    return 1;
  }
  return result;
}
