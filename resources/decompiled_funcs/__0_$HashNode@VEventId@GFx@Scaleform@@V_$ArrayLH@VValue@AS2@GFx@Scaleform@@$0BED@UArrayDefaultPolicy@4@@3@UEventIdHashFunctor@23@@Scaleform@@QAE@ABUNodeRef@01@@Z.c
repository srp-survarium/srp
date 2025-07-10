void __thiscall Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeRef *src)
{
  const Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy> *pSecond; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy> *p_Second; // edi
  unsigned int Size; // ebp
  unsigned int v5; // ebx
  const Scaleform::GFx::AS2::Value *srca; // [esp+10h] [ebp+4h]

  this->First = *src->pFirst;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  this->Second.Data.Data = 0;
  this->Second.Data.Size = 0;
  this->Second.Data.Policy.Capacity = 0;
  Size = pSecond->Data.Size;
  srca = pSecond->Data.Data;
  if ( Size )
  {
    v5 = this->Second.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Second.Data,
      &this->Second,
      v5 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::ConstructArray(&p_Second->Data.Data[v5], Size, srca);
  }
}
