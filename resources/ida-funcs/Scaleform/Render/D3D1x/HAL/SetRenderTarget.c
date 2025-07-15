char __thiscall Scaleform::Render::D3D1x::HAL::SetRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::RenderTarget *ptarget,
        bool setState)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // eax
  Scaleform::Render::RenderTarget *pObject; // ecx
  bool v7; // zf
  Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *v8; // [esp+Ch] [ebp-2F4h] BYREF
  Scaleform::Render::HAL::RenderTargetEntry __that; // [esp+10h] [ebp-2F0h] BYREF

  if ( (this->HALState & 4) != 0 )
    this->Flush(this);
  if ( (this->HALState & 8) != 0 )
    return 0;
  Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(&__that);
  pRenderTargetData = ptarget->pRenderTargetData;
  v8 = pRenderTargetData[1].__vftable;
  if ( setState )
    this->pDeviceContext->OMSetRenderTargets(
      this->pDeviceContext,
      1u,
      (ID3D11RenderTargetView *const *)&v8,
      (ID3D11DepthStencilView *)pRenderTargetData[1].pBuffer);
  ptarget->AddRef(ptarget);
  pObject = __that.pRenderTarget.pObject;
  if ( __that.pRenderTarget.pObject )
    __that.pRenderTarget.pObject->Release(__that.pRenderTarget.pObject);
  v7 = this->RenderTargetStack.Data.Size == 0;
  __that.pRenderTarget.pObject = ptarget;
  if ( v7 )
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::PushBack(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > > *)pObject,
      &this->RenderTargetStack.Data,
      &__that);
  else
    Scaleform::Render::HAL::RenderTargetEntry::operator=(&__that, this->RenderTargetStack.Data.Data);
  Scaleform::Render::HAL::RenderTargetEntry::~RenderTargetEntry(&__that);
  return 1;
}
