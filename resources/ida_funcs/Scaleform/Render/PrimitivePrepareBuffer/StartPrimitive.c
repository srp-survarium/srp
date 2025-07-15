void __thiscall Scaleform::Render::PrimitivePrepareBuffer::StartPrimitive(
        Scaleform::Render::PrimitivePrepareBuffer *this,
        void *item,
        Scaleform::Render::Primitive *p,
        Scaleform::Render::PrimitiveEmitBuffer *emitBuffer,
        Scaleform::Render::HAL *hal,
        Scaleform::Render::MeshCache *cache)
{
  const Scaleform::Render::VertexFormat *pFormat; // eax
  Scaleform::Render::PrimitiveBatch *pNext; // edi

  this->pEmitBuffer = emitBuffer;
  this->pItem = item;
  this->pHal = hal;
  this->pCache = cache;
  this->pPrimitive = p;
  pFormat = p->pFill.pObject->Data.pFormat;
  this->pSourceVFormat = pFormat;
  if ( pFormat )
  {
    hal->MapVertexFormat(
      hal,
      p->pFill.pObject->Data.Type,
      pFormat,
      &this->pSingleVFormat,
      &this->pBatchVFormat,
      &this->pInstancedVFormat,
      0);
  }
  else
  {
    this->pInstancedVFormat = 0;
    this->pBatchVFormat = 0;
    this->pSingleVFormat = 0;
  }
  this->State = PS_Loop;
  pNext = p->Batches.Root.pNext;
  this->pConvert = pNext;
  this->pPrepareTail = pNext;
  this->pPrepare = pNext;
  this->Converting = 0;
}
