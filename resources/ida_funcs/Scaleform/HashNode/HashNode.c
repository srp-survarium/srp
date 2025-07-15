void __thiscall Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>(
        Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> > *this,
        const Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef *src)
{
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  this->First = *src->pFirst;
  pSecond = (Scaleform::GFx::AS3::Value *)src->pSecond;
  this->Second = *pSecond;
  if ( (pSecond->Flags & 0x1F) > 9 )
  {
    if ( (pSecond->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(pSecond);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pSecond);
  }
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor> *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  this->First.Flags = src->First.Flags;
  pNode = src->First.Name.pNode;
  this->First.Name.pNode = pNode;
  ++pNode->RefCount;
  p_Second = &src->Second;
  this->Second = src->Second;
  if ( (src->Second.Flags & 0x1F) > 9 )
  {
    if ( (p_Second->Flags & 0x200) != 0 )
      ++src->Second.Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Second);
  }
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::AS3::Object::DynAttrsKey *pFirst; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  pFirst = src->pFirst;
  this->First.Flags = src->pFirst->Flags;
  pNode = pFirst->Name.pNode;
  this->First.Name.pNode = pNode;
  ++pNode->RefCount;
  pSecond = (Scaleform::GFx::AS3::Value *)src->pSecond;
  this->Second = *pSecond;
  if ( (pSecond->Flags & 0x1F) > 9 )
  {
    if ( (pSecond->Flags & 0x200) != 0 )
      ++pSecond->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pSecond);
  }
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::FunctionRef *p_Second; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  pNode = src->First.pNode;
  this->First.pNode = src->First.pNode;
  ++pNode->RefCount;
  p_Second = &this->Second;
  p_Second->Flags = 0;
  Function = src->Second.Function;
  p_Second->Function = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  p_Second->pLocalFrame = 0;
  pLocalFrame = src->Second.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Second, pLocalFrame, src->Second.Flags & 1);
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS2::FunctionRef *pSecond; // edx
  Scaleform::GFx::AS2::FunctionRef *p_Second; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  pNode = src->pFirst->pNode;
  this->First.pNode = pNode;
  ++pNode->RefCount;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  this->Second.Flags = 0;
  Function = pSecond->Function;
  this->Second.Function = pSecond->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  this->Second.pLocalFrame = 0;
  pLocalFrame = pSecond->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Second, pLocalFrame, pSecond->Flags & 1);
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  pNode = src->First.pNode;
  this->First.pNode = src->First.pNode;
  ++pNode->RefCount;
  p_Second = &src->Second;
  this->Second = src->Second;
  if ( (src->Second.Flags & 0x1F) > 9 )
  {
    if ( (p_Second->Flags & 0x200) != 0 )
      ++src->Second.Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Second);
  }
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  pNode = src->pFirst->pNode;
  this->First.pNode = pNode;
  ++pNode->RefCount;
  pSecond = (Scaleform::GFx::AS3::Value *)src->pSecond;
  this->Second = *pSecond;
  if ( (pSecond->Flags & 0x1F) > 9 )
  {
    if ( (pSecond->Flags & 0x200) != 0 )
      ++pSecond->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pSecond);
  }
}


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


void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *src)
{
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  this->First.Flags = src->First.Flags;
  this->First.Bonus.pWeakProxy = src->First.Bonus.pWeakProxy;
  this->First.value.VNumber = src->First.value.VNumber;
  if ( (src->First.Flags & 0x1F) > 9 )
  {
    if ( (src->First.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&src->First);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&src->First);
  }
  p_Second = &src->Second;
  this->Second = src->Second;
  if ( (src->Second.Flags & 0x1F) > 9 )
  {
    if ( (src->Second.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(p_Second);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Second);
  }
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef *src)
{
  Scaleform::GFx::AS3::Value *pFirst; // ecx
  Scaleform::GFx::AS3::Value *pSecond; // ecx

  pFirst = (Scaleform::GFx::AS3::Value *)src->pFirst;
  this->First = *src->pFirst;
  if ( (pFirst->Flags & 0x1F) > 9 )
  {
    if ( (pFirst->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(pFirst);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pFirst);
  }
  pSecond = (Scaleform::GFx::AS3::Value *)src->pSecond;
  this->Second = *pSecond;
  if ( (pSecond->Flags & 0x1F) > 9 )
  {
    if ( (pSecond->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(pSecond);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(pSecond);
  }
}
