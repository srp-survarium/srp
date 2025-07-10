char __thiscall Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        bool isConstructor2)
{
  bool v6; // cc
  char v8; // al
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v10; // zf
  Scaleform::GFx::AS2::LocalFrame *v11; // ebp
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  unsigned int RefCount; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS2::FunctionObject *v17; // edi
  Scaleform::GFx::AS2::Object *pObject; // eax
  bool v19; // bl
  Scaleform::GFx::AS2::LocalFrame *v20; // ecx
  unsigned int v21; // eax
  unsigned __int8 v23; // bl
  unsigned int v24; // eax
  Scaleform::GFx::AS2::LocalFrame *v25; // ecx
  unsigned int v26; // eax
  Scaleform::GFx::ASString::NoCaseKey key; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::FunctionRef ctor; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase orig; // [esp+1Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Member m; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value lval; // [esp+38h] [ebp-10h] BYREF

  v6 = psc->SWFVersion <= 6u;
  m.mValue.T = 0;
  lval.T.Type = 10;
  if ( v6 )
  {
    pNode = name->pNode;
    v10 = name->pNode->pLower == 0;
    key.pStr = name;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v8 = Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::GetAlt<Scaleform::GFx::ASString::NoCaseKey>(
           &pthis->Members,
           &key,
           &m);
  }
  else
  {
    v8 = Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Get(
           &pthis->Members,
           name,
           &m);
  }
  if ( v8 )
  {
    Scaleform::GFx::AS2::Value::operator=(&lval, &m.mValue);
    if ( lval.T.Type != 10 )
    {
      Scaleform::GFx::AS2::Value::operator=(val, &lval);
LABEL_41:
      if ( lval.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&lval);
      if ( m.mValue.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&m.mValue);
      return 1;
    }
  }
  v11 = 0;
  memset(&ctor, 0, 9);
  if ( isConstructor2 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&ctor, &this->__Constructor__);
  }
  else
  {
    Function = this->Constructor.Function;
    Flags = 0;
    orig.Flags = 0;
    orig.Function = Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    pLocalFrame = this->Constructor.pLocalFrame;
    orig.pLocalFrame = 0;
    if ( pLocalFrame )
    {
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&orig, pLocalFrame, this->Constructor.Flags & 1);
      Flags = orig.Flags;
      v11 = orig.pLocalFrame;
      Function = orig.Function;
    }
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&ctor, &orig);
    if ( (Flags & 2) == 0 )
    {
      if ( Function )
      {
        RefCount = Function->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    if ( (Flags & 1) == 0 )
    {
      if ( v11 )
      {
        v16 = v11->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v16) != 0 )
        {
          v11->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
    }
  }
  v17 = ctor.Function;
  if ( ctor.Function )
  {
    Scaleform::GFx::AS2::Value::SetAsFunction(val, &ctor);
LABEL_33:
    v23 = ctor.Flags;
    if ( (ctor.Flags & 2) == 0 )
    {
      if ( v17 )
      {
        v24 = v17->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v24) != 0 )
        {
          v17->RefCount = v24 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        }
      }
    }
    if ( (v23 & 1) == 0 )
    {
      v25 = ctor.pLocalFrame;
      if ( ctor.pLocalFrame )
      {
        v26 = ctor.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v26) != 0 )
        {
          ctor.pLocalFrame->RefCount = v26 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
        }
      }
    }
    goto LABEL_41;
  }
  Scaleform::GFx::AS2::Value::DropRefs(val);
  val->T.Type = 0;
  pObject = pthis->pProto.pObject;
  if ( !pObject )
    goto LABEL_33;
  v19 = pObject->GetMemberRaw(&pObject->Scaleform::GFx::AS2::ObjectInterface, psc, name, val);
  if ( (ctor.Flags & 1) == 0 )
  {
    v20 = ctor.pLocalFrame;
    if ( ctor.pLocalFrame )
    {
      v21 = ctor.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v21) != 0 )
      {
        ctor.pLocalFrame->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
      }
    }
  }
  Scaleform::GFx::AS2::Value::DropRefs(&lval);
  if ( m.mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&m.mValue);
  return v19;
}
