unsigned int __thiscall Scaleform::Render::ImageBase::GetBytes(Scaleform::Render::ImageBase *this, int *memRegion)
{
  int v3; // eax
  Scaleform::Render::ImageFormat v4; // eax
  Scaleform::Render::Size<unsigned long> v6; // [esp+4h] [ebp-8h] BYREF

  if ( memRegion )
    *memRegion = 0;
  v3 = ((int (__thiscall *)(Scaleform::Render::ImageBase *))this->GetSize)(this);
  v4 = ((int (__thiscall *)(Scaleform::Render::ImageBase *, int))this->GetFormat)(this, v3);
  return Scaleform::Render::ImageData::GetMipLevelSize(v4, &v6, 0);
}
