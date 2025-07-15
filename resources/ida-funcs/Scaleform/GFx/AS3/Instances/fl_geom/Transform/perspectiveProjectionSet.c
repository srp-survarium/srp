void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::perspectiveProjectionSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *value)
{
  void (__thiscall *v4)(Scaleform::GFx::AS3::VM *); // ecx
  float *v5; // eax
  long double v6; // st7
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  void (__thiscall *SetFocalLength)(Scaleform::GFx::DisplayObjectBase *, long double); // eax
  Scaleform::GFx::DisplayObject *v9; // ecx
  Scaleform::GFx::DisplayObject_vtbl *v10; // edx
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  Scaleform::Render::Point<float> *v12; // eax
  Scaleform::Render::Point<float> ptIn; // [esp+28h] [ebp-20h] BYREF
  float x; // [esp+30h] [ebp-18h]
  float y; // [esp+34h] [ebp-14h]
  Scaleform::Render::Point<float> v16; // [esp+38h] [ebp-10h] BYREF

  if ( value && this->pDispObj )
  {
    v4 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
    v5 = (float *)(*(int (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), Scaleform::Render::Point<float> *))(*(_DWORD *)v4 + 68))(
                    v4,
                    &v16);
    ptIn.x = v5[2] - *v5;
    *(double *)&v16 = ptIn.x * 0.5;
    value->focalLength = *(double *)&v16 / tan(0.5 * value->fieldOfView * 0.0174532925199433);
    v6 = value->focalLength * 20.0;
    value->pDispObj = this->pDispObj;
    pDispObj = this->pDispObj;
    SetFocalLength = pDispObj->SetFocalLength;
    ptIn.x = v6;
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD, _DWORD))SetFocalLength)(
      pDispObj,
      COERCE_UNSIGNED_INT64(ptIn.x),
      HIDWORD(COERCE_UNSIGNED_INT64(ptIn.x)));
    v9 = this->pDispObj;
    v10 = v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    ptIn.x = value->fieldOfView;
    ((void (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD, _DWORD))v10->SetFOV)(
      v9,
      COERCE_UNSIGNED_INT64(ptIn.x),
      HIDWORD(COERCE_UNSIGNED_INT64(ptIn.x)));
    pParent = this->pDispObj->pParent;
    v12 = &v16;
    if ( pParent )
    {
      ptIn.x = value->projectionCenter.x;
      ptIn.y = value->projectionCenter.y;
      x = ptIn.x * 20.0;
      y = 20.0 * ptIn.y;
      ptIn.x = x;
      ptIn.y = y;
      v12 = Scaleform::GFx::DisplayObjectBase::LocalToGlobal(pParent, &v16, &ptIn);
    }
    else
    {
      x = value->projectionCenter.x;
      y = value->projectionCenter.y;
      ptIn.x = x * 20.0;
      ptIn.y = 20.0 * y;
      v16.x = ptIn.x;
      v16.y = ptIn.y;
    }
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->pDispObj->SetProjectionCenter)(this->pDispObj, v12->x, v12->y);
  }
}
