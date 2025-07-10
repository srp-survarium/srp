void __thiscall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        const Scaleform::GFx::AS3::ClassInfo *ci,
        const Scaleform::GFx::AS3::ThunkInfo *func)
{
  const Scaleform::GFx::AS3::ThunkInfo *v3; // ebp
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  const char *NamespaceName; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edx
  const Scaleform::GFx::AS3::TypeInfo *Type; // ecx
  const char *Name; // eax
  bool v11; // dl
  const char *PkgName; // eax
  bool v13; // al
  int v14; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType v15; // ecx
  int v16; // eax
  bool v17; // bl
  void *pWeakProxy; // eax
  bool v19; // zf
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString method_name; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+14h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::SlotInfo nsi; // [esp+24h] [ebp-14h] BYREF

  v3 = func;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pVM->StringManagerRef->pStringManager,
                      (char *)func->Name,
                      strlen(func->Name),
                      0);
  ++ConstStringNode->RefCount;
  pVM = this->pVM;
  method_name.pNode = ConstStringNode;
  NamespaceName = v3->NamespaceName;
  if ( NamespaceName && *NamespaceName )
  {
    if ( NamespaceName == Scaleform::GFx::AS3::NS_AS3 || !strcmp(v3->NamespaceName, Scaleform::GFx::AS3::NS_AS3) )
    {
      pObject = pVM->AS3Namespace.pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
    else
    {
      pObject = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                  pVM,
                  (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&func,
                  (Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(*((_DWORD *)v3 + 4) << 28) >> 28),
                  (Scaleform::GFx::ASStringNode *)v3->NamespaceName)->pV;
    }
  }
  else
  {
    Type = ci->Type;
    Name = ci->Type->Name;
    v11 = !Name || !*Name;
    PkgName = Type->PkgName;
    v13 = !PkgName || !*PkgName;
    if ( !v11 || v13 )
    {
      pObject = pVM->PublicNamespace.pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
    else
    {
      pObject = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                  pVM,
                  (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&func,
                  (Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(*((_DWORD *)v3 + 4) << 28) >> 28),
                  (Scaleform::GFx::ASStringNode *)Type->PkgName)->pV;
    }
  }
  v14 = (int)(*((_DWORD *)v3 + 4) << 25) >> 29;
  v.Flags = 5;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VInt = (int)v3;
  v15 = BT_Code;
  if ( v14 )
  {
    v16 = v14 - 1;
    if ( v16 )
    {
      if ( v16 == 1 )
        v15 = BT_Set;
    }
    else
    {
      v15 = BT_Get;
    }
  }
  nsi.pNs.pObject = pObject;
  *(_DWORD *)&nsi = *(_DWORD *)&nsi & 0xF8000000 | 0x7FFFC02;
  memset(&nsi.CTraits, 0, 12);
  v17 = !Scaleform::GFx::AS3::Traits::RegisterWithVT(
           this,
           (Scaleform::GFx::AS3::CheckResult *)&func,
           &method_name,
           &nsi,
           &v,
           v15)->Result;
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      pWeakProxy = v.Bonus.pWeakProxy;
      v19 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v19 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  if ( v17 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v, eIllegalOverrideError, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      pVM,
      v20,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v21 = (Scaleform::GFx::ASStringNode *)v.Bonus.pWeakProxy;
    --v.Bonus.pWeakProxy[1].pObject;
    if ( !v21->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  }
  pNode = method_name.pNode;
  v19 = method_name.pNode->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
