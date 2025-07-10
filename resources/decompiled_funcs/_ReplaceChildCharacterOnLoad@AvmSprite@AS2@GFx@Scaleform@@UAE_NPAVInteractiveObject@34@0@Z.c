bool __thiscall Scaleform::GFx::AS2::AvmSprite::ReplaceChildCharacterOnLoad(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::InteractiveObject *poldChar,
        Scaleform::GFx::InteractiveObject *pnewChar)
{
  bool result; // al

  result = this->ReplaceChildCharacter(this, poldChar, pnewChar);
  if ( result )
  {
    pnewChar->OnEventLoad(pnewChar);
    this->pDispObj->pASRoot->DoActions(this->pDispObj->pASRoot);
    return 1;
  }
  return result;
}
