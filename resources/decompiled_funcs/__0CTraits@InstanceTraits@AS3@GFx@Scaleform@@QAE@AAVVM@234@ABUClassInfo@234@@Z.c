void __thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *ci)
{
  const Scaleform::GFx::AS3::ClassInfo *v3; // esi
  Scaleform::GFx::AS3::VM *v5; // edi
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *ParentClassTraits; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // ebx
  unsigned __int8 i; // bl
  unsigned __int8 j; // bl
  const Scaleform::GFx::AS3::ClassInfo *Type; // esi
  unsigned int v12; // eax
  const Scaleform::GFx::AS3::MemberInfo *ClassMember; // eax
  int v14; // ebx
  int v15; // ecx
  Scaleform::GFx::AS3::Abc::MultinameKind *v16; // eax
  Scaleform::GFx::AS3::Abc::MultinameKind *v17; // esi
  Scaleform::GFx::AS3::Multiname *v18; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v19; // ecx
  int v20; // esi
  int v21; // esi
  bool isFinal; // [esp+10h] [ebp-20h]
  bool isDynamic; // [esp+14h] [ebp-1Ch]
  Scaleform::GFx::AS3::Multiname v24; // [esp+18h] [ebp-18h] BYREF

  v3 = (const Scaleform::GFx::AS3::ClassInfo *)ci;
  v5 = vm;
  isFinal = (*(_DWORD *)ci->pData & 8) != 0;
  isDynamic = (*(_DWORD *)ci->pData & 2) != 0;
  if ( vm->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    AppDomain = vm->CallStack.Pages[(vm->CallStack.Size - 1) >> 6][(vm->CallStack.Size - 1) & 0x3F].pFile->AppDomain;
  else
    AppDomain = vm->CurrentDomain;
  ParentClassTraits = Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(vm, ci, AppDomain);
  ci = 0;
  if ( ParentClassTraits )
    ci = (Scaleform::GFx::ASStringNode *)ParentClassTraits->ITraits.pObject;
  pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
         v5,
         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&vm,
         NS_Public,
         (Scaleform::GFx::ASStringNode *)v3->Type->PkgName)->pV;
  Scaleform::GFx::AS3::Traits::Traits(this, v5, (const Scaleform::GFx::AS3::Traits *)ci, isDynamic, isFinal);
  this->Ns.pObject = pV;
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::CTraits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::CTraits::`vftable';
  this->CI = v3;
  this->ImplementsInterfaces.Data.Data = 0;
  this->ImplementsInterfaces.Data.Size = 0;
  this->ImplementsInterfaces.Data.Policy.Capacity = 0;
  for ( i = 0; i < v3->InstanceMemberNum; ++i )
    Scaleform::GFx::AS3::Traits::AddSlot(this, (Scaleform::GFx::ASStringNode *)&v3->InstanceMember[i]);
  for ( j = 0; j < v3->InstanceMethodNum; ++j )
    Scaleform::GFx::AS3::Traits::Add2VT(this, v3, &v3->InstanceMethod[j]);
  Type = (const Scaleform::GFx::AS3::ClassInfo *)v3->Type;
  v12 = (unsigned int)Type->Type >> 4;
  ci = (Scaleform::GFx::ASStringNode *)Type;
  if ( (v12 & 1) != 0 )
    this->Flags |= 4u;
  ClassMember = Type->ClassMember;
  v14 = 0;
  if ( ClassMember->Name )
  {
    v15 = 0;
    do
    {
      Scaleform::GFx::AS3::Multiname::Multiname(
        &v24,
        this->pVM,
        *(const Scaleform::GFx::AS3::TypeInfo **)((char *)&ClassMember->Name + v15));
      v17 = v16;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->ImplementsInterfaces.Data,
        &this->ImplementsInterfaces,
        this->ImplementsInterfaces.Data.Size + 1);
      v18 = &this->ImplementsInterfaces.Data.Data[this->ImplementsInterfaces.Data.Size - 1];
      if ( &this->ImplementsInterfaces.Data.Data[this->ImplementsInterfaces.Data.Size] != (Scaleform::GFx::AS3::Multiname *)24 )
      {
        v18->Kind = *v17;
        v19 = (Scaleform::GFx::AS3::GASRefCountBase *)*((_DWORD *)v17 + 1);
        v18->Obj.pObject = v19;
        if ( v19 )
          v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
        v18->Name.Flags = v17[2];
        v18->Name.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v17[3];
        v18->Name.value.VS._1.VInt = v17[4];
        v18->Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v17[5];
        if ( (v17[2] & 0x1Fu) > 9 )
        {
          if ( (v17[2] & 0x200) != 0 )
          {
            ++**((_DWORD **)v17 + 3);
          }
          else
          {
            switch ( v17[2] & 0x1F )
            {
              case 0xA:
                ++*(_DWORD *)(*((_DWORD *)v17 + 4) + 12);
                break;
              case 0xB:
              case 0xC:
              case 0xD:
              case 0xE:
              case 0xF:
                v20 = *((_DWORD *)v17 + 4);
                if ( v20 )
                  *(_DWORD *)(v20 + 16) = (*(_DWORD *)(v20 + 16) + 1) & 0x8FBFFFFF;
                break;
              case 0x10:
              case 0x11:
                v21 = *((_DWORD *)v17 + 5);
                if ( v21 )
                  *(_DWORD *)(v21 + 16) = (*(_DWORD *)(v21 + 16) + 1) & 0x8FBFFFFF;
                break;
              default:
                break;
            }
          }
        }
      }
      Scaleform::GFx::AS3::Multiname::~Multiname(&v24);
      ClassMember = (const Scaleform::GFx::AS3::MemberInfo *)ci->HashFlags;
      ++v14;
      v15 = 4 * v14;
    }
    while ( *((_DWORD *)&ClassMember->Name + v14) );
    if ( v14 )
      Scaleform::GFx::AS3::InstanceTraits::CTraits::AddInterfaceSlots2This(this, 0, this);
  }
}
