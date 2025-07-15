Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Abc::HasTraits *traits,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::ASStringNode *members)
{
  Scaleform::GFx::AS3::VMAbcFile *v5; // edx
  const Scaleform::GFx::AS3::Abc::HasTraits *v6; // esi
  Scaleform::GFx::AS3::Traits *v7; // ebx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Abc::File *pObject; // ecx
  Scaleform::GFx::AS3::Abc::TraitInfo *v10; // edi
  int v11; // eax
  int v12; // esi
  Scaleform::GFx::AS3::SlotInfo::BindingType v13; // ebp
  Scaleform::GFx::AS3::Abc::File *v14; // ecx
  int name_ind; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType BindingType; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // esi
  Scaleform::GFx::ASString *v18; // eax
  Scaleform::GFx::ASString *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int v21; // ebx
  unsigned int v22; // eax
  bool v23; // zf
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASStringNode *pStr; // eax
  Scaleform::GFx::ASStringNode *Size; // eax
  int v27; // eax
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Slots *v29; // esi
  _DWORD *p_Value; // ecx
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::AS3::CheckResult *v32; // eax
  const char *pData; // eax
  unsigned int v34; // eax
  unsigned int v35; // eax
  Scaleform::GFx::AS3::VM *v36; // esi
  const Scaleform::GFx::AS3::VM::Error *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::StringDataPtr v41; // [esp-10h] [ebp-74h]
  Scaleform::StringDataPtr v42; // [esp-8h] [ebp-6Ch]
  char resulta; // [esp+11h] [ebp-53h]
  bool _const; // [esp+12h] [ebp-52h]
  Scaleform::GFx::AS3::CheckResult v45; // [esp+13h] [ebp-51h] BYREF
  Scaleform::GFx::ASString mn_name; // [esp+14h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Traits *v47; // [esp+18h] [ebp-4Ch]
  int FixedValueSlotNumber; // [esp+1Ch] [ebp-48h]
  Scaleform::GFx::AS3::AbsoluteIndex i; // [esp+20h] [ebp-44h]
  Scaleform::GFx::ASString v50; // [esp+24h] [ebp-40h] BYREF
  Scaleform::StringDataPtr arg1; // [esp+28h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+30h] [ebp-34h]
  Scaleform::GFx::AS3::VM::Error v53; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+3Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::SlotInfo nsi; // [esp+4Ch] [ebp-18h] BYREF

  v5 = file;
  v6 = traits;
  v7 = this;
  vm = file->VMRef;
  v8 = 0;
  v47 = this;
  resulta = 1;
  i.Index = 0;
  if ( !traits->obj_traits.Data.Size )
  {
    v32 = result;
    result->Result = 1;
    return v32;
  }
  while ( 1 )
  {
    pObject = v5->File.pObject;
    v10 = pObject->Traits.TraitInfos.Data.Data[v6->obj_traits.Data.Data[v8]];
    v11 = v10->kind & 0xF;
    if ( ((v10->kind & 0xF) == 0 || v11 == 6 || v11 == 4 || v11 == 5) && (!(_BYTE)members || v10->SlotId) )
      goto LABEL_54;
    v12 = (int)&pObject->Const_Pool.const_multiname.Data.Data[v10->name_ind];
    v13 = BT_ValueArray;
    if ( v11 == 1 || v11 == 2 || v11 == 3 )
    {
      FixedValueSlotNumber = -1;
    }
    else
    {
      FixedValueSlotNumber = v7->FixedValueSlotNumber;
      v7->FixedValueSlotNumber = FixedValueSlotNumber + 1;
    }
    _const = 0;
    switch ( v10->kind & 0xF )
    {
      case 0:
        goto $LN11_83;
      case 1:
        v13 = BT_Code;
        break;
      case 2:
        v13 = BT_Get;
        break;
      case 3:
        v13 = BT_Set;
        break;
      case 4:
      case 6:
        _const = 1;
$LN11_83:
        v14 = v5->File.pObject;
        if ( (v10->kind & 0xF) != 0 && (v10->kind & 0xF) != 6 )
          name_ind = v14->AS3_Classes.Info.Data.Data[v10->Ind]->inst_info.name_ind;
        else
          name_ind = v10->Ind;
        BindingType = Scaleform::GFx::AS3::Traits::GetBindingType(
                        v7,
                        v5,
                        &v14->Const_Pool.const_multiname.Data.Data[name_ind]);
        v5 = file;
        v13 = BindingType;
        break;
      case 5:
        v13 = BT_Value;
        break;
      default:
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString(v5, &mn_name, *(Scaleform::GFx::ASStringNode **)(v12 + 8));
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                          file,
                          (Scaleform::GFx::AS3::Abc::Multiname *)v12);
    v18 = v7->GetQualifiedName(v7, (Scaleform::GFx::ASString *)&arg1.Size, qnfWithColons);
    v19 = Scaleform::GFx::ASString::operator+(v18, (Scaleform::GFx::ASString *)&arg1, (const __m128i *)"/");
    pNode = Scaleform::GFx::ASString::operator+(v19, &v50, &mn_name)->pNode;
    if ( pNode )
      ++pNode->RefCount;
    if ( InternedNamespace )
      InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
    nsi.pNs.pObject = InternedNamespace;
    v21 = (file->RefCount + 1) & 0x8FBFFFFF;
    v22 = *(_DWORD *)&nsi & 0xF8000000 | 0x7FFFC00;
    nsi.CTraits.pObject = 0;
    nsi.File.pObject = file;
    file->RefCount = v21;
    nsi.TI = v10;
    if ( pNode )
      ++pNode->RefCount;
    nsi.Name.pObject = pNode;
    *(_DWORD *)&nsi = ((unsigned __int8)(_const + 2) ^ (unsigned __int8)v22) & 0x1F ^ v22;
    if ( pNode )
    {
      v23 = pNode->RefCount-- == 1;
      if ( v23 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    v24 = v50.pNode;
    --v50.pNode->RefCount;
    if ( !v24->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    pStr = (Scaleform::GFx::ASStringNode *)arg1.pStr;
    --*((_DWORD *)arg1.pStr + 3);
    if ( !pStr->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pStr);
    Size = (Scaleform::GFx::ASStringNode *)arg1.Size;
    --*(_DWORD *)(arg1.Size + 12);
    if ( !Size->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(Size);
    v27 = v10->kind & 0xF;
    if ( v27 == 1 || v27 == 2 || v27 == 3 )
    {
      v7 = v47;
      v.value.VS._1.VInt = v10->Ind;
      v.Flags = 2;
      v.Bonus.pWeakProxy = 0;
      resulta = Scaleform::GFx::AS3::Traits::RegisterWithVT(v47, &v45, &mn_name, &nsi, &v, v13)->Result;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          pWeakProxy = v.Bonus.pWeakProxy;
          v23 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v23 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          memset(&v.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
      }
      goto LABEL_50;
    }
    v7 = v47;
    v29 = &v47->Scaleform::GFx::AS3::Slots;
    p_Value = &v29->VArray.Data.Data[Scaleform::GFx::AS3::Slots::Add(
                                       &v47->Scaleform::GFx::AS3::Slots,
                                       (Scaleform::GFx::AS3::AbsoluteIndex *)&v53,
                                       &mn_name,
                                       &nsi)->Index
                                   - v29->FirstOwnSlotNum].Value;
    if ( (*p_Value & 0x3E0) != 0 )
      break;
    *p_Value = *p_Value & 0xF800001F | (32 * (v13 & 0x1F | (32 * ((unsigned int)&loc_1FFFF & FixedValueSlotNumber))));
LABEL_50:
    if ( !resulta )
      goto LABEL_57;
    Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
    v31 = mn_name.pNode;
    --mn_name.pNode->RefCount;
    if ( !v31->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    v5 = file;
LABEL_54:
    v6 = traits;
    v8 = i.Index + 1;
    i.Index = v8;
    if ( v8 >= traits->obj_traits.Data.Size )
    {
      v32 = result;
      result->Result = resulta;
      return v32;
    }
  }
  resulta = 0;
LABEL_57:
  pData = v7->GetName(v7, (Scaleform::GFx::ASString *)&members)->pNode->pData;
  v42.pStr = pData;
  if ( pData )
    v34 = strlen(pData);
  else
    v34 = 0;
  v42.Size = v34;
  if ( mn_name.pNode->pData )
    v35 = strlen(mn_name.pNode->pData);
  else
    v35 = 0;
  v36 = vm;
  v41.Size = v35;
  v41.pStr = mn_name.pNode->pData;
  Scaleform::GFx::AS3::VM::Error::Error(&v53, eIllegalOverrideError, (Scaleform::String)vm, v41, v42);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v36,
    v37,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v38 = v53.Message.pNode;
  --v53.Message.pNode->RefCount;
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  v39 = members;
  --members->RefCount;
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
  v40 = mn_name.pNode;
  --mn_name.pNode->RefCount;
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  v32 = result;
  result->Result = resulta;
  return v32;
}
