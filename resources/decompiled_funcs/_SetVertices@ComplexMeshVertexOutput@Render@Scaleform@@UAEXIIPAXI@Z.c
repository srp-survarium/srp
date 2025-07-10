void __thiscall Scaleform::Render::ComplexMeshVertexOutput::SetVertices(
        Scaleform::Render::ComplexMeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int vertexOffset,
        unsigned __int8 *vertices,
        unsigned int vertexCount)
{
  Scaleform::Render::ComplexMesh::FillRecord *v5; // edx

  if ( this->AllocState == Alloc_Success )
  {
    v5 = &this->pMesh->FillRecords.Data.Data[fillIndex];
    Scaleform::Render::ConvertVertices_Buffered(
      this->pFills[fillIndex].pFormat,
      vertices,
      v5->pFormats[0],
      &this->pVertexDataStart[v5->VertexByteOffset + vertexOffset * v5->pFormats[0]->Size],
      vertexCount,
      0);
  }
}
