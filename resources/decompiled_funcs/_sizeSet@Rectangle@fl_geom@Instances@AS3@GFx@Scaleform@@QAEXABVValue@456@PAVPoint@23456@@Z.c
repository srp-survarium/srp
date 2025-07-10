void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::sizeSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *value)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( value )
  {
    this->width = value->x;
    this->height = value->y;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
