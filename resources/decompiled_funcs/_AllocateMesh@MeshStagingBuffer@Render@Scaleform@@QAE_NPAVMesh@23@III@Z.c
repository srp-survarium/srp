char __thiscall Scaleform::Render::MeshStagingBuffer::AllocateMesh(
        Scaleform::Render::MeshStagingBuffer *this,
        Scaleform::Render::Mesh *pmesh,
        unsigned int vertexCount,
        unsigned int vertexSize,
        unsigned int indexCount)
{
  unsigned int v5; // ebp
  unsigned int v6; // edi
  unsigned int v8; // ebx
  char result; // al
  unsigned int v10; // ecx
  unsigned int v11; // edx

  v5 = vertexCount;
  v6 = vertexSize * vertexCount;
  v8 = (vertexSize * vertexCount + 2 * indexCount + 15) & 0xFFFFFFF0;
  result = Scaleform::Render::MeshStagingBuffer::AllocateBufferSpace(this, &vertexCount, v8);
  if ( result )
  {
    v10 = vertexCount;
    v11 = indexCount;
    pmesh->StagingBufferOffset = vertexCount;
    pmesh->StagingBufferSize = v8;
    pmesh->VertexCount = v5;
    pmesh->IndexCount = v11;
    pmesh->StagingBufferIndexOffset = v6 + v10;
    pmesh->pNext = this->MeshList.Root.pNext;
    pmesh->pPrev = (Scaleform::Render::MeshStagingNode *)&this->PinSizeLimit;
    this->MeshList.Root.pNext->pPrev = &pmesh->Scaleform::Render::MeshStagingNode;
    this->MeshList.Root.pNext = &pmesh->Scaleform::Render::MeshStagingNode;
    return 1;
  }
  return result;
}
