void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::InitUserDefinedClassTraits(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  const Scaleform::GFx::AS3::Slots *Parent; // ebx
  Scaleform::GFx::AS3::VMFile *FirstOwnSlotNum; // ebp
  const Scaleform::GFx::AS3::Abc::TraitTable *p_MakeActivationInstanceTraits; // eax
  bool v5; // zf
  Scaleform::GFx::AS3::Abc::TraitInfo *v6; // ecx
  Scaleform::GFx::AS3::VMFile_vtbl *v7; // edx
  int Ind; // esi
  unsigned int *v9; // esi
  const Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v11; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *RegisteredClassTraits; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *v13; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString str_name; // [esp+8h] [ebp-10h] BYREF
  unsigned int i; // [esp+Ch] [ebp-Ch]
  const Scaleform::GFx::AS3::Abc::TraitTable *tt; // [esp+10h] [ebp-8h]
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *p; // [esp+14h] [ebp-4h]

  pObject = this->pTraits.pObject;
  Parent = pObject[1].Parent;
  FirstOwnSlotNum = (Scaleform::GFx::AS3::VMFile *)pObject[1].FirstOwnSlotNum;
  p_MakeActivationInstanceTraits = (const Scaleform::GFx::AS3::Abc::TraitTable *)&FirstOwnSlotNum[1].__vftable[3].MakeActivationInstanceTraits;
  v5 = Parent->Parent == 0;
  p = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this;
  tt = p_MakeActivationInstanceTraits;
  i = 0;
  if ( !v5 )
  {
    while ( 1 )
    {
      v6 = p_MakeActivationInstanceTraits->TraitInfos.Data.Data[*(_DWORD *)(Parent->FirstOwnSlotNum + 4 * i)];
      if ( (v6->kind & 0xF) == 4 )
      {
        v7 = FirstOwnSlotNum[1].__vftable;
        if ( (v6->kind & 0xF) != 0 && (v6->kind & 0xF) != 6 )
          Ind = *(_DWORD *)(*((_DWORD *)v7[4].~Scaleform::GFx::AS3::VMFile + v6->Ind) + 20);
        else
          Ind = v6->Ind;
        v9 = (unsigned int *)((char *)v7[2].MakeInternedNamespace + 16 * Ind);
        InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(FirstOwnSlotNum, *v9);
        Scaleform::GFx::AS3::VMFile::GetInternedString(FirstOwnSlotNum, &str_name, v9[2]);
        if ( !Scaleform::GFx::AS3::IsScaleformGFx(InternedNamespace) )
        {
          v11 = p;
          RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
                                    p->pTraits.pObject->pVM,
                                    &str_name,
                                    InternedNamespace,
                                    FirstOwnSlotNum->AppDomain);
          if ( RegisteredClassTraits )
          {
            if ( (Scaleform::GFx::AS3::VMFile *)RegisteredClassTraits[1].__vftable == FirstOwnSlotNum )
            {
              v13 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&RegisteredClassTraits->ITraits.pObject[1].4;
              if ( !v13->pObject )
                Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
                  v13,
                  v11);
            }
          }
        }
        pNode = str_name.pNode;
        --str_name.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      if ( (const Scaleform::GFx::AS3::Slots *)++i >= Parent->Parent )
        break;
      p_MakeActivationInstanceTraits = tt;
    }
  }
}
