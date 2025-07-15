const Scaleform::GFx::AS3::ClassTraits::Traits *__cdecl Scaleform::GFx::AS3::FindFixedTraits(
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Traits *t,
        unsigned int mn,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  unsigned int v5; // edi
  Scaleform::GFx::ASStringNode *v6; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // esi
  const Scaleform::GFx::AS3::Traits *v9; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v10; // ebx
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  int v13; // ebx
  Scaleform::GFx::AS3::Slots *v14; // edi
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v15; // ebx
  const unsigned int *SlotValues; // eax
  unsigned int v17; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebp
  int Prev; // esi
  Scaleform::GFx::AS3::SlotInfo *v20; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v21; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // [esp-18h] [ebp-30h]
  Scaleform::GFx::ASString name; // [esp+4h] [ebp-14h] BYREF
  const unsigned int *values; // [esp+8h] [ebp-10h]
  int v27; // [esp+Ch] [ebp-Ch]
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *namespaces; // [esp+10h] [ebp-8h]
  unsigned int size; // [esp+14h] [ebp-4h]

  pStringManager = vm->StringManagerRef->pStringManager;
  v5 = mn;
  name.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(
         (Scaleform::GFx::AS3::Value *)(v5 + 8),
         (Scaleform::GFx::AS3::CheckResult *)&mn,
         &name)->Result )
  {
    DataType = 0;
    if ( (*(_DWORD *)v5 & 3u) > 1 )
    {
      v13 = *(_DWORD *)(v5 + 4);
      v14 = &t->Scaleform::GFx::AS3::Slots;
      v15 = (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)(v13 + 20);
      namespaces = v15;
      SlotValues = (const unsigned int *)Scaleform::GFx::AS3::Slots::FindSlotValues(
                                           &t->Scaleform::GFx::AS3::Slots,
                                           &name);
      v17 = v15->Data.Size;
      values = SlotValues;
      size = v17;
      mn = 0;
      if ( v17 )
      {
        while ( 1 )
        {
          pObject = v15->Data.Data[mn].pObject;
          if ( SlotValues )
          {
            Prev = *SlotValues;
            if ( *(int *)SlotValues >= 0 )
            {
              v27 = (int)(*((_DWORD *)pObject + 5) << 28) >> 28;
              while ( 1 )
              {
                v20 = Prev >= v14->FirstOwnSlotNum
                    ? &v14->VArray.Data.Data[Prev - v14->FirstOwnSlotNum].Value
                    : (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                         (Scaleform::GFx::AS3::Slots *)v14->Parent,
                                                         (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
                v21 = v20->pNs.pObject;
                if ( (int)(*((_DWORD *)v21 + 5) << 28) >> 28 == v27 )
                {
                  if ( v27 == 1 )
                    break;
                  if ( v27 == 3 ? pObject == v21 : v21->Uri.pNode == pObject->Uri.pNode )
                    break;
                }
                if ( Prev >= v14->FirstOwnSlotNum )
                  Prev = v14->VArray.Data.Data[Prev - v14->FirstOwnSlotNum].Prev;
                else
                  Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex((Scaleform::GFx::AS3::Slots *)v14->Parent, Prev);
                if ( Prev < 0 )
                  goto LABEL_32;
              }
              DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(v20, vm);
              if ( DataType )
                break;
LABEL_32:
              v15 = namespaces;
            }
          }
          DataType = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &name, pObject, appDomain);
          if ( DataType )
            break;
          if ( ++mn >= size )
            break;
          SlotValues = values;
        }
      }
      pNode = name.pNode;
      --name.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return DataType;
    }
    else
    {
      v9 = t;
      v24 = *(const Scaleform::GFx::AS3::Instances::fl::Namespace **)(v5 + 4);
      vm = 0;
      v10 = 0;
      FixedSlot = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::FindFixedSlot(
                                                     t,
                                                     &name,
                                                     v24,
                                                     (unsigned int *)&vm,
                                                     0);
      if ( FixedSlot )
        v10 = Scaleform::GFx::AS3::SlotInfo::GetDataType(FixedSlot, v9->pVM);
      v12 = name.pNode;
      --name.pNode->RefCount;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      return v10;
    }
  }
  else
  {
    v6 = name.pNode;
    --name.pNode->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    return 0;
  }
}
