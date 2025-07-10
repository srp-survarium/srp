void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::buttonModeGet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        bool *result)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  pObject = this->pDispObj.pObject;
  if ( pObject )
    *result = *(_BYTE *)(&pObject->pPerspectiveData + pObject->AvmObjOffset) & 1;
  else
    *result = 0;
}
