void __thiscall Scaleform::Render::DICommand_GetPixel32::ExecuteSW(
        Scaleform::Render::DICommand_GetPixel32 *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  int v6; // eax
  _DWORD v7[6]; // [esp+Ch] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = (int)v5->GetImageSwizzler(v5);
  v7[2] = dest;
  v7[0] = v6;
  v7[1] = 0;
  memset(&v7[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 4))(v6, v7);
  (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v7[0] + 8))(v7[0], v7, this->Y);
  if ( this->Result )
  {
    (*(void (__thiscall **)(_DWORD, Scaleform::Render::DICommandContext **, _DWORD *, unsigned int))(*(_DWORD *)v7[0] + 20))(
      v7[0],
      &context,
      v7,
      this->X);
    *this->Result = (Scaleform::Render::Color)context;
  }
}
