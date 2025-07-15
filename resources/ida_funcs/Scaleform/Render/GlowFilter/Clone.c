Scaleform::Render::Filter *__thiscall Scaleform::Render::GlowFilter::Clone(
        Scaleform::Render::GlowFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // eax
  int v4; // eax
  int v5; // esi

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (int)v2->Alloc(v2, 60u, 0);
  v5 = v4;
  if ( !v4 )
    return 0;
  *(_DWORD *)v4 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(v4 + 4) = 1;
  *(_DWORD *)(v4 + 8) = 2;
  *(_BYTE *)(v4 + 12) = 0;
  *(_DWORD *)v4 = &Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams((Scaleform::Render::BlurFilterParams *)(v4 + 16), &this->Params);
  *(float *)(v5 + 52) = 0.0;
  *(float *)(v5 + 56) = 0.0;
  *(_DWORD *)v5 = &Scaleform::Render::GlowFilter::`vftable';
  return (Scaleform::Render::Filter *)v5;
}
