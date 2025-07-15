void __thiscall Scaleform::Render::ShadowFilter::Clone(
        Scaleform::Render::ShadowFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // eax
  Scaleform::Render::ShadowFilter *v4; // eax
  float heapa; // [esp+1Ch] [ebp+4h]

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::ShadowFilter *)v2->Alloc(v2, 60u, 0);
  if ( v4 )
  {
    heapa = this->Distance * 0.05000000074505806;
    Scaleform::Render::ShadowFilter::ShadowFilter(v4, &this->Params, this->Angle, heapa);
  }
}
