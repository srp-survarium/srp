void __thiscall Scaleform::GFx::AS3::Instances::fl_text::Font::fontTypeGet(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::Font *pObject; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_fontType; // esi
  Scaleform::GFx::ASString v; // [esp+0h] [ebp-4h] BYREF

  v.pNode = (Scaleform::GFx::ASStringNode *)this;
  pObject = this->pFont.pObject;
  if ( pObject )
  {
    if ( (pObject->Flags & 0x10) != 0 )
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                          "device",
                          6u,
                          0);
    else
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                          "embedded",
                          8u,
                          0);
    v.pNode = ConstStringNode;
    ++ConstStringNode->RefCount;
    Scaleform::GFx::AS3::Value::Assign(result, &v);
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    p_fontType = &this->fontType;
    if ( Scaleform::GFx::ASConstString::GetLength(&this->fontType) )
      Scaleform::GFx::AS3::Value::Assign(result, p_fontType);
    else
      Scaleform::GFx::AS3::Value::SetNull(result);
  }
}
