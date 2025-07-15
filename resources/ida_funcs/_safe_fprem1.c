// attributes: thunk
int __usercall _safe_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem1(a1, a2);
}
