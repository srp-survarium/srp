void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::displayAsPasswordSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::TextField *pObject; // esi
  unsigned int Flags; // eax

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  Flags = pObject->Flags;
  if ( ((Flags & 4) != 0) != value )
  {
    if ( value )
    {
      pObject->Flags = Flags | 4;
      pObject->pDocument.pObject->Flags |= 0x10u;
    }
    else
    {
      pObject->Flags = Flags & 0xFFFFFFFB;
      pObject->pDocument.pObject->Flags &= ~0x10u;
    }
    pObject->pDocument.pObject->RTFlags |= 2u;
  }
  Scaleform::GFx::TextField::SetDirtyFlag(pObject);
}
