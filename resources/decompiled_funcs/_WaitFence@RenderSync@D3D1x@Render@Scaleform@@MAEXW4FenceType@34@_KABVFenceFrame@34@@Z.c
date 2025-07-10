void __thiscall Scaleform::Render::D3D1x::RenderSync::WaitFence(
        Scaleform::Render::D3D1x::RenderSync *this,
        Scaleform::Render::FenceType waitType,
        D3D11_QUERY_DESC handle,
        const Scaleform::Render::FenceFrame *parent)
{
  ID3D11Asynchronous *Query; // ebx
  ID3D11Query *pNextEndFrameFence; // ecx
  ID3D11Query **p_pNextEndFrameFence; // edi
  ID3D11Device *pObject; // eax

  Query = (ID3D11Asynchronous *)handle.Query;
  if ( handle.Query )
  {
    pNextEndFrameFence = this->pNextEndFrameFence;
    p_pNextEndFrameFence = &this->pNextEndFrameFence;
    if ( (ID3D11Query *)handle.Query == pNextEndFrameFence )
    {
      this->pDeviceContext.pObject->End(this->pDeviceContext.pObject, pNextEndFrameFence);
      pObject = this->pDevice.pObject;
      Query = *p_pNextEndFrameFence;
      handle = 0;
      if ( pObject->CreateQuery(pObject, &handle, &this->pNextEndFrameFence) < 0 )
        *p_pNextEndFrameFence = 0;
    }
    while ( this->pDeviceContext.pObject->GetData(this->pDeviceContext.pObject, Query, 0, 0, 0) )
      Scaleform::Thread::Sleep(0);
  }
}
