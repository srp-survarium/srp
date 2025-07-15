void __thiscall Scaleform::Render::DICommand_SetPixel32::ExecuteSW(
        Scaleform::Render::DICommand_SetPixel32 *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  int v6; // eax
  _DWORD v7[6]; // [esp+18h] [ebp-18h] BYREF
  unsigned int Raw; // [esp+34h] [ebp+4h]

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = (int)v5->GetImageSwizzler(v5);
  v7[2] = dest;
  v7[0] = v6;
  v7[1] = 0;
  memset(&v7[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 4))(v6, v7);
  (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v7[0] + 8))(v7[0], v7, this->Y);
  Raw = this->Fill.Raw;
  if ( !this->OverwriteAlpha )
  {
    (*(void (__thiscall **)(_DWORD, Scaleform::Render::ImageData **, _DWORD *, unsigned int))(*(_DWORD *)v7[0] + 20))(
      v7[0],
      &dest,
      v7,
      this->X);
    HIBYTE(Raw) = HIBYTE(dest);
  }
  (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int, unsigned int))(*(_DWORD *)v7[0] + 12))(
    v7[0],
    v7,
    this->X,
    Raw);
}
