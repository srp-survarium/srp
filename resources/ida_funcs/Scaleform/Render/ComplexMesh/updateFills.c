bool __thiscall Scaleform::Render::ComplexMesh::updateFills(Scaleform::Render::ComplexMesh *this)
{
  bool result; // al
  Scaleform::Render::ComplexMesh::FillRecord *v3; // edi
  unsigned int Layer; // eax
  Scaleform::Render::MeshProvider *pObject; // ecx
  void (__thiscall *GetFillData)(Scaleform::Render::MeshProvider *, Scaleform::Render::FillData *, unsigned int, unsigned int, unsigned int); // edx
  Scaleform::Render::PrimitiveFill *MergedFill; // eax
  Scaleform::RefCountNTSImpl *v8; // ebp
  Scaleform::Render::FillData *v9; // edi
  int k; // ebp
  const Scaleform::Render::VertexFormat *v11; // ecx
  Scaleform::Render::FillData *v12; // edi
  int j; // ebp
  const Scaleform::Render::VertexFormat *pVFormat; // ecx
  unsigned int v15; // [esp+1Ch] [ebp-58h]
  unsigned int morphRatio; // [esp+20h] [ebp-54h]
  int v17; // [esp+34h] [ebp-40h]
  unsigned int i; // [esp+38h] [ebp-3Ch]
  Scaleform::Render::TextureManager *textureManager; // [esp+40h] [ebp-34h]
  Scaleform::Ptr<Scaleform::Render::Image> gi[2]; // [esp+44h] [ebp-30h] BYREF
  Scaleform::Render::FillData fd[2]; // [esp+4Ch] [ebp-28h] BYREF

  result = this->pProvider.pObject->IsValid(this->pProvider.pObject);
  if ( result )
  {
    textureManager = this->pRenderer2D->pHal.pObject->GetTextureManager(this->pRenderer2D->pHal.pObject);
    i = 0;
    if ( this->FillRecords.Data.Size )
    {
      v17 = 0;
      do
      {
        v3 = &this->FillRecords.Data.Data[v17];
        if ( v3->pFill.pObject )
        {
          fd[0].pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
          fd[1].pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
          morphRatio = this->MGFlags;
          v15 = v3->FillMatrixIndex[0];
          Layer = this->Layer;
          fd[0].Type = Fill_VColor;
          fd[1].Type = Fill_VColor;
          pObject = this->pProvider.pObject;
          fd[0].PrimFill = PrimFill_VColor_EAlpha;
          fd[1].PrimFill = PrimFill_VColor_EAlpha;
          fd[0].Color = 0;
          fd[0].FillMode.Fill = 0;
          fd[1].Color = 0;
          fd[1].FillMode.Fill = 0;
          GetFillData = pObject->GetFillData;
          gi[0].pObject = 0;
          gi[1].pObject = 0;
          GetFillData(pObject, fd, Layer, v15, morphRatio);
          this->pProvider.pObject->GetFillData(
            this->pProvider.pObject,
            &fd[1],
            this->Layer,
            v3->FillMatrixIndex[1],
            this->MGFlags);
          MergedFill = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
                         this->pFillManager,
                         v3->MergeFlags,
                         v3->pFill.pObject->Data.pFormat,
                         fd,
                         &fd[1],
                         gi,
                         &gi[1],
                         textureManager,
                         this->MorphRatio);
          v8 = MergedFill;
          if ( MergedFill )
          {
            ++MergedFill->RefCount;
            if ( v3->pFill.pObject )
              Scaleform::RefCountNTSImpl::Release(v3->pFill.pObject);
            v3->pFill.pObject = (Scaleform::Render::PrimitiveFill *)v8;
            Scaleform::RefCountNTSImpl::Release(v8);
            v12 = fd;
            for ( j = 1; j >= 0; --j )
            {
              pVFormat = v12[-1].pVFormat;
              v12 = (Scaleform::Render::FillData *)((char *)v12 - 4);
              if ( pVFormat )
                (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(pVFormat->Size + 8))(pVFormat);
            }
          }
          else
          {
            v9 = fd;
            for ( k = 1; k >= 0; --k )
            {
              v11 = v9[-1].pVFormat;
              v9 = (Scaleform::Render::FillData *)((char *)v9 - 4);
              if ( v11 )
                (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(v11->Size + 8))(v11);
            }
          }
        }
        ++v17;
        ++i;
      }
      while ( i < this->FillRecords.Data.Size );
    }
    Scaleform::Render::ComplexMesh::updateFillMatrixCache(this, &this->VertexMatrix);
    return 1;
  }
  return result;
}
