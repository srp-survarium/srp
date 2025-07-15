Scaleform::Render::D3D1x::RenderSync *__thiscall Scaleform::Render::D3D1x::RenderSync::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::RenderSync *this,
        char a2)
{
  ID3D11DeviceContext *pObject; // eax
  ID3D11Device *v4; // eax

  pObject = this->pDeviceContext.pObject;
  if ( pObject )
    pObject->Release(pObject);
  v4 = this->pDevice.pObject;
  if ( v4 )
    v4->Release(this->pDevice.pObject);
  Scaleform::Render::RenderSync::~RenderSync(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
