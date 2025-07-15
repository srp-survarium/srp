void __thiscall Scaleform::Render::Palette::Release(Scaleform::Render::Palette *this)
{
  if ( InterlockedExchangeAdd(&this->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
}
