Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Slots::GetSlotName(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::ASStringNode *SlotNameNode; // eax
  Scaleform::GFx::ASStringNode *pObject; // eax

  if ( ind.Index >= 0 && ind.Index >= this->FirstOwnSlotNum )
  {
    pObject = this->VArray.Data.Data[ind.Index - this->FirstOwnSlotNum].Key.pObject;
    ++pObject->RefCount;
    result->pNode = pObject;
    return result;
  }
  else
  {
    SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode((Scaleform::GFx::AS3::Slots *)this->Parent, ind);
    ++SlotNameNode->RefCount;
    result->pNode = SlotNameNode;
    return result;
  }
}
