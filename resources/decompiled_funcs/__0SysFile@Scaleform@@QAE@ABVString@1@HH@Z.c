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
