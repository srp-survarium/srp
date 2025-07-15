Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::SlotInfo::GetDataTypeName(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v3; // ebx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits const > *p_CTraits; // ecx
  Scaleform::GFx::AS3::VMAbcFile *v8; // edi
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // ebp
  int v10; // eax
  const Scaleform::GFx::AS3::Abc::Multiname *TypeName; // eax
  Scaleform::GFx::ASString *InternedString; // eax
  const Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::AS3::ClassTraits::Function *v14; // edi
  int v15; // eax
  Scaleform::GFx::ASStringNode *v16; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *v19; // eax

  v3 = vm;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  pObject = this->CTraits.pObject;
  p_CTraits = &this->CTraits;
  if ( pObject )
  {
    v15 = (int)pObject->GetName(pObject, (Scaleform::GFx::ASString *)&vm);
  }
  else
  {
    v8 = this->File.pObject;
    if ( v8 )
    {
      TI = (Scaleform::GFx::AS3::Abc::TraitInfo *)this->TI;
      if ( TI )
      {
        v10 = TI->kind & 0xF;
        if ( (TI->kind & 0xF) == 0 || v10 == 6 || v10 == 4 || v10 == 5 )
        {
          TypeName = Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(TI, v8->File.pObject);
          InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                             v8,
                             (Scaleform::GFx::ASString *)&vm,
                             (Scaleform::GFx::ASStringNode *)TypeName->NameIndex);
          Scaleform::GFx::ASString::operator=(result, InternedString);
        }
        else
        {
          v13 = v3->TraitsFunction.pObject->GetName(v3->TraitsFunction.pObject, (Scaleform::GFx::ASString *)&vm);
          Scaleform::GFx::ASString::operator=(result, v13);
        }
        goto LABEL_24;
      }
    }
    v14 = 0;
    switch ( (int)(*(_DWORD *)this << 22) >> 27 )
    {
      case 0:
      case 1:
      case 2:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v3->TraitsClassClass.pObject);
        v15 = (*(int (__thiscall **)(_DWORD, Scaleform::GFx::AS3::VM **))(MEMORY[0] + 28))(0, &vm);
        break;
      case 3:
      case 4:
        v15 = (int)v3->TraitsObject.pObject->GetName(v3->TraitsObject.pObject, (Scaleform::GFx::ASString *)&vm);
        break;
      case 5:
        v15 = (int)v3->TraitsBoolean.pObject->GetName(v3->TraitsBoolean.pObject, (Scaleform::GFx::ASString *)&vm);
        break;
      case 6:
        v15 = (int)v3->TraitsInt.pObject->GetName(v3->TraitsInt.pObject, (Scaleform::GFx::ASString *)&vm);
        break;
      case 7:
        v15 = (int)v3->TraitsUint.pObject->GetName(v3->TraitsUint.pObject, (Scaleform::GFx::ASString *)&vm);
        break;
      case 8:
        v15 = (int)v3->TraitsNumber.pObject->GetName(v3->TraitsNumber.pObject, (Scaleform::GFx::ASString *)&vm);
        break;
      case 9:
      case 10:
        v15 = (int)v3->TraitsString.pObject->GetName(v3->TraitsString.pObject, (Scaleform::GFx::ASString *)&vm);
        break;
      case 11:
      case 12:
      case 13:
      case 14:
        v14 = v3->TraitsFunction.pObject;
        goto LABEL_19;
      default:
LABEL_19:
        v15 = (int)v14->GetName(v14, (Scaleform::GFx::ASString *)&vm);
        break;
    }
  }
  v16 = *(Scaleform::GFx::ASStringNode **)v15;
  ++*(_DWORD *)(*(_DWORD *)v15 + 12);
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = v16;
LABEL_24:
  v19 = (Scaleform::GFx::ASStringNode *)vm;
  --vm->StringManagerRef;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  return result;
}
