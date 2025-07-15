const Scaleform::GFx::AS3::SlotInfo *__cdecl Scaleform::GFx::AS3::FindFixedSlot(
        const Scaleform::GFx::AS3::SlotInfo *vm,
        const Scaleform::GFx::AS3::Traits *t,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *mn,
        unsigned int *index,
        Scaleform::GFx::AS3::Object *obj)
{
  const Scaleform::GFx::AS3::Multiname *v5; // esi
  Scaleform::GFx::ASStringNode *v6; // eax
  unsigned int v8; // eax
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // esi
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::Slots *v11; // edi
  const Scaleform::GFx::AS3::Multiname *v12; // ebp
  const unsigned int *SlotValues; // eax
  unsigned int pObject; // edx
  unsigned int v15; // ecx
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v16; // ebx
  int Prev; // esi
  const Scaleform::GFx::AS3::SlotInfo *v18; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // edx
  int v20; // ecx
  int v21; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString name; // [esp+10h] [ebp-10h] BYREF
  unsigned int i; // [esp+14h] [ebp-Ch]
  const unsigned int *values; // [esp+18h] [ebp-8h]
  unsigned int size; // [esp+1Ch] [ebp-4h]

  v5 = (const Scaleform::GFx::AS3::Multiname *)mn;
  name.pNode = (Scaleform::GFx::ASStringNode *)vm->File.pObject->__vftable;
  ++name.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(&v5->Name, (Scaleform::GFx::AS3::CheckResult *)&vm, &name)->Result )
  {
    v8 = v5->Kind & 3;
    vm = 0;
    if ( v8 > 1 )
    {
      v11 = &t->Scaleform::GFx::AS3::Slots;
      mn = (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&v5->Obj.pObject[1];
      v12 = (const Scaleform::GFx::AS3::Multiname *)mn;
      SlotValues = (const unsigned int *)Scaleform::GFx::AS3::Slots::FindSlotValues(
                                           &t->Scaleform::GFx::AS3::Slots,
                                           &name);
      pObject = (unsigned int)v12->Obj.pObject;
      v15 = 0;
      values = SlotValues;
      size = pObject;
      i = 0;
      if ( pObject )
      {
        while ( 1 )
        {
          v16 = *(const Scaleform::GFx::AS3::Instances::fl::Namespace **)(v12->Kind + 4 * v15);
          if ( SlotValues )
          {
            Prev = *SlotValues;
            if ( *(int *)SlotValues >= 0 )
            {
              while ( 1 )
              {
                *index = Prev;
                v18 = Prev >= v11->FirstOwnSlotNum
                    ? &v11->VArray.Data.Data[Prev - v11->FirstOwnSlotNum].Value
                    : Scaleform::GFx::AS3::Slots::GetSlotInfo(
                        (Scaleform::GFx::AS3::Slots *)v11->Parent,
                        (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
                v19 = v18->pNs.pObject;
                v20 = (int)(*((_DWORD *)v16 + 5) << 28) >> 28;
                if ( (int)(*((_DWORD *)v19 + 5) << 28) >> 28 == v20 )
                {
                  v21 = v20 - 1;
                  if ( !v21 )
                    break;
                  if ( v21 == 2 ? v16 == v19 : v19->Uri.pNode == v16->Uri.pNode )
                    break;
                }
                if ( Prev >= v11->FirstOwnSlotNum )
                  Prev = v11->VArray.Data.Data[Prev - v11->FirstOwnSlotNum].Prev;
                else
                  Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex((Scaleform::GFx::AS3::Slots *)v11->Parent, Prev);
                if ( Prev < 0 )
                  goto LABEL_29;
              }
              vm = v18;
LABEL_29:
              v12 = (const Scaleform::GFx::AS3::Multiname *)mn;
            }
          }
          if ( obj )
            vm = obj->InitializeOnDemand(obj, vm, &name, v16, index);
          if ( vm )
            break;
          v15 = i + 1;
          i = v15;
          if ( v15 >= size )
            break;
          SlotValues = values;
        }
      }
      pNode = name.pNode;
      --name.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return vm;
    }
    else
    {
      FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                    t,
                    &name,
                    (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v5->Obj.pObject,
                    index,
                    obj);
      v10 = name.pNode;
      --name.pNode->RefCount;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      return FixedSlot;
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


const Scaleform::GFx::AS3::SlotInfo *__cdecl Scaleform::GFx::AS3::FindFixedSlot(
        const Scaleform::GFx::AS3::Traits *t,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        unsigned int *index,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Slots *v5; // edi
  const Scaleform::GFx::AS3::SlotInfo *v6; // ebp
  char *SlotValues; // eax
  unsigned int Prev; // esi
  Scaleform::GFx::AS3::SlotInfo *v9; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edx
  int v11; // ecx
  int v12; // ecx

  v5 = &t->Scaleform::GFx::AS3::Slots;
  v6 = 0;
  SlotValues = Scaleform::GFx::AS3::Slots::FindSlotValues(&t->Scaleform::GFx::AS3::Slots, name);
  if ( SlotValues )
  {
    Prev = *(_DWORD *)SlotValues;
    if ( *(int *)SlotValues >= 0 )
    {
      while ( 1 )
      {
        *index = Prev;
        v9 = Prev >= v5->FirstOwnSlotNum
           ? &t->VArray.Data.Data[Prev - v5->FirstOwnSlotNum].Value
           : (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                (Scaleform::GFx::AS3::Slots *)t->Parent,
                                                (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
        pObject = v9->pNs.pObject;
        v11 = (int)(*((_DWORD *)ns + 5) << 28) >> 28;
        if ( (int)(*((_DWORD *)pObject + 5) << 28) >> 28 == v11 )
        {
          v12 = v11 - 1;
          if ( !v12 )
            break;
          if ( v12 == 2 ? ns == pObject : pObject->Uri.pNode == ns->Uri.pNode )
            break;
        }
        if ( Prev >= v5->FirstOwnSlotNum )
          Prev = t->VArray.Data.Data[Prev - v5->FirstOwnSlotNum].Prev;
        else
          Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex((Scaleform::GFx::AS3::Slots *)t->Parent, Prev);
        if ( (Prev & 0x80000000) != 0 )
        {
          v6 = 0;
          goto LABEL_17;
        }
      }
      v6 = v9;
    }
  }
LABEL_17:
  if ( obj )
    return obj->InitializeOnDemand(obj, v6, name, ns, index);
  else
    return v6;
}
