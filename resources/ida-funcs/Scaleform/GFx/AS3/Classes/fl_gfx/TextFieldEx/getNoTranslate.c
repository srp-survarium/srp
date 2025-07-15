void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getNoTranslate(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v6; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( textField )
  {
    *result = (*(_DWORD *)&textField->pDispObj.pObject[1].ClipDepth & 8) != 0;
  }
  else
  {
    v6.pStr = "TextFieldEx::getNoTranslate";
    v6.Size = 27;
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eNullArgumentError, this->pTraits.pObject->pVM, v6);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v4);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
