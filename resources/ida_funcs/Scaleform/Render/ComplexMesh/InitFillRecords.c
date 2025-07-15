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
  Scaleform::Render::PrimitiveFill *MergedFill; // eax
  Scaleform::Ptr<Scaleform::Render::Image> *v19; // ebx
  Scaleform::Ptr<Scaleform::Render::Image> *v20; // ebx
  Scaleform::Render::FillData *v21; // esi
  int j; // ebx
  const Scaleform::Render::VertexFormat *pVFormat; // ecx
  Scaleform::Render::FillData *v25; // esi
  int k; // edi
  const Scaleform::Render::VertexFormat *v27; // ecx
  unsigned int v28; // [esp+20h] [ebp-58h]
  unsigned int morphRatio; // [esp+24h] [ebp-54h]
  int v30; // [esp+38h] [ebp-40h]
  unsigned int i; // [esp+3Ch] [ebp-3Ch]
  Scaleform::Render::TextureManager *textureManager; // [esp+40h] [ebp-38h]
  const Scaleform::Render::VertexFormat *tempBatchVF; // [esp+44h] [ebp-34h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> gi[2]; // [esp+48h] [ebp-30h] BYREF
  Scaleform::Render::FillData fd[2]; // [esp+50h] [ebp-28h] BYREF
  const Scaleform::Render::VertexOutput::Fill *fillsa; // [esp+7Ch] [ebp+4h]

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
    i = 0;
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
      fd[0].Type = Fill_VColor;
      fd[1].Type = Fill_VColor;
      morphRatio = this->MGFlags;
      v28 = *p_FillIndex0;
      Layer = this->Layer;
      fd[0].pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
      fd[1].pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
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
      GetFillData(pObject, fd, Layer, v28, morphRatio);
      if ( (p_FillIndex0[2] & 2) != 0 )
        this->pProvider.pObject->GetFillData(
          this->pProvider.pObject,
          &fd[1],
          this->Layer,
          p_FillIndex0[1],
          this->MGFlags);
      MergedFill = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
                     this->pFillManager,
                     p_FillIndex0[2],
                     (const Scaleform::Render::VertexFormat *)*(p_FillIndex0 - 1),
                     fd,
                     &fd[1],
                     gi,
                     &gi[1],
                     textureManager,
                     this->MorphRatio);
      fillsa = (const Scaleform::Render::VertexOutput::Fill *)MergedFill;
      if ( v14->pFill.pObject )
      {
        Scaleform::RefCountNTSImpl::Release(v14->pFill.pObject);
        MergedFill = (Scaleform::Render::PrimitiveFill *)fillsa;
      }
      v14->pFill.pObject = MergedFill;
      if ( !MergedFill )
        break;
      if ( !this->UpdateListNode.pPrev && (fd[0].Type == Fill_Image || fd[1].Type == Fill_Image) )
        Scaleform::Render::Renderer2DImpl::AddComplexMeshToUpdateList(this->pRenderer2D, &this->UpdateListNode);
      v14->IndexOffset = *indexCount;
      v14->IndexCount = *(p_FillIndex0 - 2);
      v14->VertexByteOffset = *vbSize;
      v14->VertexCount = *(p_FillIndex0 - 3);
      v14->FillMatrixIndex[0] = *p_FillIndex0;
      v14->FillMatrixIndex[1] = p_FillIndex0[1];
      v14->MergeFlags = p_FillIndex0[2];
      if ( gi[0].pObject )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->GradientImages.Data,
          &this->GradientImages,
          this->GradientImages.Data.Size + 1);
        v19 = &this->GradientImages.Data.Data[this->GradientImages.Data.Size - 1];
        if ( &this->GradientImages.Data.Data[this->GradientImages.Data.Size] != (Scaleform::Ptr<Scaleform::Render::Image> *)4 )
        {
          gi[0].pObject->AddRef(gi[0].pObject);
          v19->pObject = (Scaleform::Render::Image *)gi[0];
        }
      }
      if ( gi[1].pObject )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->GradientImages.Data,
          &this->GradientImages,
          this->GradientImages.Data.Size + 1);
        v20 = &this->GradientImages.Data.Data[this->GradientImages.Data.Size - 1];
        if ( &this->GradientImages.Data.Data[this->GradientImages.Data.Size] != (Scaleform::Ptr<Scaleform::Render::Image> *)4 )
        {
          gi[1].pObject->AddRef(gi[1].pObject);
          v20->pObject = (Scaleform::Render::Image *)gi[1];
        }
      }
      hal->MapVertexFormat(
        hal,
        v14->pFill.pObject->Data.Type,
        v14->pFill.pObject->Data.pFormat,
        v14->pFormats,
        &tempBatchVF,
        &v14->pFormats[1],
        1u);
      *vbSize += *(p_FillIndex0 - 3) * v14->pFormats[0]->Size;
      *vertexCount += *(p_FillIndex0 - 3);
      *indexCount += *(p_FillIndex0 - 2);
      v21 = fd;
      for ( j = 1; j >= 0; --j )
      {
        pVFormat = v21[-1].pVFormat;
        v21 = (Scaleform::Render::FillData *)((char *)v21 - 4);
        if ( pVFormat )
          (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(pVFormat->Size + 8))(pVFormat);
      }
      ++v30;
      p_FillIndex0 += 7;
      if ( ++i >= fillRecordCount )
        goto LABEL_31;
    }
    v25 = fd;
    for ( k = 1; k >= 0; --k )
    {
      v27 = v25[-1].pVFormat;
      v25 = (Scaleform::Render::FillData *)((char *)v25 - 4);
      if ( v27 )
        (*(void (__thiscall **)(const Scaleform::Render::VertexFormat *))(v27->Size + 8))(v27);
    }
  }
  return 0;
}
