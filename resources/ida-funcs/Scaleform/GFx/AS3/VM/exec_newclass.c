void __thiscall Scaleform::GFx::AS3::VM::exec_newclass(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASStringNode *file,
        Scaleform::GFx::ASString v)
{
  Scaleform::GFx::AS3::VMFile *v3; // ebx
  Scaleform::GFx::AS3::Abc::File *RefCount; // eax
  Scaleform::GFx::AS3::VMAbcFile *v6; // ebp
  Scaleform::GFx::AS3::Value *pCurrent; // ecx
  int v8; // edi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // ecx
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  int v14; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *pObject; // ebx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl *v18; // edi
  const Scaleform::GFx::AS3::Multiname *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // ebx
  const char *pData; // edi
  const Scaleform::GFx::AS3::VM::Error *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  bool v24; // zf
  Scaleform::GFx::ASStringNode *v25; // ecx
  Scaleform::GFx::AS3::ClassTraits::UserDefined *UserDefinedTraits; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v27; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *Class; // eax
  Scaleform::StringDataPtr v29; // [esp-10h] [ebp-50h] BYREF
  Scaleform::StringDataPtr v30; // [esp-8h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value *value; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::ASStringNode *v32; // [esp+14h] [ebp-2Ch]
  Scaleform::GFx::AS3::Value name; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v34; // [esp+28h] [ebp-18h] BYREF

  v3 = (Scaleform::GFx::AS3::VMFile *)file;
  RefCount = (Scaleform::GFx::AS3::Abc::File *)file[2].RefCount;
  v6 = (Scaleform::GFx::AS3::VMAbcFile *)RefCount->AS3_Classes.Info.Data.Data[(int)v.pNode];
  pCurrent = this->OpStack.pCurrent;
  v8 = pCurrent->Flags & 0x1F;
  file = (Scaleform::GFx::ASStringNode *)v6;
  value = pCurrent;
  if ( !v8 || (unsigned int)(v8 - 12) <= 3 && !pCurrent->value.VS._1.VInt )
  {
    if ( v6->AppDomain )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&value, eConvertNullToObjectError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v9,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      v10 = v32;
      --v32->RefCount;
      v11 = v10;
      if ( v10->RefCount )
        return;
      goto LABEL_6;
    }
    goto LABEL_10;
  }
  if ( v8 == 13 )
  {
LABEL_10:
    v14 = (int)&RefCount->Const_Pool.const_multiname.Data.Data[(int)v6->VMRef];
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                          v3,
                          *(Scaleform::GFx::AS3::Instances::fl::Namespace **)v14);
    pNode = InternedNamespace->Uri.pNode;
    if ( pNode->Size >= 0xD && !strncmp(pNode->pData, "scaleform.gfx", 0xDu) )
    {
      Scaleform::GFx::AS3::VMFile::GetInternedString(v3, &v, *(Scaleform::GFx::ASStringNode **)(v14 + 8));
      Scaleform::GFx::AS3::Value::Value(&name, &v);
      pObject = this->GlobalObject.pObject;
      v18 = pObject->__vftable;
      Scaleform::GFx::AS3::Multiname::Multiname(&v34, InternedNamespace, &name);
      LOBYTE(pObject) = !v18->GetProperty(pObject, (Scaleform::GFx::AS3::CheckResult *)&file, v19, value)->Result;
      Scaleform::GFx::AS3::Multiname::~Multiname(&v34);
      Scaleform::GFx::AS3::Value::~Value(&name);
      if ( (_BYTE)pObject )
      {
        v20 = v.pNode;
        pData = v.pNode->pData;
        Scaleform::StringDataPtr::StringDataPtr(&v30, "scaleform.gfx");
        Scaleform::StringDataPtr::StringDataPtr(&v29, pData);
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&value,
          eReadSealedError,
          (Scaleform::String)this,
          v29,
          v30);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v22,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v23 = v32;
        --v32->RefCount;
        if ( !v23->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        v24 = v20->RefCount-- == 1;
        if ( v24 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      }
      else
      {
        v25 = v.pNode;
        v24 = v.pNode->RefCount-- == 1;
        if ( v24 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
    }
    else
    {
      UserDefinedTraits = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)Scaleform::GFx::AS3::VM::GetUserDefinedTraits(
                                                                             this,
                                                                             v3,
                                                                             file);
      v27 = UserDefinedTraits->ITraits.pObject;
      if ( v27->pConstructor.pObject )
      {
        Scaleform::GFx::AS3::Value::Assign(value, v27->pConstructor.pObject);
      }
      else
      {
        Class = Scaleform::GFx::AS3::ClassTraits::UserDefined::MakeClass(
                  UserDefinedTraits,
                  (Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *)&file);
        Scaleform::GFx::AS3::Value::Pick(value, Class->pV);
      }
    }
    return;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&value, eConvertNullToObjectError, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v12,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  v13 = v32;
  --v32->RefCount;
  v11 = v13;
  if ( !v13->RefCount )
LABEL_6:
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}
