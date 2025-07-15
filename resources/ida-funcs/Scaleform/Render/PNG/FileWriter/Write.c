char __thiscall Scaleform::Render::PNG::FileWriter::Write(
        Scaleform::Render::PNG::FileWriter *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageData *imageData,
        const Scaleform::Render::ImageWriteArgs *args)
{
  const char *(__thiscall *GetFilePath)(Scaleform::File *); // edx
  const char *v5; // eax
  Scaleform::Render::ImagePlane *pPlanes; // eax
  Scaleform::Render::ImageFormat Format; // ecx
  png_struct_def *v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned __int8 **v12; // esi
  unsigned int v13; // eax
  unsigned __int8 *v14; // edx
  int v15; // eax
  Scaleform::Render::PNG::PngContext context; // [esp+8h] [ebp-11Ch] BYREF
  unsigned __int8 **ppbRowPointers; // [esp+18Ch] [ebp+68h]

  if ( !file || !file->IsValid(file) )
    return 0;
  GetFilePath = file->GetFilePath;
  ppbRowPointers = 0;
  v5 = GetFilePath(file);
  strcpy_s(context.filePath, 0x100u, v5);
  pPlanes = imageData->pPlanes;
  Format = imageData->Format;
  context.width = pPlanes->Width;
  context.height = pPlanes->Height;
  switch ( Format )
  {
    case Image_R8G8B8A8:
    case Image_B8G8R8A8:
      context.colorType = 6;
      break;
    case Image_R8G8B8:
    case Image_B8G8R8:
      context.colorType = 2;
      break;
    default:
      return 0;
  }
  context.bitDepth = 8;
  v8 = (png_struct_def *)png_create_write_struct("1.5.13", &context, Scaleform::Render::PNG::png_error_handler, 0);
  context.png_ptr = v8;
  if ( !v8 )
    return 0;
  context.info_ptr = (png_info_def *)png_create_info_struct(v8);
  if ( !context.info_ptr )
    return 0;
  png_set_write_fn(context.png_ptr, file, Scaleform::Render::PNG::png_write_data, 0);
  v9 = png_set_longjmp_fn(context.png_ptr, longjmp, 64);
  if ( _setjmp3(v9, 0) )
    return 0;
  png_set_IHDR(
    context.png_ptr,
    context.info_ptr,
    imageData->pPlanes->Width,
    imageData->pPlanes->Height,
    context.bitDepth,
    context.colorType,
    0,
    0,
    0);
  png_write_info(context.png_ptr, context.info_ptr);
  v10 = png_set_longjmp_fn(context.png_ptr, longjmp, 64);
  if ( _setjmp3(v10, 0) )
  {
    if ( ppbRowPointers )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ppbRowPointers);
    return 0;
  }
  v12 = (unsigned __int8 **)Scaleform::Memory::Alloc(4 * imageData->pPlanes->Height);
  v13 = 0;
  for ( ppbRowPointers = v12; v13 < context.height; v12[v13 - 1] = v14 )
  {
    v14 = &imageData->pPlanes->pData[v13 * imageData->pPlanes->Pitch];
    ++v13;
  }
  png_write_image(context.png_ptr, v12);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  v15 = png_set_longjmp_fn(context.png_ptr, longjmp, 64);
  if ( _setjmp3(v15, 0) )
    return 0;
  png_write_end(context.png_ptr, 0);
  return 1;
}
