void __thiscall Scaleform::Render::ImageData::GetMipLevelPlane(
        Scaleform::Render::ImageData *this,
        unsigned int mipLevel,
        unsigned int plane,
        Scaleform::Render::ImagePlane *pplane)
{
  unsigned int FormatPlaneCount; // eax

  FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(this->Format);
  Scaleform::Render::ImageData::GetPlane(this, plane + mipLevel * FormatPlaneCount, pplane);
}
