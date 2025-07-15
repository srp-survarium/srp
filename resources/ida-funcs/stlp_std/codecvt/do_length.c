unsigned int __thiscall stlp_std::codecvt<wchar_t,char,int>::do_length(
        stlp_std::codecvt<wchar_t,char,int> *this,
        int *__formal,
        int from,
        const char *end,
        unsigned int mx)
{
  bool v5; // cf
  unsigned int *p_mx; // eax

  v5 = mx < (unsigned int)&end[-from];
  end -= from;
  p_mx = &mx;
  if ( !v5 )
    p_mx = (unsigned int *)&end;
  return *p_mx;
}
