char __usercall Scaleform::Render::D3D1x::IsD3DFormatRescaleCompatible@<al>(
        Scaleform::Render::ImageFormat *ptargetImageFormat@<ecx>,
        Scaleform::Render::ResizeImageType *presizeType@<eax>,
        DXGI_FORMAT format)
{
  if ( format != DXGI_FORMAT_R8G8B8A8_UNORM )
  {
    if ( format == DXGI_FORMAT_A8_UNORM )
    {
      *ptargetImageFormat = Image_A8;
      *presizeType = ResizeGray;
      return 1;
    }
    if ( format != DXGI_FORMAT_B8G8R8A8_UNORM )
      return 0;
  }
  *ptargetImageFormat = Image_R8G8B8A8;
  *presizeType = ResizeRgbaToRgba;
  return 1;
}
