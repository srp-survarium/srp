bool __thiscall Scaleform::Render::ComplexMesh::updateFills(Scaleform::Render::ComplexMesh *this)
{
  bool result; // al
  Scaleform::Render::ComplexMesh::FillRecord *v3; // edi
  unsigned int Layer; // eax
  Scaleform::Render::MeshProvider *pObject; // ecx
  void (__thiscall *GetFillData)(Scaleform::Render::MeshProvider *, Scaleform::Render::FillData *, unsigned int, unsigned int, unsigned int); // edx
  Scaleform::Render::PrimitiveFill *v7; // eax
  Scaleform::RefCountNTSImpl *v8; // ebp
  Scaleform::Render::FillData *v9; // edi
  int j; // ebp
  const Scaleform::Render::VertexFormat *v11; // ecx
  Scaleform::Render::FillData *p_fd0; // edi
  int i; // ebp
  const Scaleform::Render::VertexFormat *pVFormat; // ecx
  unsigned int v15; // [esp+1Ch] [ebp-58h]
  unsigned int morphRatio; // [esp+20h] [ebp-54h]
  int v17; // [esp+34h] [ebp-40h]
  unsigned int v18; // [esp+38h] [ebp-3Ch]
  Scaleform::Render::TextureManager *textureManager; // [esp+40h] [ebp-34h]
  Scaleform::Ptr<Scaleform::Render::Image> gradientImg0; // [esp+44h] [ebp-30h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> gradientImg1; // [esp+48h] [ebp-2Ch] BYREF
  Scaleform::Render::FillData fd0; // [esp+4Ch] [ebp-28h] BYREF
  Scaleform::Render::FillData fd1; // [esp+60h] [ebp-14h] BYREF

  result = this->pProvider.pObject->IsValid(this->pProvider.pObject);
  if ( result )
  {
    textureManager = this->pRenderer2D->pHal.pObject->GetTextureManager(this->pRenderer2D->pHal.pObject);
    v18 = 0;
    if ( this->FillRecords.Data.Size )
    {
      v17 = 0;
      do
      {
        v3 = &this->FillRecords.Data.Data[v17];
        if ( v3->pFill.pObject )
        {
          fd0.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
          fd1.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
          morphRatio = this->MGFlags;
          v15 = v3->FillMatrixIndex[0];
          Layer = this->Layer;
          fd0.Type = Fill_VColor;
          fd1.Type = Fill_VColor;
          pObject = this->pProvider.pObject;
          fd0.PrimFill = PrimFill_VColor_EAlpha;
          fd1.PrimFill = PrimFill_VColor_EAlpha;
          fd0.Color = 0;
          fd0.FillMode.Fill = 0;
          fd1.Color = 0;
          fd1.FillMode.Fill = 0;
          GetFillData = pObject->GetFillData;
          gradientImg0.pObject = 0;
          gradientImg1.pObject = 0;
          GetFillData(pObject, &fd0, Layer, v15, morphRatio);
          this->pProvider.pObject->GetFillData(
            this->pProvider.pObject,
            &fd1,
            this->Layer,
            v3->FillMatrixIndex[1],
            this->MGFlags);
          v7 = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
                 this->pFillManager,
                 v3->MergeFlags,
                 v3->pFill.pObject->Data.pFormat,
                 &fd0,
                 &fd1,
                 &gradientImg0,
                 &gradientImg1,
                 textureManager,
                 this->MorphRatio);
          v8 = v7;
          if ( v7 )
          {
            ++v7->RefCount;
            if ( v3->pFill.pObject )
              Scaleform::RefCountNTSImpl::Release(v3->pFill.pObject);
            v3->pFill.pObject = (Scaleform::Render::PrimitiveFill *)v8;
            Scaleform::RefCountNTSImpl::Release(v8);
            p_fd0 = &fd0;
            for ( i = 1; i >= 0; --i )
            {
              pVFormat = p_fd0[-1].pVFormat;
              p_fd0 = (Scaleform::Render::FillData *)((char *)p_fd0 - 4);
              if ( pVFormat )
                (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(pVFormat->Size + 8))(pVFormat);
            }
          }
          else
          {
            v9 = &fd0;
            for ( j = 1; j >= 0; --j )
            {
              v11 = v9[-1].pVFormat;
              v9 = (Scaleform::Render::FillData *)((char *)v9 - 4);
              if ( v11 )
                (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(v11->Size + 8))(v11);
            }
          }
        }
        ++v17;
        ++v18;
      }
      while ( v18 < this->FillRecords.Data.Size );
    }
    Scaleform::Render::ComplexMesh::updateFillMatrixCache(this, &this->VertexMatrix);
    return 1;
  }
  return result;
}
