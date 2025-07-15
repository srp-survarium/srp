void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        bool *result)
{
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v5; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v6; // [esp+4h] [ebp-8h] BYREF

  if ( this->pImage.pObject )
  {
    *result = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this)->Transparent;
  }
  else
  {
    v5.pStr = "Invalid BitmapData";
    v5.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eArgumentError, this->pTraits.pObject->pVM, v5);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v3);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
