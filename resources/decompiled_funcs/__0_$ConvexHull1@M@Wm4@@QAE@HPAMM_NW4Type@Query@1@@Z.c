void __userpurge Wm4::ConvexHull1<float>::ConvexHull1<float>(
        Wm4::ConvexHull1<float> *this@<edi>,
        unsigned int iVertexQuantity@<eax>,
        Wm4::Query::Type eQueryType@<ecx>,
        const stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex> *a4@<esi>,
        float *afVertex,
        Wm4::ConvexHull1<float>::SortedVertex *fEpsilon,
        bool bOwner)
{
  Wm4::ConvexHull1<float>::SortedVertex *M_start; // esi
  int i; // eax
  Wm4::ConvexHull1<float>::SortedVertex *M_finish; // ebx
  int v10; // ebp
  int v11; // eax
  int j; // ecx
  int *v13; // eax
  stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex> v14; // [esp-18h] [ebp-2Ch]
  stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex> v15; // [esp-Ch] [ebp-20h]
  Wm4::ConvexHull1<float>::SortedVertex __val; // [esp+0h] [ebp-14h] BYREF
  stlp_std::vector<Wm4::ConvexHull1<float>::SortedVertex,stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex> > kArray; // [esp+8h] [ebp-Ch] BYREF
  float fEpsilona; // [esp+1Ch] [ebp+8h]

  this->m_fEpsilon = *(float *)&fEpsilon;
  this->m_eQueryType = eQueryType;
  __val.Value = 0.0;
  __val.Index = 0;
  this->m_iVertexQuantity = iVertexQuantity;
  this->m_iDimension = 0;
  this->m_iSimplexQuantity = 0;
  this->m_aiIndex = 0;
  this->m_bOwner = 1;
  this->__vftable = (Wm4::ConvexHull1<float>_vtbl *)&Wm4::ConvexHull1<float>::`vftable';
  this->m_afVertex = afVertex;
  stlp_std::priv::_Impl_vector<Wm4::ConvexHull1<float>::SortedVertex,stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex>>::_Impl_vector<Wm4::ConvexHull1<float>::SortedVertex,stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex>>(
    &kArray._M_impl,
    iVertexQuantity,
    &__val,
    a4);
  M_start = kArray._M_impl._M_start;
  for ( i = 0; i < this->m_iVertexQuantity; ++i )
  {
    M_start[i].Value = this->m_afVertex[i];
    M_start[i].Index = i;
  }
  M_finish = kArray._M_impl._M_finish;
  if ( M_start != kArray._M_impl._M_finish )
  {
    v10 = kArray._M_impl._M_finish - M_start;
    v11 = v10;
    for ( j = 0; v11 != 1; ++j )
      v11 >>= 1;
    stlp_std::priv::__introsort_loop<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,int,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
      M_start,
      kArray._M_impl._M_finish,
      0,
      2 * j,
      (stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>)fEpsilon);
    if ( v10 <= 16 )
    {
      stlp_std::priv::__insertion_sort<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
        M_start,
        M_finish,
        fEpsilon,
        v15);
    }
    else
    {
      stlp_std::priv::__insertion_sort<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
        M_start,
        M_start + 16,
        fEpsilon,
        v15);
      stlp_std::priv::__unguarded_insertion_sort_aux<Wm4::ConvexHull1<float>::SortedVertex *,Wm4::ConvexHull1<float>::SortedVertex,stlp_std::less<Wm4::ConvexHull1<float>::SortedVertex>>(
        M_start + 16,
        M_finish,
        fEpsilon,
        v14);
    }
  }
  fEpsilona = M_start[this->m_iVertexQuantity - 1].Value - M_start->Value;
  if ( this->m_fEpsilon <= (double)fEpsilona )
  {
    this->m_iDimension = 1;
    this->m_iSimplexQuantity = 2;
    v13 = (int *)operator new[](8u);
    this->m_aiIndex = v13;
    *v13 = M_start->Index;
    this->m_aiIndex[1] = M_start[this->m_iVertexQuantity - 1].Index;
  }
  if ( (unsigned int)(8 * (kArray._M_impl._M_end_of_storage._M_data - M_start)) <= 0x80 )
    stlp_std::__node_alloc::_M_deallocate(M_start, 8 * (kArray._M_impl._M_end_of_storage._M_data - M_start));
  else
    operator delete(M_start);
}
