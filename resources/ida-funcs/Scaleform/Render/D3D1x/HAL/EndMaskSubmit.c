void __thiscall Scaleform::Render::D3D1x::HAL::EndMaskSubmit(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // edi
  unsigned int Size; // eax
  Scaleform::Render::BlendMode v4; // eax
  Scaleform::String v5; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&v5, 0);
  v2 = this->GetEvent(this, 6);
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(v5.HeapTypeBits & 0xFFFFFFFC));
  this->Profiler.DrawMode = 0;
  if ( Scaleform::Render::HAL::checkState(
         this,
         0x48u,
         (Scaleform::GFx::AS3::Value *)"Scaleform::Render::D3D1x::HAL::EndMaskSubmit") )
  {
    Size = this->BlendModeStack.Data.Size;
    this->HALState &= ~0x40u;
    if ( Size )
      v4 = this->BlendModeStack.Data.Data[Size - 1];
    else
      v4 = Blend_Normal;
    Scaleform::Render::HAL::applyBlendMode(this, v4, 0, 0);
    if ( this->StencilAvailable )
    {
      this->pDeviceContext->OMSetDepthStencilState(
        this->pDeviceContext,
        this->DepthStencilStates[5],
        this->MaskStackTop);
    }
    else if ( this->DepthBufferAvailable )
    {
      this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[6], 0);
    }
  }
  v2->End(v2);
}
