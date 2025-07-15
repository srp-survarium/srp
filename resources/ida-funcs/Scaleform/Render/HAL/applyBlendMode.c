void __thiscall Scaleform::Render::HAL::applyBlendMode(
        Scaleform::Render::HAL *this,
        Scaleform::Render::BlendMode mode,
        BOOL sourceAc,
        Scaleform::String::DataDesc *forceAc)
{
  Scaleform::Render::RenderEvent *v5; // ebx
  Scaleform::Render::RenderEvent_vtbl *v6; // edi
  Scaleform::String::DataDesc *v7; // ecx
  void *v8; // edi
  Scaleform::Render::BlendMode OverrideBlend; // eax
  Scaleform::Render::HAL_vtbl *v10; // edi
  void (__thiscall *applyBlendModeImpl)(Scaleform::Render::HAL *, Scaleform::Render::BlendMode, bool, bool); // edx
  Scaleform::String v12; // [esp-4h] [ebp-14h] BYREF
  Scaleform::String src; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&src, (const __m128i *)"Scaleform::Render::HAL::applyBlendMode");
  v5 = this->GetEvent(this, 13);
  v6 = v5->__vftable;
  v12.pData = v7;
  Scaleform::String::String(&v12, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))v6->Begin)(v5, v12.pData);
  v8 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  OverrideBlend = mode;
  if ( (unsigned int)mode >= Blend_Count )
    OverrideBlend = Blend_None;
  if ( this->Profiler.OverrideBlend )
    OverrideBlend = this->Profiler.OverrideBlend;
  if ( OverrideBlend == Blend_Multiply || OverrideBlend == Blend_Darken )
    this->FillFlags |= 1u;
  else
    this->FillFlags &= ~1u;
  if ( OverrideBlend <= Blend_Normal )
    this->FillFlags &= ~0x10u;
  else
    this->FillFlags |= 0x10u;
  v10 = this->__vftable;
  v12.pData = forceAc;
  this->CurrentBlendState.SourceAc = sourceAc;
  this->CurrentBlendState.ForceAc = (char)forceAc;
  applyBlendModeImpl = v10->applyBlendModeImpl;
  this->CurrentBlendState.Mode = OverrideBlend;
  applyBlendModeImpl(this, OverrideBlend, sourceAc, (bool)v12.pData);
  v5->End(v5);
}
