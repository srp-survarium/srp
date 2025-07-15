void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        int *result)
{
  Scaleform::Render::ImageBase *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::Rect<unsigned long> *v7; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+0h] [ebp-10h] BYREF

  pObject = this->pImage.pObject;
  if ( pObject )
  {
    v7 = pObject->GetRect(pObject, (Scaleform::Render::Rect<unsigned long> *)&v8);
    *result = v7->x2 - v7->x1;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
