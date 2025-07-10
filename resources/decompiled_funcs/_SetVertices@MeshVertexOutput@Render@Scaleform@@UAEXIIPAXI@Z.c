void __thiscall Scaleform::Render::MeshVertexOutput::SetVertices(
        Scaleform::Render::MeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int vertexOffset,
        unsigned __int8 *vertices,
        unsigned int vertexCount)
{
  if ( !fillIndex && this->Result.Value <= Success_LargeMesh )
  {
    if ( (this->Result.Value & 1) != 0 )
      this->pCache->SetLargeMeshVertices(
        this->pCache,
        this->batchData,
        this->pSourceFormat,
        vertexOffset,
        vertices,
        vertexCount,
        this->pSingleFormat,
        this->pVertexDataStart);
    else
      memcpy(
        &this->pCache->StagingBuffer.pBuffer[vertexOffset * this->pSourceFormat->Size + this->pMesh->StagingBufferOffset],
        vertices,
        vertexCount * this->pSourceFormat->Size);
  }
}
