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
  Scaleform::GFx::AS3::VMAbcFile *v14; // ebp
  unsigned int v15; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::GFx::AS3::Traits *v17; // edi
  Scaleform::GFx::AS3::SlotInfo *v18; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v20; // zf
  Scaleform::GFx::AS3::CheckResult *v21; // eax
  const char *pData; // eax
  unsigned int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // edi
  unsigned int v25; // eax
  Scaleform::GFx::AS3::VM *v26; // esi
  const Scaleform::GFx::AS3::VM::Error *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::StringDataPtr v30; // [esp-10h] [ebp-3Ch]
  const Scaleform::GFx::AS3::Abc::TraitInfo *v31; // [esp-8h] [ebp-34h]
  Scaleform::StringDataPtr v32; // [esp-8h] [ebp-34h]
  Scaleform::GFx::AS3::Abc::Multiname *v33; // [esp-4h] [ebp-30h]
  Scaleform::GFx::ASString mn_name; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex _const; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS3::Traits *v36; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS3::AbsoluteIndex i; // [esp+1Ch] [ebp-10h]
  Scaleform::GFx::AS3::SlotIndex slot_id; // [esp+20h] [ebp-Ch] BYREF
  Scaleform::GFx::ASStringNode *v39; // [esp+24h] [ebp-8h]
  Scaleform::GFx::AS3::VM *vm; // [esp+28h] [ebp-4h]

  v4 = file;
  v5 = traits;
  vm = file->VMRef;
  Size = traits->obj_traits.Data.Size;
  v7 = 0;
  v36 = this;
  i.Index = 0;
  if ( !Size )
  {
LABEL_22:
    v21 = result;
    result->Result = 1;
    return v21;
  }
  while ( 1 )
  {
    v8 = &v4->File.pObject->__vftable;
    v9 = *(const Scaleform::GFx::AS3::Abc::TraitInfo **)(v8[36] + 4 * v5->obj_traits.Data.Data[v7]);
    v10 = v9->kind & 0xF;
    if ( (v9->kind & 0xF) != 0 && v10 != 6 && v10 != 4 && v10 != 5 )
      goto LABEL_21;
    v11 = v8[24] + 16 * v9->name_ind;
    slot_id.Index = v9->SlotId;
    if ( !slot_id.Index )
      goto LABEL_21;
    BindingType = 1;
    LOBYTE(_const.Index) = 0;
    switch ( v10 )
    {
      case 0:
        goto $LN5_155;
      case 4:
      case 6:
        LOBYTE(_const.Index) = 1;
$LN5_155:
        if ( v10 && v10 != 6 )
          Ind = *(_DWORD *)(*(_DWORD *)(v8[39] + 4 * v9->Ind) + 20);
        else
          Ind = v9->Ind;
        BindingType = Scaleform::GFx::AS3::Traits::GetBindingType(
                        v36,
                        v4,
                        (Scaleform::GFx::AS3::Abc::Multiname *)(v8[24] + 16 * Ind));
        break;
      case 5:
        BindingType = 2;
        break;
      default:
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString(v4, &mn_name, *(Scaleform::GFx::ASStringNode **)(v11 + 8));
    v33 = (Scaleform::GFx::AS3::Abc::Multiname *)v11;
    v14 = file;
    v15 = slot_id.Index - 1;
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, v33);
    if ( InternedNamespace )
      InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
    v31 = v9;
    v17 = v36;
    v18 = Scaleform::GFx::AS3::Traits::AddSetSlot(
            v36,
            (Scaleform::GFx::AS3::RelativeIndex)v15,
            &mn_name,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)InternedNamespace,
            v14,
            v31,
            _const);
    if ( (*(_DWORD *)v18 & 0x3E0) != 0 )
      break;
    pNode = mn_name.pNode;
    *(_DWORD *)v18 = *(_DWORD *)v18 & 0xFFFFFC1F | (32 * (BindingType & 0x1F | 0x3FFFE0));
    v20 = pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v4 = v14;
LABEL_21:
    v5 = traits;
    v7 = i.Index + 1;
    i.Index = v7;
    if ( v7 >= traits->obj_traits.Data.Size )
      goto LABEL_22;
  }
  pData = v17->GetName(v17, (Scaleform::GFx::ASString *)&file)->pNode->pData;
  v32.pStr = pData;
  if ( pData )
    v23 = strlen(pData);
  else
    v23 = 0;
  v24 = mn_name.pNode;
  v32.Size = v23;
  if ( mn_name.pNode->pData )
    v25 = strlen(mn_name.pNode->pData);
  else
    v25 = 0;
  v26 = vm;
  v30.Size = v25;
  v30.pStr = mn_name.pNode->pData;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&slot_id,
    eIllegalOverrideError,
    (Scaleform::String)vm,
    v30,
    v32);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v26,
    v27,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v28 = v39;
  --v39->RefCount;
  if ( !v28->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  v29 = (Scaleform::GFx::ASStringNode *)file;
  --file->pPrev;
  if ( !v29->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  v20 = v24->RefCount-- == 1;
  result->Result = 0;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  return result;
}
