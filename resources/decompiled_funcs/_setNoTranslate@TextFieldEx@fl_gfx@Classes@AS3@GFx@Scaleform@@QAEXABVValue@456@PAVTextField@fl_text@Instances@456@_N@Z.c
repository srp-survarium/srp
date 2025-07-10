void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setNoTranslate(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        bool noTranslate)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

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
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eNullArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
