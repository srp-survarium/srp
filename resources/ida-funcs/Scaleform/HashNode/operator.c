void __thiscall Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::operator=(
        Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> > *this,
        const Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *> >::NodeRef *src)
{
  Scaleform::GFx::Resource **pSecond; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  this->First = *src->pFirst;
  pSecond = (Scaleform::GFx::Resource **)src->pSecond;
  if ( *pSecond )
    Scaleform::RefCountImpl::AddRef(*pSecond);
  pObject = (Scaleform::RefCountVImpl *)this->Second.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Second.pObject = (Scaleform::Render::Text::FontHandle *)*pSecond;
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::AS3::MultinameHash<bool,2>::Key *pFirst; // ebx
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v5; // ecx

  pFirst = src->pFirst;
  pNode = src->pFirst->Name.pNode;
  ++pNode->RefCount;
  v5 = this->First.Name.pNode;
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->First.Name.pNode = pNode;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->First.pNs,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pFirst->pNs);
  this->Second = *src->pSecond;
}


Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *__that)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::AS2::FunctionObject *pObject; // eax
  Scaleform::GFx::AS2::FunctionObject *v7; // ecx
  unsigned int RefCount; // eax

  pNode = __that->First.pNode;
  ++__that->First.pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  this->Second.RegistrarFunc = __that->Second.RegistrarFunc;
  pObject = __that->Second.ResolvedFunc.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v7 = this->Second.ResolvedFunc.pObject;
  if ( v7 )
  {
    RefCount = v7->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v7->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
  this->Second.ResolvedFunc.pObject = __that->Second.ResolvedFunc.pObject;
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *pSecond; // edi
  Scaleform::GFx::AS2::FunctionObject *pObject; // eax
  Scaleform::GFx::AS2::FunctionObject *v8; // ecx
  unsigned int RefCount; // eax

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  this->Second.RegistrarFunc = pSecond->RegistrarFunc;
  pObject = pSecond->ResolvedFunc.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v8 = this->Second.ResolvedFunc.pObject;
  if ( v8 )
  {
    RefCount = v8->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
    this->Second.ResolvedFunc.pObject = pSecond->ResolvedFunc.pObject;
  }
  else
  {
    this->Second.ResolvedFunc.pObject = pSecond->ResolvedFunc.pObject;
  }
}


Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *__that)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = __that->First.pNode;
  ++__that->First.pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->Second.Callback, &__that->Second.Callback);
  Scaleform::GFx::AS2::Value::operator=(&this->Second.UserData, &__that->Second.UserData);
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::Object::Watchpoint *pSecond; // edi
  Scaleform::GFx::AS2::Object::Watchpoint *p_Second; // esi

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&p_Second->Callback, &pSecond->Callback);
  Scaleform::GFx::AS2::Value::operator=(&p_Second->UserData, &pSecond->UserData);
}


Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor> *__that)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = __that->First.pNode;
  ++__that->First.pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  Scaleform::GFx::AS2::Value::operator=(&this->Second.mValue, &__that->Second.mValue);
  this->Second.mValue.T.PropFlags = __that->Second.mValue.T.PropFlags;
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::Member *pSecond; // edi
  Scaleform::GFx::AS2::Member *p_Second; // esi

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  p_Second = &this->Second;
  Scaleform::GFx::AS2::Value::operator=(&p_Second->mValue, &pSecond->mValue);
  p_Second->mValue.T.PropFlags = pSecond->mValue.T.PropFlags;
}


Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *__that)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject> *v6; // esi
  Scaleform::GFx::AS2::SharedObject *pObject; // ecx
  unsigned int RefCount; // eax

  pNode = __that->First.pNode;
  ++__that->First.pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  if ( __that == (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *)-4 )
    v6 = 0;
  else
    v6 = &__that->Second.Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject>;
  if ( v6->pObject )
    v6->pObject->RefCount = (v6->pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->Second.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->Second.Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject> = (Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject>)v6->pObject;
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeRef *src)
{
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v4; // ecx
  const Scaleform::GFx::AS2::SharedObjectPtr *pSecond; // eax
  Scaleform::GFx::AS2::SharedObject **p_pObject; // edi
  Scaleform::GFx::AS2::SharedObject *pObject; // ecx
  unsigned int RefCount; // eax

  pNode = src->pFirst->pNode;
  ++pNode->RefCount;
  v4 = this->First.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->First.pNode = pNode;
  pSecond = src->pSecond;
  if ( pSecond )
    p_pObject = &pSecond->pObject;
  else
    p_pObject = 0;
  if ( *p_pObject )
    (*p_pObject)->RefCount = ((*p_pObject)->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->Second.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
    this->Second.pObject = *p_pObject;
  }
  else
  {
    this->Second.pObject = *p_pObject;
  }
}


Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *__that)
{
  this->First.Id = __that->First.Id;
  this->First.WcharCode = __that->First.WcharCode;
  this->First.KeyCode = __that->First.KeyCode;
  this->First.AsciiCode = __that->First.AsciiCode;
  this->First.RollOverCnt = __that->First.RollOverCnt;
  this->First.ControllerIndex = __that->First.ControllerIndex;
  this->First.KeysState.States = __that->First.KeysState.States;
  this->First.MouseWheelDelta = __that->First.MouseWheelDelta;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>>::operator=(
    &this->Second,
    &__that->Second);
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::EventId *pFirst; // eax

  pFirst = src->pFirst;
  this->First.Id = src->pFirst->Id;
  this->First.WcharCode = pFirst->WcharCode;
  this->First.KeyCode = pFirst->KeyCode;
  this->First.AsciiCode = pFirst->AsciiCode;
  this->First.RollOverCnt = pFirst->RollOverCnt;
  this->First.ControllerIndex = pFirst->ControllerIndex;
  this->First.KeysState.States = pFirst->KeysState.States;
  this->First.MouseWheelDelta = pFirst->MouseWheelDelta;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>>::operator=(
    &this->Second,
    src->pSecond);
}


Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *__thiscall Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *this,
        const Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *__that)
{
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v4; // ecx

  this->First.Id = __that->First.Id;
  if ( __that->Second.HType == RH_Pointer )
  {
    pResource = __that->Second.pResource;
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
  if ( this->Second.HType == RH_Pointer )
  {
    v4 = this->Second.pResource;
    if ( v4 )
      Scaleform::GFx::Resource::Release(v4);
  }
  this->Second = __that->Second;
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::operator=(
        Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp> *this,
        const Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef *src)
{
  const Scaleform::GFx::ResourceHandle *pSecond; // edi
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::Resource *v5; // ecx

  this->First.Id = src->pFirst->Id;
  pSecond = src->pSecond;
  if ( pSecond->HType == RH_Pointer )
  {
    pResource = pSecond->pResource;
    if ( pResource )
      Scaleform::RefCountImpl::AddRef(pResource);
  }
  if ( this->Second.HType == RH_Pointer )
  {
    v5 = this->Second.pResource;
    if ( v5 )
      Scaleform::GFx::Resource::Release(v5);
  }
  this->Second.HType = pSecond->HType;
  this->Second.BindIndex = pSecond->BindIndex;
}


Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor> *__thiscall Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor> *__that)
{
  Scaleform::String::operator=(&this->First, &__that->First);
  if ( &this->Second != &__that->Second )
  {
    Scaleform::StatBag::Clear(&this->Second.Bag);
    Scaleform::StatBag::CombineStatBags(
      &this->Second.Bag,
      &__that->Second.Bag,
      (bool (__thiscall *)(Scaleform::StatBag *, unsigned int, Scaleform::Stat *))Scaleform::StatBag::Add);
  }
  this->Second.TotalMemory = __that->Second.TotalMemory;
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor> *this,
        const Scaleform::HashNode<Scaleform::String,Scaleform::StatsUpdate::FileStats,Scaleform::String::NoCaseHashFunctor>::NodeRef *src)
{
  const Scaleform::StatsUpdate::FileStats *pSecond; // edi
  Scaleform::StatsUpdate::FileStats *p_Second; // esi

  Scaleform::String::operator=(&this->First, src->pFirst);
  pSecond = src->pSecond;
  p_Second = &this->Second;
  if ( p_Second != pSecond )
  {
    Scaleform::StatBag::Clear(&p_Second->Bag);
    Scaleform::StatBag::CombineStatBags(
      &p_Second->Bag,
      &pSecond->Bag,
      (bool (__thiscall *)(Scaleform::StatBag *, unsigned int, Scaleform::Stat *))Scaleform::StatBag::Add);
  }
  p_Second->TotalMemory = pSecond->TotalMemory;
}


void __thiscall Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>>::operator=(
        Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> > *this,
        const Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef *src)
{
  Scaleform::GFx::Resource **pSecond; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  this->First = *src->pFirst;
  pSecond = (Scaleform::GFx::Resource **)src->pSecond;
  if ( *pSecond )
    Scaleform::RefCountImpl::AddRef(*pSecond);
  pObject = (Scaleform::RefCountVImpl *)this->Second.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Second.pObject = (Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes *)*pSecond;
}
