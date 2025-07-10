void __thiscall Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *src)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy> *p_Second; // edi
  unsigned int Size; // ebp
  unsigned int v4; // ebx
  Scaleform::GFx::AS2::Value *srca; // [esp+10h] [ebp+4h]

  this->First.Id = src->First.Id;
  this->First.WcharCode = src->First.WcharCode;
  this->First.KeyCode = src->First.KeyCode;
  this->First.TouchID = src->First.TouchID;
  *(_DWORD *)&this->First.RollOverCnt = *(_DWORD *)&src->First.RollOverCnt;
  p_Second = &this->Second;
  this->Second.Data.Data = 0;
  this->Second.Data.Size = 0;
  this->Second.Data.Policy.Capacity = 0;
  Size = src->Second.Data.Size;
  srca = src->Second.Data.Data;
  if ( Size )
  {
    v4 = this->Second.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Second.Data,
      &this->Second,
      v4 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::ConstructArray(&p_Second->Data.Data[v4], Size, srca);
  }
}
