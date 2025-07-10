char __thiscall Scaleform::SysFile::Close(Scaleform::SysFile *this)
{
  Scaleform::File *v2; // eax
  Scaleform::File *v3; // edi
  Scaleform::File *pObject; // ecx

  if ( !this->IsValid(this) )
    return 0;
  this->pFile.pObject->Close(this->pFile.pObject);
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
  pObject = this->pFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->pFile.pObject = v3;
  return 1;
}
