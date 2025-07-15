void __thiscall Scaleform::Render::DICommand_SetPixels::ExecuteSW(
        Scaleform::Render::DICommand_SetPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  int v6; // eax
  unsigned int v7; // ebp
  int y1; // ebx
  int x1; // edi
  unsigned int v10; // eax
  bool *Result; // esi
  bool *v12; // esi
  _DWORD v13[6]; // [esp+10h] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = (int)v5->GetImageSwizzler(v5);
  v7 = 0;
  v13[2] = dest;
  v13[0] = v6;
  v13[1] = 0;
  memset(&v13[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 4))(v6, v13);
  y1 = this->DestRect.y1;
  if ( y1 >= this->DestRect.y2 )
  {
LABEL_6:
    Result = this->Result;
    if ( Result )
      *Result = 1;
  }
  else
  {
    while ( 1 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v13[0] + 8))(v13[0], v13, y1);
      x1 = this->DestRect.x1;
      if ( x1 < this->DestRect.x2 )
        break;
LABEL_5:
      if ( ++y1 >= this->DestRect.y2 )
        goto LABEL_6;
    }
    while ( v7 < this->Provider->GetLength(this->Provider) )
    {
      v10 = this->Provider->ReadNextPixel(this->Provider);
      (*(void (__thiscall **)(_DWORD, _DWORD *, int, unsigned int))(*(_DWORD *)v13[0] + 12))(v13[0], v13, x1++, v10);
      ++v7;
      if ( x1 >= this->DestRect.x2 )
        goto LABEL_5;
    }
    v12 = this->Result;
    if ( v12 )
      *v12 = 0;
  }
}
