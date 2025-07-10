void __thiscall Scaleform::GFx::AS2::Value::SetAsCharacter(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::InteractiveObject *pchar)
{
  Scaleform::GFx::CharacterHandle *pObject; // esi

  if ( pchar )
  {
    pObject = pchar->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pchar);
  }
  else
  {
    pObject = 0;
  }
  if ( this->T.Type != 7 || this->V.pCharHandle != pObject )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 7;
    this->NV.Int32Value = (int)pObject;
    if ( pObject )
      ++pObject->RefCount;
  }
}
