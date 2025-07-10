void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::hitTestObject(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *obj)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v5; // ecx
  Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  Scaleform::Render::Matrix2x4<float> *v7; // eax
  Scaleform::Render::Rect<float> r; // [esp+128h] [ebp-60h] BYREF
  Scaleform::Render::Rect<float> v9; // [esp+138h] [ebp-50h] BYREF
  Scaleform::Render::Rect<float> v10; // [esp+148h] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+158h] [ebp-30h] BYREF
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
  pObject->GetBounds(pObject, &r, &v12);
  if ( r.x1 != r.x2 || r.y1 != r.y2 )
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
      v5->GetBounds(v5, &v9, &v12);
      if ( v9.x1 != v9.x2 || v9.y1 != v9.y2 )
      {
        WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this->pDispObj.pObject, &v12);
        Scaleform::Render::Matrix2x4<float>::EncloseTransform(WorldMatrix, &pr, (__m128 *)&r);
        v7 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(obj->pDispObj.pObject, &v12);
        Scaleform::Render::Matrix2x4<float>::EncloseTransform(v7, &v10, (__m128 *)&v9);
        *result = Scaleform::Render::Rect<float>::Intersects(&pr, &v10);
      }
    }
  }
}
