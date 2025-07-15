void __thiscall Scaleform::Render::D3D1x::RenderSync::BeginFrame(Scaleform::Render::D3D1x::RenderSync *this)
{
  ID3D11Device *pObject; // ecx
  D3D11_QUERY_DESC v3; // [esp+4h] [ebp-8h] BYREF

  pObject = this->pDevice.pObject;
  if ( pObject )
  {
    v3.MiscFlags = 0;
    v3.Query = D3D11_QUERY_EVENT;
    if ( pObject->CreateQuery(pObject, &v3, &this->pNextEndFrameFence) < 0 )
      this->pNextEndFrameFence = 0;
    Scaleform::Render::RenderSync::BeginFrame(this);
  }
}
