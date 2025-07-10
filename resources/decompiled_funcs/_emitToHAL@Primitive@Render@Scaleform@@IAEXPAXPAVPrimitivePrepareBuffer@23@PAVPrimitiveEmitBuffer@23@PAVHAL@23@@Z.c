void __thiscall Scaleform::Render::Primitive::emitToHAL(
        Scaleform::Render::Primitive *this,
        void *item,
        Scaleform::Render::PrimitivePrepareBuffer *prepareBuffer,
        Scaleform::Render::PrimitiveEmitBuffer *emitBuffer,
        Scaleform::Render::HAL *hal)
{
  Scaleform::Render::PrimitiveBatch *pDraw; // ebx
  Scaleform::Render::PrimitiveBatch *pPrepare; // edi

  if ( item == emitBuffer->pItem )
  {
    pDraw = emitBuffer->pDraw;
  }
  else
  {
    pDraw = this->Batches.Root.pNext;
    emitBuffer->pItem = item;
    emitBuffer->pDraw = pDraw;
  }
  if ( item == prepareBuffer->pItem )
  {
    pPrepare = prepareBuffer->pPrepare;
    emitBuffer->pDraw = pPrepare;
  }
  else
  {
    pPrepare = this->Batches.Root.pPrev->pNext;
  }
  if ( this->ModifyIndex < this->Meshes.Data.Size )
    Scaleform::Render::Primitive::updateMeshIndicies_Impl(this);
  hal->DrawProcessedPrimitive(hal, this, pDraw, pPrepare);
}
