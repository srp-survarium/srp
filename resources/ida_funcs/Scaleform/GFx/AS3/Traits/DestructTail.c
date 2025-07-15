void __thiscall Scaleform::GFx::AS3::Traits::DestructTail(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::Object *obj)
{
  unsigned int i; // edi
  unsigned int v4; // eax
  unsigned int FirstOwnSlotNum; // edx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax

  for ( i = this->FirstOwnSlotNum + this->VArray.Data.Size; i; --i )
  {
    v4 = i - 1;
    if ( (int)(i - 1) >= 0 && (FirstOwnSlotNum = this->FirstOwnSlotNum, v4 >= FirstOwnSlotNum) )
      p_Value = &this->VArray.Data.Data[v4 - FirstOwnSlotNum].Value;
    else
      p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                   (Scaleform::GFx::AS3::Slots *)this->Parent,
                                                   (Scaleform::GFx::AS3::AbsoluteIndex)(i - 1));
    if ( (*(_DWORD *)p_Value & 0x10) == 0 )
      Scaleform::GFx::AS3::SlotInfo::DestroyPrimitiveMember(p_Value, obj);
  }
}
