void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::merge(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::Render::DrawableImage *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::Render::DrawableImage *v8; // ebx
  double *pNext; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *Value; // edi
  Scaleform::GFx::AS3::Value *p_pQueue; // esi
  unsigned int *v12; // edi
  int v13; // ebx
  long double y; // st7
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v15; // eax
  double v16; // st7
  int v17; // eax
  double v18; // st7
  int v19; // eax
  double v20; // st7
  int v21; // eax
  double v22; // st7
  Scaleform::GFx::AS3::Instances::fl_geom::Point *pt[2]; // [esp+4h] [ebp-30h] BYREF
  Scaleform::Render::DrawableImage *srcImage; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v25; // [esp+10h] [ebp-24h]
  unsigned int multipliers[4]; // [esp+14h] [ebp-20h] BYREF
  Scaleform::Render::Rect<long> sourceRect; // [esp+24h] [ebp-10h] BYREF

  if ( this->pImage.pObject )
  {
    if ( argc == 7 )
    {
      v8 = argv;
      pNext = (double *)argv->pNext;
      Value = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->pTexture.Value;
      pt[0] = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)argv->DrawableImageState;
      argv = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
      srcImage = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, Value);
      if ( srcImage )
      {
        if ( argv )
        {
          p_pQueue = (Scaleform::GFx::AS3::Value *)&v8->pQueue;
          v12 = multipliers;
          v13 = 4;
          do
          {
            Scaleform::GFx::AS3::Value::Convert2UInt32(p_pQueue++, (Scaleform::GFx::AS3::CheckResult *)&argc, v12++);
            --v13;
          }
          while ( v13 );
          y = pt[0]->y;
          pt[0] = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(int)pt[0]->x;
          v15 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(int)y;
          v16 = pNext[6];
          pt[1] = v15;
          v17 = (int)v16;
          v18 = pNext[7];
          sourceRect.x1 = v17;
          v19 = (int)v18;
          v20 = pNext[5] + pNext[6];
          sourceRect.y1 = v19;
          v21 = (int)v20;
          v22 = pNext[4] + pNext[7];
          sourceRect.x2 = v21;
          sourceRect.y2 = (int)v22;
          Scaleform::Render::DrawableImage::Merge(
            argv,
            srcImage,
            &sourceRect,
            (const Scaleform::Render::Point<long> *)pt,
            multipliers[0],
            multipliers[1],
            multipliers[2],
            multipliers[3]);
        }
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&srcImage, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    v7 = v25;
    --v25->RefCount;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
