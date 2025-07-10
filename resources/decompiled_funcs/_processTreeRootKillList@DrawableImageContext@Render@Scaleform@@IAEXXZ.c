void __thiscall Scaleform::Render::DrawableImageContext::processTreeRootKillList(
        Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Lock *p_TreeRootKillListLock; // ebp
  unsigned int i; // edi
  Scaleform::Render::TreeRoot *v4; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_TreeRootKillList; // esi

  if ( !this->RContext )
    return;
  p_TreeRootKillListLock = &this->TreeRootKillListLock;
  EnterCriticalSection(&this->TreeRootKillListLock.cs);
  for ( i = 0; i < this->TreeRootKillList.Data.Size; ++i )
  {
    v4 = this->TreeRootKillList.Data.Data[i];
    if ( v4->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
  p_TreeRootKillList = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->TreeRootKillList;
  if ( !p_TreeRootKillList->Size )
  {
    if ( !p_TreeRootKillList->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_TreeRootKillList,
        p_TreeRootKillList,
        0);
    goto LABEL_13;
  }
  if ( (p_TreeRootKillList->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_13:
    p_TreeRootKillList->Size = 0;
    LeaveCriticalSection(&p_TreeRootKillListLock->cs);
    return;
  }
  if ( p_TreeRootKillList->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_TreeRootKillList->Data);
    p_TreeRootKillList->Data = 0;
  }
  p_TreeRootKillList->Policy.Capacity = 0;
  p_TreeRootKillList->Size = 0;
  LeaveCriticalSection(&p_TreeRootKillListLock->cs);
}
