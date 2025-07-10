char __thiscall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::DoLock(
        Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer> *this,
        ID3D11DeviceContext *pcontext)
{
  D3D11_MAPPED_SUBRESOURCE *p_MappedBuffer; // edi

  p_MappedBuffer = &this->MappedBuffer;
  if ( pcontext->Map(pcontext, this->pBuffer.pObject, 0, D3D11_MAP_WRITE_NO_OVERWRITE, 0, &this->MappedBuffer) < 0 )
    return 0;
  this->pData = p_MappedBuffer->pData;
  return 1;
}
