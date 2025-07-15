void __thiscall Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *itr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // ebx
  unsigned int FirstOwnSlotNum; // ecx
  int Index; // esi
  bool v7; // zf
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // eax
  unsigned int v9; // ecx
  const Scaleform::GFx::AS3::SlotInfo *p_Value; // ebp
  Scaleform::GFx::AS3::Slots *v11; // edi
  const Scaleform::GFx::AS3::SlotInfo *SlotInfo; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // ecx
  unsigned int RefCount; // eax
  int v17; // esi
  Scaleform::GFx::AS3::SlotInfo::BindingType v18; // esi
  Scaleform::GFx::AS3::SlotInfo *AddOwnSlotInfo; // edi
  int v20; // ebp
  Scaleform::GFx::AS3::VTable *VT; // eax
  unsigned int v22; // eax
  int v23; // ebp
  Scaleform::GFx::AS3::VTable *v24; // eax
  int v25; // esi
  Scaleform::GFx::AS3::VTable *v26; // eax
  int v27; // esi
  Scaleform::GFx::AS3::VTable *v28; // eax
  _DWORD *i; // ebx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v31; // eax
  Scaleform::GFx::ASStringNode *Parent; // eax
  const Scaleform::GFx::AS3::Value *v33; // [esp-8h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v34; // [esp-8h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v35; // [esp-8h] [ebp-60h]
  const Scaleform::GFx::AS3::Value *v36; // [esp-8h] [ebp-60h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *v37; // [esp+10h] [ebp-48h]
  Scaleform::GFx::ASStringNode *v38; // [esp+14h] [ebp-44h]
  Scaleform::GFx::AS3::AbsoluteIndex result; // [esp+18h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::AS3::AbsoluteIndex v41; // [esp+20h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex ind; // [esp+24h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v43; // [esp+28h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v44; // [esp+2Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v45; // [esp+30h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v46; // [esp+34h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v47; // [esp+38h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Slots::CIterator it; // [esp+3Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::SlotInfo newSlot; // [esp+44h] [ebp-14h] BYREF

  v3 = itr;
  FirstOwnSlotNum = itr->FirstOwnSlotNum;
  Index = 0;
  v7 = FirstOwnSlotNum + itr->VArray.Data.Size == 0;
  v37 = this;
  vm = this->pVM;
  it.Ind.Index = 0;
  if ( v7 )
  {
LABEL_43:
    for ( i = &v3->pParent.pObject->Scaleform::GFx::AS3::Traits::__vftable; i; i = (_DWORD *)i[18] )
      (*(void (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::VMAbcFile *, Scaleform::GFx::AS3::InstanceTraits::Traits *))(*i + 60))(
        i,
        file_ptr,
        this);
    return;
  }
  while ( 1 )
  {
    if ( Index >= 0 && Index >= FirstOwnSlotNum )
    {
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v3->VArray.Data.Data[Index - FirstOwnSlotNum].Key.pObject;
      v38 = (Scaleform::GFx::ASStringNode *)pObject;
    }
    else
    {
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                                                                 (Scaleform::GFx::AS3::Slots *)v3->Parent,
                                                                 (Scaleform::GFx::AS3::AbsoluteIndex)Index);
      v38 = (Scaleform::GFx::ASStringNode *)pObject;
    }
    ++pObject->pPrev;
    itr = pObject;
    if ( Index >= 0 && (v9 = v3->FirstOwnSlotNum, Index >= v9) )
      p_Value = &v3->VArray.Data.Data[Index - v9].Value;
    else
      p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(
                  (Scaleform::GFx::AS3::Slots *)v3->Parent,
                  (Scaleform::GFx::AS3::AbsoluteIndex)Index);
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
LABEL_37:
    v7 = v38->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
    if ( Index < 0 || Index < v3->FirstOwnSlotNum + v3->VArray.Data.Size )
      it.Ind.Index = ++Index;
    FirstOwnSlotNum = v3->FirstOwnSlotNum;
    this = v37;
    if ( Index >= FirstOwnSlotNum + v3->VArray.Data.Size )
      goto LABEL_43;
  }
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
    v11,
    &v41,
    (const Scaleform::GFx::ASString *)&itr,
    vm->PublicNamespace.pObject);
  if ( v41.Index < 0 )
  {
    SlotInfo = 0;
  }
  else if ( v41.Index >= v11->FirstOwnSlotNum )
  {
    SlotInfo = &v11->VArray.Data.Data[v41.Index - v11->FirstOwnSlotNum].Value;
  }
  else
  {
    SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo((Scaleform::GFx::AS3::Slots *)v11->Parent, v41);
  }
  if ( SlotInfo )
  {
    Scaleform::GFx::AS3::SlotInfo::SlotInfo(&newSlot, SlotInfo);
    v14 = p_Value->pNs.pObject;
    v15 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)newSlot.pNs.pObject;
    if ( v14 != newSlot.pNs.pObject )
    {
      if ( v14 )
        v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
      if ( v15 )
      {
        if ( ((unsigned __int8)v15 & 1) == 0 )
        {
          RefCount = v15->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v15->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
          }
        }
      }
      newSlot.pNs.pObject = v14;
    }
    Scaleform::GFx::AS3::Slots::Add(v11, &v43, (Scaleform::GFx::ASString *)&itr, &newSlot);
    Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&newSlot);
    goto LABEL_37;
  }
  if ( (v3->Flags & 4) != 0 )
  {
    v17 = *(_DWORD *)p_Value;
    *((_DWORD *)p_Value->pNs.pObject + 5) |= 0x10u;
    v18 = v17 << 22 >> 27;
    ind.Index = -1;
    AddOwnSlotInfo = Scaleform::GFx::AS3::Slots::FindAddOwnSlotInfo(
                       v11,
                       (Scaleform::GFx::ASString *)&itr,
                       p_Value,
                       &ind);
    switch ( v18 )
    {
      case BT_Code:
      case BT_Get:
        v20 = (32 * *(_DWORD *)p_Value) >> 15;
        v33 = &Scaleform::GFx::AS3::Traits::GetVT(v3)->VTMethods.Data.Data[v20];
        VT = Scaleform::GFx::AS3::Traits::GetVT(v37);
        v22 = *(_DWORD *)AddOwnSlotInfo & 0xF800001F
            | (32 * (v18 & 0x1F | (32 * (Scaleform::GFx::AS3::VTable::AddMethod(VT, &v44, v33, v18)->Index & 0x1FFFF))));
        goto LABEL_35;
      case BT_Set:
        v23 = ((32 * *(_DWORD *)p_Value) >> 15) + 1;
        v34 = &Scaleform::GFx::AS3::Traits::GetVT(v3)->VTMethods.Data.Data[v23];
        v24 = Scaleform::GFx::AS3::Traits::GetVT(v37);
        v22 = *(_DWORD *)AddOwnSlotInfo & 0xF800001F
            | (32 * (v18 & 0x1F | (32 * (Scaleform::GFx::AS3::VTable::AddMethod(v24, &v45, v34, v18)->Index & 0x1FFFF))));
        goto LABEL_35;
      case BT_GetSet:
        v25 = (32 * *(_DWORD *)p_Value) >> 15;
        v35 = &Scaleform::GFx::AS3::Traits::GetVT(v3)->VTMethods.Data.Data[v25];
        v26 = Scaleform::GFx::AS3::Traits::GetVT(v37);
        *(_DWORD *)AddOwnSlotInfo = *(_DWORD *)AddOwnSlotInfo & 0xF800019F
                                  | ((Scaleform::GFx::AS3::VTable::AddMethod(v26, &v46, v35, BT_Get)->Index & 0x1FFFF) << 10)
                                  | 0x180;
        v27 = ((32 * *(_DWORD *)p_Value) >> 15) + 1;
        v36 = &Scaleform::GFx::AS3::Traits::GetVT(v3)->VTMethods.Data.Data[v27];
        v28 = Scaleform::GFx::AS3::Traits::GetVT(v37);
        v22 = *(_DWORD *)AddOwnSlotInfo & 0xF80001BF
            | ((Scaleform::GFx::AS3::VTable::AddMethod(v28, &v47, v36, BT_Set)->Index & 0x1FFFF) << 10)
            | 0x1A0;
LABEL_35:
        *(_DWORD *)AddOwnSlotInfo = v22;
        break;
      default:
        break;
    }
    Index = it.Ind.Index;
    goto LABEL_37;
  }
  pVM = v37->pVM;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&it, eIllegalInterfaceMethodBodyError, pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    pVM,
    v31,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  Parent = (Scaleform::GFx::ASStringNode *)it.Parent;
  --it.Parent->VArray.Data.Size;
  if ( !Parent->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(Parent);
  v7 = v38->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
}
