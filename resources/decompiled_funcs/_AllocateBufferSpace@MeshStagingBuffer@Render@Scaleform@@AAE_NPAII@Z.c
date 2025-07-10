char __thiscall Scaleform::Render::MeshStagingBuffer::AllocateBufferSpace(
        Scaleform::Render::MeshStagingBuffer *this,
        unsigned int *poffset,
        unsigned int size)
{
  Scaleform::List<Scaleform::Render::MeshStagingNode,Scaleform::Render::MeshStagingNode> *p_MeshList; // ebx
  Scaleform::Render::MeshStagingNode *v6; // eax
  Scaleform::Render::MeshStagingNode *pPrev; // esi
  unsigned int v8; // eax
  unsigned int StagingBufferOffset; // ecx
  unsigned int v10; // edi

  if ( size > this->PinSizeLimit )
    return 0;
  p_MeshList = &this->MeshList;
  while ( 1 )
  {
    v6 = this == (Scaleform::Render::MeshStagingBuffer *)-16
       ? 0
       : (Scaleform::Render::MeshStagingNode *)&this->PinSizeLimit;
    if ( this->MeshList.Root.pNext == v6 )
      break;
    pPrev = p_MeshList->Root.pPrev;
    v8 = this->MeshList.Root.pNext->StagingBufferSize + this->MeshList.Root.pNext->StagingBufferOffset;
    StagingBufferOffset = p_MeshList->Root.pPrev->StagingBufferOffset;
    if ( v8 > StagingBufferOffset )
    {
      if ( this->BufferSize - v8 >= size )
      {
        *poffset = v8;
        return 1;
      }
      v10 = p_MeshList->Root.pPrev->StagingBufferOffset;
    }
    else
    {
      v10 = StagingBufferOffset - v8;
    }
    if ( v10 >= size )
    {
      *poffset = StagingBufferOffset - v10;
      return 1;
    }
    pPrev->pPrev->pNext = pPrev->pNext;
    pPrev->pNext->pPrev = pPrev->pPrev;
    if ( pPrev->PinCount )
    {
      if ( v10 )
      {
        memmove(
          &this->pBuffer[pPrev->StagingBufferOffset - v10],
          &this->pBuffer[pPrev->StagingBufferOffset],
          pPrev->StagingBufferSize);
        pPrev->StagingBufferIndexOffset -= v10;
        pPrev->StagingBufferOffset -= v10;
      }
      pPrev->pNext = this->MeshList.Root.pNext;
      pPrev->pPrev = (Scaleform::Render::MeshStagingNode *)&this->PinSizeLimit;
      this->MeshList.Root.pNext->pPrev = pPrev;
      this->MeshList.Root.pNext = pPrev;
    }
    else
    {
      pPrev->OnStagingNodeEvict(pPrev);
    }
  }
  *poffset = 0;
  return 1;
}
