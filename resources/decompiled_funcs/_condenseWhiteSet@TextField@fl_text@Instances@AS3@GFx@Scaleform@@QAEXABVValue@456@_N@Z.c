void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::condenseWhiteSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  pObject = this->pDispObj.pObject;
  if ( value )
    *(_DWORD *)&pObject[1].ClipDepth |= 0x10u;
  else
    *(_DWORD *)&pObject[1].ClipDepth &= ~0x10u;
}
