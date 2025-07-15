void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::decompose(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result,
        const Scaleform::GFx::ASString *orientationStyle)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v6; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-8h] BYREF

  v6.pStr = "instance::Matrix3D::decompose() is not implemented yet";
  v6.Size = 54;
  Scaleform::GFx::AS3::VM::Error::Error(&v7, eNotImplementedError, this->pTraits.pObject->pVM, v6);
  Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v4);
  pNode = v7.Message.pNode;
  --v7.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
