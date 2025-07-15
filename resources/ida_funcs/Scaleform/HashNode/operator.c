bool __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::operator==<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *src)
{
  unsigned int Flags; // eax
  bool v4; // bl
  Scaleform::GFx::AS3::Value y; // [esp+8h] [ebp-10h] BYREF

  Flags = src->First.Flags;
  y.Bonus.pWeakProxy = src->First.Bonus.pWeakProxy;
  y.value.VNumber = src->First.value.VNumber;
  y.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&src->First);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&src->First);
  }
  v4 = Scaleform::GFx::AS3::StrictEqual(&this->First, &y);
  if ( (y.Flags & 0x1F) > 9 )
  {
    if ( (y.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&y);
      return v4;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&y);
  }
  return v4;
}


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


Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *__thiscall Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::operator=(
        Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *this,
        const Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *__that)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax
  Scaleform::Render::ShapeMeshProvider *v4; // eax

  this->First = __that->First;
  pObject = __that->Second.pObject;
  if ( pObject )
    pObject->AddRef(&pObject->Scaleform::Render::MeshProvider);
  v4 = this->Second.pObject;
  if ( v4 )
    v4->Release(&v4->Scaleform::Render::MeshProvider);
  this->Second.pObject = __that->Second.pObject;
  return this;
}


void __thiscall Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::operator=(
        Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> > *this,
        const Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *> >::NodeRef *src)
{
  const Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *pSecond; // edi
  Scaleform::Render::ShapeMeshProvider *pObject; // eax

  this->First = *src->pFirst;
  pSecond = src->pSecond;
  if ( pSecond->pObject )
    pSecond->pObject->AddRef(&pSecond->pObject->Scaleform::Render::MeshProvider);
  pObject = this->Second.pObject;
  if ( pObject )
    pObject->Release(&pObject->Scaleform::Render::MeshProvider);
  this->Second = (Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>)pSecond->pObject;
}


void __thiscall Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::operator=(
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


void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::operator=(
        Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef *src)
{
  const Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *pFirst; // ebx
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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
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


Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> > *__thiscall Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::operator=(
        Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> > *this,
        const Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> > *__that)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::Object *v4; // ecx
  unsigned int RefCount; // eax

  this->First = __that->First;
  pObject = __that->Second.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v4 = this->Second.pObject;
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
  this->Second.pObject = __that->Second.pObject;
  return this;
}


void __thiscall Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::operator=(
        Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> > *this,
        const Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *src)
{
  const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *pSecond; // edi
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->First = *src->pFirst;
  pSecond = src->pSecond;
  if ( pSecond->pObject )
    pSecond->pObject->RefCount = (pSecond->pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->Second.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
    this->Second = (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)pSecond->pObject;
  }
  else
  {
    this->Second = (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)pSecond->pObject;
  }
}
