void __thiscall Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::Unlock(
        Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer> *this,
        ID3D11DeviceContext *pcontext)
{
  pcontext->Unmap(pcontext, this->pBuffer.pObject, 0);
  this->pData = 0;
}
