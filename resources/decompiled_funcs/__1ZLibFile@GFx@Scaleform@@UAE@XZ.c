void __thiscall Scaleform::GFx::ZLibFile::~ZLibFile(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // esi
  int v3; // eax
  Scaleform::RefCountVImpl **v4; // esi

  pImpl = this->pImpl;
  this->__vftable = (Scaleform::GFx::ZLibFile_vtbl *)&Scaleform::GFx::ZLibFile::`vftable';
  if ( pImpl )
  {
    if ( pImpl->ZStream.avail_in )
    {
      v3 = pImpl->pIn.pObject->Tell(pImpl->pIn.pObject);
      pImpl->pIn.pObject->Seek(pImpl->pIn.pObject, v3 - pImpl->ZStream.avail_in, 0);
    }
    inflateEnd(&this->pImpl->ZStream);
    v4 = (Scaleform::RefCountVImpl **)this->pImpl;
    if ( v4 )
    {
      if ( *v4 )
        Scaleform::RefCountImpl::Release(*v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
