int __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        const char *str)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v6; // [esp-8h] [ebp-18h]
  Scaleform::GFx::AS3::VM::Error v7; // [esp+8h] [ebp-8h] BYREF

  if ( strcmp(str, "never") )
  {
    if ( !strcmp(str, "always") )
      return 1;
    if ( !strcmp(str, "auto") )
      return 2;
    v6.pStr = "pixelSnapping";
    v6.Size = 13;
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eInvalidEnumError, this->pTraits.pObject->pVM, v6);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v4);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  return 0;
}
