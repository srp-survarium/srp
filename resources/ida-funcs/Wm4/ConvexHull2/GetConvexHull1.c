Wm4::ConvexHull1<float> *__usercall Wm4::ConvexHull2<float>::GetConvexHull1@<eax>(
        Wm4::ConvexHull2<float> *this@<ecx>,
        int a2@<esi>)
{
  float *v2; // edi
  int i; // eax
  Wm4::ConvexHull1<float> *v4; // eax

  if ( *(_DWORD *)(a2 + 12) != 1 )
    return 0;
  v2 = (float *)operator new[](4 * *(_DWORD *)(a2 + 8));
  for ( i = 0; i < *(_DWORD *)(a2 + 8); ++i )
    v2[i] = (float)(*(float *)(a2 + 56) * (float)(*(float *)(*(_DWORD *)(a2 + 32) + 8 * i + 4) - *(float *)(a2 + 48)))
          + (float)(*(float *)(a2 + 52) * (float)(*(float *)(*(_DWORD *)(a2 + 32) + 8 * i) - *(float *)(a2 + 44)));
  v4 = (Wm4::ConvexHull1<float> *)operator new(0x24u);
  if ( v4 )
    return Wm4::ConvexHull1<float>::ConvexHull1<float>(
             *(_DWORD *)(a2 + 4),
             *(_DWORD *)(a2 + 24),
             v4,
             *(_DWORD *)(a2 + 8),
             v2);
  else
    return 0;
}
