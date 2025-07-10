Scaleform::Render::D3D1x::MeshCacheItem *__usercall Scaleform::Render::D3D1x::MeshCacheItem::Create@<eax>(
        unsigned int vertexAllocSize@<edi>,
        unsigned int vertexCount@<ecx>,
        unsigned int indexAllocSize@<esi>,
        Scaleform::Render::MeshCacheItem::MeshType type,
        Scaleform::Render::MeshCacheListSet *pcacheList,
        Scaleform::Render::MeshCacheItem::MeshBaseContent *mc,
        Scaleform::Render::D3D1x::VertexBuffer *pvb,
        Scaleform::Render::D3D1x::IndexBuffer *pib,
        unsigned int vertexOffset,
        unsigned int indexOffset,
        unsigned int indexCount)
{
  Scaleform::Render::D3D1x::MeshCacheItem *result; // eax

  result = (Scaleform::Render::D3D1x::MeshCacheItem *)Scaleform::Render::MeshCacheItem::Create(
                                                        type,
                                                        pcacheList,
                                                        0x50u,
                                                        mc,
                                                        vertexAllocSize + indexAllocSize,
                                                        vertexCount,
                                                        indexCount);
  if ( result )
  {
    result->pVertexBuffer = pvb;
    result->pIndexBuffer = pib;
    result->VBAllocOffset = vertexOffset;
    result->VBAllocSize = vertexAllocSize;
    result->IBAllocOffset = indexOffset;
    result->IBAllocSize = indexAllocSize;
  }
  return result;
}
