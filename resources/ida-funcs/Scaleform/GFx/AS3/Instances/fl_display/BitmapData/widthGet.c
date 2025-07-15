void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        int *result)
{
  Scaleform::Render::ImageBase *pObject; // ecx
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::Rect<unsigned long> *v6; // eax
  Scaleform::StringDataPtr v7; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-10h] BYREF

  pObject = this->pImage.pObject;
  if ( pObject )
  {
    v6 = pObject->GetRect(pObject, (Scaleform::Render::Rect<unsigned long> *)&v8);
    *result = v6->x2 - v6->x1;
  }
  else
  {
    v7.pStr = "Invalid BitmapData";
    v7.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eArgumentError, this->pTraits.pObject->pVM, v7);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v4);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
