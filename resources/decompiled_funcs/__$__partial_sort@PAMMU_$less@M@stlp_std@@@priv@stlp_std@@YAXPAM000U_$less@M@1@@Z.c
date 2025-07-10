void __usercall stlp_std::priv::__partial_sort<float *,float,stlp_std::less<float>>(
        float *__first@<eax>,
        float *__middle,
        float *__last,
        float *__formal)
{
  float *i; // ebx
  float *v7; // [esp+8h] [ebp-10h]
  int *v8; // [esp+Ch] [ebp-Ch]
  float *__middlea; // [esp+1Ch] [ebp+4h]

  stlp_std::__make_heap<float *,stlp_std::less<float>,float,int>(
    __first,
    __middle,
    (stlp_std::less<float>)__formal,
    v7,
    v8);
  for ( i = __middle; i < __last; ++i )
  {
    __middlea = *(float **)i;
    if ( *__first > *i )
    {
      *i = *__first;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(
        __first,
        0,
        __middle - __first,
        *(float *)&__middlea,
        (stlp_std::less<float>)__formal);
    }
  }
  stlp_std::sort_heap<float *,stlp_std::less<float>>(__first, __middle, (stlp_std::less<float>)__formal);
}
