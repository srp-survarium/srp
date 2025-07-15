void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::interpolate(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *thisMat,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *toMat,
        long double percent)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, pVM);
  Scaleform::GFx::AS3::VM::ThrowError(pVM, v6);
  pNode = v8.Message.pNode;
  --v8.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
