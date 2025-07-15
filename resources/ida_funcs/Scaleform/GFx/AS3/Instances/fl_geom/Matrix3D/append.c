void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::append(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *lhs)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+C8h] [ebp-E8h] BYREF
  Scaleform::Render::Matrix3x4<float> v8; // [esp+D0h] [ebp-E0h] BYREF
  unsigned __int8 v9[48]; // [esp+100h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix4x4<double> dst; // [esp+130h] [ebp-80h] BYREF

  if ( lhs )
  {
    memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)&this->mat4, sizeof(dst));
    Scaleform::Render::Matrix4x4<double>::MultiplyMatrix_NonOpt(&this->mat4, &lhs->mat4, &dst);
    if ( this->pDispObj )
    {
      Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(&this->mat4, &v8);
      memcpy(v9, (unsigned __int8 *)&v8, sizeof(v9));
      this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)v9);
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
