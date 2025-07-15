void __thiscall Scaleform::Render::D3D1x::HAL::applyBlendModeImpl(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::BlendMode mode,
        bool sourceAc,
        bool forceAc)
{
  Scaleform::Render::RenderEvent *v5; // eax
  int v6; // ecx
  Scaleform::String v7; // [esp-8h] [ebp-14h] BYREF
  BOOL v8; // [esp-4h] [ebp-10h]
  Scaleform::Render::ScopedRenderEvent v9; // [esp+8h] [ebp-4h] BYREF

  v8 = 1;
  v7.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(&v7, "Scaleform::Render::D3D1x::HAL::applyBlendModeImpl");
  v5 = this->GetEvent(this, 13);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v9, v5, v7, v8);
  if ( this->pDeviceContext )
  {
    v6 = 0;
    if ( sourceAc )
      v6 = 18;
    this->pDeviceContext->OMSetBlendState(this->pDeviceContext, (&this->BlendStates[mode])[v6], 0, -1u);
  }
  v9.EventObj->End(v9.EventObj);
}
