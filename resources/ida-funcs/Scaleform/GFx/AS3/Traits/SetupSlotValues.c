Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Traits::SetupSlotValues(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        const Scaleform::GFx::AS3::Abc::HasTraits *t,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *for_obj)
{
  const Scaleform::GFx::AS3::Abc::HasTraits *v5; // edx
  Scaleform::GFx::AS3::VM *pVM; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Abc::File *pObject; // ecx
  Scaleform::GFx::AS3::Abc::TraitInfo *v11; // esi
  int *p_Ind; // eax
  int v13; // edx
  int v14; // ecx
  Scaleform::GFx::AS3::Abc::MultinameKind v15; // edx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // edi
  Scaleform::GFx::ASStringNode *p_default_value; // eax
  Scaleform::GFx::AS3::VM *v18; // esi
  Scaleform::GFx::AS3::Value *DetailValue; // eax
  Scaleform::GFx::AS3::WeakProxy *v20; // eax
  Scaleform::GFx::AS3::Value *v21; // ecx
  Scaleform::GFx::AS3::Abc::File *v22; // ecx
  int name_ind; // eax
  Scaleform::GFx::AS3::VM *v24; // esi
  int *v25; // eax
  int v26; // edx
  int v27; // ecx
  Scaleform::GFx::AS3::Abc::MultinameKind v28; // edx
  Scaleform::GFx::AS3::Value *DefaultValue; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult *v31; // eax
  Scaleform::GFx::AS3::CheckResult v32; // [esp+12h] [ebp-4Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v33; // [esp+13h] [ebp-49h] BYREF
  Scaleform::GFx::AS3::InitializerGuard __; // [esp+14h] [ebp-48h]
  Scaleform::GFx::AS3::AbsoluteIndex i; // [esp+18h] [ebp-44h]
  Scaleform::GFx::AS3::Value v36; // [esp+1Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v37; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Abc::Multiname mn; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Abc::Multiname v39; // [esp+4Ch] [ebp-10h] BYREF
  bool filea; // [esp+64h] [ebp+8h]

  v5 = t;
  pVM = this->pVM;
  ++pVM->InInitializer;
  v8 = 0;
  __.Resource = pVM;
  i.Index = 0;
  if ( !t->obj_traits.Data.Size )
  {
LABEL_26:
    v31 = result;
    --pVM->InInitializer;
    result->Result = 1;
    return v31;
  }
  while ( 1 )
  {
    pObject = file->File.pObject;
    v11 = pObject->Traits.TraitInfos.Data.Data[v5->obj_traits.Data.Data[v8]];
    if ( (v11->kind & 0xF) != 0 && (v11->kind & 0xF) != 6 )
      goto LABEL_24;
    p_Ind = &pObject->Const_Pool.const_multiname.Data.Data[v11->name_ind].Ind;
    v13 = p_Ind[1];
    mn.Ind = *p_Ind;
    v14 = p_Ind[2];
    mn.NextIndex = v13;
    v15 = p_Ind[3];
    mn.NameIndex = v14;
    mn.Kind = v15;
    SlotInfo = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Traits::FindSlotInfo(this, file, &mn);
    if ( !SlotInfo )
      goto LABEL_24;
    p_default_value = (Scaleform::GFx::ASStringNode *)&v11->default_value;
    if ( v11->default_value.ValueIndex <= 0 )
    {
      v22 = file->File.pObject;
      if ( (v11->kind & 0xF) != 0 && (v11->kind & 0xF) != 6 )
        name_ind = v22->AS3_Classes.Info.Data.Data[v11->Ind]->inst_info.name_ind;
      else
        name_ind = v11->Ind;
      v24 = this->pVM;
      v25 = &v22->Const_Pool.const_multiname.Data.Data[name_ind].Ind;
      v26 = v25[1];
      v39.Ind = *v25;
      v27 = v25[2];
      v39.NextIndex = v26;
      v28 = v25[3];
      v39.NameIndex = v27;
      v39.Kind = v28;
      DefaultValue = Scaleform::GFx::AS3::VM::GetDefaultValue(v24, &v37, file, &v39);
      filea = !Scaleform::GFx::AS3::SlotInfo::SetSlotValue(SlotInfo, &v33, v24, DefaultValue, for_obj)->Result;
      if ( (v37.Flags & 0x1F) > 9 )
      {
        if ( (v37.Flags & 0x200) == 0 )
        {
          v21 = &v37;
          goto LABEL_22;
        }
        pWeakProxy = v37.Bonus.pWeakProxy;
        --v37.Bonus.pWeakProxy->RefCount;
        if ( !pWeakProxy->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        v37.Flags &= 0xFFFFFDE0;
        memset(&v37.Bonus, 0, 12);
      }
    }
    else
    {
      v18 = this->pVM;
      DetailValue = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(file, &v36, p_default_value);
      filea = !Scaleform::GFx::AS3::SlotInfo::SetSlotValue(SlotInfo, &v32, v18, DetailValue, for_obj)->Result;
      if ( (v36.Flags & 0x1F) <= 9 )
        goto LABEL_23;
      if ( (v36.Flags & 0x200) == 0 )
      {
        v21 = &v36;
LABEL_22:
        Scaleform::GFx::AS3::Value::ReleaseInternal(v21);
        goto LABEL_23;
      }
      v20 = v36.Bonus.pWeakProxy;
      --v36.Bonus.pWeakProxy->RefCount;
      if ( !v20->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
      v36.Flags &= 0xFFFFFDE0;
      memset(&v36.Bonus, 0, 12);
    }
LABEL_23:
    if ( filea )
      break;
LABEL_24:
    v5 = t;
    v8 = i.Index + 1;
    i.Index = v8;
    if ( v8 >= t->obj_traits.Data.Size )
    {
      pVM = __.Resource;
      goto LABEL_26;
    }
  }
  v31 = result;
  --__.Resource->InInitializer;
  result->Result = 0;
  return v31;
}
