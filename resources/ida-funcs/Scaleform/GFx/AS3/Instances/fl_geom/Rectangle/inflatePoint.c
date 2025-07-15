void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::inflatePoint(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  long double x; // st7
  long double y; // st6
  Scaleform::GFx::AS3::VM::Error v8; // [esp+0h] [ebp-8h] BYREF

  if ( point )
  {
    x = point->x;
    y = point->y;
    this->x = this->x - x;
    this->width = x * 2.0 + this->width;
    this->y = this->y - y;
    this->height = 2.0 * y + this->height;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
