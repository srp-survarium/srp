void __thiscall Scaleform::Render::DICommand_FillRect::ExecuteSW(
        Scaleform::Render::DICommand_FillRect *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int Height; // edx
  unsigned int Raw; // ebp
  int y1; // ebx
  int x2; // edi
  int i; // esi
  Scaleform::Render::Rect<long> v12; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::Render::Rect<long> v13; // [esp+1Ch] [ebp-28h] BYREF
  _DWORD v14[6]; // [esp+2Ch] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v14[0] = v5->GetImageSwizzler(v5);
  v14[1] = 0;
  v14[2] = dest;
  memset(&v14[3], 0, 12);
  (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v14[0] + 4))(v14[0], v14);
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  v13.x2 = pPlanes->Width;
  v13.x1 = 0;
  v13.y1 = 0;
  v13.y2 = Height;
  memset(&v12, 0, sizeof(v12));
  if ( Scaleform::Render::Rect<long>::IntersectRect(&v13, &v12, &this->ApplyRect) )
  {
    Raw = this->FillColor.Raw;
    if ( !this->pImage.pObject->Transparent )
      Raw |= 0xFF000000;
    y1 = v12.y1;
    if ( v12.y1 < v12.y2 )
    {
      x2 = v12.x2;
      do
      {
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v14[0] + 8))(v14[0], v14, y1);
        for ( i = v12.x1; i < x2; ++i )
          (*(void (__thiscall **)(_DWORD, _DWORD *, int, unsigned int))(*(_DWORD *)v14[0] + 12))(v14[0], v14, i, Raw);
        ++y1;
      }
      while ( y1 < v12.y2 );
    }
  }
}
