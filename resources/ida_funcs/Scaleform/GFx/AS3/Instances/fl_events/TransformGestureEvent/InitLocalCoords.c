void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::InitLocalCoords(
        Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *this)
{
  char v2; // bl
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // edi
  unsigned int RefCount; // eax
  bool v6; // zf
  const Scaleform::Render::Matrix2x4<float> *m; // eax
  double x; // st7
  char v9; // [esp+CFh] [ebp-51h]
  Scaleform::Render::Point<float> v10; // [esp+D0h] [ebp-50h] BYREF
  Scaleform::Render::Point<float> result; // [esp+D8h] [ebp-48h] BYREF
  Scaleform::Render::Matrix2x4<float> v; // [esp+E0h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v13; // [esp+100h] [ebp-20h] BYREF

  v2 = 0;
  v10.x = 0.0;
  if ( !this->LocalInitialized )
  {
    pObject = this->Target.pObject;
    if ( !pObject
      || (CurrentDomain = this->pTraits.pObject->pVM->CurrentDomain,
          v2 = 1,
          *(_QWORD *)&v.M[0][0] = 0,
          Scaleform::GFx::AS3::Value::AssignUnsafe((Scaleform::GFx::AS3::Value *)&v, pObject),
          v9 = 1,
          !Scaleform::GFx::AS3::VM::IsOfType(
             this->pTraits.pObject->pVM,
             (const Scaleform::GFx::AS3::Value *)&v,
             "flash.display.DisplayObject",
             CurrentDomain)) )
    {
      v9 = 0;
    }
    if ( (v2 & 1) != 0 && (LOBYTE(v.M[0][0]) & 0x1Fu) > 9 )
    {
      if ( (LOWORD(v.M[0][0]) & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v);
    }
    if ( v9 )
    {
      RefCount = this->Target.pObject[1].RefCount;
      v13.M[0][0] = 1.0;
      v6 = *(_DWORD *)(RefCount + 32) == 0;
      v13.M[0][1] = 0.0;
      v13.M[0][2] = 0.0;
      v13.M[0][3] = 0.0;
      v13.M[1][0] = 0.0;
      v13.M[1][2] = 0.0;
      v13.M[1][3] = 0.0;
      v13.M[1][1] = 1.0;
      if ( !v6 )
      {
        m = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
              *(Scaleform::GFx::DisplayObjectBase **)(RefCount + 32),
              &v);
        Scaleform::Render::Matrix2x4<float>::operator=(&v13, m);
      }
      v10.x = this->StageX;
      v10.y = this->StageY;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v13, (Scaleform::Render::Point<float> *)&v, &v10);
      v10.x = this->OffsetX + this->StageX;
      v10.y = this->OffsetY + this->StageY;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v13, &result, &v10);
      x = result.x;
      this->LocalInitialized = 1;
      this->LocalOffsetX = x - v.M[0][0];
      this->LocalOffsetY = result.y - v.M[0][1];
    }
    else
    {
      this->LocalInitialized = 1;
      this->LocalOffsetY = 0.0;
      this->LocalOffsetX = 0.0;
    }
  }
}
