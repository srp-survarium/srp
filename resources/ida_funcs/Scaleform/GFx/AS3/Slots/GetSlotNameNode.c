Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::AS3::Slots::GetSlotNameNode(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  if ( ind.Index >= 0 && ind.Index >= this->FirstOwnSlotNum )
    return this->VArray.Data.Data[ind.Index - this->FirstOwnSlotNum].Key.pObject;
  else
    return Scaleform::GFx::AS3::Slots::GetSlotNameNode((Scaleform::GFx::AS3::Slots *)this->Parent, ind);
}
