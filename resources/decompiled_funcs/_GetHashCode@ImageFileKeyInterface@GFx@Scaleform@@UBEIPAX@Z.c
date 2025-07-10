unsigned int __thiscall Scaleform::GFx::ImageFileKeyInterface::GetHashCode(
        Scaleform::GFx::ImageFileKeyInterface *this,
        void *hdata)
{
  unsigned int v2; // ebx
  int v3; // esi
  int v4; // edi

  v2 = *((_DWORD *)hdata + 4);
  v3 = *((_DWORD *)hdata + 2);
  v4 = *((_DWORD *)hdata + 3);
  return v3
       ^ v4
       ^ v2
       ^ ((v3 ^ v4 ^ v2) >> 7)
       ^ Scaleform::GFx::ResourceFileInfo::GetHashCode(*((Scaleform::GFx::ResourceFileInfo **)hdata + 5));
}
