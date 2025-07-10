void __usercall Wm4::ConvexHull2<float>::GetConvexHull1(
        Wm4::ConvexHull2<float> *this@<ecx>,
        const Wm4::Vector2<float> *a2@<ebp>,
        bool a3@<dil>,
        int a4@<esi>)
{
  int v4; // edi
  float *v5; // ebx
  Wm4::ConvexHull1<float> *v6; // edi
  const Wm4::Vector2<float> *fEpsilon; // [esp+0h] [ebp-14h]
  Wm4::Vector2<float> kDiff; // [esp+Ch] [ebp-8h] BYREF

  if ( *(_DWORD *)(a4 + 12) == 1 )
  {
    v4 = 0;
    v5 = (float *)operator new[](4 * *(_DWORD *)(a4 + 8));
    if ( *(int *)(a4 + 8) > 0 )
    {
      fEpsilon = a2;
      do
      {
        Wm4::Vector2<float>::operator-(
          (Wm4::Vector2<float> *)(a4 + 44),
          &kDiff,
          (Wm4::Vector2<float> *)(*(_DWORD *)(a4 + 32) + 8 * v4++),
          fEpsilon);
        v5[v4 - 1] = *(float *)(a4 + 56) * kDiff.m_afTuple[1] + *(float *)(a4 + 52) * kDiff.m_afTuple[0];
      }
      while ( v4 < *(_DWORD *)(a4 + 8) );
    }
    v6 = (Wm4::ConvexHull1<float> *)operator new(0x24u);
    if ( v6 )
      Wm4::ConvexHull1<float>::ConvexHull1<float>(
        v6,
        *(_DWORD *)(a4 + 8),
        v5,
        *(float *)(a4 + 24),
        a3,
        *(Wm4::Query::Type *)(a4 + 4));
  }
}
