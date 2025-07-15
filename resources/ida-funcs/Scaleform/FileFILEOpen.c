Scaleform::FILEFile *__cdecl Scaleform::FileFILEOpen(const Scaleform::String *path, int flags)
{
  Scaleform::FILEFile *v2; // esi

  v2 = (Scaleform::FILEFile *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
  if ( !v2 )
    return 0;
  v2->__vftable = (Scaleform::FILEFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  v2->RefCount = 1;
  v2->__vftable = (Scaleform::FILEFile_vtbl *)&Scaleform::FILEFile::`vftable';
  Scaleform::String::String(&v2->FileName, path);
  v2->OpenFlags = flags;
  Scaleform::FILEFile::init(v2);
  return v2;
}
