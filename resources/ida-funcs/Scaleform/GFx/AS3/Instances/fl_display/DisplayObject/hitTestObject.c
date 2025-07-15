void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::hitTestObject(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *obj)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v5; // ecx
  Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  Scaleform::Render::Matrix2x4<float> *v7; // eax
  __m128 v8; // [esp+128h] [ebp-60h] BYREF
  __m128 v9; // [esp+138h] [ebp-50h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+148h] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> v11; // [esp+158h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v12; // [esp+168h] [ebp-20h] BYREF

  v12.M[0][0] = 1.0;
  v12.M[0][1] = 0.0;
  v12.M[0][2] = 0.0;
  v12.M[0][3] = 0.0;
  *result = 0;
  pObject = this->pDispObj.pObject;
  v12.M[1][0] = 0.0;
  v12.M[1][2] = 0.0;
  v12.M[1][3] = 0.0;
  v12.M[1][1] = 1.0;
  pObject->GetBounds(pObject, (Scaleform::Render::Rect<float> *)&v8, &v12);
  if ( v8.m128_f32[0] != v8.m128_f32[2] || v8.m128_f32[1] != v8.m128_f32[3] )
  {
    if ( obj )
    {
      v5 = obj->pDispObj.pObject;
      v12.M[0][0] = 1.0;
      v12.M[0][1] = 0.0;
      v12.M[0][2] = 0.0;
      v12.M[0][3] = 0.0;
      v12.M[1][0] = 0.0;
      v12.M[1][2] = 0.0;
      v12.M[1][3] = 0.0;
      v12.M[1][1] = 1.0;
      v5->GetBounds(v5, (Scaleform::Render::Rect<float> *)&v9, &v12);
      if ( v9.m128_f32[0] != v9.m128_f32[2] || v9.m128_f32[1] != v9.m128_f32[3] )
      {
        WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this->pDispObj.pObject, &v12);
        Scaleform::Render::Matrix2x4<float>::EncloseTransform(WorldMatrix, (__m128 *)&v11, &v8);
        v7 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(obj->pDispObj.pObject, &v12);
        Scaleform::Render::Matrix2x4<float>::EncloseTransform(v7, (__m128 *)&r, &v9);
        *result = Scaleform::Render::Rect<float>::Intersects(&v11, &r);
      }
    }
  }
}
