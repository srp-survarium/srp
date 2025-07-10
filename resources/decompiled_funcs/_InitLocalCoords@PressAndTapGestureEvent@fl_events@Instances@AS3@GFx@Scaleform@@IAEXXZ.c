void __thiscall Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::InitLocalCoords(
        Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *this)
{
  char v2; // bl
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // edi
  Scaleform::GFx::DisplayObjectBase *RefCount; // ecx
  char v6; // [esp+6Fh] [ebp-39h]
  Scaleform::Render::Point<float> v7; // [esp+70h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+78h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+88h] [ebp-20h] BYREF

  v2 = 0;
  v7.x = 0.0;
  if ( !this->LocalInitialized )
  {
    if ( !this->TapStageSet
      || (pObject = this->Target.pObject) == 0
      || (CurrentDomain = this->pTraits.pObject->pVM->CurrentDomain,
          v2 = 1,
          v.Flags = 0,
          v.Bonus.pWeakProxy = 0,
          Scaleform::GFx::AS3::Value::AssignUnsafe(&v, pObject),
          v6 = 1,
          !Scaleform::GFx::AS3::VM::IsOfType(
             this->pTraits.pObject->pVM,
             &v,
             "flash.display.DisplayObject",
             CurrentDomain)) )
    {
      v6 = 0;
    }
    if ( (v2 & 1) != 0 && (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
    if ( v6 )
    {
      RefCount = (Scaleform::GFx::DisplayObjectBase *)this->Target.pObject[1].RefCount;
      pmat.M[0][0] = 1.0;
      pmat.M[0][1] = 0.0;
      pmat.M[0][2] = 0.0;
      pmat.M[0][3] = 0.0;
      pmat.M[1][0] = 0.0;
      pmat.M[1][2] = 0.0;
      pmat.M[1][3] = 0.0;
      pmat.M[1][1] = 1.0;
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(RefCount, &pmat);
      v7.x = this->TapStageX;
      v7.y = this->TapStageY;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, (Scaleform::Render::Point<float> *)&v, &v7);
      this->TapLocalX = *(float *)&v.Flags;
      this->LocalInitialized = 1;
      this->TapLocalY = *(float *)&v.Bonus.pWeakProxy;
    }
    else
    {
      this->LocalInitialized = 1;
      this->TapLocalY = 0.0;
      this->TapLocalX = 0.0;
    }
  }
}
