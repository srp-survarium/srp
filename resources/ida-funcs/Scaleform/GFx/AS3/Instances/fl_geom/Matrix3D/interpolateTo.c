void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::interpolateTo(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *toMat,
        long double percent)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v7; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  v7.pStr = "instance::Matrix3D::interpolateTo() is not implemented yet";
  v7.Size = 58;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, this->pTraits.pObject->pVM, v7);
  Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v5);
  pNode = v8.Message.pNode;
  --v8.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
