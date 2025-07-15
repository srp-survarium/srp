void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setNoTranslate(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        bool noTranslate)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( textField )
  {
    pObject = textField->pDispObj.pObject;
    if ( noTranslate )
      *(_DWORD *)&pObject[1].ClipDepth |= 8u;
    else
      *(_DWORD *)&pObject[1].ClipDepth &= ~8u;
  }
  else
  {
    v8.pStr = "TextFieldEx::setNoTranslate";
    v8.Size = 27;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eNullArgumentError, this->pTraits.pObject->pVM, v8);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
