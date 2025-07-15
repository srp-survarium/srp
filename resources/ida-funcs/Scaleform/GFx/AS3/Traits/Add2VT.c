void __thiscall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::SlotInfo *si,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::SlotInfo *v5; // edi
  int v6; // esi
  int v7; // edx
  Scaleform::GFx::AS3::VTable *v8; // ecx
  int v9; // ebp
  Scaleform::GFx::AS3::SlotInfo::BindingType v10; // edx
  Scaleform::GFx::AS3::SlotInfo *v11; // ebx
  bool v12; // zf
  int v13; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType v14; // ebx
  const Scaleform::GFx::AS3::Value *v15; // eax
  Scaleform::GFx::AS3::SlotInfo *pObject; // esi
  Scaleform::GFx::AS3::AbsoluteIndex result; // [esp+Ch] [ebp-4h] BYREF

  VT = Scaleform::GFx::AS3::Traits::GetVT(this);
  v5 = si;
  v6 = (32 * *(_DWORD *)si) >> 15;
  v7 = *(_DWORD *)si | 0x10;
  v8 = VT;
  *(_DWORD *)si = v7;
  if ( v6 < 0 )
  {
    v14 = new_bt;
    v15 = v;
    pObject = (Scaleform::GFx::AS3::SlotInfo *)v5->Name.pObject;
    ++pObject->File.pObject;
    si = pObject;
    *(_DWORD *)v5 = *(_DWORD *)v5 & 0xF800001F
                  | (32
                   * (v14 & 0x1F
                    | (32
                     * ((unsigned int)&loc_1FFFF
                      & Scaleform::GFx::AS3::VTable::AddMethod(
                          v8,
                          &result,
                          v15,
                          v14,
                          (const Scaleform::GFx::ASString *)&si)->Index))));
    v12 = pObject->File.pObject-- == (Scaleform::GFx::AS3::VMAbcFile *)1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pObject);
  }
  else
  {
    v9 = v7 << 22 >> 27;
    if ( v9 != 11 || new_bt == BT_Code )
    {
      v10 = new_bt;
      v11 = (Scaleform::GFx::AS3::SlotInfo *)v5->Name.pObject;
      ++v11->File.pObject;
      si = v11;
      Scaleform::GFx::AS3::VTable::SetMethod(
        VT,
        (Scaleform::GFx::AS3::AbsoluteIndex)v6,
        v,
        v10,
        (const Scaleform::GFx::ASString *)&si);
      v12 = v11->File.pObject-- == (Scaleform::GFx::AS3::VMAbcFile *)1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v11);
      v13 = v9;
      if ( v9 == 12 )
      {
        if ( new_bt != BT_Set )
        {
LABEL_12:
          if ( v13 != v9 )
            *(_DWORD *)v5 = *(_DWORD *)v5 & 0xF800001F | (32 * (v13 & 0x1F | (32 * ((unsigned int)&loc_1FFFF & v6))));
          return;
        }
      }
      else
      {
        if ( v9 != 13 )
          return;
        if ( new_bt != BT_Get )
          goto LABEL_12;
      }
      v13 = 14;
      goto LABEL_12;
    }
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
        Scaleform::GFx::ASStringNode *ci,
        const Scaleform::GFx::AS3::ThunkInfo *func)
{
  const Scaleform::GFx::AS3::ThunkInfo *v3; // ebx
  Scaleform::GFx::ASStringNode *ConstStringNode; // edi
  Scaleform::GFx::ASStringNode *NamespaceName; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edx
  const Scaleform::GFx::AS3::TypeInfo *pData; // ecx
  const char *v10; // eax
  bool v11; // dl
  const char *PkgName; // eax
  bool v13; // al
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  const Scaleform::GFx::AS3::SlotInfo *v17; // eax
  bool v18; // bl
  bool v19; // zf
  void *pWeakProxy; // eax
  const char *v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  const Scaleform::GFx::AS3::VM::Error *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::StringDataPtr v27; // [esp-10h] [ebp-54h]
  Scaleform::StringDataPtr v28; // [esp-8h] [ebp-4Ch]
  Scaleform::GFx::AS3::SlotInfo::BindingType v29; // [esp-4h] [ebp-48h]
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-34h]
  Scaleform::GFx::ASString method_name; // [esp+14h] [ebp-30h] BYREF
  Scaleform::GFx::ASStringNode *v32; // [esp+18h] [ebp-2Ch]
  Scaleform::GFx::AS3::Value v; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::SlotInfo v34; // [esp+2Ch] [ebp-18h] BYREF

  v3 = func;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pVM->StringManagerRef->pStringManager,
                      (char *)func->Name,
                      strlen(func->Name),
                      0);
  ++ConstStringNode->RefCount;
  NamespaceName = (Scaleform::GFx::ASStringNode *)v3->NamespaceName;
  pVM = this->pVM;
  method_name.pNode = ConstStringNode;
  vm = pVM;
  if ( NamespaceName && LOBYTE(NamespaceName->pData) )
  {
    if ( NamespaceName == (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::NS_AS3
      || !strcmp((const char *)NamespaceName, Scaleform::GFx::AS3::NS_AS3) )
    {
      pObject = vm->AS3Namespace.pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
    else
    {
      pObject = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                  vm,
                  (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&func,
                  (Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(*((_DWORD *)v3 + 4) << 28) >> 28),
                  NamespaceName)->pV;
    }
  }
  else
  {
    pData = (const Scaleform::GFx::AS3::TypeInfo *)ci->pData;
    v10 = (const char *)*((_DWORD *)ci->pData + 1);
    v11 = !v10 || !*v10;
    PkgName = pData->PkgName;
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
                  (Scaleform::GFx::ASStringNode *)pData->PkgName)->pV;
    }
  }
  ++ConstStringNode->RefCount;
  v14 = (int)(*((_DWORD *)v3 + 4) << 25) >> 29;
  v.Flags = 5;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VInt = (int)v3;
  ci = ConstStringNode;
  v15 = 11;
  if ( v14 )
  {
    v16 = v14 - 1;
    if ( v16 )
    {
      if ( v16 == 1 )
        v15 = 13;
    }
    else
    {
      v15 = 12;
    }
  }
  v29 = v15;
  Scaleform::GFx::AS3::SlotInfo::SlotInfo(
    &v34,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)pObject,
    0,
    2u,
    (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&ci);
  v18 = !Scaleform::GFx::AS3::Traits::RegisterWithVT(
           this,
           (Scaleform::GFx::AS3::CheckResult *)&func,
           &method_name,
           v17,
           &v,
           v29)->Result;
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v34);
  v19 = ConstStringNode->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
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
  if ( v18 )
  {
    v21 = this->GetName(this, &func)->pNode->pData;
    v28.pStr = v21;
    if ( v21 )
      v22 = strlen(v21);
    else
      v22 = 0;
    v28.Size = v22;
    if ( ConstStringNode->pData )
      v23 = strlen(ConstStringNode->pData);
    else
      v23 = 0;
    v27.Size = v23;
    v27.pStr = ConstStringNode->pData;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&method_name,
      eIllegalOverrideError,
      (Scaleform::String)vm,
      v27,
      v28);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      vm,
      v24,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v25 = v32;
    --v32->RefCount;
    if ( !v25->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    v26 = (Scaleform::GFx::ASStringNode *)func;
    --func->NamespaceName;
    if ( !v26->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  }
  v19 = ConstStringNode->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
}
