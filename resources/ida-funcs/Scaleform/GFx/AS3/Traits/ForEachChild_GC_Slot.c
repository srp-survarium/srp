void __thiscall Scaleform::GFx::AS3::Traits::ForEachChild_GC_Slot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::Object *obj,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  unsigned int Size; // ebx
  bool v6; // zf
  unsigned int v7; // ebx
  int v8; // esi
  unsigned int FirstOwnSlotNum; // ecx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax

  Size = this->VArray.Data.Size;
  v6 = this->FirstOwnSlotNum + Size == 0;
  v7 = this->FirstOwnSlotNum + Size;
  v8 = 0;
  if ( !v6 )
  {
    do
    {
      if ( v8 >= 0 && (FirstOwnSlotNum = this->FirstOwnSlotNum, v8 >= FirstOwnSlotNum) )
        p_Value = &this->VArray.Data.Data[v8 - FirstOwnSlotNum].Value;
      else
        p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                     (Scaleform::GFx::AS3::Slots *)this->Parent,
                                                     (Scaleform::GFx::AS3::AbsoluteIndex)v8);
      Scaleform::GFx::AS3::SlotInfo::ForEachChild_GC(p_Value, prcc, obj, op);
      ++v8;
    }
    while ( v8 < v7 );
  }
}
