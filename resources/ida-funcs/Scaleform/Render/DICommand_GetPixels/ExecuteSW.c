void __thiscall Scaleform::Render::DICommand_GetPixels::ExecuteSW(
        Scaleform::Render::DICommand_GetPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  int v6; // eax
  int i; // ebx
  int j; // edi
  _DWORD v9[6]; // [esp+Ch] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = (int)v5->GetImageSwizzler(v5);
  v9[1] = 0;
  memset(&v9[3], 0, 12);
  v9[2] = dest;
  v9[0] = v6;
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 4))(v6, v9);
  for ( i = this->SourceRect.y1; i < this->SourceRect.y2; ++i )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v9[0] + 8))(v9[0], v9, i);
    for ( j = this->SourceRect.x1; j < this->SourceRect.x2; ++j )
    {
      (*(void (__thiscall **)(_DWORD, Scaleform::Render::DICommandContext **, _DWORD *, int))(*(_DWORD *)v9[0] + 20))(
        v9[0],
        &context,
        v9,
        j);
      this->Provider->WriteNextPixel(this->Provider, (unsigned int)context);
    }
  }
}
