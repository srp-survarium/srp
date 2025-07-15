void __thiscall Scaleform::Render::BevelFilter::Clone(
        Scaleform::Render::BevelFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // eax
  Scaleform::Render::BevelFilter *v4; // eax
  float dist; // [esp+1Ch] [ebp+4h]

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::BevelFilter *)v2->Alloc(v2, 60u, 0);
  if ( v4 )
  {
    dist = this->Distance * 0.05000000074505806;
    Scaleform::Render::BevelFilter::BevelFilter(v4, &this->Params, this->Angle, dist);
  }
}
