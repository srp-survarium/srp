void __thiscall Scaleform::Render::DICommand_GetColorBoundsRect::ExecuteSW(
        Scaleform::Render::DICommand_GetColorBoundsRect *this,
        unsigned int context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  int v4; // eax
  int v5; // eax
  Scaleform::Render::ImageData *v6; // ebp
  int v7; // esi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  char v9; // bl
  unsigned int v10; // edi
  Scaleform::Render::Rect<long> *Result; // eax
  int Width; // [esp+1Ch] [ebp-28h]
  int Height; // [esp+20h] [ebp-24h]
  int v15; // [esp+24h] [ebp-20h]
  int v16; // [esp+28h] [ebp-1Ch]
  _DWORD v17[6]; // [esp+2Ch] [ebp-18h] BYREF

  v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(context + 4) + 220))(*(_DWORD *)(context + 4));
  v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 60))(v4);
  v6 = dest;
  v7 = 0;
  v17[0] = v5;
  v17[1] = 0;
  v17[2] = dest;
  memset(&v17[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v5 + 4))(v5, v17);
  pPlanes = v6->pPlanes;
  v9 = 0;
  v10 = 0;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  v15 = 0;
  v16 = 0;
  if ( Height )
  {
    while ( 1 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD *, unsigned int))(*(_DWORD *)v17[0] + 8))(v17[0], v17, v10);
      if ( v6->pPlanes->Width )
        break;
LABEL_17:
      ++v10;
      v7 = 0;
      if ( v10 >= v6->pPlanes->Height )
        goto LABEL_18;
    }
    while ( 1 )
    {
      (*(void (__thiscall **)(_DWORD, unsigned int *, _DWORD *, int))(*(_DWORD *)v17[0] + 20))(
        v17[0],
        &context,
        v17,
        v7);
      if ( this->FindColor )
      {
        if ( (context & this->Mask) == this->SearchColor )
          goto LABEL_7;
      }
      else if ( (context & this->Mask) != this->SearchColor )
      {
LABEL_7:
        if ( Width >= v7 )
          Width = v7;
        if ( Height >= (int)v10 )
          Height = v10;
        if ( v7 + 1 >= v15 )
          v15 = v7 + 1;
        if ( (int)(v10 + 1) >= v16 )
          v16 = v10 + 1;
        v9 = 1;
      }
      if ( ++v7 >= v6->pPlanes->Width )
        goto LABEL_17;
    }
  }
LABEL_18:
  Result = this->Result;
  if ( Result )
  {
    if ( v9 )
    {
      Result->x1 = Width;
      Result->y1 = Height;
      Result->x2 = v15;
      Result->y2 = v16;
    }
    else
    {
      Result->x1 = 0;
      Result->y1 = 0;
      Result->x2 = 0;
      Result->y2 = 0;
    }
  }
}
