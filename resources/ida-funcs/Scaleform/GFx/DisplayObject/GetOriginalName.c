Scaleform::GFx::ASString *__thiscall Scaleform::GFx::DisplayObject::GetOriginalName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString *v5; // eax

  pObject = this->pNameHandle.pObject;
  if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0 )
  {
    pNode = pObject->OriginalName.pNode;
    v5 = result;
    result->pNode = pNode;
    ++pNode->RefCount;
  }
  else
  {
    Scaleform::GFx::DisplayObject::GetName(this, result);
    return result;
  }
  return v5;
}
