void __thiscall Scaleform::Render::D3D1x::HAL::PopMask(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // ebx
  Scaleform::Render::RenderEvent_vtbl *v3; // edi
  Scaleform::String::DataDesc *v4; // ecx
  void *v5; // edi
  Scaleform::Render::HAL::MaskStackEntry *v6; // eax
  int y2; // ecx
  int x2; // edx
  int y1; // edi
  int x1; // eax
  ID3D11DeviceContext *pDeviceContext; // eax
  ID3D11DepthStencilState *v12; // edx
  Scaleform::String v13; // [esp-4h] [ebp-14h] BYREF
  Scaleform::String src; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&src, (char *)&stru_973F54);
  v2 = this->GetEvent(this, 7);
  v3 = v2->__vftable;
  v13.pData = v4;
  Scaleform::String::String(&v13, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))v3->Begin)(v2, v13.pData);
  v5 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  if ( (this->HALState & 8) == 0 )
  {
    Scaleform::GFx::AS2::Object::SetValue((Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this, 8u, &stru_973F54);
    v2->End(v2);
    return;
  }
  if ( !this->StencilAvailable && !this->DepthBufferAvailable )
    goto LABEL_19;
  v6 = &this->MaskStack.Data.Data[--this->MaskStackTop];
  if ( v6->pPrimitive.pObject->Type == Mask_Clipped )
  {
    y2 = v6->OldViewRect.y2;
    x2 = v6->OldViewRect.x2;
    y1 = v6->OldViewRect.y1;
    x1 = v6->OldViewRect.x1;
    this->ViewRect.y2 = y2;
    this->ViewRect.x1 = x1;
    this->ViewRect.y1 = y1;
    this->ViewRect.x2 = x2;
    if ( this->MaskStack.Data.Data[this->MaskStackTop].OldViewportValid )
      this->HALState |= 0x20u;
    else
      this->HALState &= ~0x20u;
    this->updateViewport(this);
  }
  if ( this->StencilAvailable )
  {
    pDeviceContext = this->pDeviceContext;
    if ( this->MaskStackTop )
    {
      pDeviceContext->OMSetDepthStencilState(pDeviceContext, this->DepthStencilStates[5], this->MaskStackTop);
      v2->End(v2);
      return;
    }
    v12 = this->DepthStencilStates[0];
    v13.pData = 0;
    goto LABEL_18;
  }
  if ( this->DepthBufferAvailable )
  {
    pDeviceContext = this->pDeviceContext;
    v13.pData = (Scaleform::String::DataDesc *)this->MaskStackTop;
    v12 = this->DepthStencilStates[6];
LABEL_18:
    pDeviceContext->OMSetDepthStencilState(pDeviceContext, v12, v13.HeapTypeBits);
  }
LABEL_19:
  v2->End(v2);
}
