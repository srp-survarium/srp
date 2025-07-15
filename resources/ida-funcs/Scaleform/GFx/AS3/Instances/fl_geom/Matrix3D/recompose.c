void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::recompose(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *components,
        const Scaleform::GFx::ASString *orientationStyle)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v7; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  v7.pStr = "instance::Matrix3D::recompose() is not implemented yet";
  v7.Size = 54;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, this->pTraits.pObject->pVM, v7);
  Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v5);
  pNode = v8.Message.pNode;
  --v8.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
