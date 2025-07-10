int __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        const char *str)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+8h] [ebp-8h] BYREF

  if ( strcmp(str, "never") )
  {
    if ( !strcmp(str, "always") )
      return 1;
    if ( !strcmp(str, "auto") )
      return 2;
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eInvalidEnumError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v4);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  return 0;
}
