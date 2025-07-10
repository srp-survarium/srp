Scaleform::Render::D3D1x::VertexBuffer *__thiscall Scaleform::Render::D3D1x::IndexBuffer::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::VertexBuffer *this,
        char a2)
{
  ID3D11Buffer *pObject; // eax

  pObject = this->pBuffer.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->__vftable = (Scaleform::Render::D3D1x::VertexBuffer_vtbl *)&Scaleform::Render::MeshBuffer::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
