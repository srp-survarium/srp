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
