void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        bool *result)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v5; // [esp+0h] [ebp-8h] BYREF

  if ( this->pImage.pObject )
  {
    *result = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this)->Transparent;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v5, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v3);
    pNode = v5.Message.pNode;
    --v5.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
