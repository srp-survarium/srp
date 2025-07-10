void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::TypeInfo *ti)
{
  const Scaleform::GFx::AS3::TypeInfo *v4; // ecx
  const Scaleform::GFx::AS3::VM *v5; // ebp
  char *PkgName; // edx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  const Scaleform::GFx::AS3::VM *v8; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *pObject; // esi
  Scaleform::GFx::AS3::GASRefCountBase *v10; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v11; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::TypeInfo *ConstStringNode; // esi
  Scaleform::GFx::ASString uri; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+14h] [ebp-4h]

  v4 = ti;
  this->Obj.pObject = 0;
  this->Name.Flags = 0;
  v5 = vm;
  this->Name.Bonus.pWeakProxy = 0;
  PkgName = (char *)v4->PkgName;
  pStringManager = v5->StringManagerRef->pStringManager;
  sm = v5->StringManagerRef;
  uri.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, PkgName, strlen(PkgName), 0);
  ++uri.pNode->RefCount;
  if ( uri.pNode->Size )
  {
    pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v5->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInternedInstance(
      pObject,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&vm,
      NS_Public,
      &uri,
      &v);
  }
  else
  {
    v8 = (const Scaleform::GFx::AS3::VM *)v5->PublicNamespace.pObject;
    vm = v8;
    if ( !v8 )
      goto LABEL_8;
    ++v8->GC.GC;
    v8->GC.GC = (Scaleform::GFx::AS3::ASRefCountCollector *)((int)v8->GC.GC & 0x8FBFFFFF);
  }
  v8 = vm;
LABEL_8:
  v10 = this->Obj.pObject;
  v11 = (Scaleform::GFx::AS3::GASRefCountBase *)v8;
  if ( v8 != (const Scaleform::GFx::AS3::VM *)v10 )
  {
    if ( v10 )
    {
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        this->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v10 - 1);
      }
      else
      {
        RefCount = v10->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
    }
    this->Obj.pObject = v11;
  }
  pNode = uri.pNode;
  --uri.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  ConstStringNode = (const Scaleform::GFx::AS3::TypeInfo *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                             sm->pStringManager,
                                                             (char *)ti->Name,
                                                             strlen(ti->Name),
                                                             0);
  ++ConstStringNode->Parent;
  ti = ConstStringNode;
  Scaleform::GFx::AS3::Value::Assign(&this->Name, (const Scaleform::GFx::ASString *)&ti);
  if ( ConstStringNode->Parent-- == (const Scaleform::GFx::AS3::TypeInfo *)1 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)ConstStringNode);
  Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
}
