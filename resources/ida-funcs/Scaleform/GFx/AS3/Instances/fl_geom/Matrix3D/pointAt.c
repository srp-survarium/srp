void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::pointAt(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *pos,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *at,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *up)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  double v9; // st7
  double x; // [esp+170h] [ebp-98h]
  double v11; // [esp+170h] [ebp-98h]
  double y; // [esp+178h] [ebp-90h]
  double v13; // [esp+178h] [ebp-90h]
  double z; // [esp+180h] [ebp-88h]
  Scaleform::GFx::AS3::VM::Error v15; // [esp+188h] [ebp-80h] BYREF
  Scaleform::Render::Point3<double> upVec; // [esp+190h] [ebp-78h] BYREF
  Scaleform::Render::Point3<double> lookAtPt[2]; // [esp+1A8h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> eyePt; // [esp+1D8h] [ebp-30h] BYREF

  if ( pos )
  {
    *(double *)&eyePt.M[0][0] = pos->x;
    *(double *)&eyePt.M[0][2] = pos->y;
    *(double *)&eyePt.M[1][0] = pos->z;
    if ( at )
    {
      x = at->x;
      y = at->y;
      z = at->z;
    }
    else
    {
      x = 0.0;
      z = 0.0;
      y = 1.0;
    }
    lookAtPt[0].x = x;
    lookAtPt[0].y = y;
    lookAtPt[0].z = z;
    if ( up )
    {
      v11 = up->x;
      v13 = up->y;
      v9 = up->z;
    }
    else
    {
      v9 = 1.0;
      v11 = 0.0;
      v13 = 0.0;
    }
    upVec.x = v11;
    upVec.y = v13;
    upVec.z = v9;
    Scaleform::Render::Matrix4x4<double>::ViewRH(
      &this->mat4,
      (const Scaleform::Render::Point3<double> *)&eyePt,
      lookAtPt,
      &upVec);
    if ( this->pDispObj )
    {
      Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(&this->mat4, &eyePt);
      memcpy((unsigned __int8 *)lookAtPt, (unsigned __int8 *)&eyePt, sizeof(lookAtPt));
      this->pDispObj->SetMatrix3D(this->pDispObj, (const Scaleform::Render::Matrix3x4<float> *)lookAtPt);
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v7);
    pNode = v15.Message.pNode;
    --v15.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
