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
  Scaleform::GFx::AS3::Slots *v13; // ebx
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v14; // edi
  const unsigned int *SlotValues; // eax
  unsigned int v16; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebp
  int Prev; // esi
  Scaleform::GFx::AS3::SlotInfo *v19; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v20; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // [esp-18h] [ebp-30h]
  Scaleform::GFx::ASString name; // [esp+4h] [ebp-14h] BYREF
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *namespaces; // [esp+8h] [ebp-10h]
  const unsigned int *values; // [esp+Ch] [ebp-Ch]
  int v27; // [esp+10h] [ebp-8h]
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
      v13 = &t->Scaleform::GFx::AS3::Slots;
      v14 = (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)(*(_DWORD *)(v5 + 4) + 20);
      namespaces = v14;
      SlotValues = (const unsigned int *)Scaleform::GFx::AS3::Slots::FindSlotValues(
                                           &t->Scaleform::GFx::AS3::Slots,
                                           &name);
      v16 = v14->Data.Size;
      values = SlotValues;
      size = v16;
      mn = 0;
      if ( v16 )
      {
        while ( 1 )
        {
          pObject = v14->Data.Data[mn].pObject;
          if ( SlotValues )
          {
            Prev = *SlotValues;
            if ( *(int *)SlotValues >= 0 )
            {
              v27 = (int)(*((_DWORD *)pObject + 5) << 28) >> 28;
              while ( 1 )
              {
                v19 = Prev >= v13->FirstOwnSlotNum
                    ? &v13->VArray.Data.Data[Prev - v13->FirstOwnSlotNum].Value
                    : (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                         (Scaleform::GFx::AS3::Slots *)v13->Parent,
                                                         (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
                v20 = v19->pNs.pObject;
                if ( (int)(*((_DWORD *)v20 + 5) << 28) >> 28 == v27 )
                {
                  if ( v27 == 1 )
                    break;
                  if ( v27 == 3 ? pObject == v20 : v20->Uri.pNode == pObject->Uri.pNode )
                    break;
                }
                if ( Prev >= v13->FirstOwnSlotNum )
                  Prev = v13->VArray.Data.Data[Prev - v13->FirstOwnSlotNum].Prev;
                else
                  Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex((Scaleform::GFx::AS3::Slots *)v13->Parent, Prev);
                if ( Prev < 0 )
                  goto LABEL_32;
              }
              DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(v19, vm);
              if ( DataType )
                break;
LABEL_32:
              v14 = namespaces;
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
      v23 = *(const Scaleform::GFx::AS3::Instances::fl::Namespace **)(v5 + 4);
      vm = 0;
      v10 = 0;
      FixedSlot = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::FindFixedSlot(
                                                     t,
                                                     &name,
                                                     v23,
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
