void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginBitmapFill(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *bitmap,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *matrix,
        bool repeat,
        bool smooth)
{
  Scaleform::GFx::ImageResource *ImageResource; // edi
  const Scaleform::Render::Matrix2x4<float> *MatrixF; // eax
  Scaleform::GFx::FillType v9; // esi
  Scaleform::Render::Matrix2x4<float> mtx; // [esp+50h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v11; // [esp+70h] [ebp-20h] BYREF

  if ( bitmap )
  {
    ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(bitmap);
    if ( ImageResource )
    {
      mtx.M[0][0] = 1.0;
      mtx.M[0][1] = 0.0;
      mtx.M[0][2] = 0.0;
      mtx.M[0][3] = 0.0;
      mtx.M[1][0] = 0.0;
      mtx.M[1][2] = 0.0;
      mtx.M[1][3] = 0.0;
      mtx.M[1][1] = 1.0;
      if ( matrix )
      {
        MatrixF = Scaleform::GFx::AS3::Instances::fl_geom::Matrix::GetMatrixF(matrix, &v11);
        Scaleform::Render::Matrix2x4<float>::operator=(&mtx, MatrixF);
      }
      if ( smooth )
        v9 = !repeat + 64;
      else
        v9 = !repeat + 66;
      Scaleform::GFx::DrawingContext::AcquirePath(this->pDrawing.pObject, 1);
      Scaleform::GFx::DrawingContext::BeginBitmapFill(this->pDrawing.pObject, v9, ImageResource, &mtx);
    }
  }
}
