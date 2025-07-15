void __userpurge btQuantizedBvh::setInternalNodeAabbMin(
        btQuantizedBvh *this@<ecx>,
        int a2@<eax>,
        int nodeIndex,
        const btVector3 *aabbMin)
{
  float v4; // xmm2_4
  _WORD *v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  _DWORD *v8; // edi

  if ( *(_BYTE *)(a2 + 72) )
  {
    v4 = *(float *)(nodeIndex + 8) - *(float *)(a2 + 24);
    v5 = (_WORD *)(*(_DWORD *)(a2 + 148) + 16 * (_DWORD)this);
    v6 = *(float *)(a2 + 52) * (float)(*(float *)(nodeIndex + 4) - *(float *)(a2 + 20));
    v7 = *(float *)(a2 + 56);
    *v5 = (int)(float)(*(float *)(a2 + 48) * (float)(*(float *)nodeIndex - *(float *)(a2 + 16))) & 0xFFFE;
    v5[1] = (int)v6 & 0xFFFE;
    v5[2] = (int)(float)(v7 * v4) & 0xFFFE;
  }
  else
  {
    v8 = (_DWORD *)(((_DWORD)this << 6) + *(_DWORD *)(a2 + 108));
    *v8++ = *(_DWORD *)nodeIndex;
    *v8++ = *(_DWORD *)(nodeIndex + 4);
    *v8 = *(_DWORD *)(nodeIndex + 8);
    v8[1] = *(_DWORD *)(nodeIndex + 12);
  }
}
