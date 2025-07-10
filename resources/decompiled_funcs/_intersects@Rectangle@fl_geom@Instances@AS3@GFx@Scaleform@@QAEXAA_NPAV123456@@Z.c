void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::intersects(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *toIntersect)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+8h] [ebp-8h] BYREF

  if ( toIntersect )
  {
    if ( toIntersect->width > 0.0 && toIntersect->height > 0.0 )
    {
      if ( this->width <= 0.0 || this->height <= 0.0 )
      {
        *result = 0;
        return;
      }
      if ( this->y + this->height >= toIntersect->y
        && toIntersect->y + toIntersect->height >= this->y
        && toIntersect->x + toIntersect->width >= this->x
        && this->x + this->width >= toIntersect->x )
      {
        *result = 1;
        return;
      }
    }
    *result = 0;
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
