void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::equals(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *toCompare,
        bool allFour)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v7; // al
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  if ( toCompare )
  {
    v7 = toCompare->x == this->x && toCompare->y == this->y && toCompare->z == this->z;
    *result = v7;
    if ( allFour )
      *result = v7 && toCompare->w == this->w;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
