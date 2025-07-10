void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::scale9GridSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *value)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  float x; // [esp+1Ch] [ebp-14h]
  float y; // [esp+1Ch] [ebp-14h]
  float width; // [esp+1Ch] [ebp-14h]
  float v7; // [esp+1Ch] [ebp-14h]
  float height; // [esp+1Ch] [ebp-14h]
  float v9; // [esp+1Ch] [ebp-14h]
  float v10; // [esp+20h] [ebp-10h] BYREF
  float v11; // [esp+24h] [ebp-Ch]
  float v12; // [esp+28h] [ebp-8h]
  float v13; // [esp+2Ch] [ebp-4h]

  pObject = this->pDispObj.pObject;
  if ( value )
  {
    x = value->x;
    v10 = x * 20.0;
    y = value->y;
    v11 = y * 20.0;
    width = value->width;
    v7 = width * 20.0;
    v12 = v7 + v10;
    height = value->height;
    v9 = 20.0 * height;
    v13 = v9 + v11;
  }
  else
  {
    v10 = 0.0;
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
  }
  pObject->SetScale9Grid(pObject, (const Scaleform::Render::Rect<float> *)&v10);
}
