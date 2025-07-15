void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GlobalObjectCPP(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Class *v5; // eax
  Scaleform::GFx::AS3::Class *v6; // eax
  Scaleform::GFx::AS3::Class *v7; // eax
  Scaleform::GFx::AS3::Classes::fl::Boolean *ClassBoolean; // eax
  Scaleform::GFx::AS3::Classes::fl::Number *ClassNumber; // eax
  Scaleform::GFx::AS3::Classes::fl::int_ *ClassSInt; // eax
  Scaleform::GFx::AS3::Classes::fl::uint *ClassUInt; // eax
  Scaleform::GFx::AS3::Classes::fl::String *ClassString; // eax
  Scaleform::GFx::AS3::Classes::fl::Array *ClassArray; // eax
  Scaleform::GFx::AS3::Classes::fl::QName *ClassQName; // eax
  Scaleform::GFx::AS3::XMLSupport *pObject; // edi
  Scaleform::GFx::AS3::Traits *v16; // eax
  Scaleform::GFx::AS3::Class *v17; // eax
  Scaleform::GFx::AS3::Traits *v18; // eax
  Scaleform::GFx::AS3::Class *v19; // eax
  const Scaleform::GFx::AS3::ThunkInfo *v20; // edi
  Scaleform::GFx::AS3::Traits *v21; // ecx
  Scaleform::GFx::AS3::Traits *v22; // ecx
  const Scaleform::GFx::AS3::ThunkInfo *v23; // edi
  const Scaleform::GFx::AS3::MemberInfo *v24; // edi
  const Scaleform::GFx::AS3::ThunkInfo *v25; // edi
  int v26; // ebx
  Scaleform::GFx::AS3::TypeInfo TInfo; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::ClassInfo CInfo; // [esp+24h] [ebp-1Ch] BYREF
  int vma; // [esp+44h] [ebp+4h]
  int vmb; // [esp+44h] [ebp+4h]
  int vmc; // [esp+44h] [ebp+4h]

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl *)&Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::`vftable';
  this->CIRegistrationHash.mHash.pTable = 0;
  this->PositiveInfinity = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
  this->NegativeInfinity = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
  this->NaN = Scaleform::GFx::NumberUtil::NaN();
  this->undefined.Flags = 0;
  this->undefined.Bonus.pWeakProxy = 0;
  this->INCLUDE_BASES = 2;
  this->INCLUDE_INTERFACES = 4;
  this->INCLUDE_VARIABLES = 8;
  this->INCLUDE_ACCESSORS = 16;
  this->INCLUDE_METHODS = 32;
  this->INCLUDE_METADATA = 64;
  this->INCLUDE_CONSTRUCTOR = 128;
  this->INCLUDE_TRAITS = 256;
  this->USE_ITRAITS = 512;
  this->HIDE_OBJECT = 1024;
  this->FLASH10_FLAGS = 1535;
  this->HIDE_NSURI_METHODS = 1;
  this->Values.Data.Data = 0;
  this->Values.Data.Size = 0;
  this->Values.Data.Policy.Capacity = 0;
  this->CTraits.Data.Data = 0;
  this->CTraits.Data.Size = 0;
  this->CTraits.Data.Policy.Capacity = 0;
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::RegisterClassInfoTable(
    this,
    Scaleform::GFx::AS3::Classes::ClassRegistrationTable);
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(vm->TraitsObject.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, Constructor);
  v5 = Scaleform::GFx::AS3::Traits::GetConstructor(vm->TraitsClassClass.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, v5);
  v6 = Scaleform::GFx::AS3::Traits::GetConstructor(vm->TraitsNamespace.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, v6);
  v7 = Scaleform::GFx::AS3::Traits::GetConstructor(vm->TraitsFunction.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, v7);
  ClassBoolean = Scaleform::GFx::AS3::VM::GetClassBoolean(vm);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, ClassBoolean);
  ClassNumber = Scaleform::GFx::AS3::VM::GetClassNumber(vm);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, ClassNumber);
  ClassSInt = Scaleform::GFx::AS3::VM::GetClassSInt(vm);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, ClassSInt);
  ClassUInt = Scaleform::GFx::AS3::VM::GetClassUInt(vm);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, ClassUInt);
  ClassString = Scaleform::GFx::AS3::VM::GetClassString(vm);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, ClassString);
  ClassArray = Scaleform::GFx::AS3::VM::GetClassArray(vm);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, ClassArray);
  ClassQName = Scaleform::GFx::AS3::VM::GetClassQName(vm);
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, ClassQName);
  pObject = vm->XMLSupport_.pObject;
  if ( pObject->Enabled )
  {
    v16 = pObject->GetITraitsXML(pObject);
    v17 = Scaleform::GFx::AS3::Traits::GetConstructor(v16);
    Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, v17);
    v18 = pObject->GetITraitsXMLList(pObject);
    v19 = Scaleform::GFx::AS3::Traits::GetConstructor(v18);
    Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(this, v19);
  }
  TInfo.Name = uri;
  TInfo.PkgName = uri;
  TInfo.Flags = 1;
  TInfo.Parent = 0;
  TInfo.Implements = 0;
  CInfo.Type = &TInfo;
  memset(&CInfo.Factory, 0, 24);
  v20 = f_3;
  vma = 13;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this->pTraits.pObject, &CInfo, v20++);
    --vma;
  }
  while ( vma );
  CInfo.Type = &TInfo;
  v21 = this->pTraits.pObject;
  TInfo.Flags = 1;
  TInfo.Name = uri;
  TInfo.PkgName = "flash.net";
  TInfo.Parent = 0;
  TInfo.Implements = 0;
  memset(&CInfo.Factory, 0, 24);
  Scaleform::GFx::AS3::Traits::Add2VT(v21, &CInfo, f_2);
  v22 = this->pTraits.pObject;
  TInfo.Flags = 1;
  TInfo.Name = uri;
  TInfo.PkgName = "flash.system";
  TInfo.Parent = 0;
  TInfo.Implements = 0;
  CInfo.Type = &TInfo;
  memset(&CInfo.Factory, 0, 24);
  Scaleform::GFx::AS3::Traits::Add2VT(v22, &CInfo, f_1);
  TInfo.Name = uri;
  TInfo.Flags = 1;
  TInfo.PkgName = "flash.utils";
  TInfo.Parent = 0;
  TInfo.Implements = 0;
  CInfo.Type = &TInfo;
  memset(&CInfo.Factory, 0, 24);
  v23 = f_0;
  vmb = 11;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this->pTraits.pObject, &CInfo, v23++);
    --vmb;
  }
  while ( vmb );
  v24 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::mi;
  vmc = 16;
  do
  {
    Scaleform::GFx::AS3::Traits::AddSlot(t, v24++);
    --vmc;
  }
  while ( vmc );
  TInfo.Parent = 0;
  TInfo.Implements = 0;
  memset(&CInfo.Factory, 0, 24);
  TInfo.Flags = 1;
  TInfo.Name = uri;
  TInfo.PkgName = "avmplus";
  CInfo.Type = &TInfo;
  v25 = f;
  v26 = 3;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this->pTraits.pObject, &CInfo, v25++);
    --v26;
  }
  while ( v26 );
}
