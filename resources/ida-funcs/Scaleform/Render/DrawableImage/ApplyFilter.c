void __thiscall Scaleform::Render::DrawableImage::ApplyFilter(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        Scaleform::GFx::Resource *filter)
{
  Scaleform::Render::DICommand_ApplyFilter v6; // [esp+8h] [ebp-28h] BYREF

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(&v6, this, source, sourceRect, destPoint);
  v6.__vftable = (Scaleform::Render::DICommand_ApplyFilter_vtbl *)&Scaleform::Render::DICommand_ApplyFilter::`vftable';
  if ( filter )
    Scaleform::RefCountImpl::AddRef(filter);
  v6.pFilter.pObject = (Scaleform::Render::Filter *)filter;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ApplyFilter>(this, &v6);
  if ( v6.pFilter.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6.pFilter.pObject);
  if ( v6.pSource.pObject )
    ((void (__thiscall *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DICommand_ApplyFilter_vtbl *))v6.pSource.pObject->Release)(
      v6.pSource.pObject,
      v6.__vftable);
  v6.__vftable = (Scaleform::Render::DICommand_ApplyFilter_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v6.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_ApplyFilter_vtbl *))v6.pImage.pObject->Release)(v6.__vftable);
}
