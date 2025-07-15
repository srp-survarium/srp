void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::containsRect(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  long double x; // st7
  long double y; // st6
  long double v8; // st5
  long double v9; // st4
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-8h] BYREF

  if ( rect )
  {
    if ( 0.0 == rect->height && 0.0 == rect->width )
    {
      *result = rect->x > this->x && rect->y > this->y;
    }
    else
    {
      x = rect->x;
      y = rect->y;
      v8 = this->x;
      v9 = this->y;
      *result = rect->width + x <= this->width + v8 && y + rect->height <= this->height + v9 && v8 <= x && y >= v9;
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v10.Message.pNode;
    --v10.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
