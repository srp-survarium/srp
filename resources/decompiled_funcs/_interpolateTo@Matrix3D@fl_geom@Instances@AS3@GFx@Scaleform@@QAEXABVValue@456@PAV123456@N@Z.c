void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::interpolateTo(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *toMat,
        long double percent)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v7, eNotImplementedError, pVM);
  Scaleform::GFx::AS3::VM::ThrowError(pVM, v5);
  pNode = v7.Message.pNode;
  --v7.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
