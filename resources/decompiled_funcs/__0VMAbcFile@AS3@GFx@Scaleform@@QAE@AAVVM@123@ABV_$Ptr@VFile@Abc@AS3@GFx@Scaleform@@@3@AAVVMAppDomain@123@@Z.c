void __thiscall Scaleform::GFx::AS3::VMAbcFile::VMAbcFile(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *file,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned int Size; // ebp
  unsigned int v6; // edi
  Scaleform::GFx::AS3::VMAbcFile **Data; // eax

  Scaleform::GFx::AS3::VMFile::VMFile(this, vm, appDomain);
  this->__vftable = (Scaleform::GFx::AS3::VMAbcFile_vtbl *)&Scaleform::GFx::AS3::VMAbcFile::`vftable';
  if ( file->pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)file->pObject);
  this->File = (Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File>)file->pObject;
  this->AbsObjects.pTable = 0;
  this->GlobalObjects.pTable = 0;
  this->Children.Data.Data = 0;
  this->Children.Data.Size = 0;
  this->Children.Data.Policy.Capacity = 0;
  this->FunctionTraitsCache.mHash.pTable = 0;
  this->LoadedClasses.Data.Data = 0;
  this->LoadedClasses.Data.Size = 0;
  this->LoadedClasses.Data.Policy.Capacity = 0;
  this->OpCodeArray.Data.Data = 0;
  this->OpCodeArray.Data.Size = 0;
  this->OpCodeArray.Data.Policy.Capacity = 0;
  this->Exceptions.Data.Data = 0;
  this->Exceptions.Data.Size = 0;
  this->Exceptions.Data.Policy.Capacity = 0;
  this->RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[22351416];
  Size = file->pObject->MethodBodies.Info.Data.Size;
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy> *)&this->OpCodeArray,
    Size);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Exceptions.Data,
    Size);
  if ( !vm->InDestructor )
  {
    v6 = vm->VMAbcFilesWeak.Data.Size + 1;
    if ( v6 >= vm->VMAbcFilesWeak.Data.Size )
    {
      if ( v6 >= vm->VMAbcFilesWeak.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &vm->VMAbcFilesWeak.Data,
          &vm->VMAbcFilesWeak,
          v6 + (v6 >> 2));
    }
    else if ( v6 < vm->VMAbcFilesWeak.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::VMAbcFile *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &vm->VMAbcFilesWeak.Data,
        &vm->VMAbcFilesWeak,
        vm->VMAbcFilesWeak.Data.Size + 1);
    }
    Data = vm->VMAbcFilesWeak.Data.Data;
    vm->VMAbcFilesWeak.Data.Size = v6;
    Data[v6 - 1] = this;
  }
}
