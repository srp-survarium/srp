void __thiscall Scaleform::Render::DICommand_Clear::ExecuteSW(
        Scaleform::Render::DICommand_Clear *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  unsigned int v6; // esi
  unsigned int Raw; // ebp
  int v8; // ebx
  _DWORD v9[6]; // [esp+10h] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = 0;
  v9[0] = v5->GetImageSwizzler(v5);
  v9[1] = 0;
  v9[2] = dest;
  memset(&v9[3], 0, 12);
  (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v9[0] + 4))(v9[0], v9);
  Raw = this->FillColor.Raw;
  v8 = 0;
  if ( dest->pPlanes->Height )
  {
    while ( 1 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v9[0] + 8))(v9[0], v9, v8);
      if ( dest->pPlanes->Width )
      {
        do
          (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int, unsigned int))(*(_DWORD *)v9[0] + 12))(
            v9[0],
            v9,
            v6++,
            Raw);
        while ( v6 < dest->pPlanes->Width );
      }
      if ( ++v8 >= dest->pPlanes->Height )
        break;
      v6 = 0;
    }
  }
}
