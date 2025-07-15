int __cdecl Scaleform::Render::PNG::GFxPngReadInfo(Scaleform::Render::PNG::PngContext *context)
{
  int v1; // eax
  int *p_colorType; // ebx
  double dGamma; // [esp+1Ch] [ebp-8h] BYREF

  v1 = png_set_longjmp_fn(context->png_ptr, longjmp, 64);
  if ( _setjmp3(v1, 0) )
    return 0;
  png_set_sig_bytes(context->png_ptr, 8);
  png_read_info(context->png_ptr, context->info_ptr);
  p_colorType = &context->colorType;
  png_get_IHDR(
    context->png_ptr,
    context->info_ptr,
    &context->width,
    &context->height,
    &context->bitDepth,
    &context->colorType,
    &context->interlaceType,
    0,
    0);
  if ( context->bitDepth == 16 )
    png_set_strip_16(context->png_ptr);
  if ( *p_colorType == 3 )
    png_set_palette_to_rgb(context->png_ptr);
  if ( context->bitDepth < 8 )
    png_set_expand_gray_1_2_4_to_8(context->png_ptr);
  if ( png_get_valid(context->png_ptr, context->info_ptr, 16) )
    png_set_tRNS_to_alpha(context->png_ptr);
  if ( !*p_colorType || *p_colorType == 4 )
    png_set_gray_to_rgb(context->png_ptr);
  if ( png_get_gAMA(context->png_ptr, context->info_ptr, &dGamma) )
    png_set_gamma((int)context->png_ptr, 2.2, dGamma);
  png_read_update_info(context->png_ptr, context->info_ptr);
  png_get_IHDR(
    context->png_ptr,
    context->info_ptr,
    &context->width,
    &context->height,
    &context->bitDepth,
    &context->colorType,
    &context->interlaceType,
    0,
    0);
  context->ulRowBytes = png_get_rowbytes(context->png_ptr, context->info_ptr);
  return 1;
}
