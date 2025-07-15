int __cdecl trans_cb(int a, int b, bn_gencb_st *gcb)
{
  _DWORD **arg; // eax

  arg = (_DWORD **)gcb->arg;
  *arg[8] = a;
  arg[8][1] = b;
  return ((int (__cdecl *)(_DWORD **))arg[7])(arg);
}
