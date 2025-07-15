void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::interpolate(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *thisMat,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *toMat,
        long double percent)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+4h] [ebp-8h] BYREF

  v8.pStr = "instance::Matrix3D::interpolate() is not implemented yet";
  v8.Size = 56;
  Scaleform::GFx::AS3::VM::Error::Error(&v9, eNotImplementedError, this->pTraits.pObject->pVM, v8);
  Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v6);
  pNode = v9.Message.pNode;
  --v9.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
