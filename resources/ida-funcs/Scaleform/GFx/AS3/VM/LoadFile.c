Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *__thiscall Scaleform::GFx::AS3::VM::LoadFile(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *result,
        const Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *file,
        Scaleform::GFx::AS3::VMAppDomain *appDomain,
        bool to_execute)
{
  Scaleform::GFx::AS3::VMAbcFile *v6; // eax
  Scaleform::GFx::AS3::VMAbcFile *v7; // eax
  Scaleform::GFx::AS3::VMAbcFile *v8; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v9; // esi
  unsigned int v10; // ecx
  unsigned int RefCount; // eax

  v6 = (Scaleform::GFx::AS3::VMAbcFile *)this->MHeap->Alloc(this->MHeap, 124, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS3::VMAbcFile::VMAbcFile(v6, this, file, appDomain);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  if ( Scaleform::GFx::AS3::VMAbcFile::RegisterUserDefinedClassTraits(v8)
    && Scaleform::GFx::AS3::VMAbcFile::RegisterScrips(v8, to_execute) )
  {
    v9 = result;
    result->pObject = v8;
    if ( !v8 )
      return v9;
    v10 = (v8->RefCount + 1) & 0x8FBFFFFF;
    v8->RefCount = v10;
    if ( ((unsigned __int8)v8 & 1) != 0 )
      return v9;
    RefCount = v10;
  }
  else
  {
    v9 = result;
    result->pObject = 0;
    if ( !v8 || ((unsigned __int8)v8 & 1) != 0 )
      return v9;
    RefCount = v8->RefCount;
  }
  if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
  {
    v8->RefCount = RefCount - 1;
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
  }
  return v9;
}
