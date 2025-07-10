void __thiscall Scaleform::BufferedFile::BufferedFile(Scaleform::BufferedFile *this, Scaleform::GFx::Resource *pfile)
{
  this->__vftable = (Scaleform::BufferedFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::BufferedFile_vtbl *)&Scaleform::DelegatedFile::`vftable';
  if ( pfile )
    Scaleform::RefCountImpl::AddRef(pfile);
  this->pFile.pObject = (Scaleform::File *)pfile;
  this->__vftable = (Scaleform::BufferedFile_vtbl *)&Scaleform::BufferedFile::`vftable';
  this->pBuffer = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 8184, 1, 0);
  this->BufferMode = NoBuffer;
  this->FilePos = ((__int64 (__thiscall *)(Scaleform::GFx::Resource *))pfile->__vftable[1].GetKey)(pfile);
  this->Pos = 0;
  this->DataSize = 0;
}
