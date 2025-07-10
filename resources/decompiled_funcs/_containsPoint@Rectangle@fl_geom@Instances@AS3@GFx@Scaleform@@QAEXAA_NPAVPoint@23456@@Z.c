void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::containsPoint(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+10h] [ebp-8h] BYREF

  if ( point )
  {
    Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::contains(this, result, point->x, point->y);
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
