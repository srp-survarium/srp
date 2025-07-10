void __usercall stlp_std::sort_heap<float *,stlp_std::less<float>>(
        float *__first@<esi>,
        float *__last@<eax>,
        stlp_std::less<float> __comp)
{
  int v3; // eax
  double v4; // st7
  int v5; // edi
  float __val; // [esp+0h] [ebp-10h]

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(float *)((char *)__first + v3 - 4);
      *(float *)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      __val = v4;
      stlp_std::__adjust_heap<float *,int,float,stlp_std::less<float>>(__first, 0, (v3 - 4) >> 2, __val, __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}
