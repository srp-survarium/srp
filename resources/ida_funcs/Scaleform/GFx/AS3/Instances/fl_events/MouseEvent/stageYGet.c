void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::stageYGet(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        long double *result)
{
  char v2; // bl
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // edi
  Scaleform::GFx::DisplayObjectBase *RefCount; // ecx
  char v7; // [esp+5Fh] [ebp-31h]
  Scaleform::GFx::AS3::Value v; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+70h] [ebp-20h] BYREF

  v2 = 0;
  v.Flags = 0;
  pObject = this->Target.pObject;
  if ( !pObject
    || (CurrentDomain = this->pTraits.pObject->pVM->CurrentDomain,
        v2 = 1,
        v.Flags = 0,
        v.Bonus.pWeakProxy = 0,
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v, pObject),
        v7 = 1,
        !Scaleform::GFx::AS3::VM::IsOfType(this->pTraits.pObject->pVM, &v, "flash.display.DisplayObject", CurrentDomain)) )
  {
    v7 = 0;
  }
  if ( (v2 & 1) != 0 && (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  if ( v7 )
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
    *(float *)&v.Flags = this->LocalX;
    *(float *)&v.Bonus.pWeakProxy = this->LocalY;
    *(float *)&v.Flags = pmat.M[1][1] * *(float *)&v.Bonus.pWeakProxy + *(float *)&v.Flags * pmat.M[1][0] + pmat.M[1][3];
    *(float *)&v.Flags = *(float *)&v.Flags * 0.05000000074505806;
    *result = *(float *)&v.Flags;
  }
  else
  {
    *result = 0.0;
  }
}
