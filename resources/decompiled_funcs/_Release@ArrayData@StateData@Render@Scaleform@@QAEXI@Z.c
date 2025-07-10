void __thiscall Scaleform::Render::StateData::ArrayData::Release(
        Scaleform::Render::StateData::ArrayData *this,
        unsigned int count)
{
  unsigned int v3; // edi
  Scaleform::Render::StateData::ArrayData *i; // esi

  if ( InterlockedExchangeAdd(&this->RefCount, -1) == 1 )
  {
    v3 = count;
    for ( i = this + 1; v3; i += 2 )
    {
      (*(void (__thiscall **)(volatile int, volatile int, int))(*(_DWORD *)i->RefCount + 8))(
        i->RefCount,
        i[1].RefCount,
        1);
      --v3;
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}
