void __thiscall Scaleform::SysFile::SysFile(
        Scaleform::SysFile *this,
        const Scaleform::String *path,
        int flags,
        int mode)
{
  this->__vftable = (Scaleform::SysFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->pFile.pObject = 0;
  this->__vftable = (Scaleform::SysFile_vtbl *)&Scaleform::SysFile::`vftable';
  Scaleform::SysFile::Open(this, path, flags, mode);
}


void __thiscall Scaleform::SysFile::SysFile(Scaleform::SysFile *this)
{
  Scaleform::File *v2; // eax
  Scaleform::File *v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::SysFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->pFile.pObject = 0;
  this->__vftable = (Scaleform::SysFile_vtbl *)&Scaleform::SysFile::`vftable';
  v2 = (Scaleform::File *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 8, 0);
  if ( v2 )
  {
    v2->__vftable = (Scaleform::File_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v2->RefCount = 1;
    v2->__vftable = (Scaleform::File_vtbl *)&Scaleform::UnopenedFile::`vftable';
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFile.pObject = v3;
}
