void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Point::equals(
        Scaleform::GFx::AS3::Instances::fl_geom::Point *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *toCompare)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( toCompare )
  {
    *result = toCompare->x == this->x && toCompare->y == this->y;
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
