Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *__thiscall Scaleform::GFx::AS3::VM::FindVMAbcFileWeak(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *result,
        const char *name,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::VMAbcFile **v5; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v6; // eax
  Scaleform::GFx::AS3::VMAbcFile *v7; // ecx
  unsigned int n; // [esp+10h] [ebp-8h]
  Scaleform::GFx::AS3::VMAbcFile **Data; // [esp+14h] [ebp-4h]

  v4 = 0;
  n = this->VMAbcFilesWeak.Data.Size;
  if ( n )
  {
    Data = this->VMAbcFilesWeak.Data.Data;
    v5 = Data;
    while ( strcmp((const char *)(((*v5)->File.pObject->Source.HeapTypeBits & 0xFFFFFFFC) + 8), name)
         || (*v5)->AppDomain != appDomain )
    {
      ++v4;
      ++v5;
      if ( v4 >= n )
        goto LABEL_6;
    }
    v7 = Data[v4];
    v6 = result;
    result->pObject = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
LABEL_6:
    v6 = result;
    result->pObject = 0;
  }
  return v6;
}
