void __thiscall Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *itr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // ebx
  unsigned int FirstOwnSlotNum; // ecx
  int v6; // edi
  bool v7; // zf
  Scaleform::GFx::AS3::InstanceTraits::Traits *SlotNameNode; // eax
  unsigned int v9; // ecx
  const Scaleform::GFx::AS3::SlotInfo *p_Value; // ebp
  Scaleform::GFx::AS3::Slots *v11; // esi
  const Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // ebp
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // ecx
  unsigned int RefCount; // eax
  int v17; // edi
  int v18; // edi
  int Index; // eax
  _DWORD *v20; // esi
  int v21; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v22; // ebp
  Scaleform::GFx::AS3::VTable *VT; // eax
  unsigned int v24; // eax
  int v25; // ebp
  int v26; // edi
  Scaleform::GFx::AS3::Value *v27; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v28; // edi
  Scaleform::GFx::AS3::VTable *v29; // eax
  int v30; // edi
  Scaleform::GFx::AS3::VTable *v31; // eax
  const Scaleform::GFx::AS3::Value *v32; // edi
  Scaleform::GFx::AS3::VTable *v33; // eax
  _DWORD *i; // ebx
  unsigned int v35; // eax
  const Scaleform::GFx::AS3::VM::Error *v36; // eax
  Scaleform::GFx::ASStringNode *Parent; // eax
  Scaleform::GFx::AS3::AbsoluteIndex *v38; // [esp-10h] [ebp-70h]
  const Scaleform::GFx::AS3::Value *v39; // [esp-Ch] [ebp-6Ch]
  const Scaleform::GFx::AS3::Value *v40; // [esp-Ch] [ebp-6Ch]
  Scaleform::GFx::AS3::SlotInfo::BindingType v41; // [esp-8h] [ebp-68h]
  Scaleform::StringDataPtr v42; // [esp-8h] [ebp-68h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *v43; // [esp+10h] [ebp-50h]
  Scaleform::GFx::ASStringNode *pObject; // [esp+14h] [ebp-4Ch]
  Scaleform::GFx::AS3::AbsoluteIndex result; // [esp+18h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+1Ch] [ebp-44h]
  Scaleform::GFx::AS3::AbsoluteIndex ind; // [esp+20h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v48; // [esp+24h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v49; // [esp+28h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v50; // [esp+2Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v51; // [esp+30h] [ebp-30h] BYREF
  char v52; // [esp+34h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v53; // [esp+38h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v54; // [esp+3Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Slots::CIterator it; // [esp+40h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::SlotInfo newSlot; // [esp+48h] [ebp-18h] BYREF

  v3 = itr;
  FirstOwnSlotNum = itr->FirstOwnSlotNum;
  v6 = 0;
  v7 = FirstOwnSlotNum + itr->VArray.Data.Size == 0;
  v43 = this;
  vm = this->pVM;
  it.Ind.Index = 0;
  if ( v7 )
  {
LABEL_49:
    for ( i = &v3->pParent.pObject->Scaleform::GFx::AS3::Traits::__vftable; i; i = (_DWORD *)i[18] )
      (*(void (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::VMAbcFile *, Scaleform::GFx::AS3::InstanceTraits::Traits *))(*i + 72))(
        i,
        file_ptr,
        this);
    return;
  }
  while ( 1 )
  {
    if ( v6 >= 0 && v6 >= FirstOwnSlotNum )
    {
      pObject = v3->VArray.Data.Data[v6 - FirstOwnSlotNum].Key.pObject;
      SlotNameNode = (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject;
    }
    else
    {
      SlotNameNode = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                                                                      (Scaleform::GFx::AS3::Slots *)v3->Parent,
                                                                      (Scaleform::GFx::AS3::AbsoluteIndex)v6);
      pObject = (Scaleform::GFx::ASStringNode *)SlotNameNode;
    }
    ++SlotNameNode->pPrev;
    itr = SlotNameNode;
    if ( v6 >= 0 && (v9 = v3->FirstOwnSlotNum, v6 >= v9) )
      p_Value = &v3->VArray.Data.Data[v6 - v9].Value;
    else
      p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(
                  (Scaleform::GFx::AS3::Slots *)v3->Parent,
                  (Scaleform::GFx::AS3::AbsoluteIndex)v6);
    v11 = &this->Scaleform::GFx::AS3::Slots;
    Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
      v11,
      &result,
      (const Scaleform::GFx::ASString *)&itr,
      p_Value->pNs.pObject);
    if ( result.Index < 0 )
      break;
    if ( !(result.Index >= v11->FirstOwnSlotNum
         ? &v11->VArray.Data.Data[result.Index - v11->FirstOwnSlotNum].Value
         : (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                              (Scaleform::GFx::AS3::Slots *)v11->Parent,
                                              result)) )
      break;
LABEL_43:
    v7 = pObject->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
    if ( v6 < 0 || v6 < v3->FirstOwnSlotNum + v3->VArray.Data.Size )
      it.Ind.Index = ++v6;
    FirstOwnSlotNum = v3->FirstOwnSlotNum;
    this = v43;
    if ( v6 >= FirstOwnSlotNum + v3->VArray.Data.Size )
      goto LABEL_49;
  }
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
    v11,
    &ind,
    (const Scaleform::GFx::ASString *)&itr,
    vm->PublicNamespace.pObject);
  if ( ind.Index < 0 )
  {
    SlotInfo = 0;
  }
  else if ( ind.Index >= v11->FirstOwnSlotNum )
  {
    SlotInfo = &v11->VArray.Data.Data[ind.Index - v11->FirstOwnSlotNum].Value;
  }
  else
  {
    SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo((Scaleform::GFx::AS3::Slots *)v11->Parent, ind);
  }
  if ( SlotInfo )
  {
    Scaleform::GFx::AS3::SlotInfo::SlotInfo(&newSlot, SlotInfo);
    v14 = p_Value->pNs.pObject;
    v15 = newSlot.pNs.pObject;
    if ( v14 != newSlot.pNs.pObject )
    {
      if ( v14 )
        v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
      if ( v15 )
      {
        if ( ((unsigned __int8)v15 & 1) == 0 )
        {
          RefCount = v15->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v15->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
          }
        }
      }
      newSlot.pNs.pObject = v14;
    }
    Scaleform::GFx::AS3::Slots::Add(v11, &v48, (Scaleform::GFx::ASString *)&itr, &newSlot);
    Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&newSlot);
    goto LABEL_43;
  }
  if ( (v3->Flags & 4) != 0 )
  {
    v17 = *(_DWORD *)p_Value;
    *((_DWORD *)p_Value->pNs.pObject + 5) |= 0x10u;
    v18 = v17 << 22 >> 27;
    Index = Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
              v11,
              &v49,
              (const Scaleform::GFx::ASString *)&itr,
              p_Value->pNs.pObject)->Index;
    if ( Index < 0 )
      Index = Scaleform::GFx::AS3::Slots::Add(v11, &v50, (Scaleform::GFx::ASString *)&itr, p_Value)->Index;
    v20 = &v11->VArray.Data.Data[Index - v11->FirstOwnSlotNum].Value;
    switch ( v18 )
    {
      case 11:
      case 12:
        v21 = (32 * *(_DWORD *)p_Value) >> 15;
        v41 = v18;
        v39 = &Scaleform::GFx::AS3::Traits::GetVT(v3)->VTMethods.Data.Data[v21];
        v38 = &v51;
        goto LABEL_35;
      case 13:
        v25 = ((32 * *(_DWORD *)p_Value) >> 15) + 1;
        v41 = v18;
        v39 = &Scaleform::GFx::AS3::Traits::GetVT(v3)->VTMethods.Data.Data[v25];
        v38 = (Scaleform::GFx::AS3::AbsoluteIndex *)&v52;
LABEL_35:
        v22 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v20[5];
        ++v22->pPrev;
        itr = v22;
        VT = Scaleform::GFx::AS3::Traits::GetVT(v43);
        v24 = *v20 & 0xF800001F
            | (32
             * (v18 & 0x1F
              | (32
               * ((unsigned int)&loc_1FFFF
                & Scaleform::GFx::AS3::VTable::AddMethod(VT, v38, v39, v41, (const Scaleform::GFx::ASString *)&itr)->Index))));
        goto LABEL_40;
      case 14:
        v26 = (32 * *(_DWORD *)p_Value) >> 15;
        v27 = &Scaleform::GFx::AS3::Traits::GetVT(v3)->VTMethods.Data.Data[v26];
        v28 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v20[5];
        ++v28->pPrev;
        v40 = v27;
        itr = v28;
        v29 = Scaleform::GFx::AS3::Traits::GetVT(v43);
        *v20 = *v20 & 0xF800019F
             | (((unsigned int)&loc_1FFFF
               & Scaleform::GFx::AS3::VTable::AddMethod(v29, &v53, v40, BT_Get, (const Scaleform::GFx::ASString *)&itr)->Index) << 10)
             | 0x180;
        v7 = v28->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v28);
        v30 = ((32 * *(_DWORD *)p_Value) >> 15) + 1;
        v31 = Scaleform::GFx::AS3::Traits::GetVT(v3);
        v22 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v20[5];
        v32 = &v31->VTMethods.Data.Data[v30];
        ++v22->pPrev;
        itr = v22;
        v33 = Scaleform::GFx::AS3::Traits::GetVT(v43);
        v24 = *v20 & 0xF80001BF
            | (((unsigned int)&loc_1FFFF
              & Scaleform::GFx::AS3::VTable::AddMethod(v33, &v54, v32, BT_Set, (const Scaleform::GFx::ASString *)&itr)->Index) << 10)
            | 0x1A0;
LABEL_40:
        *v20 = v24;
        v7 = v22->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v22);
        break;
      default:
        break;
    }
    v6 = it.Ind.Index;
    goto LABEL_43;
  }
  if ( pObject->pData )
    v35 = strlen(pObject->pData);
  else
    v35 = 0;
  v42.Size = v35;
  v42.pStr = pObject->pData;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&it,
    eIllegalInterfaceMethodBodyError,
    (Scaleform::String)v43->pVM,
    v42);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v43->pVM,
    v36,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  Parent = (Scaleform::GFx::ASStringNode *)it.Parent;
  --it.Parent->VArray.Data.Size;
  if ( !Parent->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(Parent);
  v7 = pObject->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
}
