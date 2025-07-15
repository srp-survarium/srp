void __thiscall Scaleform::GFx::AS3::TR::State::exec_findproperty(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v4; // esi
  int *Data; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // edx
  int v9; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // eax
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [esp+Ch] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+10h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+20h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::TR::ReadMn args; // [esp+38h] [ebp-28h] BYREF

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
  v6 = mn_index;
  WCode->Size = v4;
  Data[v4 - 1] = v6;
  pFile = this->pTracer->CF->pFile;
  VMRef = pFile->VMRef;
  args.File = pFile;
  args.VMRef = VMRef;
  args.StateRef = this;
  args.Num = 0;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &args.ArgMN,
    pFile,
    &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v6]);
  v9 = Scaleform::GFx::AS3::TR::StackReader::Read(&args, &args.ArgMN);
  args.Num += v9;
  memset(&prop, 0, 16);
  Scaleform::GFx::AS3::TR::State::FindProp(
    this,
    &prop,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
    &stype,
    &mn_index);
  if ( (prop.This.Flags & 0x1F) != 0
    && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
    && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &prop.This);
  }
  else
  {
    pObject = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    val.Bonus.pWeakProxy = 0;
    val.value.VS._1.VInt = (int)pObject;
    val.Flags = 72;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &val);
    Scaleform::GFx::AS3::Value::~Value(&val);
  }
  Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
