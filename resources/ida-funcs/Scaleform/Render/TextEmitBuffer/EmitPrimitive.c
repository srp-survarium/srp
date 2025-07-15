void __thiscall Scaleform::Render::TextEmitBuffer::EmitPrimitive(
        Scaleform::Render::TextEmitBuffer *this,
        Scaleform::Render::TextPrepareBuffer *prepareBuffer,
        Scaleform::Render::HAL *hal)
{
  unsigned int ProcessingLayer; // ebx
  Scaleform::Render::TextPrimitiveBundle *pBundle; // ecx
  _DWORD *p_pData; // eax
  Scaleform::Render::Primitive *v7; // edi
  int v8; // eax
  bool layerProcessingFinished; // [esp+Fh] [ebp-1h]
  Scaleform::Render::PrimitivePrepareBuffer *prepareBuffera; // [esp+14h] [ebp+4h]

  layerProcessingFinished = 1;
  if ( this->pItem == prepareBuffer->pItem )
  {
    ProcessingLayer = prepareBuffer->ProcessingLayer;
    if ( ProcessingLayer < this->pBundle->Layers.Size )
    {
      ++ProcessingLayer;
      layerProcessingFinished = 0;
    }
  }
  else
  {
    ProcessingLayer = this->pBundle->Layers.Size;
  }
  if ( this->EmitLayer < ProcessingLayer )
  {
    prepareBuffera = &prepareBuffer->PPBuffer;
    do
    {
      pBundle = this->pBundle;
      if ( pBundle->Layers.Size <= 2 )
        p_pData = &pBundle->Layers.AD.pData;
      else
        p_pData = &pBundle->Layers.AD.pData->pObject;
      v7 = (Scaleform::Render::Primitive *)p_pData[this->EmitLayer];
      v8 = (int)v7[1].Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
      if ( v8 >= 11 )
      {
        if ( v8 == 11 )
        {
          if ( this->MaskStatus == Mask_NotInUse && pBundle->pMaskPrimitive.pObject )
          {
            hal->PushMask_BeginSubmit(hal, pBundle->pMaskPrimitive.pObject);
            this->MaskStatus = Mask_Submitting;
          }
        }
        else if ( this->MaskStatus == Mask_Submitting )
        {
          hal->EndMaskSubmit(hal);
          this->MaskStatus = Mask_InUse;
        }
      }
      Scaleform::Render::Primitive::emitToHAL(v7, v7, prepareBuffera, &this->PEBuffer, hal);
      ++this->EmitLayer;
    }
    while ( this->EmitLayer < ProcessingLayer );
  }
  if ( layerProcessingFinished )
  {
    if ( this->MaskStatus )
    {
      hal->PopMask(hal);
      this->MaskStatus = Mask_NotInUse;
    }
    this->pItem = 0;
  }
  else
  {
    --this->EmitLayer;
  }
}
