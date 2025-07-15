void __thiscall Scaleform::Render::D3D1x::HAL::applyBlendModeImpl(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::BlendMode mode,
        bool sourceAc,
        bool forceAc)
{
  Scaleform::Render::RenderEvent *v5; // edi
  Scaleform::Render::RenderEvent_vtbl *v6; // ebx
  Scaleform::String::DataDesc *v7; // ecx
  void *v8; // ebx
  int v9; // ecx
  Scaleform::String v10; // [esp-4h] [ebp-14h] BYREF
  Scaleform::String src; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&src, "Scaleform::Render::D3D1x::HAL::applyBlendModeImpl");
  v5 = this->GetEvent(this, 13);
  v6 = v5->__vftable;
  v10.pData = v7;
  Scaleform::String::String(&v10, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))v6->Begin)(v5, v10.pData);
  v8 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  if ( this->pDeviceContext )
  {
    v9 = 0;
    if ( sourceAc )
      v9 = 18;
    this->pDeviceContext->OMSetBlendState(this->pDeviceContext, (&this->BlendStates[mode])[v9], 0, -1u);
    v5->End(v5);
  }
  else
  {
    v5->End(v5);
  }
}
