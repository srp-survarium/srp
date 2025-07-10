void __thiscall Scaleform::Render::ComplexMeshVertexOutput::SetIndices(
        Scaleform::Render::ComplexMeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int indexOffset,
        unsigned __int8 *indices,
        unsigned int indexCount)
{
  if ( this->AllocState == Alloc_Success )
    memcpy(
      (unsigned __int8 *)&this->pIndexDataStart[indexOffset + this->pMesh->FillRecords.Data.Data[fillIndex].IndexOffset],
      indices,
      2 * indexCount);
}
