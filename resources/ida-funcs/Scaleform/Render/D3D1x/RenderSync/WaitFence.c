void __thiscall Scaleform::Render::D3D1x::RenderSync::WaitFence(
        Scaleform::Render::D3D1x::RenderSync *this,
        Scaleform::Render::FenceType waitType,
        unsigned __int64 handle,
        const Scaleform::Render::FenceFrame *parent)
{
  ID3D11Query **p_pNextEndFrameFence; // ebx
  ID3D11Device *pObject; // eax
  HRESULT i; // eax
  D3D11_QUERY_DESC v8; // [esp+8h] [ebp-8h] BYREF
  ID3D11Asynchronous *v9; // [esp+20h] [ebp+10h]

  v9 = (ID3D11Asynchronous *)handle;
  if ( (_DWORD)handle )
  {
    p_pNextEndFrameFence = &this->pNextEndFrameFence;
    if ( (ID3D11Query *)handle == this->pNextEndFrameFence )
    {
      this->pDeviceContext.pObject->End(this->pDeviceContext.pObject, this->pNextEndFrameFence);
      v9 = *p_pNextEndFrameFence;
      v8.Query = D3D11_QUERY_EVENT;
      v8.MiscFlags = 0;
      pObject = this->pDevice.pObject;
      v8.Query = D3D11_QUERY_EVENT;
      if ( pObject->CreateQuery(pObject, &v8, &this->pNextEndFrameFence) < 0 )
        *p_pNextEndFrameFence = 0;
    }
    for ( i = this->pDeviceContext.pObject->GetData(this->pDeviceContext.pObject, v9, 0, 0, 0);
          i;
          i = this->pDeviceContext.pObject->GetData(this->pDeviceContext.pObject, v9, 0, 0, 0) )
    {
      Scaleform::Thread::Sleep(0);
    }
  }
}
