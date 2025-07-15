void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::antiAliasTypeSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::TextField *pObject; // ecx

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  if ( !strcmp(value->pNode->pData, "normal") )
  {
    pObject->pDocument.pObject->Flags &= ~0x40u;
    Scaleform::GFx::TextField::SetDirtyFlag(pObject);
  }
  else
  {
    if ( !strcmp(value->pNode->pData, "advanced") )
      pObject->pDocument.pObject->Flags |= 0x40u;
    Scaleform::GFx::TextField::SetDirtyFlag(pObject);
  }
}
