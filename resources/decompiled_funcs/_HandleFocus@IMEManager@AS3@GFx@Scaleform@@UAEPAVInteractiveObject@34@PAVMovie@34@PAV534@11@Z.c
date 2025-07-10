Scaleform::GFx::TextField *__thiscall Scaleform::GFx::AS3::IMEManager::HandleFocus(
        Scaleform::GFx::AS3::IMEManager *this,
        Scaleform::GFx::Movie *pmovie,
        Scaleform::GFx::InteractiveObject *poldFocusedItem,
        Scaleform::GFx::TextField *pnewFocusingItem,
        Scaleform::GFx::InteractiveObject *ptopMostItem)
{
  int v5; // ebx
  Scaleform::GFx::AS3::IMEManager *v6; // edi
  Scaleform::GFx::IMEManagerBase *pimeManager; // ecx
  Scaleform::GFx::Sprite *CandidateListSprite; // eax
  Scaleform::GFx::InteractiveObject *v10; // edi
  int v11; // edx
  Scaleform::GFx::AS3::AvmDisplayObj *v12; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  __int16 Flags; // cx
  Scaleform::GFx::AS3::MovieRoot *AS3Root; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *AVM; // eax
  int (__thiscall **v17)(_DWORD *, char *, int, Scaleform::GFx::AS3::Value *); // edi
  int v18; // eax
  Scaleform::GFx::AS3::MovieRoot *v19; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v20; // eax
  int (__thiscall **v21)(_DWORD *, char *, int, Scaleform::GFx::AS3::Value *); // edi
  int v22; // eax
  Scaleform::GFx::AS3::MovieRoot *v23; // eax
  Scaleform::GFx::ASString *v24; // eax
  Scaleform::GFx::ASMovieRootBase_vtbl *v25; // eax
  int (__thiscall **v26)(_DWORD *, char *, int, Scaleform::GFx::AS3::Value *); // esi
  int v27; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  char v31; // [esp+2Dh] [ebp-C1h]
  _DWORD *v32; // [esp+2Eh] [ebp-C0h]
  Scaleform::String path; // [esp+32h] [ebp-BCh] BYREF
  int v34; // [esp+36h] [ebp-B8h] BYREF
  Scaleform::GFx::InteractiveObject *currItem; // [esp+3Ah] [ebp-B4h]
  int v36; // [esp+3Eh] [ebp-B0h] BYREF
  Scaleform::GFx::IMEManagerBase *pimeManagerBase; // [esp+42h] [ebp-ACh]
  Scaleform::GFx::ASString v; // [esp+46h] [ebp-A8h] BYREF
  Scaleform::GFx::ASString v39; // [esp+4Ah] [ebp-A4h] BYREF
  Scaleform::GFx::ASString v40; // [esp+4Eh] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+52h] [ebp-9Ch] BYREF
  Scaleform::GFx::AS3::IMEManager *v42; // [esp+62h] [ebp-8Ch]
  Scaleform::GFx::AS3::Value v43; // [esp+66h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::Value v44; // [esp+76h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+86h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+96h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Multiname v47; // [esp+A6h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Multiname v48; // [esp+BEh] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname v49; // [esp+D6h] [ebp-18h] BYREF

  v5 = 0;
  v6 = this;
  v39.pNode = 0;
  pimeManager = this->pimeManager;
  v42 = v6;
  pimeManagerBase = pimeManager;
  if ( !pimeManager )
    return pnewFocusingItem;
  CandidateListSprite = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::IMEManagerBase *, Scaleform::GFx::Movie *))pimeManager->IsMovieActive)(
                                                    pimeManager,
                                                    pmovie);
  if ( !(_BYTE)CandidateListSprite )
    return pnewFocusingItem;
  if ( !ptopMostItem )
  {
LABEL_62:
    if ( pnewFocusingItem )
    {
      CandidateListSprite = (Scaleform::GFx::Sprite *)pnewFocusingItem->GetType(pnewFocusingItem);
      if ( CandidateListSprite == (Scaleform::GFx::Sprite *)4 )
      {
        CandidateListSprite = Scaleform::GFx::AS3::IMEManager::GetCandidateListSprite(v6);
        if ( CandidateListSprite )
          Scaleform::GFx::TextField::SetCandidateListFont(pnewFocusingItem, CandidateListSprite);
      }
    }
    if ( poldFocusedItem )
    {
      CandidateListSprite = (Scaleform::GFx::Sprite *)poldFocusedItem->GetType(poldFocusedItem);
      if ( CandidateListSprite == (Scaleform::GFx::Sprite *)4 )
      {
        if ( !pnewFocusingItem )
        {
          Scaleform::GFx::IMEManagerBase::DoFinalize(pimeManagerBase);
          goto LABEL_70;
        }
        pnewFocusingItem->GetType(pnewFocusingItem);
        Scaleform::GFx::IMEManagerBase::DoFinalize(pimeManagerBase);
      }
    }
    if ( pnewFocusingItem )
    {
      CandidateListSprite = (Scaleform::GFx::Sprite *)pnewFocusingItem->GetType(pnewFocusingItem);
      if ( CandidateListSprite == (Scaleform::GFx::Sprite *)4 )
      {
        CandidateListSprite = (Scaleform::GFx::Sprite *)Scaleform::GFx::TextField::IsIMEEnabled(pnewFocusingItem);
        if ( (_BYTE)CandidateListSprite )
        {
          LOBYTE(CandidateListSprite) = 1;
          goto LABEL_71;
        }
      }
    }
LABEL_70:
    LOBYTE(CandidateListSprite) = 0;
LABEL_71:
    Scaleform::GFx::IMEManagerBase::EnableIME(pimeManagerBase, (BOOL)CandidateListSprite);
    return pnewFocusingItem;
  }
  Scaleform::String::String(&path);
  Scaleform::GFx::DisplayObject::GetAbsolutePath(ptopMostItem, &path);
  if ( v6->IsCandidateList(v6, (const char *)((path.HeapTypeBits & 0xFFFFFFFC) + 8)) )
    goto LABEL_73;
  v10 = ptopMostItem;
  currItem = ptopMostItem;
  val.Flags = 0;
  val.Bonus.pWeakProxy = 0;
  while ( 1 )
  {
    if ( ((v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
        ? (unsigned int)v10
        : 0) == 0 )
      goto LABEL_60;
    v11 = *((v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
          ? &v10->AvmObjOffset
          : (unsigned __int8 *)65);
    v12 = (Scaleform::GFx::AS3::AvmDisplayObj *)(((v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
                                                 & 0x400) != 0
                                                ? (unsigned int)v10
                                                : 0)
                                               + 4 * v11);
    pAS3RawPtr = v12->pAS3RawPtr;
    if ( !pAS3RawPtr )
      pAS3RawPtr = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(((v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
                                                                                   & 0x400) != 0
                                                                                  ? (unsigned int)v10
                                                                                  : 0)
                                                                                 + 4 * v11
                                                                                 + 4);
    v32 = &pAS3RawPtr->__vftable;
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    {
      pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
      v32 = &pAS3RawPtr->__vftable;
    }
    Flags = 0;
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0;
    if ( pAS3RawPtr )
      break;
LABEL_56:
    if ( (Flags & 0x1Fu) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
LABEL_60:
    currItem = v10->pParent;
    if ( !currItem )
    {
      Scaleform::GFx::AS3::Value::~Value(&val);
      Scaleform::String::~String(&path);
      v6 = v42;
      goto LABEL_62;
    }
    v10 = currItem;
  }
  AS3Root = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(v12);
  v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(AS3Root->BuiltinsMgr.pStringManager, "IsCandidateList");
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&name, &v);
  v5 |= 0xFu;
  AVM = Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(v12);
  v17 = (int (__thiscall **)(_DWORD *, char *, int, Scaleform::GFx::AS3::Value *))(*v32 + 16);
  Scaleform::GFx::AS3::Multiname::Multiname(
    &v49,
    (Scaleform::GFx::AS3::Instances::fl::Namespace *)AVM[1].CheckAvm,
    &name);
  if ( *(_BYTE *)(*v17)(v32, (char *)&v34 + 3, v18, &result) )
    goto LABEL_17;
  v19 = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(v12);
  v40.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(v19->BuiltinsMgr.pStringManager, "IsStatusWindow");
  ++v40.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&v43, &v40);
  v5 |= 0xF0u;
  v20 = Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(v12);
  v21 = (int (__thiscall **)(_DWORD *, char *, int, Scaleform::GFx::AS3::Value *))(*v32 + 16);
  Scaleform::GFx::AS3::Multiname::Multiname(
    &v47,
    (Scaleform::GFx::AS3::Instances::fl::Namespace *)v20[1].CheckAvm,
    &v43);
  if ( *(_BYTE *)(*v21)(v32, (char *)&v36 + 3, v22, &result) )
    goto LABEL_17;
  v23 = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(v12);
  v24 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
          &v23->BuiltinsMgr,
          &v39,
          "IsLangBar");
  Scaleform::GFx::AS3::Value::Value(&v44, v24);
  v5 |= 0xF00u;
  v25 = Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(v12);
  v26 = (int (__thiscall **)(_DWORD *, char *, int, Scaleform::GFx::AS3::Value *))(*v32 + 16);
  Scaleform::GFx::AS3::Multiname::Multiname(
    &v48,
    (Scaleform::GFx::AS3::Instances::fl::Namespace *)v25[1].CheckAvm,
    &v44);
  v31 = 0;
  if ( *(_BYTE *)(*v26)(v32, (char *)&v34 + 2, v27, &result) )
LABEL_17:
    v31 = 1;
  if ( (v5 & 0x800) != 0 )
    v5 &= ~0x800u;
  if ( (v5 & 0x400) != 0 )
  {
    v5 &= ~0x400u;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v48);
  }
  if ( (v5 & 0x200) != 0 )
  {
    v5 &= ~0x200u;
    if ( (v44.Flags & 0x1F) > 9 )
    {
      if ( (v44.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v44);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v44);
    }
  }
  if ( (v5 & 0x100) != 0 )
  {
    pNode = v39.pNode;
    --v39.pNode->RefCount;
    v5 &= ~0x100u;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( (v5 & 0x80u) != 0 )
    v5 &= ~0x80u;
  if ( (v5 & 0x40) != 0 )
  {
    v5 &= ~0x40u;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v47);
  }
  if ( (v5 & 0x20) != 0 )
  {
    v5 &= ~0x20u;
    if ( (v43.Flags & 0x1F) > 9 )
    {
      if ( (v43.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v43);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v43);
    }
  }
  if ( (v5 & 0x10) != 0 )
  {
    v29 = v40.pNode;
    --v40.pNode->RefCount;
    v5 &= ~0x10u;
    if ( !v29->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  }
  if ( (v5 & 8) != 0 )
    v5 &= ~8u;
  if ( (v5 & 4) != 0 )
  {
    v5 &= ~4u;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v49);
  }
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
  }
  if ( (v5 & 1) != 0 )
  {
    v30 = v.pNode;
    --v.pNode->RefCount;
    v5 &= ~1u;
    if ( !v30->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  }
  if ( !v31 )
  {
    Flags = result.Flags;
    v10 = currItem;
    goto LABEL_56;
  }
  Scaleform::GFx::AS3::Value::~Value(&result);
  Scaleform::GFx::AS3::Value::~Value(&val);
LABEL_73:
  Scaleform::String::~String(&path);
  return (Scaleform::GFx::TextField *)poldFocusedItem;
}
