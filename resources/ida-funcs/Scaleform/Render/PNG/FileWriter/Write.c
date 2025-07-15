char __userpurge Scaleform::Render::PNG::FileWriter::Write@<al>(
        Scaleform::Render::PNG::FileWriter *this@<ecx>,
        int a2@<edi>,
        Scaleform::File *file,
        const Scaleform::Render::ImageData *imageData,
        const Scaleform::Render::ImageWriteArgs *args)
{
  const char *(__thiscall *GetFilePath)(Scaleform::File *); // edx
  const char *v6; // eax
  Scaleform::Render::ImagePlane *pPlanes; // eax
  Scaleform::Render::ImageFormat Format; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  void *v13; // esi
  unsigned int v14; // eax
  unsigned __int8 *v15; // edx
  int v16; // eax
  int v17; // [esp+8h] [ebp-11Ch] BYREF
  int info_struct; // [esp+Ch] [ebp-118h]
  unsigned int Width; // [esp+10h] [ebp-114h]
  unsigned int Height; // [esp+14h] [ebp-110h]
  int v21; // [esp+18h] [ebp-10Ch]
  int v22; // [esp+1Ch] [ebp-108h]
  char _Dst[256]; // [esp+8Ch] [ebp-98h] BYREF
  void *i; // [esp+18Ch] [ebp+68h]

  if ( !file || !file->IsValid(file) )
    return 0;
  GetFilePath = file->GetFilePath;
  i = 0;
  v6 = GetFilePath(file);
  strcpy_s(a2, _Dst, 256, v6);
  pPlanes = imageData->pPlanes;
  Format = imageData->Format;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  switch ( Format )
  {
    case Image_R8G8B8A8:
    case Image_B8G8R8A8:
      v22 = 6;
      break;
    case Image_R8G8B8:
    case Image_B8G8R8:
      v22 = 2;
      break;
    default:
      return 0;
  }
  v21 = 8;
  v9 = png_create_write_struct("1.5.13", &v17, Scaleform::Render::PNG::png_error_handler, 0);
  v17 = v9;
  if ( !v9 )
    return 0;
  info_struct = png_create_info_struct(v9);
  if ( !info_struct )
    return 0;
  png_set_write_fn(v17, file, Scaleform::Render::PNG::png_write_data, 0);
  v10 = png_set_longjmp_fn(v17, longjmp, 64);
  if ( _setjmp3(v10, 0) )
    return 0;
  png_set_IHDR(v17, info_struct, imageData->pPlanes->Width, imageData->pPlanes->Height, v21, v22, 0, 0, 0);
  png_write_info(v17, info_struct);
  v11 = png_set_longjmp_fn(v17, longjmp, 64);
  if ( _setjmp3(v11, 0) )
  {
    if ( i )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, i);
    return 0;
  }
  v13 = Scaleform::Memory::Alloc(4 * imageData->pPlanes->Height);
  v14 = 0;
  for ( i = v13; v14 < Height; *((_DWORD *)v13 + v14 - 1) = v15 )
  {
    v15 = &imageData->pPlanes->pData[v14 * imageData->pPlanes->Pitch];
    ++v14;
  }
  png_write_image(v17, v13);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  v16 = png_set_longjmp_fn(v17, longjmp, 64);
  if ( _setjmp3(v16, 0) )
    return 0;
  png_write_end(v17, 0);
  return 1;
}
