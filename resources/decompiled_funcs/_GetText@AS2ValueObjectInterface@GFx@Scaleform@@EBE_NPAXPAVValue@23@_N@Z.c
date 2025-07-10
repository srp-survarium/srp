bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pval,
        Scaleform::String reqHtml)
{
  Scaleform::GFx::CharacterHandle *v5; // edi
  Scaleform::GFx::TextField *v6; // ebx
  const char *v8; // eax
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  int v10; // ecx
  Scaleform::GFx::AS2::Environment *v11; // edi
  Scaleform::GFx::CharacterHandle *v12; // eax
  Scaleform::GFx::Value *v13; // edx
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS2::Value value; // [esp+Ch] [ebp-10h] BYREF

  v5 = pdata;
  v6 = (Scaleform::GFx::TextField *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v6 )
    return 0;
  if ( v6->GetType(v6) == MouseWheel )
  {
    pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
    v10 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
    v11 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 124))(v10);
    Scaleform::GFx::TextField::GetText(v6, (Scaleform::GFx::ASString *)&pdata, reqHtml);
    v12 = pdata;
    v13 = pval;
    ++pdata->NamePath.pNode;
    value.NV.Int32Value = (int)v12;
    value.T.Type = 5;
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v11, &value, v13);
    Scaleform::GFx::AS2::Value::DropRefs(&value);
    v14 = (Scaleform::GFx::ASStringNode *)pdata;
    --pdata->NamePath.pNode;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    return 1;
  }
  else
  {
    v8 = "htmlText";
    if ( !LOBYTE(reqHtml.pData) )
      v8 = "text";
    return this->GetMember(this, v5, v8, pval, 1);
  }
}
