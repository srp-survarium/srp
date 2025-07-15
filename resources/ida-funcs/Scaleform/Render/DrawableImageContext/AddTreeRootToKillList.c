void __thiscall Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *proot)
{
  Scaleform::Lock *p_TreeRootKillListLock; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_TreeRootKillList; // edi
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v6; // eax

  p_TreeRootKillListLock = &this->TreeRootKillListLock;
  EnterCriticalSection(&this->TreeRootKillListLock.cs);
  p_TreeRootKillList = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->TreeRootKillList;
  v5 = this->TreeRootKillList.Data.Size + 1;
  if ( v5 >= p_TreeRootKillList->Size )
  {
    if ( v5 >= p_TreeRootKillList->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_TreeRootKillList,
        p_TreeRootKillList,
        v5 + (v5 >> 2));
  }
  else if ( v5 < p_TreeRootKillList->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_TreeRootKillList,
      p_TreeRootKillList,
      v5);
  }
  v6 = &p_TreeRootKillList->Data[v5 - 1];
  p_TreeRootKillList->Size = v5;
  if ( v6 )
    v6->pObject = proot;
  LeaveCriticalSection(&p_TreeRootKillListLock->cs);
}
