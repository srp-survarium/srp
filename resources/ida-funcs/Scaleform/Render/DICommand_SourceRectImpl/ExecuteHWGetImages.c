void __thiscall Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_CopyChannel>::ExecuteHWGetImages(
        Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *this,
        Scaleform::Render::DrawableImage **images,
        Scaleform::Render::Size<float> *readOffsets)
{
  int v4; // edi
  Scaleform::Render::Size<float> v5; // [esp+8h] [ebp-8h]
  Scaleform::Render::Size<float> v6; // [esp+8h] [ebp-8h]

  v4 = 0;
  if ( this->GetRequireSourceRead(this) )
  {
    *images = this->pImage.pObject;
    v4 = 1;
    v5.Width = (float)this->DestPoint.x;
    v5.Height = (float)this->DestPoint.y;
    *readOffsets = v5;
  }
  images[v4] = this->pSource.pObject;
  v6.Width = (float)this->SourceRect.x1;
  v6.Height = (float)this->SourceRect.y1;
  readOffsets[v4] = v6;
}
