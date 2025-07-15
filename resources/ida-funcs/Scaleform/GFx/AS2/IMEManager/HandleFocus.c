Scaleform::GFx::TextField *__thiscall Scaleform::GFx::AS2::IMEManager::HandleFocus(
        Scaleform::GFx::AS2::IMEManager *this,
        Scaleform::GFx::Movie *pmovie,
        Scaleform::GFx::InteractiveObject *poldFocusedItem,
        Scaleform::GFx::TextField *pnewFocusingItem,
        Scaleform::String ptopMostItem)
{
  Scaleform::GFx::AS2::IMEManager *v5; // esi
  Scaleform::GFx::Value::ObjectInterface *pimeManager; // ecx
  int v7; // ebx
  Scaleform::GFx::CharacterDef::CharacterDefType IsIMEEnabled; // eax
  Scaleform::GFx::TextField *v10; // edi
  Scaleform::GFx::AS2::MovieRoot *pObject; // ebp
  Scaleform::GFx::FontResource *FontResource; // edi
  Scaleform::GFx::Sprite *LevelMovie; // ecx
  Scaleform::GFx::InteractiveObject *v14; // ebp
  Scaleform::String::DataDesc *pData; // edi
  Scaleform::String::DataDesc *v16; // ecx
  _DWORD *v17; // esi
  int v18; // eax
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  int v20; // eax
  int v21; // eax
  Scaleform::GFx::AS2::StringManager *v22; // eax
  int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::String::DataDesc *v26; // [esp+28h] [ebp-2Ch]
  Scaleform::GFx::ASStringNode *v27; // [esp+2Ch] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+30h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::IMEManager *v29; // [esp+34h] [ebp-20h]
  Scaleform::GFx::Value pval; // [esp+38h] [ebp-1Ch] BYREF
  char v31; // [esp+58h] [ebp+4h]

  v5 = this;
  pimeManager = (Scaleform::GFx::Value::ObjectInterface *)this->pimeManager;
  v7 = 0;
  v29 = v5;
  pval.pObjectInterface = pimeManager;
  if ( !pimeManager )
    return pnewFocusingItem;
  IsIMEEnabled = ((int (__thiscall *)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Movie *))pimeManager->GetCxform)(
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
      pval.Type = VT_Undefined;
      pval.mValue.IValue = 0;
      if ( FontResource )
      {
        if ( !Scaleform::GFx::Movie::GetVariable(
                v5->pMovie,
                (Scaleform::GFx::Value *)&pval.Type,
                "_global.gfx_ime_candidate_list_state") )
        {
          if ( (pval.mValue.BValue & 0x40) != 0 )
          {
            (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, Scaleform::GFx::Value::ValueType *, _DWORD))(*(_DWORD *)pval.Type + 8))(
              pval.Type,
              &pval.Type,
              *((_DWORD *)&pval.mValue.BValue + 1));
            pval.Type = VT_Undefined;
          }
          pval.mValue.IValue = 5;
          *(double *)((char *)&pval.mValue + 4) = 0.0;
        }
        LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 9999);
        if ( LevelMovie && 2.0 == *(double *)((char *)&pval.mValue + 4) )
          Scaleform::GFx::Sprite::SetIMECandidateListFont(LevelMovie, FontResource);
      }
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&pval.Type);
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
  pData = ptopMostItem.pData;
  if ( ptopMostItem.pData )
  {
    Scaleform::String::String(&ptopMostItem);
    Scaleform::GFx::DisplayObject::GetAbsolutePath((Scaleform::GFx::DisplayObject *)pData, &ptopMostItem);
    if ( v5->IsCandidateList(v5, (const char *)((ptopMostItem.HeapTypeBits & 0xFFFFFFFC) + 8)) )
    {
LABEL_36:
      Scaleform::String::~String(&ptopMostItem);
      return (Scaleform::GFx::TextField *)v14;
    }
    v16 = pData;
    v26 = pData;
    LOBYTE(pval.Type) = 0;
    while ( ((v16[5].Size & 0x4000000) != 0 ? (unsigned int)v16 : 0) != 0 )
    {
      v17 = (_DWORD *)(((v16[5].Size & 0x4000000) != 0 ? (unsigned int)v16 : 0)
                     + 4
                     * *((v16[5].Size & 0x4000000) != 0 ? (unsigned __int8 *)&v16[5].RefCount + 1 : (unsigned __int8 *)65));
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
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int, Scaleform::GFx::ASStringNode **, Scaleform::GFx::Value::ValueType *))(v17[1] + 44))(
             v17 + 1,
             v20 + 116,
             &ConstStringNode,
             &pval.Type)
        || (v7 |= 2u,
            v21 = (*(int (__thiscall **)(_DWORD *))(*v17 + 124))(v17),
            v22 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*(Scaleform::GFx::AS2::GlobalContext **)(v21 + 116)),
            v27 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v22->pStringManager, "isStatusWindow", 0xEu, 0),
            ++v27->RefCount,
            v23 = (*(int (__thiscall **)(_DWORD *))(*v17 + 124))(v17),
            v31 = 0,
            (*(unsigned __int8 (__thiscall **)(_DWORD *, int, Scaleform::GFx::ASStringNode **, Scaleform::GFx::Value::ValueType *))(v17[1] + 44))(
              v17 + 1,
              v23 + 116,
              &v27,
              &pval.Type)) )
      {
        v31 = 1;
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
      if ( v31 )
      {
        Scaleform::GFx::AS2::Value::~Value((Scaleform::GFx::AS2::Value *)&pval.Type);
        Scaleform::String::~String(&ptopMostItem);
        return (Scaleform::GFx::TextField *)poldFocusedItem;
      }
      v5 = v29;
      v14 = poldFocusedItem;
      v26 = *(Scaleform::String::DataDesc **)v26[2].Data;
      if ( !v26 )
        break;
      v16 = v26;
    }
    if ( v5->IsStatusWindow(v5, (const char *)((ptopMostItem.HeapTypeBits & 0xFFFFFFFC) + 8))
      || v5->IsLangBar(v5, (const char *)((ptopMostItem.HeapTypeBits & 0xFFFFFFFC) + 8)) )
    {
      Scaleform::GFx::AS2::Value::~Value((Scaleform::GFx::AS2::Value *)&pval.Type);
      goto LABEL_36;
    }
    Scaleform::GFx::IMEManagerBase::DoFinalize((Scaleform::GFx::IMEManagerBase *)pval.pObjectInterface);
    Scaleform::GFx::AS2::Value::~Value((Scaleform::GFx::AS2::Value *)&pval.Type);
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
    Scaleform::GFx::IMEManagerBase::EnableIME((Scaleform::GFx::IMEManagerBase *)pval.pObjectInterface, IsIMEEnabled);
    return v10;
  }
  return 0;
}
