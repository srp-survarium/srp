bool __thiscall Scaleform::GFx::ZLibFile::Close(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // esi
  int v4; // eax
  int v5; // ebx
  Scaleform::RefCountVImpl **v6; // esi

  pImpl = this->pImpl;
  if ( !pImpl )
    return 0;
  if ( pImpl->ZStream.avail_in )
  {
    v4 = pImpl->pIn.pObject->Tell(pImpl->pIn.pObject);
    pImpl->pIn.pObject->Seek(pImpl->pIn.pObject, v4 - pImpl->ZStream.avail_in, 0);
  }
  v5 = inflateEnd(&this->pImpl->ZStream);
  this->pImpl->pIn.pObject->Close(this->pImpl->pIn.pObject);
  v6 = (Scaleform::RefCountVImpl **)this->pImpl;
  if ( v6 )
  {
    if ( *v6 )
      Scaleform::RefCountImpl::Release(*v6);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  }
  this->pImpl = 0;
  return v5 == 0;
}
