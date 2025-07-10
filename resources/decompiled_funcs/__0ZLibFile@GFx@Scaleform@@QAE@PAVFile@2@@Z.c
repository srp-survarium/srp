void __thiscall Scaleform::GFx::ZLibFile::ZLibFile(
        Scaleform::GFx::ZLibFile *this,
        Scaleform::GFx::Resource *psourceFile)
{
  Scaleform::GFx::ZLibFileImpl *v3; // eax
  Scaleform::GFx::ZLibFileImpl *v4; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::ZLibFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ZLibFile_vtbl *)&Scaleform::GFx::ZLibFile::`vftable';
  this->pImpl = 0;
  if ( psourceFile && (unsigned __int8)psourceFile->GetResourceTypeCode(psourceFile) )
  {
    v5 = 2;
    v3 = (Scaleform::GFx::ZLibFileImpl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           8280,
                                           &v5);
    if ( v3 )
    {
      Scaleform::GFx::ZLibFileImpl::ZLibFileImpl(v3, psourceFile);
      this->pImpl = v4;
    }
    else
    {
      this->pImpl = 0;
    }
  }
}
