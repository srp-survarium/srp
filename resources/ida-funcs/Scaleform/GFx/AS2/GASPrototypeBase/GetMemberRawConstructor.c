bool __thiscall Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
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
  Scaleform::GFx::ASString::NoCaseKey v27; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::FunctionRefBase func; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase orig; // [esp+1Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v31; // [esp+38h] [ebp-10h] BYREF

  v6 = psc->SWFVersion <= 6u;
  v.T = 0;
  v31.T.Type = 10;
  if ( v6 )
  {
    pNode = name->pNode;
    v10 = name->pNode->pLower == 0;
    v27.pStr = name;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v8 = Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::GetAlt<Scaleform::GFx::ASString::NoCaseKey>(
           &pthis->Members,
           &v27,
           (Scaleform::GFx::AS2::Member *)&v);
  }
  else
  {
    v8 = Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Get(
           &pthis->Members,
           name,
           (Scaleform::GFx::AS2::Member *)&v);
  }
  if ( v8 )
  {
    Scaleform::GFx::AS2::Value::operator=(&v31, &v);
    if ( v31.T.Type != 10 )
    {
      Scaleform::GFx::AS2::Value::operator=(val, &v31);
LABEL_41:
      if ( v31.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v31);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      return 1;
    }
  }
  v11 = 0;
  memset(&func, 0, 9);
  if ( isConstructor2 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&func, &this->__Constructor__);
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
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&func, &orig);
    if ( (Flags & 2) == 0 )
    {
      if ( Function )
      {
        RefCount = Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
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
        if ( (v16 & 0x3FFFFFF) != 0 )
        {
          v11->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
    }
  }
  v17 = func.Function;
  if ( func.Function )
  {
    Scaleform::GFx::AS2::Value::SetAsFunction(val, &func);
LABEL_33:
    v23 = func.Flags;
    if ( (func.Flags & 2) == 0 )
    {
      if ( v17 )
      {
        v24 = v17->RefCount;
        if ( (v24 & 0x3FFFFFF) != 0 )
        {
          v17->RefCount = v24 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        }
      }
    }
    if ( (v23 & 1) == 0 )
    {
      v25 = func.pLocalFrame;
      if ( func.pLocalFrame )
      {
        v26 = func.pLocalFrame->RefCount;
        if ( (v26 & 0x3FFFFFF) != 0 )
        {
          func.pLocalFrame->RefCount = v26 - 1;
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
  if ( (func.Flags & 1) == 0 )
  {
    v20 = func.pLocalFrame;
    if ( func.pLocalFrame )
    {
      v21 = func.pLocalFrame->RefCount;
      if ( (v21 & 0x3FFFFFF) != 0 )
      {
        func.pLocalFrame->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
      }
    }
  }
  Scaleform::GFx::AS2::Value::DropRefs(&v31);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v19;
}
