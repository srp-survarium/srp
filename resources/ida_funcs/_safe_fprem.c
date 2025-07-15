// attributes: thunk
int __usercall _safe_fprem@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem(a1, a2);
}
