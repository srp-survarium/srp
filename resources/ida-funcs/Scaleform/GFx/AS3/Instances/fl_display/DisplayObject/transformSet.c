void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::transformSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *value)
{
  Scaleform::GFx::DisplayObject *pObject; // ebx
  const Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::GFx::DisplayObject *v6; // esi
  Scaleform::Render::TreeNode *v7; // eax
  void (__thiscall **p_SetMatrix3D)(Scaleform::GFx::DisplayObject *, const Scaleform::Render::Matrix3x4<float> *); // ebx
  const Scaleform::Render::Matrix3x4<float> *v9; // eax
  void (__thiscall **p_SetMatrix)(Scaleform::GFx::DisplayObject *, const Scaleform::Render::Matrix2x4<float> *); // ebx
  const Scaleform::Render::Matrix2x4<float> *v11; // eax
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::DisplayObject *v13; // edi
  float v15[12]; // [esp+C0h] [ebp-70h] BYREF
  float v16[16]; // [esp+F0h] [ebp-40h] BYREF

  pObject = this->pDispObj.pObject;
  Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(value->pDispObj);
  Scaleform::GFx::DisplayObjectBase::SetCxform(pObject, Cxform);
  v6 = this->pDispObj.pObject;
  v7 = v6->pRenNode.pObject;
  if ( v7
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v7 & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&v7[-1] - ((unsigned int)v7 & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x200) != 0 )
  {
    p_SetMatrix3D = (void (__thiscall **)(Scaleform::GFx::DisplayObject *, const Scaleform::Render::Matrix3x4<float> *))&v6->SetMatrix3D;
    v9 = value->pDispObj->GetMatrix3D(value->pDispObj);
    (*p_SetMatrix3D)(v6, v9);
  }
  else
  {
    p_SetMatrix = (void (__thiscall **)(Scaleform::GFx::DisplayObject *, const Scaleform::Render::Matrix2x4<float> *))&v6->SetMatrix;
    v11 = value->pDispObj->GetMatrix(value->pDispObj);
    (*p_SetMatrix)(v6, v11);
  }
  memset((int)v15, 0, sizeof(v15));
  pDispObj = value->pDispObj;
  v15[0] = 1.0;
  v15[5] = 1.0;
  v15[10] = 1.0;
  if ( pDispObj->GetViewMatrix3D(pDispObj, (Scaleform::Render::Matrix3x4<float> *)v15, 0) )
    this->pDispObj.pObject->SetViewMatrix3D(this->pDispObj.pObject, (const Scaleform::Render::Matrix3x4<float> *)v15);
  memset((int)v16, 0, sizeof(v16));
  v13 = value->pDispObj;
  v16[0] = 1.0;
  v16[5] = 1.0;
  v16[10] = 1.0;
  v16[15] = 1.0;
  if ( v13->GetProjectionMatrix3D(v13, (Scaleform::Render::Matrix4x4<float> *)v16, 0) )
    this->pDispObj.pObject->SetProjectionMatrix3D(
      this->pDispObj.pObject,
      (const Scaleform::Render::Matrix4x4<float> *)v16);
}
