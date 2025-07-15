void __thiscall Scaleform::GFx::AS3::TR::State::exec_newclass(
        Scaleform::GFx::AS3::TR::State *this,
        const Scaleform::GFx::AS3::Abc::ClassInfo *v)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v4; // esi
  int *Data; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // edi
  Scaleform::GFx::AS3::Abc::File *pObject; // eax
  Scaleform::GFx::AS3::Abc::ClassInfo **v8; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace **v9; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  bool IsScaleformGFx; // al
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  void *UserDefinedTraits; // eax
  Scaleform::GFx::AS3::Tracer *pTracer; // ecx
  unsigned int v15; // esi
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v16; // [esp-4h] [ebp-24h]
  Scaleform::GFx::AS3::Value val; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *class_info; // [esp+24h] [ebp+4h]

  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v4 = WCode->Size + 1;
  if ( v4 >= WCode->Size )
  {
    if ( v4 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v4 + (v4 >> 2));
  }
  else if ( v4 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v4;
  Data[v4 - 1] = (int)v;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  pFile = this->pTracer->CF->pFile;
  pObject = pFile->File.pObject;
  v8 = pObject->AS3_Classes.Info.Data.Data;
  v9 = (Scaleform::GFx::AS3::Instances::fl::Namespace **)&pObject->Const_Pool.const_multiname.Data.Data[v8[(_DWORD)v]->inst_info.name_ind];
  class_info = (Scaleform::GFx::ASStringNode *)v8[(_DWORD)v];
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(pFile, *v9);
  IsScaleformGFx = Scaleform::GFx::AS3::IsScaleformGFx(InternedNamespace);
  VMRef = this->pTracer->CF->pFile->VMRef;
  if ( IsScaleformGFx )
    UserDefinedTraits = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                          VMRef,
                          pFile,
                          (Scaleform::GFx::AS3::Abc::Multiname *)v9);
  else
    UserDefinedTraits = Scaleform::GFx::AS3::VM::GetUserDefinedTraits(VMRef, pFile, class_info);
  if ( !UserDefinedTraits )
    UserDefinedTraits = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject;
  v16 = (const Scaleform::GFx::AS3::InstanceTraits::Traits *)*((_DWORD *)UserDefinedTraits + 25);
  pTracer = this->pTracer;
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)UserDefinedTraits;
  v15 = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(pTracer, v16) & 0xFFFFFFF7)) | 9;
  val.Flags = v15;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &val);
  if ( (v15 & 0x1F) > 9 )
  {
    if ( (v15 & 0x200) != 0 )
    {
      if ( !--MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    }
  }
}
