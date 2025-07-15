void __thiscall Scaleform::String::DataDesc::Release(Scaleform::String::DataDesc *this)
{
  if ( InterlockedExchangeAdd(&this->RefCount, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
}
