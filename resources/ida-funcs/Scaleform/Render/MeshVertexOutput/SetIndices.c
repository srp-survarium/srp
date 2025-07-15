void __thiscall Scaleform::Render::MeshVertexOutput::SetIndices(
        Scaleform::Render::MeshVertexOutput *this,
        unsigned int fillIndex,
        unsigned int indexOffset,
        const __m128i *indices,
        unsigned int indexCount)
{
  if ( !fillIndex && this->Result.Value <= Success_LargeMesh )
  {
    if ( (this->Result.Value & 1) != 0 )
      this->pCache->SetLargeMeshIndices(
        this->pCache,
        this->batchData,
        this->pSourceFormat,
        indexOffset,
        (const unsigned __int16 *)indices,
        indexCount,
        this->pSingleFormat,
        (unsigned __int8 *)this->pIndexDataStart);
    else
      memcpy(
        (int)&this->pCache->StagingBuffer.pBuffer[2 * indexOffset + this->pMesh->StagingBufferIndexOffset],
        indices,
        2 * indexCount);
  }
}
