char __thiscall Scaleform::SysFile::Open(Scaleform::SysFile *this, const Scaleform::String *path, int flags, int mode)
{
  Scaleform::FILEFile *v5; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::File *v7; // edi
  Scaleform::BufferedFile *v8; // eax
  Scaleform::File *v9; // eax
  Scaleform::File *v10; // edi
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::File *v13; // eax
  Scaleform::File *v14; // edi
  Scaleform::RefCountVImpl *v15; // ecx

  v5 = Scaleform::FileFILEOpen(path, flags);
  pObject = (Scaleform::RefCountVImpl *)this->pFile.pObject;
  v7 = v5;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFile.pObject = v7;
  if ( v7 && v7->IsValid(v7) )
  {
    if ( (flags & 0x20) != 0 )
    {
      v8 = (Scaleform::BufferedFile *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 40, 0);
      if ( v8 )
      {
        Scaleform::BufferedFile::BufferedFile(v8, (Scaleform::GFx::Resource *)this->pFile.pObject);
        v10 = v9;
      }
      else
      {
        v10 = 0;
      }
      v11 = (Scaleform::RefCountVImpl *)this->pFile.pObject;
      if ( v11 )
        Scaleform::RefCountImpl::Release(v11);
      this->pFile.pObject = v10;
    }
    return 1;
  }
  else
  {
    v13 = (Scaleform::File *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 8, 0);
    if ( v13 )
    {
      v13->__vftable = (Scaleform::File_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v13->RefCount = 1;
      v13->__vftable = (Scaleform::File_vtbl *)&Scaleform::UnopenedFile::`vftable';
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    v15 = (Scaleform::RefCountVImpl *)this->pFile.pObject;
    if ( v15 )
      Scaleform::RefCountImpl::Release(v15);
    this->pFile.pObject = v14;
    return 0;
  }
}
