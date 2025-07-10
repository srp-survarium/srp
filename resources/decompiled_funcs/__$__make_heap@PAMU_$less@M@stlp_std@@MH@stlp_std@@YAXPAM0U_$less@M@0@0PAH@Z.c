void __usercall stlp_std::__make_heap<float *,stlp_std::less<float>,float,int>(
        float *__first@<edi>,
        float *__last,
        stlp_std::less<float> __comp)
{
  int v3; // ebx
  int v4; // esi
  double v5; // st7
  float v6; // [esp+0h] [ebp-14h]

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, v4, __last - __first, __first[v4], __comp);
    while ( v4 )
    {
      v5 = __first[--v4];
      v6 = v5;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, v4, v3, v6, __comp);
    }
  }
}
