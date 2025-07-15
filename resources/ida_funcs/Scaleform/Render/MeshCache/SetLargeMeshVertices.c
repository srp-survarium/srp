char __thiscall Scaleform::Render::MeshCache::SetLargeMeshVertices(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCacheItem *pcacheItem,
        const Scaleform::Render::VertexFormat *pSourceFormat,
        unsigned int vertexOffset,
        unsigned __int8 *pvertices,
        unsigned int vertexCount,
        const Scaleform::Render::VertexFormat *pDestFormat,
        unsigned __int8 *pdestStart)
{
  Scaleform::Render::ConvertVertices_Buffered(
    pSourceFormat,
    pvertices,
    pDestFormat,
    &pdestStart[vertexOffset * pDestFormat->Size],
    vertexCount,
    0);
  return 1;
}
