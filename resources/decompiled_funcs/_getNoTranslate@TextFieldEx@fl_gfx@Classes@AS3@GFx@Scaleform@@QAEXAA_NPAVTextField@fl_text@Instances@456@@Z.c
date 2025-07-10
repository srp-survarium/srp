void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::getNoTranslate(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( textField )
  {
    *result = (*(_DWORD *)&textField->pDispObj.pObject[1].ClipDepth & 8) != 0;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eNullArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v4);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
