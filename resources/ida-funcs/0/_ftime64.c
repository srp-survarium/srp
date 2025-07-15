void __usercall _ftime64(int a1@<ebx>, __timeb64 *tp)
{
  _ftime64_s(a1, tp);
}
