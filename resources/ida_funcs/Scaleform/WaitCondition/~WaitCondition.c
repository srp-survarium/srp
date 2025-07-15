void __thiscall Scaleform::WaitCondition::~WaitCondition(Scaleform::WaitCondition *this)
{
  Scaleform::WaitConditionImpl *pImpl; // esi

  pImpl = this->pImpl;
  if ( this->pImpl )
  {
    Scaleform::WaitConditionImpl::~WaitConditionImpl(this->pImpl);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
}
