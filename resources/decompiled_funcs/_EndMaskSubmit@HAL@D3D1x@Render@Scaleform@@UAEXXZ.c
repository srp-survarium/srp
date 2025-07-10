void __thiscall Scaleform::Render::D3D1x::HAL::EndMaskSubmit(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // ebx
  void *v3; // edi
  unsigned int Size; // eax
  Scaleform::Render::BlendMode v5; // eax
  Scaleform::String v6; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&v6, 0);
  v2 = this->GetEvent(this, 6);
  v3 = (void *)(v6.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v6.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( (this->HALState & 0x48) == 0x48 )
  {
    this->HALState &= ~0x40u;
    Size = this->BlendModeStack.Data.Size;
    if ( Size )
      v5 = this->BlendModeStack.Data.Data[Size - 1];
    else
      v5 = Blend_Normal;
    Scaleform::Render::HAL::applyBlendMode(this, v5, 0, 0);
    if ( this->StencilAvailable )
    {
      this->pDeviceContext->OMSetDepthStencilState(
        this->pDeviceContext,
        this->DepthStencilStates[5],
        this->MaskStackTop);
      v2->End(v2);
    }
    else
    {
      if ( this->DepthBufferAvailable )
        this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[6], 0);
      v2->End(v2);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Object::SetValue(
      (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this,
      0x48u,
      &stru_973F24);
    v2->End(v2);
  }
}
