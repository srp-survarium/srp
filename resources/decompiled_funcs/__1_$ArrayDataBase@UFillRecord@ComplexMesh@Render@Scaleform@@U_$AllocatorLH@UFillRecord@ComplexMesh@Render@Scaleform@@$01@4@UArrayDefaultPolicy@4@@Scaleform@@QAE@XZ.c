void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Render::ComplexMesh::FillRecord *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pFill.pObject )
        Scaleform::RefCountNTSImpl::Release(v3->pFill.pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
