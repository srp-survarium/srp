char __thiscall Scaleform::Render::D3D1x::HAL::SetRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::RenderTarget *ptarget,
        bool setState)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx
  bool v6; // zf
  unsigned int Size; // edx
  Scaleform::ArrayLH<Scaleform::Render::HAL::RenderTargetEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_RenderTargetStack; // esi
  int v9; // eax
  Scaleform::Render::RenderBuffer::RenderTargetData_vtbl *v10; // [esp+5F0h] [ebp-2F4h] BYREF
  Scaleform::Render::HAL::RenderTargetEntry __that; // [esp+5F4h] [ebp-2F0h] BYREF

  if ( (this->HALState & 4) != 0 )
    this->Flush(this);
  if ( (this->HALState & 8) != 0 )
    return 0;
  Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(&__that);
  pRenderTargetData = ptarget->pRenderTargetData;
  v10 = pRenderTargetData[1].__vftable;
  if ( setState )
    this->pDeviceContext->OMSetRenderTargets(
      this->pDeviceContext,
      1u,
      (ID3D11RenderTargetView *const *)&v10,
      (ID3D11DepthStencilView *)pRenderTargetData[1].pBuffer);
  ptarget->AddRef(ptarget);
  if ( __that.pRenderTarget.pObject )
    __that.pRenderTarget.pObject->Release(__that.pRenderTarget.pObject);
  v6 = this->RenderTargetStack.Data.Size == 0;
  __that.pRenderTarget.pObject = ptarget;
  if ( v6 )
  {
    Size = this->RenderTargetStack.Data.Size;
    p_RenderTargetStack = &this->RenderTargetStack;
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &p_RenderTargetStack->Data,
      p_RenderTargetStack,
      Size + 1);
    v9 = p_RenderTargetStack->Data.Size;
    if ( &p_RenderTargetStack->Data.Data[v9] != (Scaleform::Render::HAL::RenderTargetEntry *)752 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(&p_RenderTargetStack->Data.Data[v9 - 1], &__that);
  }
  else
  {
    Scaleform::Render::HAL::RenderTargetEntry::operator=(
      this->RenderTargetStack.Data.Data,
      this->RenderTargetStack.Data.Data,
      &__that);
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(&__that.OldMatrixState);
  if ( __that.pRenderTarget.pObject )
    __that.pRenderTarget.pObject->Release(__that.pRenderTarget.pObject);
  return 1;
}
