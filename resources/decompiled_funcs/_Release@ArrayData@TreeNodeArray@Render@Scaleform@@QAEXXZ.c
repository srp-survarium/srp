void __thiscall Scaleform::Render::TreeNodeArray::ArrayData::Release(Scaleform::Render::TreeNodeArray::ArrayData *this)
{
  if ( InterlockedExchangeAdd(&this->RefCount, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
}
