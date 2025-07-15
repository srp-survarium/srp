void __userpurge Scaleform::Render::Texture::Texture(
        Scaleform::Render::Texture *this@<ecx>,
        int a2@<esi>,
        Scaleform::GFx::Resource *pmanagerLocks,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned __int8 mipLevels,
        unsigned __int16 use,
        Scaleform::Render::ImageBase *pimage,
        const Scaleform::Render::TextureFormat *pformat)
{
  unsigned int Width; // ecx

  *(_DWORD *)a2 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = &Scaleform::Render::Texture::`vftable';
  if ( pmanagerLocks )
    Scaleform::RefCountImpl::AddRef(pmanagerLocks);
  *(_DWORD *)(a2 + 16) = pmanagerLocks;
  *(_DWORD *)(a2 + 20) = pimage;
  Width = size->Width;
  *(_DWORD *)(a2 + 28) = size->Height;
  *(_DWORD *)(a2 + 24) = Width;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_BYTE *)(a2 + 36) = mipLevels;
  *(_WORD *)(a2 + 38) = use;
  *(_DWORD *)(a2 + 48) = pformat;
  *(_BYTE *)(a2 + 37) = 1;
  *(_BYTE *)(a2 + 40) = 0;
}
