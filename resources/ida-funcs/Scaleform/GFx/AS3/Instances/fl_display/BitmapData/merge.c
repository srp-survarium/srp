void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::merge(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::Render::DrawableImage *argv)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::Render::DrawableImage *v7; // ebx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *Value; // edi
  double *pNext; // ebp
  Scaleform::GFx::AS3::Value *p_pQueue; // esi
  unsigned int *v11; // edi
  int v12; // ebx
  long double y; // st7
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v14; // eax
  double v15; // st7
  int v16; // eax
  double v17; // st7
  int v18; // eax
  double v19; // st7
  int v20; // eax
  double v21; // st7
  Scaleform::StringDataPtr v22; // [esp-8h] [ebp-48h]
  Scaleform::GFx::AS3::Instances::fl_geom::Point *pt[2]; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::DrawableImage *srcImage; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v25; // [esp+1Ch] [ebp-24h]
  unsigned int multipliers[4]; // [esp+20h] [ebp-20h] BYREF
  Scaleform::Render::Rect<long> sourceRect; // [esp+30h] [ebp-10h] BYREF

  if ( this->pImage.pObject )
  {
    if ( argc == 7 )
    {
      v7 = argv;
      Value = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->pTexture.Value;
      pNext = (double *)argv->pNext;
      pt[0] = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)argv->DrawableImageState;
      argv = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
      srcImage = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, Value);
      if ( srcImage )
      {
        if ( argv )
        {
          p_pQueue = (Scaleform::GFx::AS3::Value *)&v7->pQueue;
          v11 = multipliers;
          v12 = 4;
          do
          {
            Scaleform::GFx::AS3::Value::Convert2UInt32(p_pQueue++, (Scaleform::GFx::AS3::CheckResult *)&argc, v11++);
            --v12;
          }
          while ( v12 );
          y = pt[0]->y;
          pt[0] = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(int)pt[0]->x;
          v14 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(int)y;
          v15 = pNext[6];
          pt[1] = v14;
          v16 = (int)v15;
          v17 = pNext[7];
          sourceRect.x1 = v16;
          v18 = (int)v17;
          v19 = pNext[5] + pNext[6];
          sourceRect.y1 = v18;
          v20 = (int)v19;
          v21 = pNext[4] + pNext[7];
          sourceRect.x2 = v20;
          sourceRect.y2 = (int)v21;
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
    v22.pStr = "Invalid BitmapData";
    v22.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&srcImage,
      eArgumentError,
      this->pTraits.pObject->pVM,
      v22);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    v6 = v25;
    --v25->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}
