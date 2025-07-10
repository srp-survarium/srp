void __thiscall Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::operator=(
        Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> > *this,
        const Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeRef *src)
{
  const Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *pSecond; // eax
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *p_Second; // esi
  bool Owner; // bl
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *pObject; // ebp
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // edi

  this->First = *src->pFirst;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  if ( &this->Second != pSecond )
  {
    Owner = pSecond->Owner;
    pObject = pSecond->pObject;
    pSecond->Owner = 0;
    p_Data = &p_Second->pObject->Data;
    if ( p_Second->pObject != pObject )
    {
      if ( p_Data )
      {
        if ( this->Second.Owner )
        {
          this->Second.Owner = 0;
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>(p_Data);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Data);
        }
      }
      p_Second->pObject = pObject;
    }
    p_Second->Owner = Owner;
  }
}
