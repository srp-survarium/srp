void __thiscall Scaleform::Render::MeshStagingBuffer::Reset(Scaleform::Render::MeshStagingBuffer *this)
{
  Scaleform::Render::MeshStagingNode *v2; // eax
  Scaleform::Render::MeshStagingNode *pNext; // ecx

  if ( this->pBuffer )
  {
    while ( 1 )
    {
      v2 = this == (Scaleform::Render::MeshStagingBuffer *)-16
         ? 0
         : (Scaleform::Render::MeshStagingNode *)&this->PinSizeLimit;
      if ( this->MeshList.Root.pNext == v2 )
        break;
      pNext = this->MeshList.Root.pNext;
      pNext->StagingBufferOffset = 0;
      pNext->StagingBufferIndexOffset = 0;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      pNext->OnStagingNodeEvict(pNext);
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pBuffer);
    this->pBuffer = 0;
    this->BufferSize = 0;
    this->TotalPinnedSize = 0;
  }
}
