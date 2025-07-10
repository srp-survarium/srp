void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::rawDataSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *value)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v4; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::Matrix4x4<double> *p_mat4; // ebx
  unsigned int v9; // esi
  char v10; // al
  Scaleform::GFx::DisplayObject *pDispObj; // edi
  Scaleform::GFx::AS3::VM::Error v12; // [esp+B8h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Value v13; // [esp+C0h] [ebp-70h] BYREF
  unsigned __int8 src[48]; // [esp+D0h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+100h] [ebp-30h] BYREF

  v4 = value;
  if ( value )
  {
    p_mat4 = &this->mat4;
    v9 = 0;
    v12.ID = (Scaleform::GFx::AS3::VM::ErrorID)&this->mat4;
    while ( 1 )
    {
      v10 = 0;
      v13.Flags = 0;
      v13.Bonus.pWeakProxy = 0;
      if ( v9 < v4->V.ValueA.Data.Size )
      {
        v10 = 4;
        v13.value.VNumber = v4->V.ValueA.Data.Data[v9];
        v13.Flags = 4;
      }
      *(double *)v12.ID = v13.value.VNumber;
      if ( (v10 & 0x1Fu) > 9 )
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
      v12.ID += 8;
      if ( (int)++v9 >= 16 )
        break;
      v4 = value;
    }
    Scaleform::Render::Matrix4x4<double>::Transpose(&this->mat4);
    this->mat4.M[0][3] = this->mat4.M[0][3] * 20.0;
    this->mat4.M[1][3] = this->mat4.M[1][3] * 20.0;
    this->mat4.M[2][3] = 20.0 * this->mat4.M[2][3];
    pDispObj = this->pDispObj;
    if ( pDispObj )
    {
      *(float *)src = p_mat4->M[0][0];
      *(float *)&src[4] = p_mat4->M[0][1];
      *(float *)&src[8] = p_mat4->M[0][2];
      *(float *)&src[12] = p_mat4->M[0][3];
      *(float *)&src[16] = p_mat4->M[1][0];
      *(float *)&src[20] = p_mat4->M[1][1];
      *(float *)&src[24] = p_mat4->M[1][2];
      *(float *)&src[28] = p_mat4->M[1][3];
      *(float *)&src[32] = p_mat4->M[2][0];
      *(float *)&src[36] = p_mat4->M[2][1];
      *(float *)&src[40] = p_mat4->M[2][2];
      *(float *)&src[44] = p_mat4->M[2][3];
      memcpy((unsigned __int8 *)&dst, src, sizeof(dst));
      pDispObj->SetMatrix3D(pDispObj, &dst);
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
