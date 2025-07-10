void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::dotProduct(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        long double *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *a)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( a )
  {
    *result = a->y * this->y + a->x * this->x + a->z * this->z;
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
