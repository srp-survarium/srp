void __thiscall Scaleform::Render::TextEmitBuffer::EmitPrimitive(
        Scaleform::Render::TextEmitBuffer *this,
        Scaleform::Render::PrimitivePrepareBuffer *prepareBuffer,
        Scaleform::Render::HAL *hal)
{
  const Scaleform::Render::VertexFormat *pSourceVFormat; // ebx
  Scaleform::Render::TextPrimitiveBundle *pBundle; // ecx
  _DWORD *p_pData; // eax
  Scaleform::Render::Primitive *v7; // edi
  int v8; // eax
  char v9; // [esp+Fh] [ebp-1h]
  Scaleform::Render::PrimitivePrepareBuffer *prepareBuffera; // [esp+14h] [ebp+4h]

  v9 = 1;
  if ( this->pItem == prepareBuffer->pItem )
  {
    pSourceVFormat = prepareBuffer->pSourceVFormat;
    if ( (unsigned int)pSourceVFormat < this->pBundle->Layers.Size )
    {
      pSourceVFormat = (const Scaleform::Render::VertexFormat *)((char *)pSourceVFormat + 1);
      v9 = 0;
    }
  }
  else
  {
    pSourceVFormat = (const Scaleform::Render::VertexFormat *)this->pBundle->Layers.Size;
  }
  if ( this->EmitLayer < (unsigned int)pSourceVFormat )
  {
    prepareBuffera = (Scaleform::Render::PrimitivePrepareBuffer *)&prepareBuffer->pInstancedVFormat;
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
    while ( this->EmitLayer < (unsigned int)pSourceVFormat );
  }
  if ( v9 )
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
