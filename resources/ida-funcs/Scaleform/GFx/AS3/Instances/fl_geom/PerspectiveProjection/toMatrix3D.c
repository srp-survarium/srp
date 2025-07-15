void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection::toMatrix3D(
        Scaleform::GFx::AS3::Instances::fl_geom::PerspectiveProjection *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  int v4; // edi
  double v5; // st7
  double v6; // st7
  Scaleform::GFx::AS3::Value *p_argv; // eax
  int v8; // ecx
  Scaleform::GFx::AS3::Value *v9; // esi
  unsigned int v10; // edx
  Scaleform::GFx::AS3::Value *v11; // esi
  int i; // edi
  unsigned int Flags; // eax
  float v14; // [esp+568h] [ebp-18Ch]
  float v15; // [esp+568h] [ebp-18Ch]
  float v16; // [esp+568h] [ebp-18Ch]
  float v17; // [esp+568h] [ebp-18Ch]
  float v18; // [esp+568h] [ebp-18Ch]
  float v19; // [esp+568h] [ebp-18Ch]
  float v20; // [esp+568h] [ebp-18Ch]
  float v21; // [esp+56Ch] [ebp-188h]
  float focalLength; // [esp+56Ch] [ebp-188h]
  float v23; // [esp+56Ch] [ebp-188h]
  float v24; // [esp+56Ch] [ebp-188h]
  Scaleform::GFx::AS3::CheckResult v25; // [esp+573h] [ebp-181h] BYREF
  unsigned __int8 src[64]; // [esp+574h] [ebp-180h] BYREF
  _DWORD dst[16]; // [esp+5B4h] [ebp-140h] BYREF
  Scaleform::GFx::AS3::Value argv; // [esp+5F4h] [ebp-100h] BYREF
  char vars0; // [esp+6F4h] [ebp+0h] BYREF

  pDispObj = this->pDispObj;
  v4 = 0;
  if ( pDispObj )
  {
    v14 = pDispObj->pASRoot->pMovieImpl->VisibleFrameRect.x2 - pDispObj->pASRoot->pMovieImpl->VisibleFrameRect.x1;
    v15 = fabs(v14);
    v5 = v15 * 0.05000000074505806;
  }
  else
  {
    v5 = 500.0;
  }
  if ( 0.0 == this->focalLength )
  {
    v16 = v5;
    v17 = v16 * 0.5;
    v21 = v17;
    v18 = this->fieldOfView * 3.141592653589793 / 180.0;
    v19 = 0.5 * v18;
    v20 = tan(v19);
    v6 = v21 / v20;
  }
  else
  {
    focalLength = this->focalLength;
    v6 = focalLength;
  }
  v23 = v6;
  memset((int)src, 0, sizeof(src));
  *(float *)&src[60] = 1.0;
  *(float *)src = v23;
  *(float *)&src[20] = v23;
  *(float *)&src[40] = 1.0;
  memcpy((int)dst, (const __m128i *)src, sizeof(dst));
  *(float *)&dst[14] = 1.0;
  p_argv = &argv;
  v8 = 15;
  *(float *)&dst[15] = 0.0;
  do
  {
    p_argv->Flags = 0;
    p_argv->Bonus.pWeakProxy = 0;
    ++p_argv;
    --v8;
  }
  while ( v8 >= 0 );
  v9 = &argv;
  do
  {
    v24 = *(float *)&dst[v4];
    if ( (v9->Flags & 0x1F) > 9 )
    {
      if ( (v9->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v9);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v9);
    }
    v10 = v9->Flags & 0xFFFFFFE4;
    v9->value.VNumber = v24;
    v9->Flags = v10 | 4;
    ++v4;
    ++v9;
  }
  while ( v4 < 16 );
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    this->pTraits.pObject->pVM,
    &v25,
    result,
    "flash.geom.Matrix3D",
    0x10u,
    &argv);
  v11 = (Scaleform::GFx::AS3::Value *)&vars0;
  for ( i = 15; i >= 0; --i )
  {
    Flags = v11[-1].Flags;
    --v11;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v11);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
    }
  }
}
