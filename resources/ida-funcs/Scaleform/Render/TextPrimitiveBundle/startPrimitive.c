void __thiscall Scaleform::Render::TextPrimitiveBundle::startPrimitive(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::TextPrepareBuffer *prepareBuffer,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::TreeCacheText *v5; // ebx
  unsigned int i; // ebp
  Scaleform::Render::TreeCacheText *pSourceNode; // esi
  Scaleform::Render::TextMeshProvider *MeshProvider; // eax
  Scaleform::Render::HAL *pHAL; // ecx

  v5 = 0;
  for ( i = 0; i < this->Entries.Data.Size; ++i )
  {
    pSourceNode = (Scaleform::Render::TreeCacheText *)this->Entries.Data.Data[i]->pSourceNode;
    MeshProvider = Scaleform::Render::TreeCacheText::GetMeshProvider(pSourceNode);
    if ( MeshProvider && MeshProvider->pBundle == this )
    {
      Scaleform::Render::TextMeshProvider::AddToInUseList(MeshProvider);
    }
    else
    {
      pSourceNode->pNextNoBatch = v5;
      v5 = pSourceNode;
    }
  }
  pHAL = qp->pHAL;
  prepareBuffer->pItem = item;
  prepareBuffer->pEmitBuffer = (Scaleform::Render::TextEmitBuffer *)&qp->136;
  prepareBuffer->pHal = pHAL;
  prepareBuffer->pCache = pHAL->GetMeshCache(pHAL);
  prepareBuffer->pBundle = this;
  prepareBuffer->pRemainingTextFields = v5;
  prepareBuffer->ProcessingLayer = 0;
  prepareBuffer->LayersFinished = 0;
  prepareBuffer->LayersPinned = 0;
  prepareBuffer->PPBuffer.pItem = 0;
  Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(prepareBuffer, 1);
}
