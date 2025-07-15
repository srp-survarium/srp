void __thiscall Scaleform::Render::DrawableImage::Scroll(Scaleform::Render::DrawableImage *this, int x, int y)
{
  Scaleform::Render::DICommand_Scroll *v4; // eax
  Scaleform::Render::DICommand_Scroll v5; // [esp+4h] [ebp-2Ch] BYREF

  Scaleform::Render::DICommand_Scroll::DICommand_Scroll(&v5, this, x, y);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Scroll>(this, v4);
  if ( v5.pSource.pObject )
    v5.pSource.pObject->Release(v5.pSource.pObject);
  v5.__vftable = (Scaleform::Render::DICommand_Scroll_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v5.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_Scroll_vtbl *))v5.pImage.pObject->Release)(v5.__vftable);
}
