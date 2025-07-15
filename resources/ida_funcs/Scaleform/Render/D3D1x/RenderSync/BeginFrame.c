void __thiscall Scaleform::Render::D3D1x::RenderSync::BeginFrame(Scaleform::Render::D3D1x::RenderSync *this)
{
  ID3D11Device *pObject; // eax
  ID3D11Query **p_pNextEndFrameFence; // esi
  D3D11_QUERY_DESC desc; // [esp+4h] [ebp-8h] BYREF

  pObject = this->pDevice.pObject;
  if ( pObject )
  {
    p_pNextEndFrameFence = &this->pNextEndFrameFence;
    desc.MiscFlags = 0;
    desc.Query = D3D11_QUERY_EVENT;
    if ( pObject->CreateQuery(pObject, &desc, &this->pNextEndFrameFence) < 0 )
      *p_pNextEndFrameFence = 0;
    Scaleform::Render::RenderSync::BeginFrame(this);
  }
}
