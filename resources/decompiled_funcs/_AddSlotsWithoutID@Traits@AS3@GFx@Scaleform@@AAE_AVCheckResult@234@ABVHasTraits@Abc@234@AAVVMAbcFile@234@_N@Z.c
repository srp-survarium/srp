Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Abc::HasTraits *traits,
        Scaleform::GFx::AS3::VMAbcFile *file,
        bool members)
{
  const Scaleform::GFx::AS3::Abc::HasTraits *v6; // esi
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Abc::File *pObject; // ebp
  Scaleform::GFx::AS3::Abc::TraitInfo *v9; // esi
  int v10; // eax
  const Scaleform::GFx::AS3::Abc::Multiname *v11; // edx
  Scaleform::GFx::AS3::SlotInfo::BindingType v12; // edi
  unsigned int FixedValueSlotNumber; // ebp
  Scaleform::GFx::AS3::Abc::File *v14; // edx
  int name_ind; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType BindingType; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  unsigned int v18; // ecx
  int v19; // eax
  void *pWeakProxy; // eax
  bool v21; // zf
  Scaleform::GFx::AS3::Slots *v22; // esi
  Scaleform::GFx::AS3::AbsoluteIndex *v23; // eax
  Scaleform::GFx::AS3::Slots::Pair *Data; // edx
  int v25; // ecx
  int Value; // eax
  unsigned __int32 *p_Value; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::CheckResult *v29; // eax
  Scaleform::GFx::AS3::VM *v30; // esi
  const Scaleform::GFx::AS3::VM::Error *v31; // eax
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // ecx
  char resulta; // [esp+12h] [ebp-42h]
  Scaleform::GFx::AS3::CheckResult v35; // [esp+13h] [ebp-41h] BYREF
  Scaleform::GFx::AS3::Traits *v36; // [esp+14h] [ebp-40h]
  Scaleform::GFx::ASString mn_name; // [esp+18h] [ebp-3Ch] BYREF
  const Scaleform::GFx::AS3::Abc::Multiname *mn; // [esp+1Ch] [ebp-38h]
  Scaleform::GFx::AS3::AbsoluteIndex i; // [esp+20h] [ebp-34h]
  Scaleform::GFx::AS3::VM *vm; // [esp+24h] [ebp-30h]
  Scaleform::GFx::AS3::VM::Error v41; // [esp+28h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+30h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::SlotInfo nsi; // [esp+40h] [ebp-14h] BYREF
  char _const; // [esp+60h] [ebp+Ch]

  v6 = traits;
  vm = file->VMRef;
  v7 = 0;
  v36 = this;
  resulta = 1;
  i.Index = 0;
  if ( !traits->obj_traits.Data.Size )
  {
    v29 = result;
    result->Result = 1;
    return v29;
  }
  while ( 1 )
  {
    pObject = file->File.pObject;
    v9 = pObject->Traits.TraitInfos.Data.Data[v6->obj_traits.Data.Data[v7]];
    v10 = v9->kind & 0xF;
    if ( ((v9->kind & 0xF) == 0 || v10 == 6 || v10 == 4 || v10 == 5) && (!members || v9->SlotId) )
      goto LABEL_41;
    v11 = &pObject->Const_Pool.const_multiname.Data.Data[v9->name_ind];
    v12 = BT_ValueArray;
    mn = v11;
    if ( v10 == 1 || v10 == 2 || v10 == 3 )
    {
      FixedValueSlotNumber = -1;
    }
    else
    {
      FixedValueSlotNumber = this->FixedValueSlotNumber;
      this->FixedValueSlotNumber = FixedValueSlotNumber + 1;
    }
    _const = 0;
    switch ( v9->kind & 0xF )
    {
      case 0:
        goto $LN11_77;
      case 1:
        v12 = BT_Code;
        break;
      case 2:
        v12 = BT_Get;
        break;
      case 3:
        v12 = BT_Set;
        break;
      case 4:
      case 6:
        _const = 1;
$LN11_77:
        v14 = file->File.pObject;
        if ( (v9->kind & 0xF) != 0 && (v9->kind & 0xF) != 6 )
          name_ind = v14->AS3_Classes.Info.Data.Data[v9->Ind]->inst_info.name_ind;
        else
          name_ind = v9->Ind;
        BindingType = Scaleform::GFx::AS3::Traits::GetBindingType(
                        this,
                        file,
                        &v14->Const_Pool.const_multiname.Data.Data[name_ind]);
        v11 = mn;
        v12 = BindingType;
        break;
      case 5:
        v12 = BT_Value;
        break;
      default:
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString(file, &mn_name, (Scaleform::GFx::ASStringNode *)v11->NameIndex);
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                          file,
                          (Scaleform::GFx::AS3::Abc::Multiname *)mn);
    if ( InternedNamespace )
      InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
    nsi.pNs.pObject = InternedNamespace;
    v18 = *(_DWORD *)&nsi & 0xFFFFFC00;
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
    v19 = v9->kind & 0xF;
    nsi.CTraits.pObject = 0;
    nsi.File.pObject = file;
    nsi.TI = v9;
    *(_DWORD *)&nsi = ((unsigned __int8)((_const != 0) + 2) ^ (unsigned __int8)v18) & 0x1F ^ (v18 | 0x7FFFC00);
    if ( v19 == 1 || v19 == 2 || v19 == 3 )
    {
      v.value.VS._1.VInt = v9->Ind;
      v.Flags = 2;
      v.Bonus.pWeakProxy = 0;
      resulta = Scaleform::GFx::AS3::Traits::RegisterWithVT(v36, &v35, &mn_name, &nsi, &v, v12)->Result;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          pWeakProxy = v.Bonus.pWeakProxy;
          v21 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v21 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          memset(&v.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
      }
      goto LABEL_37;
    }
    v22 = &v36->Scaleform::GFx::AS3::Slots;
    v23 = Scaleform::GFx::AS3::Slots::Add(
            &v36->Scaleform::GFx::AS3::Slots,
            (Scaleform::GFx::AS3::AbsoluteIndex *)&v41,
            &mn_name,
            &nsi);
    Data = v22->VArray.Data.Data;
    v25 = v23->Index - v22->FirstOwnSlotNum;
    Value = (int)Data[v23->Index - v22->FirstOwnSlotNum].Value;
    p_Value = (unsigned __int32 *)&Data[v25].Value;
    if ( (Value & 0x3E0) != 0 )
      break;
    *p_Value = Value & 0xF800001F | (32 * (v12 & 0x1F | (32 * (FixedValueSlotNumber & 0x1FFFF))));
LABEL_37:
    if ( !resulta )
      goto LABEL_44;
    Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
    pNode = mn_name.pNode;
    v21 = mn_name.pNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    this = v36;
LABEL_41:
    v6 = traits;
    v7 = i.Index + 1;
    i.Index = v7;
    if ( v7 >= traits->obj_traits.Data.Size )
    {
      v29 = result;
      result->Result = resulta;
      return v29;
    }
  }
  resulta = 0;
LABEL_44:
  v30 = vm;
  Scaleform::GFx::AS3::VM::Error::Error(&v41, eIllegalOverrideError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v30,
    v31,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v32 = v41.Message.pNode;
  --v41.Message.pNode->RefCount;
  if ( !v32->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
  v33 = mn_name.pNode;
  v21 = mn_name.pNode->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  v29 = result;
  result->Result = resulta;
  return v29;
}
