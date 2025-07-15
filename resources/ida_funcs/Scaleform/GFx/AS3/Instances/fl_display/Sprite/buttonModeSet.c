void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::buttonModeSet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  pObject = this->pDispObj.pObject;
  if ( pObject )
    pObject = (Scaleform::GFx::DisplayObject *)((char *)pObject + 4 * pObject->AvmObjOffset);
  if ( value )
    LOBYTE(pObject->pPerspectiveData) |= 1u;
  else
    LOBYTE(pObject->pPerspectiveData) &= ~1u;
}
