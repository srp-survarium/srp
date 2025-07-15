Scaleform::GFx::ASString *__thiscall Scaleform::GFx::DisplayObject::GetName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString *v5; // eax
  Scaleform::GFx::ASMovieRootBase *v6; // ecx
  int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx

  pObject = this->pNameHandle.pObject;
  if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0 )
  {
    pNode = pObject->Name.pNode;
    v5 = result;
    ++pNode->RefCount;
    result->pNode = pNode;
  }
  else
  {
    v6 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v7 = (int)v6->GetStringManager(v6);
    ++*(_DWORD *)(v7 + 44);
    v8 = (Scaleform::GFx::ASStringNode *)(v7 + 32);
    v5 = result;
    result->pNode = v8;
  }
  return v5;
}
