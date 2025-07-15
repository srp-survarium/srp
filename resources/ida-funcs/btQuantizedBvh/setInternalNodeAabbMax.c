void __userpurge btQuantizedBvh::setInternalNodeAabbMax(
        btQuantizedBvh *this@<ecx>,
        int a2@<eax>,
        int nodeIndex,
        const btVector3 *aabbMax)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  _WORD *v7; // ecx
  int v8; // eax
  int v9; // ecx

  if ( *(_BYTE *)(a2 + 72) )
  {
    v4 = *(float *)(a2 + 52) * (float)(*(float *)(nodeIndex + 4) - *(float *)(a2 + 20));
    v5 = *(float *)(a2 + 56) * (float)(*(float *)(nodeIndex + 8) - *(float *)(a2 + 24));
    v6 = s_bm_current_air_resistance;
    v7 = (_WORD *)(*(_DWORD *)(a2 + 148) + 16 * (_DWORD)this + 6);
    *v7 = (int)(float)((float)(*(float *)(a2 + 48) * (float)(*(float *)nodeIndex - *(float *)(a2 + 16)))
                     + s_bm_current_air_resistance)
        | 1;
    v7[1] = (int)(float)(v4 + v6) | 1;
    v7[2] = (int)(float)(v5 + v6) | 1;
  }
  else
  {
    v8 = *(_DWORD *)(a2 + 108);
    v9 = (_DWORD)this << 6;
    *(_DWORD *)(v8 + v9 + 16) = *(_DWORD *)nodeIndex;
    *(_DWORD *)(v8 + v9 + 20) = *(_DWORD *)(nodeIndex + 4);
    *(_DWORD *)(v8 + v9 + 24) = *(_DWORD *)(nodeIndex + 8);
    *(_DWORD *)(v8 + v9 + 28) = *(_DWORD *)(nodeIndex + 12);
  }
}
