Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> > *__thiscall Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::operator=(
        Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> > *this,
        const Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> > *__that)
{
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *p_Second; // esi
  bool Owner; // dl
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *pObject; // ebp
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // edi
  bool __thata; // [esp+Ch] [ebp+4h]

  p_Second = &this->Second;
  this->First = __that->First;
  if ( &this->Second != &__that->Second )
  {
    Owner = __that->Second.Owner;
    pObject = __that->Second.pObject;
    __that->Second.Owner = 0;
    p_Data = &p_Second->pObject->Data;
    __thata = Owner;
    if ( p_Second->pObject != pObject )
    {
      if ( p_Data && this->Second.Owner )
      {
        this->Second.Owner = 0;
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>(p_Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Data);
      }
      p_Second->pObject = pObject;
    }
    this->Second.Owner = __thata;
  }
  return this;
}
