void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixels(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v8; // esi
  Scaleform::GFx::AS3::VM *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  long double x; // st7
  int v14; // eax
  long double y; // st7
  int v16; // eax
  long double v17; // st7
  int v18; // eax
  long double v19; // st7
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v20; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pObject; // eax
  Scaleform::Render::DrawableImage *image; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::ASStringNode *v24; // [esp+Ch] [ebp-1Ch]
  Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider provider; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> r; // [esp+18h] [ebp-10h] BYREF

  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&image, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    v6 = v24;
    --v24->RefCount;
    v7 = v6;
    if ( v6->RefCount )
      return;
    goto LABEL_3;
  }
  v8 = rect;
  if ( rect )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    x = v8->x;
    image = DrawableImageFromBitmapData;
    v14 = (int)x;
    y = v8->y;
    r.x1 = v14;
    v16 = (int)y;
    v17 = v8->width + v8->x;
    r.y1 = v16;
    v18 = (int)v17;
    v19 = v8->height + v8->y;
    r.x2 = v18;
    r.y2 = (int)v19;
    if ( v18 != r.x1 && (int)v19 != r.y1 )
    {
      Scaleform::GFx::AS3::VM::constructBuiltinObject(
        this->pTraits.pObject->pVM,
        (Scaleform::GFx::AS3::CheckResult *)&rect,
        result,
        "flash.utils.ByteArray",
        0,
        0);
      if ( (_BYTE)rect )
      {
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(
          (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)result->pObject,
          4 * (r.y2 - r.y1) * (r.x2 - r.x1));
        pObject = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)result->pObject;
        provider.__vftable = (Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider_vtbl *)&Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::`vftable';
        provider.PixelArray = pObject;
        Scaleform::Render::DrawableImage::GetPixels(image, &provider, &r);
      }
      else
      {
        v20 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)result->pObject;
        if ( result->pObject )
        {
          if ( ((unsigned __int8)v20 & 1) != 0 )
          {
            result->pObject = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)((char *)v20 - 1);
            result->pObject = 0;
          }
          else
          {
            RefCount = v20->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              v20->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
            }
            result->pObject = 0;
          }
        }
      }
    }
  }
  else
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&image, eNullPointerError, v9);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v9, v10);
    v11 = v24;
    --v24->RefCount;
    v7 = v11;
    if ( !v11->RefCount )
LABEL_3:
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
