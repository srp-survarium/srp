void __userpurge Scaleform::Render::Texture::Texture(
        Scaleform::Render::Texture *this@<esi>,
        Scaleform::GFx::Resource *pmanagerLocks@<edi>,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned __int8 mipLevels,
        unsigned __int16 use,
        Scaleform::Render::ImageBase *pimage,
        const Scaleform::Render::TextureFormat *pformat)
{
  unsigned int Width; // ecx

  this->__vftable = (Scaleform::Render::Texture_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::ListNode<Scaleform::Render::Texture> = 0;
  this->__vftable = (Scaleform::Render::Texture_vtbl *)&Scaleform::Render::Texture::`vftable';
  if ( pmanagerLocks )
    Scaleform::RefCountImpl::AddRef(pmanagerLocks);
  this->pManagerLocks.pObject = (Scaleform::Render::TextureManagerLocks *)pmanagerLocks;
  this->pImage = pimage;
  Width = size->Width;
  this->ImgSize.Height = size->Height;
  this->ImgSize.Width = Width;
  this->Use = use;
  this->State = State_PreCapture;
  this->MipLevels = mipLevels;
  this->TextureCount = 1;
  this->TextureFlags = 0;
  this->pMap = 0;
  this->pFormat = pformat;
}
