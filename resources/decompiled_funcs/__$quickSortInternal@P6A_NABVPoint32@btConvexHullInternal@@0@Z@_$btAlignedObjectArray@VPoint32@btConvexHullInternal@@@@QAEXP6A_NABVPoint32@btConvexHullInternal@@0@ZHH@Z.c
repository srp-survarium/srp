void __thiscall btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
        btAlignedObjectArray<btConvexHullInternal::Point32> *this,
        bool (__cdecl *CompareFunc)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *),
        int lo,
        int hi)
{
  int v4; // ebx
  int v6; // edi
  int i; // eax
  int j; // eax
  btConvexHullInternal::Point32 *m_data; // edx
  __int64 v11; // xmm0_8
  __int64 v12; // xmm1_8
  btConvexHullInternal::Point32 *v13; // ecx
  btConvexHullInternal::Point32 *v14; // ecx
  btConvexHullInternal::Point32 x; // [esp+10h] [ebp-10h] BYREF
  bool (__cdecl *CompareFunca)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *); // [esp+24h] [ebp+4h]
  bool (__cdecl *CompareFuncb)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *); // [esp+24h] [ebp+4h]

  v4 = lo;
  v6 = hi;
  x = this->m_data[(lo + hi) / 2];
  do
  {
    if ( CompareFunc(&this->m_data[v4], &x) )
    {
      for ( i = 16 * v4; ; i = (int)CompareFunca )
      {
        ++v4;
        CompareFunca = (bool (__cdecl *)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *))(i + 16);
        if ( !CompareFunc((const btConvexHullInternal::Point32 *)((char *)this->m_data + i + 16), &x) )
          break;
      }
    }
    if ( CompareFunc(&x, &this->m_data[v6]) )
    {
      for ( j = 16 * v6; ; j = (int)CompareFuncb )
      {
        --v6;
        CompareFuncb = (bool (__cdecl *)(const btConvexHullInternal::Point32 *, const btConvexHullInternal::Point32 *))(j - 16);
        if ( !CompareFunc(&x, (const btConvexHullInternal::Point32 *)((char *)this->m_data + j - 16)) )
          break;
      }
    }
    if ( v4 > v6 )
      break;
    m_data = this->m_data;
    v11 = *(_QWORD *)&m_data[v4].x;
    v12 = *(_QWORD *)&m_data[v4].z;
    v13 = &m_data[v4];
    *(_QWORD *)&v13->x = *(_QWORD *)&m_data[v6].x;
    *(_QWORD *)&v13->z = *(_QWORD *)&m_data[v6].z;
    v14 = &this->m_data[v6];
    ++v4;
    --v6;
    *(_QWORD *)&v14->x = v11;
    *(_QWORD *)&v14->z = v12;
  }
  while ( v4 <= v6 );
  if ( lo < v6 )
    btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
      this,
      CompareFunc,
      lo,
      v6);
  if ( v4 < hi )
    btAlignedObjectArray<btConvexHullInternal::Point32>::quickSortInternal<bool (__cdecl *)(btConvexHullInternal::Point32 const &,btConvexHullInternal::Point32 const &)>(
      this,
      CompareFunc,
      v4,
      hi);
}
