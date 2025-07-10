int __cdecl bn_sqr_words(unsigned __int64 a1, int a2)
{
  unsigned __int64 v2; // rax
  int v3; // ecx
  __m64 v4; // mm0
  unsigned __int64 v5; // kr00_8
  unsigned int v6; // ebx

  LODWORD(v2) = &OPENSSL_ia32cap_P;
  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x1Au) )
  {
    v2 = a1;
    v3 = a2;
    do
    {
      v4 = _mm_cvtsi32_si64(*(_DWORD *)HIDWORD(v2));
      HIDWORD(v2) += 4;
      *(__m64 *)v2 = _mm_mul_su64(v4, v4);
      --v3;
      LODWORD(v2) = v2 + 8;
    }
    while ( v3 );
    _m_empty();
  }
  else
  {
    v5 = a1;
    v6 = a2 & 0xFFFFFFF8;
    if ( (a2 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        *(_QWORD *)v5 = (unsigned int)*(_DWORD *)HIDWORD(v5) * (unsigned __int64)(unsigned int)*(_DWORD *)HIDWORD(v5);
        *(_QWORD *)(v5 + 8) = *(unsigned int *)(HIDWORD(v5) + 4) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 4);
        *(_QWORD *)(v5 + 16) = *(unsigned int *)(HIDWORD(v5) + 8) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 8);
        *(_QWORD *)(v5 + 24) = *(unsigned int *)(HIDWORD(v5) + 12)
                             * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 12);
        *(_QWORD *)(v5 + 32) = *(unsigned int *)(HIDWORD(v5) + 16)
                             * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 16);
        *(_QWORD *)(v5 + 40) = *(unsigned int *)(HIDWORD(v5) + 20)
                             * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 20);
        *(_QWORD *)(v5 + 48) = *(unsigned int *)(HIDWORD(v5) + 24)
                             * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 24);
        v2 = *(unsigned int *)(HIDWORD(v5) + 28) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 28);
        *(_QWORD *)(v5 + 56) = v2;
        v6 -= 8;
        v5 = __PAIR64__(HIDWORD(v5) + 32, (int)v5 + 64);
      }
      while ( v6 );
    }
    if ( (a2 & 7) != 0 )
    {
      v2 = (unsigned int)*(_DWORD *)HIDWORD(v5) * (unsigned __int64)(unsigned int)*(_DWORD *)HIDWORD(v5);
      *(_QWORD *)v5 = v2;
      if ( (a2 & 7) != 1 )
      {
        v2 = *(unsigned int *)(HIDWORD(v5) + 4) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 4);
        *(_QWORD *)(v5 + 8) = v2;
        if ( (a2 & 7) != 2 )
        {
          v2 = *(unsigned int *)(HIDWORD(v5) + 8) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 8);
          *(_QWORD *)(v5 + 16) = v2;
          if ( (a2 & 7) != 3 )
          {
            v2 = *(unsigned int *)(HIDWORD(v5) + 12) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 12);
            *(_QWORD *)(v5 + 24) = v2;
            if ( (a2 & 7) != 4 )
            {
              v2 = *(unsigned int *)(HIDWORD(v5) + 16) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 16);
              *(_QWORD *)(v5 + 32) = v2;
              if ( (a2 & 7) != 5 )
              {
                v2 = *(unsigned int *)(HIDWORD(v5) + 20) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 20);
                *(_QWORD *)(v5 + 40) = v2;
                if ( (a2 & 7) != 6 )
                {
                  v2 = *(unsigned int *)(HIDWORD(v5) + 24) * (unsigned __int64)*(unsigned int *)(HIDWORD(v5) + 24);
                  *(_QWORD *)(v5 + 48) = v2;
                }
              }
            }
          }
        }
      }
    }
  }
  return v2;
}
