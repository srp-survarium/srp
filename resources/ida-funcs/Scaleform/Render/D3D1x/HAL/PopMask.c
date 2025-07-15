void __thiscall Scaleform::Render::D3D1x::HAL::PopMask(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // eax
  Scaleform::Render::HAL::MaskStackEntry *v3; // eax
  ID3D11DeviceContext *pDeviceContext; // eax
  Scaleform::String v5; // [esp-8h] [ebp-18h] BYREF
  unsigned int MaskStackTop; // [esp-4h] [ebp-14h]
  Scaleform::Render::ScopedRenderEvent v7; // [esp+Ch] [ebp-4h] BYREF

  MaskStackTop = 1;
  v5.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(&v5, "Scaleform::Render::D3D1x::HAL::PopMask");
  v2 = this->GetEvent(this, 7);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v7, v2, v5, MaskStackTop);
  if ( Scaleform::Render::HAL::checkState(
         this,
         8u,
         (Scaleform::GFx::AS3::Value *)"Scaleform::Render::D3D1x::HAL::PopMask")
    && (this->StencilAvailable || this->DepthBufferAvailable) )
  {
    v3 = &this->MaskStack.Data.Data[--this->MaskStackTop];
    if ( v3->pPrimitive.pObject->Type == Mask_Clipped )
    {
      Scaleform::Render::Rect<int>::SetRect(&this->ViewRect, &v3->OldViewRect);
      if ( this->MaskStack.Data.Data[this->MaskStackTop].OldViewportValid )
        this->HALState |= 0x20u;
      else
        this->HALState &= ~0x20u;
      this->updateViewport(this);
    }
    if ( this->StencilAvailable )
    {
      pDeviceContext = this->pDeviceContext;
      if ( !this->MaskStackTop )
      {
        MaskStackTop = 0;
        v5.pData = (Scaleform::String::DataDesc *)this->DepthStencilStates[0];
LABEL_15:
        pDeviceContext->OMSetDepthStencilState(pDeviceContext, (ID3D11DepthStencilState *)v5.pData, MaskStackTop);
        goto LABEL_16;
      }
      pDeviceContext->OMSetDepthStencilState(pDeviceContext, this->DepthStencilStates[5], this->MaskStackTop);
    }
    else if ( this->DepthBufferAvailable )
    {
      MaskStackTop = this->MaskStackTop;
      pDeviceContext = this->pDeviceContext;
      v5.pData = (Scaleform::String::DataDesc *)this->DepthStencilStates[6];
      goto LABEL_15;
    }
  }
LABEL_16:
  v7.EventObj->End(v7.EventObj);
}
