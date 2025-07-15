void __thiscall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::SlotInfo *si,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::VTable *VT; // eax
  int v5; // esi
  int v6; // edx
  Scaleform::GFx::AS3::SlotInfo::BindingType v7; // ebp
  int v8; // edi
  int v9; // eax
  char v10; // si

  VT = Scaleform::GFx::AS3::Traits::GetVT(this);
  v5 = (32 * *(_DWORD *)si) >> 15;
  v6 = *(_DWORD *)si | 0x10;
  *(_DWORD *)si = v6;
  if ( v5 < 0 )
  {
    v10 = new_bt;
    *(_DWORD *)si = *(_DWORD *)si & 0xF800001F
                  | (32
                   * (v10 & 0x1F
                    | (32
                     * (Scaleform::GFx::AS3::VTable::AddMethod(
                          VT,
                          (Scaleform::GFx::AS3::AbsoluteIndex *)&new_bt,
                          v,
                          new_bt)->Index
                      & 0x1FFFF))));
    return;
  }
  v7 = new_bt;
  v8 = v6 << 22 >> 27;
  if ( v8 != 11 || new_bt == BT_Code )
  {
    Scaleform::GFx::AS3::VTable::SetMethod(VT, (Scaleform::GFx::AS3::AbsoluteIndex)v5, v, new_bt);
    v9 = v8;
    if ( v8 == 12 )
    {
      if ( v7 != BT_Set )
      {
LABEL_10:
        if ( v9 != v8 )
          *(_DWORD *)si = *(_DWORD *)si & 0xF800001F | (32 * (v9 & 0x1F | (32 * (v5 & 0x1FFFF))));
        return;
      }
    }
    else
    {
      if ( v8 != 13 )
        return;
      if ( v7 != BT_Get )
        goto LABEL_10;
    }
    v9 = 14;
    goto LABEL_10;
  }
}


void __thiscall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *mn_name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *mn_ns,
        const Scaleform::GFx::AS3::SlotInfo *nsi,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::Slots *v7; // edi
  Scaleform::GFx::AS3::SlotInfo::BindingType v8; // ebp
  Scaleform::GFx::AS3::SlotInfo *p_Value; // edi

  v7 = &this->Scaleform::GFx::AS3::Slots;
  Scaleform::GFx::AS3::Slots::Add(
    &this->Scaleform::GFx::AS3::Slots,
    (Scaleform::GFx::AS3::AbsoluteIndex *)&nsi,
    mn_name,
    nsi);
  v8 = bt;
  p_Value = &v7->VArray.Data.Data[(unsigned int)nsi - v7->FirstOwnSlotNum].Value;
  Scaleform::GFx::AS3::Traits::UpdateVT4IM(this, mn_name, mn_ns, v, bt);
  Scaleform::GFx::AS3::Traits::Add2VT(this, p_Value, v, v8);
}


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
