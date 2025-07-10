void __thiscall Scaleform::GFx::AS2::Value::Value(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax

  this->T.Type = 7;
  if ( pcharacter )
  {
    pObject = pcharacter->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pcharacter);
    this->NV.Int32Value = (int)pObject;
    if ( pObject )
      ++pObject->RefCount;
  }
  else
  {
    this->NV.Int32Value = 0;
  }
}
