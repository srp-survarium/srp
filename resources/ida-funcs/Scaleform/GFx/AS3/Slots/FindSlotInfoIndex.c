Scaleform::GFx::AS3::AbsoluteIndex *__thiscall Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  char *SlotValues; // eax
  int Prev; // esi
  int v7; // ebx
  Scaleform::GFx::AS3::SlotInfo *v8; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  Scaleform::GFx::AS3::AbsoluteIndex *v11; // eax

  SlotValues = Scaleform::GFx::AS3::Slots::FindSlotValues(this, name);
  if ( SlotValues && (Prev = *(_DWORD *)SlotValues, *(int *)SlotValues >= 0) )
  {
    v7 = (int)(*((_DWORD *)ns + 5) << 28) >> 28;
    while ( 1 )
    {
      v8 = Prev >= this->FirstOwnSlotNum
         ? &this->VArray.Data.Data[Prev - this->FirstOwnSlotNum].Value
         : (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                              (Scaleform::GFx::AS3::Slots *)this->Parent,
                                              (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
      pObject = v8->pNs.pObject;
      if ( (int)(*((_DWORD *)pObject + 5) << 28) >> 28 == v7 )
      {
        if ( v7 == 1 )
          break;
        if ( v7 == 3 ? ns == pObject : pObject->Uri.pNode == ns->Uri.pNode )
          break;
      }
      if ( Prev >= this->FirstOwnSlotNum )
        Prev = this->VArray.Data.Data[Prev - this->FirstOwnSlotNum].Prev;
      else
        Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex((Scaleform::GFx::AS3::Slots *)this->Parent, Prev);
      if ( Prev < 0 )
        goto LABEL_17;
    }
    v11 = result;
    result->Index = Prev;
  }
  else
  {
LABEL_17:
    v11 = result;
    result->Index = -1;
  }
  return v11;
}
