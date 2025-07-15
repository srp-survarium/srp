char __thiscall Scaleform::Render::MeshCache::SetLargeMeshIndices(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCacheItem *pcacheItem,
        const Scaleform::Render::VertexFormat *pSourceFormat,
        unsigned int indexOffset,
        const __m128i *pindices,
        unsigned int indexCount,
        const Scaleform::Render::VertexFormat *pDestFormat,
        unsigned __int8 *pdestIndex)
{
  memcpy((int)&pdestIndex[2 * indexOffset], pindices, 2 * indexCount);
  return 1;
}
