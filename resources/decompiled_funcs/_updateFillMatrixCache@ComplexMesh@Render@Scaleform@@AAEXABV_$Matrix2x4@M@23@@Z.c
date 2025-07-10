void __thiscall Scaleform::Render::ComplexMesh::updateFillMatrixCache(
        Scaleform::Render::ComplexMesh *this,
        const Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  unsigned int v3; // ebx
  Scaleform::ArrayLH<Scaleform::Render::Matrix2x4<float>,2,Scaleform::ArrayDefaultPolicy> *p_FillMatrixCache; // ebp
  unsigned int v5; // edi
  int v6; // ebx
  unsigned int fillCount; // [esp+1Ch] [ebp-4h]

  v3 = this->pProvider.pObject->GetFillCount(this->pProvider.pObject, this->Layer, this->MGFlags);
  p_FillMatrixCache = &this->FillMatrixCache;
  fillCount = v3;
  Scaleform::ArrayData<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FillMatrixCache.Data,
    v3);
  if ( this->FillMatrixCache.Data.Size == v3 )
  {
    v5 = 0;
    if ( v3 )
    {
      v6 = 0;
      do
      {
        this->pProvider.pObject->GetFillMatrix(
          this->pProvider.pObject,
          this,
          &p_FillMatrixCache->Data.Data[v6],
          this->Layer,
          v5,
          this->MGFlags);
        Scaleform::Render::Matrix2x4<float>::Prepend(&p_FillMatrixCache->Data.Data[v6], vertexMatrix);
        ++v5;
        ++v6;
      }
      while ( v5 < fillCount );
    }
  }
}
