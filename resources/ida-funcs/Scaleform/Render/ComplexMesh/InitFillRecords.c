char __thiscall Scaleform::Render::ComplexMesh::InitFillRecords(
        Scaleform::Render::ComplexMesh *this,
        const Scaleform::Render::VertexOutput::Fill *fills,
        unsigned int fillRecordCount,
        const Scaleform::Render::Matrix2x4<float> *vertexMatrix,
        Scaleform::Render::HAL *hal,
        unsigned int *vbSize,
        unsigned int *vertexCount,
        unsigned int *indexCount)
{
  unsigned int Size; // esi
  Scaleform::ArrayLH<Scaleform::Render::ComplexMesh::FillRecord,2,Scaleform::ArrayDefaultPolicy> *p_FillRecords; // ebx
  Scaleform::Render::ComplexMesh::FillRecord *v11; // eax
  int v12; // ecx
  unsigned int *p_FillIndex0; // edi
  Scaleform::Render::ComplexMesh::FillRecord *v14; // esi
  unsigned int Layer; // eax
  Scaleform::Render::MeshProvider *pObject; // ecx
  void (__thiscall *GetFillData)(Scaleform::Render::MeshProvider *, Scaleform::Render::FillData *, unsigned int, unsigned int, unsigned int); // edx
  Scaleform::Render::PrimitiveFill *v18; // eax
  Scaleform::Ptr<Scaleform::Render::Image> *v19; // ebx
  Scaleform::Ptr<Scaleform::Render::Image> *v20; // ebx
  Scaleform::Render::FillData *p_fd0; // esi
  int i; // ebx
  const Scaleform::Render::VertexFormat *pVFormat; // ecx
  Scaleform::Render::FillData *v25; // esi
  int j; // edi
  const Scaleform::Render::VertexFormat *v27; // ecx
  unsigned int v28; // [esp+20h] [ebp-58h]
  unsigned int morphRatio; // [esp+24h] [ebp-54h]
  int v30; // [esp+38h] [ebp-40h]
  int v31; // [esp+3Ch] [ebp-3Ch]
  Scaleform::Render::TextureManager *textureManager; // [esp+40h] [ebp-38h]
  int v33; // [esp+44h] [ebp-34h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> gradientImg0; // [esp+48h] [ebp-30h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> gradientImg1; // [esp+4Ch] [ebp-2Ch] BYREF
  Scaleform::Render::FillData fd0; // [esp+50h] [ebp-28h] BYREF
  Scaleform::Render::FillData fd1; // [esp+64h] [ebp-14h] BYREF
  Scaleform::Render::PrimitiveFill *v38; // [esp+7Ch] [ebp+4h]

  Size = this->FillRecords.Data.Size;
  p_FillRecords = &this->FillRecords;
  Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->FillRecords.Data,
    &this->FillRecords,
    fillRecordCount);
  if ( fillRecordCount > Size )
  {
    v11 = &p_FillRecords->Data.Data[Size];
    v12 = fillRecordCount - Size;
    if ( fillRecordCount != Size )
    {
      do
      {
        if ( v11 )
          v11->pFill.pObject = 0;
        ++v11;
        --v12;
      }
      while ( v12 );
    }
  }
  if ( this->FillRecords.Data.Size == fillRecordCount )
  {
    textureManager = hal->GetTextureManager(hal);
    if ( this->UpdateListNode.pPrev )
    {
      this->UpdateListNode.pPrev->pNext = this->UpdateListNode.pNext;
      this->UpdateListNode.pNext->pPrev = this->UpdateListNode.pPrev;
      this->UpdateListNode.pNext = 0;
      this->UpdateListNode.pPrev = 0;
    }
    *vbSize = 0;
    *indexCount = 0;
    *vertexCount = 0;
    v31 = 0;
    if ( !fillRecordCount )
    {
LABEL_31:
      this->VertexMatrix = *vertexMatrix;
      Scaleform::Render::ComplexMesh::updateFillMatrixCache(this, vertexMatrix);
      return 1;
    }
    v30 = 0;
    p_FillIndex0 = &fills->FillIndex0;
    while ( 1 )
    {
      v14 = &this->FillRecords.Data.Data[v30];
      fd0.Type = Fill_VColor;
      fd1.Type = Fill_VColor;
      morphRatio = this->MGFlags;
      v28 = *p_FillIndex0;
      Layer = this->Layer;
      fd0.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
      fd1.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
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
      GetFillData(pObject, &fd0, Layer, v28, morphRatio);
      if ( (p_FillIndex0[2] & 2) != 0 )
        this->pProvider.pObject->GetFillData(this->pProvider.pObject, &fd1, this->Layer, p_FillIndex0[1], this->MGFlags);
      v18 = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
              this->pFillManager,
              p_FillIndex0[2],
              (const Scaleform::Render::VertexFormat *)*(p_FillIndex0 - 1),
              &fd0,
              &fd1,
              &gradientImg0,
              &gradientImg1,
              textureManager,
              this->MorphRatio);
      v38 = v18;
      if ( v14->pFill.pObject )
      {
        Scaleform::RefCountNTSImpl::Release(v14->pFill.pObject);
        v18 = v38;
      }
      v14->pFill.pObject = v18;
      if ( !v18 )
        break;
      if ( !this->UpdateListNode.pPrev && (fd0.Type == Fill_Image || fd1.Type == Fill_Image) )
        Scaleform::Render::Renderer2DImpl::AddComplexMeshToUpdateList(this->pRenderer2D, &this->UpdateListNode);
      v14->IndexOffset = *indexCount;
      v14->IndexCount = *(p_FillIndex0 - 2);
      v14->VertexByteOffset = *vbSize;
      v14->VertexCount = *(p_FillIndex0 - 3);
      v14->FillMatrixIndex[0] = *p_FillIndex0;
      v14->FillMatrixIndex[1] = p_FillIndex0[1];
      v14->MergeFlags = p_FillIndex0[2];
      if ( gradientImg0.pObject )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->GradientImages.Data,
          &this->GradientImages,
          this->GradientImages.Data.Size + 1);
        v19 = &this->GradientImages.Data.Data[this->GradientImages.Data.Size - 1];
        if ( &this->GradientImages.Data.Data[this->GradientImages.Data.Size] != (Scaleform::Ptr<Scaleform::Render::Image> *)4 )
        {
          gradientImg0.pObject->AddRef(gradientImg0.pObject);
          v19->pObject = gradientImg0.pObject;
        }
      }
      if ( gradientImg1.pObject )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->GradientImages.Data,
          &this->GradientImages,
          this->GradientImages.Data.Size + 1);
        v20 = &this->GradientImages.Data.Data[this->GradientImages.Data.Size - 1];
        if ( &this->GradientImages.Data.Data[this->GradientImages.Data.Size] != (Scaleform::Ptr<Scaleform::Render::Image> *)4 )
        {
          gradientImg1.pObject->AddRef(gradientImg1.pObject);
          v20->pObject = gradientImg1.pObject;
        }
      }
      hal->MapVertexFormat(
        hal,
        v14->pFill.pObject->Data.Type,
        v14->pFill.pObject->Data.pFormat,
        v14->pFormats,
        (const Scaleform::Render::VertexFormat **)&v33,
        &v14->pFormats[1],
        1u);
      *vbSize += *(p_FillIndex0 - 3) * v14->pFormats[0]->Size;
      *vertexCount += *(p_FillIndex0 - 3);
      *indexCount += *(p_FillIndex0 - 2);
      p_fd0 = &fd0;
      for ( i = 1; i >= 0; --i )
      {
        pVFormat = p_fd0[-1].pVFormat;
        p_fd0 = (Scaleform::Render::FillData *)((char *)p_fd0 - 4);
        if ( pVFormat )
          (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(pVFormat->Size + 8))(pVFormat);
      }
      ++v30;
      p_FillIndex0 += 7;
      if ( ++v31 >= fillRecordCount )
        goto LABEL_31;
    }
    v25 = &fd0;
    for ( j = 1; j >= 0; --j )
    {
      v27 = v25[-1].pVFormat;
      v25 = (Scaleform::Render::FillData *)((char *)v25 - 4);
      if ( v27 )
        (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(v27->Size + 8))(v27);
    }
  }
  return 0;
}
