void __thiscall Scaleform::Render::ComplexMeshVertexOutput::SetIndices(
        Scaleform::Render::ComplexMeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int indexOffset,
        const __m128i *indices,
        unsigned int indexCount)
{
  if ( this->AllocState == Alloc_Success )
    memcpy(
      (int)&this->pIndexDataStart[indexOffset + this->pMesh->FillRecords.Data.Data[fillIndex].IndexOffset],
      indices,
      2 * indexCount);
}
