void __thiscall Scaleform::GFx::AS3::Traits::ConstructTail(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::Object *obj)
{
  unsigned int Size; // ebp
  bool v4; // zf
  unsigned int v5; // ebp
  int v6; // esi
  unsigned int FirstOwnSlotNum; // ecx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // ecx

  Size = this->VArray.Data.Size;
  v4 = this->FirstOwnSlotNum + Size == 0;
  v5 = this->FirstOwnSlotNum + Size;
  v6 = 0;
  if ( !v4 )
  {
    do
    {
      if ( v6 >= 0 && (FirstOwnSlotNum = this->FirstOwnSlotNum, v6 >= FirstOwnSlotNum) )
        p_Value = &this->VArray.Data.Data[v6 - FirstOwnSlotNum].Value;
      else
        p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                     (Scaleform::GFx::AS3::Slots *)this->Parent,
                                                     (Scaleform::GFx::AS3::AbsoluteIndex)v6);
      v9 = *(_DWORD *)p_Value;
      if ( (*(_DWORD *)p_Value & 0x10) == 0 )
      {
        v10 = (Scaleform::GFx::AS3::Object_vtbl **)((char *)&obj->__vftable + ((32 * v9) >> 15));
        v11 = (v9 << 22 >> 27) - 2;
        if ( v11 )
        {
          v12 = v11 - 1;
          if ( v12 )
          {
            if ( v12 == 6 )
              *v10 = 0;
          }
          else if ( v10 )
          {
            *v10 = 0;
          }
        }
        else if ( v10 )
        {
          *v10 = 0;
          v10[1] = 0;
        }
      }
      ++v6;
    }
    while ( v6 < v5 );
  }
}
