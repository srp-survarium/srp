void __thiscall Scaleform::Render::DrawableImage::Compare(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *image0,
        Scaleform::Render::DrawableImage *image1)
{
  Scaleform::Render::DICommand_Compare *v4; // eax
  Scaleform::Render::DICommand_Compare v5; // [esp+4h] [ebp-28h] BYREF

  Scaleform::Render::DICommand_Compare::DICommand_Compare(&v5, this, image0, image1);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Compare>(this, v4);
  if ( v5.pImageCompare1.pObject )
    v5.pImageCompare1.pObject->Release(v5.pImageCompare1.pObject);
  if ( v5.pSource.pObject )
    v5.pSource.pObject->Release(v5.pSource.pObject);
  v5.__vftable = (Scaleform::Render::DICommand_Compare_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v5.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_Compare_vtbl *))v5.pImage.pObject->Release)(v5.__vftable);
}
