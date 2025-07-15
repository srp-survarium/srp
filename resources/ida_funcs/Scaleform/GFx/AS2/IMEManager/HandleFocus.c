Scaleform::GFx::TextField *__thiscall Scaleform::GFx::AS2::IMEManager::HandleFocus(
        Scaleform::GFx::AS2::IMEManager *this,
        Scaleform::GFx::Movie *pmovie,
        Scaleform::GFx::InteractiveObject *poldFocusedItem,
        Scaleform::GFx::TextField *pnewFocusingItem,
        Scaleform::String ptopMostItem)
{
  Scaleform::GFx::AS2::IMEManager *v5; // esi
  Scaleform::GFx::IMEManagerBase *pimeManager; // ecx
  int v7; // ebx
  Scaleform::GFx::CharacterDef::CharacterDefType IsIMEEnabled; // eax
  Scaleform::GFx::TextField *v10; // edi
  Scaleform::GFx::AS2::MovieRoot *pObject; // ebp
  Scaleform::GFx::FontResource *FontResource; // edi
  Scaleform::GFx::Sprite *LevelMovie; // ecx
  Scaleform::GFx::InteractiveObject *v14; // ebp
  Scaleform::GFx::InteractiveObject *pData; // edi
  Scaleform::GFx::InteractiveObject *v16; // ecx
  _DWORD *v17; // esi
  int v18; // eax
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  int v20; // eax
  int v21; // eax
  Scaleform::GFx::AS2::StringManager *v22; // eax
  int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::InteractiveObject *currItem; // [esp+28h] [ebp-2Ch]
  Scaleform::GFx::ASStringNode *v27; // [esp+2Ch] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+30h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::IMEManager *v29; // [esp+34h] [ebp-20h]
  Scaleform::GFx::IMEManagerBase *pimeManagerBase; // [esp+38h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value val; // [esp+3Ch] [ebp-18h] BYREF
  char pmoviea; // [esp+58h] [ebp+4h]

  v5 = this;
  pimeManager = this->pimeManager;
  v7 = 0;
  v29 = v5;
  pimeManagerBase = pimeManager;
  if ( !pimeManager )
    return pnewFocusingItem;
  IsIMEEnabled = ((int (__thiscall *)(Scaleform::GFx::IMEManagerBase *, Scaleform::GFx::Movie *))pimeManager->IsMovieActive)(
                   pimeManager,
                   pmovie);
  v10 = pnewFocusingItem;
  if ( !(_BYTE)IsIMEEnabled )
    return v10;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)v5->pMovie->pASMovieRoot.pObject;
  if ( pnewFocusingItem )
  {
    IsIMEEnabled = pnewFocusingItem->GetType(pnewFocusingItem);
    if ( IsIMEEnabled == MouseWheel )
    {
      FontResource = Scaleform::GFx::TextField::GetFontResource(pnewFocusingItem);
      *(_QWORD *)&val.T.Type = 0;
      if ( FontResource )
      {
        if ( !(unsigned __int8)Scaleform::GFx::Movie::GetVariable(
                                 v5->pMovie,
                                 (Scaleform::GFx::Value *)&val,
                                 "_global.gfx_ime_candidate_list_state") )
        {
          if ( (val.V.BooleanValue & 0x40) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::LocalFrame *))(**(_DWORD **)&val.T.Type + 8))(
              *(_DWORD *)&val.T.Type,
              &val,
              val.V.FunctionValue.pLocalFrame);
            *(_DWORD *)&val.T.Type = 0;
          }
          val.NV.Int32Value = 5;
          *(double *)((char *)&val.NV.NumberValue + 4) = 0.0;
        }
        LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 9999);
        if ( LevelMovie && 2.0 == *(double *)((char *)&val.NV.NumberValue + 4) )
          Scaleform::GFx::Sprite::SetIMECandidateListFont(LevelMovie, FontResource);
      }
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&val);
      v10 = pnewFocusingItem;
    }
  }
  v14 = poldFocusedItem;
  if ( !poldFocusedItem || (IsIMEEnabled = poldFocusedItem->GetType(poldFocusedItem), IsIMEEnabled != MouseWheel) )
  {
LABEL_39:
    if ( !v10 )
      goto LABEL_40;
    goto LABEL_46;
  }
  pData = (Scaleform::GFx::InteractiveObject *)ptopMostItem.pData;
  if ( ptopMostItem.pData )
  {
    Scaleform::String::String(&ptopMostItem);
    Scaleform::GFx::DisplayObject::GetAbsolutePath(pData, &ptopMostItem);
    if ( v5->IsCandidateList(v5, (const char *)((ptopMostItem.HeapTypeBits & 0xFFFFFFFC) + 8)) )
    {
LABEL_36:
      Scaleform::String::~String(&ptopMostItem);
      return (Scaleform::GFx::TextField *)v14;
    }
    v16 = pData;
    currItem = pData;
    val.T.Type = 0;
    while ( ((v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
           ? (unsigned int)v16
           : 0) != 0 )
    {
      v17 = (_DWORD *)(((v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
                      ? (unsigned int)v16
                      : 0)
                     + 4
                     * *((v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
                       ? &v16->AvmObjOffset
                       : (unsigned __int8 *)65));
      v7 |= 1u;
      v18 = (*(int (__thiscall **)(_DWORD *))(*v17 + 124))(v17);
      StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*(Scaleform::GFx::AS2::GlobalContext **)(v18 + 116));
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManager->pStringManager,
                          "isLanguageBar",
                          0xDu,
                          0);
      ++ConstStringNode->RefCount;
      v20 = (*(int (__thiscall **)(_DWORD *))(*v17 + 124))(v17);
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(v17[1] + 44))(
             v17 + 1,
             v20 + 116,
             &ConstStringNode,
             &val)
        || (v7 |= 2u,
            v21 = (*(int (__thiscall **)(_DWORD *))(*v17 + 124))(v17),
            v22 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*(Scaleform::GFx::AS2::GlobalContext **)(v21 + 116)),
            v27 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v22->pStringManager, "isStatusWindow", 0xEu, 0),
            ++v27->RefCount,
            v23 = (*(int (__thiscall **)(_DWORD *))(*v17 + 124))(v17),
            pmoviea = 0,
            (*(unsigned __int8 (__thiscall **)(_DWORD *, int, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(v17[1] + 44))(
              v17 + 1,
              v23 + 116,
              &v27,
              &val)) )
      {
        pmoviea = 1;
      }
      if ( (v7 & 2) != 0 )
      {
        v24 = v27;
        --v27->RefCount;
        v7 &= ~2u;
        if ( !v24->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      }
      if ( (v7 & 1) != 0 )
      {
        v25 = ConstStringNode;
        --ConstStringNode->RefCount;
        v7 &= ~1u;
        if ( !v25->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
      if ( pmoviea )
      {
        Scaleform::GFx::AS2::Value::~Value(&val);
        Scaleform::String::~String(&ptopMostItem);
        return (Scaleform::GFx::TextField *)poldFocusedItem;
      }
      v5 = v29;
      v14 = poldFocusedItem;
      currItem = currItem->pParent;
      if ( !currItem )
        break;
      v16 = currItem;
    }
    if ( v5->IsStatusWindow(v5, (const char *)((ptopMostItem.HeapTypeBits & 0xFFFFFFFC) + 8))
      || v5->IsLangBar(v5, (const char *)((ptopMostItem.HeapTypeBits & 0xFFFFFFFC) + 8)) )
    {
      Scaleform::GFx::AS2::Value::~Value(&val);
      goto LABEL_36;
    }
    Scaleform::GFx::IMEManagerBase::DoFinalize(pimeManagerBase);
    Scaleform::GFx::AS2::Value::~Value(&val);
    Scaleform::String::~String(&ptopMostItem);
    v10 = pnewFocusingItem;
    goto LABEL_39;
  }
  if ( pnewFocusingItem )
  {
    v10 = pnewFocusingItem;
LABEL_46:
    IsIMEEnabled = v10->GetType(v10);
    if ( IsIMEEnabled == MouseWheel )
    {
      IsIMEEnabled = Scaleform::GFx::TextField::IsIMEEnabled(v10);
      if ( (_BYTE)IsIMEEnabled )
      {
        LOBYTE(IsIMEEnabled) = 1;
        goto LABEL_41;
      }
    }
LABEL_40:
    LOBYTE(IsIMEEnabled) = 0;
LABEL_41:
    Scaleform::GFx::IMEManagerBase::EnableIME(pimeManagerBase, IsIMEEnabled);
    return v10;
  }
  return 0;
}
