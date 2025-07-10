void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::matrixSet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *value)
{
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::DisplayObject *v5; // ecx
  float tx; // [esp+ECh] [ebp-84h]
  float ty; // [esp+ECh] [ebp-84h]
  float a; // [esp+F0h] [ebp-80h] BYREF
  float c; // [esp+F4h] [ebp-7Ch]
  float v10; // [esp+F8h] [ebp-78h]
  float v11; // [esp+FCh] [ebp-74h]
  float b; // [esp+100h] [ebp-70h]
  float d; // [esp+104h] [ebp-6Ch]
  float v14; // [esp+108h] [ebp-68h]
  float v15; // [esp+10Ch] [ebp-64h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+110h] [ebp-60h] BYREF

  if ( this->pDispObj )
  {
    if ( value )
    {
      pDispObj = this->pDispObj;
      a = value->a;
      c = value->c;
      v10 = 0.0;
      tx = value->tx;
      v11 = tx * 20.0;
      b = value->b;
      d = value->d;
      v14 = 0.0;
      ty = value->ty;
      v15 = 20.0 * ty;
      pDispObj->SetMatrix(pDispObj, (const Scaleform::Render::Matrix2x4<float> *)&a);
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&gd);
      Scaleform::GFx::DisplayObjectBase::GetGeomData(this->pDispObj, &gd);
      gd.X = (int)v11;
      gd.Y = (int)v15;
      gd.Rotation = atan2(b, a) * 180.0 / 3.141592653589793;
      gd.XScale = sqrt(b * b + a * a) * 100.0;
      v5 = this->pDispObj;
      gd.YScale = sqrt(d * d + c * c) * 100.0;
      Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &gd);
    }
    this->pDispObj->SetAcceptAnimMoves(this->pDispObj, 0);
  }
}
