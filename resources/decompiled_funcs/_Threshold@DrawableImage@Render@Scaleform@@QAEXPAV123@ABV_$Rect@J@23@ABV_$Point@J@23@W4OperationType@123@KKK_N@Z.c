void __thiscall Scaleform::Render::DrawableImage::Threshold(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::DrawableImage::OperationType op,
        unsigned int threshold,
        unsigned int color,
        unsigned int mask,
        bool copySource)
{
  Scaleform::Render::DICommand_Threshold v10; // [esp+4h] [ebp-38h] BYREF

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(&v10, this, source, sourceRect, destPoint);
  v10.Threshold = threshold;
  v10.ThresholdColor = color;
  v10.Operation = op;
  v10.CopySource = copySource;
  v10.__vftable = (Scaleform::Render::DICommand_Threshold_vtbl *)&Scaleform::Render::DICommand_Threshold::`vftable';
  v10.Mask = mask;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Threshold>(this, &v10);
  if ( v10.pSource.pObject )
    v10.pSource.pObject->Release(v10.pSource.pObject);
  v10.__vftable = (Scaleform::Render::DICommand_Threshold_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v10.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_Threshold_vtbl *))v10.pImage.pObject->Release)(v10.__vftable);
}
