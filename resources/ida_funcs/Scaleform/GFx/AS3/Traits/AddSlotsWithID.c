Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Traits::AddSlotsWithID(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Abc::HasTraits *traits,
        Scaleform::GFx::AS3::VMAbcFile *file)
{
  Scaleform::GFx::AS3::VMAbcFile *v4; // ebx
  const Scaleform::GFx::AS3::Abc::HasTraits *v5; // esi
  unsigned int Size; // eax
  unsigned int v7; // edx
  _DWORD *v8; // ecx
  const Scaleform::GFx::AS3::Abc::TraitInfo *v9; // edi
  int v10; // eax
  int v11; // ebp
  char BindingType; // si
  int Ind; // eax
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::SlotInfo *v16; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v18; // zf
  Scaleform::GFx::AS3::CheckResult *v19; // eax
  Scaleform::GFx::AS3::VM *v20; // esi
  const Scaleform::GFx::AS3::VM::Error *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // ecx
  Scaleform::GFx::ASString mn_name; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex _const; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS3::Traits *v26; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS3::AbsoluteIndex i; // [esp+1Ch] [ebp-10h]
  Scaleform::GFx::AS3::SlotIndex slot_id; // [esp+20h] [ebp-Ch]
  Scaleform::GFx::AS3::VM *vm; // [esp+24h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v30; // [esp+28h] [ebp-4h]

  v4 = file;
  v5 = traits;
  vm = file->VMRef;
  Size = traits->obj_traits.Data.Size;
  v7 = 0;
  v26 = this;
  i.Index = 0;
  if ( !Size )
  {
LABEL_22:
    v19 = result;
    result->Result = 1;
    return v19;
  }
  while ( 1 )
  {
    v8 = &v4->File.pObject->__vftable;
    v9 = *(const Scaleform::GFx::AS3::Abc::TraitInfo **)(v8[34] + 4 * v5->obj_traits.Data.Data[v7]);
    v10 = v9->kind & 0xF;
    if ( (v9->kind & 0xF) != 0 && v10 != 6 && v10 != 4 && v10 != 5 )
      goto LABEL_21;
    v11 = v8[22] + 16 * v9->name_ind;
    slot_id.Index = v9->SlotId;
    if ( !slot_id.Index )
      goto LABEL_21;
    BindingType = 1;
    LOBYTE(_const.Index) = 0;
    switch ( v10 )
    {
      case 0:
        goto $LN5_140;
      case 4:
      case 6:
        LOBYTE(_const.Index) = 1;
$LN5_140:
        if ( v10 && v10 != 6 )
          Ind = *(_DWORD *)(*(_DWORD *)(v8[37] + 4 * v9->Ind) + 20);
        else
          Ind = v9->Ind;
        BindingType = Scaleform::GFx::AS3::Traits::GetBindingType(
                        v26,
                        v4,
                        (Scaleform::GFx::AS3::Abc::Multiname *)(v8[22] + 16 * Ind));
        break;
      case 5:
        BindingType = 2;
        break;
      default:
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString(v4, &mn_name, *(Scaleform::GFx::ASStringNode **)(v11 + 8));
    v14 = slot_id.Index - 1;
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                          file,
                          (Scaleform::GFx::AS3::Abc::Multiname *)v11);
    if ( InternedNamespace )
      InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
    v16 = Scaleform::GFx::AS3::Traits::AddSetSlot(
            v26,
            (Scaleform::GFx::AS3::RelativeIndex)v14,
            &mn_name,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)InternedNamespace,
            file,
            v9,
            _const);
    if ( (*(_DWORD *)v16 & 0x3E0) != 0 )
      break;
    pNode = mn_name.pNode;
    *(_DWORD *)v16 = *(_DWORD *)v16 & 0xFFFFFC1F | (32 * ((unsigned int)&loc_3FFFE0 | BindingType & 0x1F));
    v18 = pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v4 = file;
LABEL_21:
    v5 = traits;
    v7 = i.Index + 1;
    i.Index = v7;
    if ( v7 >= traits->obj_traits.Data.Size )
      goto LABEL_22;
  }
  v20 = vm;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&vm, eIllegalOverrideError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v20,
    v21,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v22 = v30;
  --v30->RefCount;
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v23 = mn_name.pNode;
  v18 = mn_name.pNode->RefCount-- == 1;
  result->Result = 0;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  return result;
}
