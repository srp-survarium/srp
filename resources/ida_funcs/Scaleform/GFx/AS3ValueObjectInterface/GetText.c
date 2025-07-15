bool __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::ASString reqHtml)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // ebp
  int v6; // eax
  Scaleform::GFx::TextField *v8; // edi
  const char *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value value; // [esp+Ch] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v6 + 60) - 17) >= 0xC || (*(_DWORD *)(v6 + 56) & 0x20) != 0 )
    return 0;
  v8 = (Scaleform::GFx::TextField *)pdata[12];
  if ( v8->GetType(v8) == MouseWheel )
  {
    Scaleform::GFx::TextField::GetText(v8, &reqHtml, (Scaleform::String)reqHtml.pNode);
    Scaleform::GFx::AS3::Value::Value(&value, &reqHtml);
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, (Scaleform::GFx::ASStringNode *)pval);
    Scaleform::GFx::AS3::Value::~Value(&value);
    pNode = reqHtml.pNode;
    --reqHtml.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 1;
  }
  else
  {
    v9 = "htmlText";
    if ( !LOBYTE(reqHtml.pNode) )
      v9 = "text";
    return this->GetMember(this, pdata, v9, pval, 1);
  }
}
