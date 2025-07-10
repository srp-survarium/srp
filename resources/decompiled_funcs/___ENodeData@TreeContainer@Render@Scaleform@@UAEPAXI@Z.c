Scaleform::Render::TreeRoot::NodeData *__thiscall Scaleform::Render::TreeContainer::NodeData::`vector deleting destructor'(
        Scaleform::Render::TreeRoot::NodeData *this,
        char a2)
{
  void *v3; // esi

  if ( ((int)this->Children.pNodes[0] & 1) != 0 )
  {
    v3 = (void *)(this->Children.pData[0] & 0xFFFFFFFE);
    if ( InterlockedExchangeAdd((volatile LONG *)v3, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  if ( this->States.ArraySize )
    Scaleform::Render::StateData::destroyBag_NotEmpty(&this->States);
  Scaleform::Render::ContextImpl::EntryData::~EntryData(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
