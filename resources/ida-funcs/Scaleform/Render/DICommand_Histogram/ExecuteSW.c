void __thiscall Scaleform::Render::DICommand_Histogram::ExecuteSW(
        Scaleform::Render::DICommand_Histogram *this,
        unsigned int context,
        Scaleform::Render::ImageData *dst,
        Scaleform::Render::ImageData **__formal)
{
  int v5; // eax
  int v6; // eax
  Scaleform::Render::ImageData *v7; // ebx
  int i; // ebp
  Scaleform::Render::ImagePlane *pPlanes; // edx
  int y2; // eax
  int j; // edi
  int Width; // eax
  unsigned int v13; // eax
  _DWORD v14[6]; // [esp+10h] [ebp-18h] BYREF

  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(context + 4) + 220))(*(_DWORD *)(context + 4));
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 60))(v5);
  v7 = dst;
  v14[0] = v6;
  v14[1] = 0;
  v14[2] = dst;
  memset(&v14[3], 0, 12);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 4))(v6, v14);
  for ( i = this->SourceRect.y1 < 0 ? 0 : this->SourceRect.y1; ; ++i )
  {
    pPlanes = v7->pPlanes;
    y2 = this->SourceRect.y2;
    if ( (signed int)pPlanes->Height < y2 )
      y2 = pPlanes->Height;
    if ( i >= y2 )
      break;
    (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v14[0] + 8))(v14[0], v14, i);
    for ( j = this->SourceRect.x1 < 0 ? 0 : this->SourceRect.x1; ; ++j )
    {
      Width = v7->pPlanes->Width;
      if ( Width >= this->SourceRect.x2 )
        Width = this->SourceRect.x2;
      if ( j >= Width )
        break;
      (*(void (__thiscall **)(_DWORD, unsigned int *, _DWORD *, int))(*(_DWORD *)v14[0] + 20))(v14[0], &context, v14, j);
      v13 = context;
      ++this->Result[(unsigned __int8)context + 512];
      v13 >>= 8;
      ++this->Result[(unsigned __int8)v13 + 256];
      v13 >>= 8;
      ++this->Result[(unsigned __int8)v13];
      ++this->Result[BYTE1(v13) + 768];
    }
  }
}
