Wm4::ConvexHull1<float>::SortedVertex *__userpurge Wm4::ConvexHull1<float>::ConvexHull1<float>@<eax>(
        int a1@<ecx>,
        int a2@<xmm0>,
        Wm4::ConvexHull1<float>::SortedVertex *this,
        int iVertexQuantity,
        float *afVertex)
{
  unsigned int Value_low; // eax
  Wm4::ConvexHull1<float>::SortedVertex *M_start; // edi
  int i; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // eax
  Wm4::ConvexHull1<float>::SortedVertex *v11; // esi
  int *v12; // eax
  const stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex> *v14; // [esp+0h] [ebp-24h]
  stlp_std::priv::_Impl_vector<Wm4::ConvexHull1<float>::SortedVertex,stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex> > v15; // [esp+Ch] [ebp-18h] BYREF
  Wm4::ConvexHull1<float>::SortedVertex __val; // [esp+18h] [ebp-Ch] BYREF

  Wm4::ConvexHull<float>::ConvexHull<float>((int)this, a1, a2, iVertexQuantity, 1);
  LODWORD(this[4].Value) = afVertex;
  __val.Value = 0.0;
  __val.Index = 0;
  Value_low = LODWORD(this[1].Value);
  LODWORD(this->Value) = &Wm4::ConvexHull1<float>::`vftable';
  stlp_std::priv::_Impl_vector<Wm4::ConvexHull1<float>::SortedVertex,stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex>>::_Impl_vector<Wm4::ConvexHull1<float>::SortedVertex,stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex>>(
    &v15,
    Value_low,
    &__val,
    v14);
  M_start = v15._M_start;
  for ( i = 0; i < SLODWORD(this[1].Value); ++i )
  {
    M_start[i].Value = *(float *)(LODWORD(this[4].Value) + 4 * i);
    M_start[i].Index = i;
  }
  if ( M_start != v15._M_finish )
  {
    v8 = v15._M_finish - M_start;
    v9 = v8;
    v10 = 0;
    while ( v9 != 1 )
    {
      ++v10;
      v9 >>= 1;
    }
    stlp_std::priv::__introsort_loop<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,int,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
      M_start,
      v15._M_finish,
      0,
      2 * v10,
      this);
    if ( v8 <= 16 )
    {
      stlp_std::priv::__insertion_sort<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
        M_start,
        v15._M_finish,
        this);
    }
    else
    {
      v11 = M_start + 16;
      stlp_std::priv::__insertion_sort<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
        M_start,
        M_start + 16,
        this);
      while ( v11 != v15._M_finish )
      {
        stlp_std::priv::__unguarded_linear_insert<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
          v11,
          *v11);
        ++v11;
      }
    }
  }
  if ( (float)(M_start[LODWORD(this[1].Value) - 1].Value - M_start->Value) >= this[3].Value )
  {
    this[1].Index = 1;
    LODWORD(this[2].Value) = 2;
    v12 = (int *)operator new[](8u);
    this[2].Index = (int)v12;
    *v12 = M_start->Index;
    *(_DWORD *)(this[2].Index + 4) = M_start[LODWORD(this[1].Value) - 1].Index;
  }
  stlp_std::__node_alloc::deallocate(
    (_STLP_atomic_freelist::item *)M_start,
    8 * (v15._M_end_of_storage._M_data - M_start));
  return this;
}
