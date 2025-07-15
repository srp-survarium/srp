void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getVector(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v6; // edi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  long double x; // st7
  int v10; // eax
  long double y; // st7
  int v12; // eax
  long double v13; // st7
  int v14; // eax
  long double v15; // st7
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v16; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *pObject; // edx
  Scaleform::StringDataPtr v19; // [esp-8h] [ebp-3Ch]
  Scaleform::StringDataPtr v20; // [esp-8h] [ebp-3Ch]
  Scaleform::Render::DrawableImage *image; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::ASStringNode *v22; // [esp+14h] [ebp-20h]
  Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider provider; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::Render::Rect<long> r; // [esp+24h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    v19.pStr = "Invalid BitmapData";
    v19.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&image,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v19);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v4);
    goto LABEL_3;
  }
  v6 = rect;
  if ( !rect )
  {
    v20.pStr = "rect";
    v20.Size = 4;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&image,
      eNullPointerError,
      this->pTraits.pObject->pVM,
      v20);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v7);
LABEL_3:
    v5 = v22;
    --v22->RefCount;
    if ( !v5->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    return;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  x = v6->x;
  image = DrawableImageFromBitmapData;
  v10 = (int)x;
  y = v6->y;
  r.x1 = v10;
  v12 = (int)y;
  v13 = v6->width + v6->x;
  r.y1 = v12;
  v14 = (int)v13;
  v15 = v6->height + v6->y;
  r.x2 = v14;
  r.y2 = (int)v15;
  if ( v14 != r.x1 && (int)v15 != r.y1 )
  {
    Scaleform::GFx::AS3::VM::constructBuiltinObject(
      this->pTraits.pObject->pVM,
      (Scaleform::GFx::AS3::CheckResult *)&rect,
      result,
      "Vector.<uint>",
      0,
      0);
    if ( (_BYTE)rect )
    {
      Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthSet(
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)result->pObject,
        4 * (r.y2 - r.y1) * (r.x2 - r.x1));
      pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)result->pObject;
      provider.__vftable = (Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider_vtbl *)&Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::`vftable';
      provider.Location = 0;
      provider.PixelVector = pObject;
      Scaleform::Render::DrawableImage::GetPixels(image, &provider, &r);
    }
    else
    {
      v16 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)result->pObject;
      if ( result->pObject )
      {
        if ( ((unsigned __int8)v16 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v16 - 1);
          result->pObject = 0;
        }
        else
        {
          RefCount = v16->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v16->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
          }
          result->pObject = 0;
        }
      }
    }
  }
}
