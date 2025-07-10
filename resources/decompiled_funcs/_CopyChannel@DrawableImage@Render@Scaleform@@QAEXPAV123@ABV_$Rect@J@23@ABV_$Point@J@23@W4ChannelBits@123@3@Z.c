void __thiscall Scaleform::Render::DrawableImage::CopyChannel(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::DrawableImage::ChannelBits sourceChannel,
        Scaleform::Render::DrawableImage::ChannelBits destChannel)
{
  Scaleform::Render::DICommand_CopyChannel v7; // [esp+4h] [ebp-2Ch] BYREF

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(&v7, this, source, sourceRect, destPoint);
  v7.DestChannel = destChannel;
  v7.__vftable = (Scaleform::Render::DICommand_CopyChannel_vtbl *)&Scaleform::Render::DICommand_CopyChannel::`vftable';
  v7.SourceChannel = sourceChannel;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyChannel>(this, &v7);
  if ( v7.pSource.pObject )
    v7.pSource.pObject->Release(v7.pSource.pObject);
  v7.__vftable = (Scaleform::Render::DICommand_CopyChannel_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v7.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_CopyChannel_vtbl *))v7.pImage.pObject->Release)(v7.__vftable);
}
