void __thiscall Scaleform::Render::DICommand_ApplyFilter::ExecuteHWGetImages(
        Scaleform::Render::DICommand_ApplyFilter *this,
        Scaleform::Render::DrawableImage **images,
        Scaleform::Render::Size<float> *readOffsets)
{
  Scaleform::Render::Size<float> v3; // [esp+4h] [ebp-8h]

  *images = this->pImage.pObject;
  v3.Width = (float)this->DestPoint.x;
  v3.Height = (float)this->DestPoint.y;
  *readOffsets = v3;
  images[1] = this->pSource.pObject;
  v3.Width = (float)this->SourceRect.x1;
  v3.Height = (float)this->SourceRect.y1;
  readOffsets[1] = v3;
}
