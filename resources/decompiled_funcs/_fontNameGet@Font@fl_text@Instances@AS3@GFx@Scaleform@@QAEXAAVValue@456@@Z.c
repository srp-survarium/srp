void __thiscall Scaleform::GFx::AS3::Instances::fl_text::Font::fontNameGet(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Font *pObject; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  char *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_fontName; // esi
  Scaleform::GFx::ASString v; // [esp+4h] [ebp-4h] BYREF

  pObject = this->pFont.pObject;
  if ( pObject )
  {
    StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
    v4 = (char *)pObject->GetName(this->pFont.pObject);
    v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v4);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Assign(result, &v);
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    p_fontName = &this->fontName;
    if ( Scaleform::GFx::ASConstString::GetLength(&this->fontName) )
      Scaleform::GFx::AS3::Value::Assign(result, p_fontName);
    else
      Scaleform::GFx::AS3::Value::SetNull(result);
  }
}
