int __thiscall Scaleform::Render::TextPrepareBuffer::ProcessPrimitive(
        Scaleform::Render::TextPrepareBuffer *this,
        BOOL waitForCache)
{
  Scaleform::Render::TextPrimitiveBundle *pBundle; // ecx
  $037AF80D9AEBE352D643A8853E25724C *v4; // eax
  Scaleform::Render::Primitive *v6; // [esp-18h] [ebp-24h]

  if ( this->LayersFinished )
  {
    pBundle = this->pBundle;
    this->PPBuffer.pItem = 0;
    Scaleform::Render::TextPrimitiveBundle::clearBatchLayers(pBundle);
    Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(this, 0);
    this->LayersFinished = 0;
    this->ProcessingLayer = 0;
  }
  if ( this->ProcessingLayer < this->pBundle->Layers.Size )
  {
    do
    {
      v4 = this->pBundle->Layers.Size <= 2
         ? &this->pBundle->Layers.4
         : ($037AF80D9AEBE352D643A8853E25724C *)this->pBundle->Layers.AD.pData;
      v6 = (Scaleform::Render::Primitive *)(&v4->AD.pData)[this->ProcessingLayer];
      if ( Scaleform::Render::Primitive::prepare(
             v6,
             v6,
             &this->PPBuffer,
             &this->pEmitBuffer->PEBuffer,
             this->pHal,
             this->pCache,
             waitForCache) == QIP_NeedCache )
        return 1;
    }
    while ( ++this->ProcessingLayer < this->pBundle->Layers.Size );
  }
  if ( this->LayersPinned )
  {
    Scaleform::Render::TextPrimitiveBundle::unpinLayerBatches(this->pBundle);
    this->LayersPinned = 0;
  }
  if ( this->pRemainingTextFields )
  {
    this->LayersFinished = 1;
    return 1;
  }
  return 0;
}
