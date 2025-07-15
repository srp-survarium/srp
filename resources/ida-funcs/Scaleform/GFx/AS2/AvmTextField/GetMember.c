char __thiscall Scaleform::GFx::AS2::AvmTextField::GetMember(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::AS2::Environment *penv,
        __int64 name)
{
  int StandardMemberConstant; // eax
  Scaleform::GFx::TextField *pObject; // esi
  unsigned int v6; // ecx
  char val; // cl
  Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *Text; // eax
  int TextColor32; // eax
  long double TextWidth; // st7
  long double TextHeight; // st7
  long double Length; // st7
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::Render::Text::DocView *v17; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  bool IsSelectable; // al
  const Scaleform::GFx::ASString *ShadowStyle; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  long double HScrollOffset; // st7
  long double v23; // st7
  long double v24; // st7
  long double MaxHScroll; // st7
  long double v26; // st7
  Scaleform::GFx::MovieImpl *v27; // ecx
  Scaleform::GFx::ASStringNode *v28; // edi
  Scaleform::GFx::ASStringNode *v29; // esi
  Scaleform::GFx::MovieImpl *v30; // ecx
  bool v31; // zf
  unsigned int MaxLength; // eax
  long double EndIndex; // st7
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::ASStringNode *v35; // esi
  Scaleform::GFx::ASStringNode *v36; // edi
  unsigned int CSSData; // eax
  double ShadowAlpha; // st7
  long double LinesCount; // st7
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::Render::Text::DocView *v41; // esi
  double FontScaleFactor; // st7
  Scaleform::GFx::AS2::GlobalContext *v43; // eax
  Scaleform::GFx::AS2::GlobalContext *v44; // ecx
  Scaleform::GFx::ASStringManager *v45; // ecx
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // esi
  unsigned int Size; // eax
  Scaleform::Render::Text::EditorKitBase *v49; // eax
  Scaleform::Render::Text::EditorKitBase *v50; // eax
  Scaleform::Render::Text::EditorKitBase *v51; // eax
  Scaleform::Render::Text::EditorKitBase *v52; // eax
  Scaleform::Log *v53; // eax
  Scaleform::GFx::ASStringNode *pLower; // eax
  Scaleform::GFx::ASString v55; // [esp+2Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::ASString str[2]; // [esp+30h] [ebp-18h] BYREF
  Scaleform::GFx::ASStringNode *v57; // [esp+3Ch] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v58; // [esp+40h] [ebp-8h] BYREF
  Scaleform::GFx::ASString result; // [esp+44h] [ebp-4h] BYREF

  str[0].pNode = (Scaleform::GFx::ASStringNode *)this;
  v55.pNode = 0;
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmTextField *)((char *)this - 4),
                             (Scaleform::GFx::ASString *)name);
  pObject = (Scaleform::GFx::TextField *)this->pProto.pObject;
  switch ( StandardMemberConstant )
  {
    case 25:
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)HIDWORD(name));
      *(_BYTE *)HIDWORD(name) = 0;
      v53 = penv->Target->GetLog(penv->Target);
      if ( !v53 )
        return 1;
      Scaleform::Log::LogWarning(v53, "Retrieval of the TextField.filters property is not implemented.");
      return 1;
    case 40:
      Text = Scaleform::GFx::TextField::GetText(pObject, &v58, 0);
      Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), Text);
      pNode = v58.pNode;
      goto LABEL_7;
    case 41:
      TextWidth = Scaleform::GFx::TextField::GetTextWidth(pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), TextWidth);
      return 1;
    case 42:
      TextHeight = Scaleform::GFx::TextField::GetTextHeight(pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), TextHeight);
      return 1;
    case 43:
      TextColor32 = Scaleform::GFx::TextField::GetTextColor32(pObject);
      Scaleform::GFx::AS2::Value::SetInt((Scaleform::GFx::AS2::Value *)HIDWORD(name), TextColor32);
      return 1;
    case 44:
      Length = (double)Scaleform::Render::Text::StyledText::GetLength(pObject->pDocument.pObject->pDocument.pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), Length);
      return 1;
    case 45:
      v6 = pObject->Flags >> 1;
      goto LABEL_3;
    case 46:
      v9 = Scaleform::GFx::TextField::GetText(pObject, (Scaleform::GFx::ASString *)&v57, (Scaleform::String)1);
      Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), v9);
      pNode = v57;
LABEL_7:
      if ( !--pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return 1;
    case 47:
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)HIDWORD(name));
      v36 = str[0].pNode;
      *(_BYTE *)HIDWORD(name) = 0;
      if ( !Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)v36->RefCount)
        || !*(_DWORD *)(Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)v36->RefCount) + 64) )
      {
        return 1;
      }
      CSSData = Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)v36->RefCount);
      Scaleform::GFx::AS2::Value::SetAsObject(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        *(Scaleform::GFx::AS2::Object **)(CSSData + 64));
      return 1;
    case 48:
      if ( (pObject->Flags & 1) != 0 )
      {
        v17 = pObject->pDocument.pObject;
        if ( (v17->AlignProps & 3) != 0 )
        {
          if ( (v17->AlignProps & 3) == 1 )
          {
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "right",
                                5u,
                                0);
            goto LABEL_25;
          }
          if ( (v17->AlignProps & 3) != 2 )
          {
LABEL_20:
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)HIDWORD(name));
            *(_BYTE *)HIDWORD(name) = 0;
            return 1;
          }
          v16 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                  (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  "center",
                  6u,
                  0);
        }
        else
        {
          v16 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                  (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  "left",
                  4u,
                  0);
        }
      }
      else
      {
        v16 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                "none",
                4u,
                0);
      }
      ConstStringNode = v16;
LABEL_25:
      ++ConstStringNode->RefCount;
      str[0].pNode = ConstStringNode;
      Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
      v31 = ConstStringNode->RefCount-- == 1;
      if ( !v31 )
        return 1;
LABEL_147:
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      return 1;
    case 49:
      LOBYTE(v6) = pObject->pDocument.pObject->Flags >> 3;
      goto LABEL_3;
    case 50:
      LOBYTE(v6) = pObject->pDocument.pObject->Flags >> 2;
      goto LABEL_3;
    case 51:
      val = HIBYTE(pObject->pDocument.pObject->BorderColor) != 0;
      goto LABEL_4;
    case 52:
      if ( !*((_DWORD *)str[0].pNode[1].pData + 5) )
        goto LABEL_32;
      Scaleform::GFx::AS2::Value::SetString(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (const Scaleform::GFx::ASString *)&str[0].pNode[1]);
      return 1;
    case 53:
      IsSelectable = Scaleform::GFx::TextField::IsSelectable(pObject);
      Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)HIDWORD(name), IsSelectable);
      return 1;
    case 54:
      LOBYTE(v6) = ~(pObject->pDocument.pObject->Flags >> 5);
      goto LABEL_3;
    case 55:
      pMovieImpl = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
      if ( (pObject->pDocument.pObject->Flags & 0x40) != 0 )
      {
        v55.pNode = (Scaleform::GFx::ASStringNode *)4;
        v28 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)pMovieImpl,
                "advanced",
                8u,
                0);
        ++v28->RefCount;
        str[0].pNode = v28;
        v35 = v28;
      }
      else
      {
        v55.pNode = (Scaleform::GFx::ASStringNode *)8;
        v35 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)pMovieImpl,
                "normal",
                6u,
                0);
        ++v35->RefCount;
        str[0].pNode = v35;
        v28 = v35;
      }
      Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
      if ( ((int)v55.pNode & 8) != 0 )
      {
        v55.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)v55.pNode & 0xFFFFFFF7);
        v31 = v35->RefCount-- == 1;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
      }
      v31 = ((int)v55.pNode & 4) == 0;
      goto LABEL_56;
    case 56:
      HScrollOffset = (double)(unsigned int)(__int64)Scaleform::GFx::TextField::GetHScrollOffset(pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), HScrollOffset);
      return 1;
    case 57:
      v23 = (double)(Scaleform::Render::Text::DocView::GetVScrollOffset(pObject->pDocument.pObject) + 1);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), v23);
      return 1;
    case 58:
      v24 = (double)(Scaleform::Render::Text::DocView::GetMaxVScroll(pObject->pDocument.pObject) + 1);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), v24);
      return 1;
    case 59:
      MaxHScroll = (double)(unsigned int)(__int64)Scaleform::GFx::TextField::GetMaxHScroll(pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), MaxHScroll);
      return 1;
    case 60:
      val = HIBYTE(pObject->pDocument.pObject->BackgroundColor) != 0;
      goto LABEL_4;
    case 61:
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (double)(pObject->pDocument.pObject->BackgroundColor & 0xFFFFFF));
      return 1;
    case 62:
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (double)(pObject->pDocument.pObject->BorderColor & 0xFFFFFF));
      return 1;
    case 63:
      v26 = (double)(Scaleform::Render::Text::DocView::GetBottomVScroll(pObject->pDocument.pObject) + 1);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), v26);
      return 1;
    case 64:
      if ( (unsigned __int8)Scaleform::GFx::TextField::IsReadOnly(pObject) )
      {
        v27 = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
        v55.pNode = (Scaleform::GFx::ASStringNode *)1;
        v28 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)v27,
                "dynamic",
                7u,
                0);
        ++v28->RefCount;
        str[0].pNode = v28;
        v29 = v28;
      }
      else
      {
        v30 = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
        v55.pNode = (Scaleform::GFx::ASStringNode *)2;
        v29 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)v30,
                "input",
                5u,
                0);
        ++v29->RefCount;
        str[0].pNode = v29;
        v28 = v29;
      }
      Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
      if ( ((int)v55.pNode & 2) != 0 )
      {
        v55.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)v55.pNode & 0xFFFFFFFD);
        v31 = v29->RefCount-- == 1;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      }
      v31 = ((int)v55.pNode & 1) == 0;
LABEL_56:
      if ( v31 )
        return 1;
      v31 = v28->RefCount-- == 1;
      if ( !v31 )
        return 1;
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      return 1;
    case 65:
      MaxLength = pObject->pDocument.pObject->MaxLength;
      if ( MaxLength )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)pObject->pDocument.pObject->MaxLength;
        EndIndex = (double)MaxLength;
LABEL_61:
        Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), EndIndex);
        return 1;
      }
      else
      {
LABEL_32:
        Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)HIDWORD(name));
        *(_BYTE *)HIDWORD(name) = 1;
        return 1;
      }
    case 66:
      v6 = pObject->Flags >> 4;
      goto LABEL_3;
    case 67:
      Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)HIDWORD(name), (pObject->Flags & 0x80) != 0);
      return 1;
    case 68:
      Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)HIDWORD(name), (pObject->Flags & 4) != 0);
      return 1;
    case 69:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      ShadowStyle = Scaleform::GFx::TextField::GetShadowStyle(pObject, &result);
      Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), ShadowStyle);
      v21 = result.pNode;
      --result.pNode->RefCount;
      if ( v21->RefCount )
        return 1;
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      return 1;
    case 70:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetInt(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw & 0xFFFFFF);
      return 1;
    case 71:
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(unsigned int *))(str[0].pNode[-1].Size + 124))(&str[0].pNode[-1].Size)
                                + 116)
                    + 52) != 1 )
        goto $LN7_84;
      v6 = pObject->Scaleform::GFx::InteractiveObject::Flags >> 11;
      goto LABEL_3;
    case 72:
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(unsigned int *))(str[0].pNode[-1].Size + 124))(&str[0].pNode[-1].Size)
                                + 116)
                    + 52) != 1 )
        goto $LN7_84;
      v6 = pObject->Flags >> 3;
      goto LABEL_3;
    case 73:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      str[0].pNode = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::TextField::GetCursorPos(pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), (double)(int)str[0].pNode);
      return 1;
    case 74:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      LinesCount = (double)Scaleform::Render::Text::DocView::GetLinesCount(pObject->pDocument.pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), LinesCount);
      return 1;
    case 75:
      pContext = penv->StringContext.pContext;
      if ( pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v41 = pObject->pDocument.pObject;
      if ( (v41->Flags & 2) != 0 )
      {
        switch ( (v41->AlignProps >> 2) & 3 )
        {
          case 0:
            break;
          case 1:
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "top",
                                3u,
                                0);
            ++ConstStringNode->RefCount;
            str[0].pNode = ConstStringNode;
            Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
            v31 = ConstStringNode->RefCount-- == 1;
            if ( v31 )
              goto LABEL_147;
            return 1;
          case 2:
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "bottom",
                                6u,
                                0);
            ++ConstStringNode->RefCount;
            str[0].pNode = ConstStringNode;
            Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
            v31 = ConstStringNode->RefCount-- == 1;
            if ( v31 )
              goto LABEL_147;
            return 1;
          case 3:
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "center",
                                6u,
                                0);
            ++ConstStringNode->RefCount;
            str[0].pNode = ConstStringNode;
            Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
            v31 = ConstStringNode->RefCount-- == 1;
            if ( v31 )
              goto LABEL_147;
            return 1;
          default:
            goto LABEL_20;
        }
      }
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                          "none",
                          4u,
                          0);
      ++ConstStringNode->RefCount;
      str[0].pNode = ConstStringNode;
      Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
      v31 = ConstStringNode->RefCount-- == 1;
      if ( v31 )
        goto LABEL_147;
      return 1;
    case 76:
      if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
      {
        FontScaleFactor = Scaleform::GFx::TextField::GetFontScaleFactor(pObject);
        Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), FontScaleFactor);
      }
      goto $LN7_84;
    case 77:
      v43 = penv->StringContext.pContext;
      if ( v43->GFxExtensions.Value == 1 )
      {
        switch ( (pObject->pDocument.pObject->AlignProps >> 2) & 3 )
        {
          case 0:
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)v43->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "none",
                                4u,
                                0);
            ++ConstStringNode->RefCount;
            str[0].pNode = ConstStringNode;
            Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
            v31 = ConstStringNode->RefCount-- == 1;
            if ( v31 )
              goto LABEL_147;
            return 1;
          case 1:
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)v43->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "top",
                                3u,
                                0);
            ++ConstStringNode->RefCount;
            str[0].pNode = ConstStringNode;
            Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
            v31 = ConstStringNode->RefCount-- == 1;
            if ( v31 )
              goto LABEL_147;
            return 1;
          case 2:
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)v43->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "bottom",
                                6u,
                                0);
            ++ConstStringNode->RefCount;
            str[0].pNode = ConstStringNode;
            Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
            v31 = ConstStringNode->RefCount-- == 1;
            if ( v31 )
              goto LABEL_147;
            return 1;
          case 3:
            ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                (Scaleform::GFx::ASStringManager *)v43->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                "center",
                                6u,
                                0);
            ++ConstStringNode->RefCount;
            str[0].pNode = ConstStringNode;
            Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), str);
            v31 = ConstStringNode->RefCount-- == 1;
            if ( v31 )
              goto LABEL_147;
            return 1;
          default:
            goto LABEL_20;
        }
      }
      goto $LN7_84;
    case 78:
      v44 = penv->StringContext.pContext;
      if ( v44->GFxExtensions.Value == 1 )
      {
        if ( ((pObject->pDocument.pObject->AlignProps >> 4) & 3) == 1 )
        {
          v46 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                  (Scaleform::GFx::ASStringManager *)v44->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  "shrink",
                  6u,
                  0);
        }
        else
        {
          v45 = (Scaleform::GFx::ASStringManager *)v44->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
          v46 = ((pObject->pDocument.pObject->AlignProps >> 4) & 3) == 2
              ? Scaleform::GFx::ASStringManager::CreateConstStringNode(v45, "fit", 3u, 0)
              : Scaleform::GFx::ASStringManager::CreateConstStringNode(v45, "none", 4u, 0);
        }
        v47 = v46;
        ++v46->RefCount;
        v55.pNode = v46;
        Scaleform::GFx::AS2::Value::SetString((Scaleform::GFx::AS2::Value *)HIDWORD(name), &v55);
        v31 = v47->RefCount-- == 1;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v47);
      }
      goto $LN7_84;
    case 79:
      if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
        Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)HIDWORD(name), pObject->Flags & 0x100);
      goto $LN7_84;
    case 80:
      if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
        Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)HIDWORD(name), (pObject->Flags & 0x200) != 0);
      goto $LN7_84;
    case 81:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      if ( !Scaleform::GFx::TextField::IsSelectable(pObject) || !pObject->pDocument.pObject->pEditorKit.pObject )
        goto LABEL_85;
      str[0].pNode = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::TextField::GetBeginIndex(pObject);
      EndIndex = (double)(int)str[0].pNode;
      if ( (int)str[0].pNode >= 0 )
        goto LABEL_61;
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), EndIndex + 4294967296.0);
      return 1;
    case 82:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      if ( Scaleform::GFx::TextField::IsSelectable(pObject) && pObject->pDocument.pObject->pEditorKit.pObject )
        EndIndex = (double)(unsigned int)Scaleform::GFx::TextField::GetEndIndex(pObject);
      else
LABEL_85:
        EndIndex = -1.0;
      goto LABEL_61;
    case 83:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v50 = pObject->pDocument.pObject->pEditorKit.pObject;
      if ( !v50 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (double)(unsigned int)v50[14].__vftable);
      return 1;
    case 84:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v49 = pObject->pDocument.pObject->pEditorKit.pObject;
      if ( !v49 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (double)(unsigned int)v49[14].RefCount);
      return 1;
    case 85:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v52 = pObject->pDocument.pObject->pEditorKit.pObject;
      if ( !v52 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (double)(unsigned int)v52[15].__vftable);
      return 1;
    case 86:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v51 = pObject->pDocument.pObject->pEditorKit.pObject;
      if ( !v51 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (double)(unsigned int)v51[15].RefCount);
      return 1;
    case 87:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v6 = pObject->Flags >> 10;
      goto LABEL_3;
    case 88:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v6 = pObject->Flags >> 11;
      goto LABEL_3;
    case 92:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      val = pObject->pDocument.pObject->Flags >> 7;
      goto LABEL_4;
    case 93:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.BlurX * 0.05);
      return 1;
    case 94:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.BlurY * 0.05);
      return 1;
    case 95:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.BlurStrength);
      return 1;
    case 96:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Outline);
      return 1;
    case 97:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      LOBYTE(v6) = pObject->pDocument.pObject->FlagsEx;
      goto LABEL_3;
    case 98:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetBool(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (pObject->pDocument.pObject->FlagsEx & 2) != 0);
      return 1;
    case 100:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      ShadowAlpha = Scaleform::GFx::TextField::GetShadowAlpha(pObject);
      Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)HIDWORD(name), ShadowAlpha);
      return 1;
    case 101:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.ShadowAngle * 57.29578399658203);
      return 1;
    case 102:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.ShadowParams.BlurX * 0.05);
      return 1;
    case 103:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.ShadowParams.BlurY * 0.05);
      return 1;
    case 104:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.ShadowDistance * 0.05);
      return 1;
    case 105:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetBool(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (pObject->pDocument.pObject->Filter.ShadowFlags & 0x40) != 0);
      return 1;
    case 106:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      v6 = pObject->pDocument.pObject->Filter.ShadowFlags >> 5;
LABEL_3:
      val = v6 & 1;
LABEL_4:
      Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)HIDWORD(name), val);
      return 1;
    case 107:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        (double)((unsigned int)(SLOBYTE(pObject->pDocument.pObject->Filter.ShadowFlags) < 0) + 1));
      return 1;
    case 108:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_84;
      Scaleform::GFx::AS2::Value::SetNumber(
        (Scaleform::GFx::AS2::Value *)HIDWORD(name),
        pObject->pDocument.pObject->Filter.ShadowParams.Strength);
      return 1;
    case 109:
      goto $LN7_84;
    default:
      if ( (*(unsigned __int8 (__thiscall **)(unsigned int *, int, _DWORD, _DWORD))(str[0].pNode[-1].Size + 144))(
             &str[0].pNode[-1].Size,
             StandardMemberConstant,
             HIDWORD(name),
             0) )
      {
        return 1;
      }
$LN7_84:
      Size = str[0].pNode[1].Size;
      if ( Size )
        return (*(int (__thiscall **)(unsigned int, Scaleform::GFx::AS2::Environment *, _DWORD, _DWORD))(*(_DWORD *)(Size + 16) + 16))(
                 Size + 16,
                 penv,
                 name,
                 HIDWORD(name));
      if ( penv
        && *(_DWORD *)name == *(_DWORD *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion )
      {
        Scaleform::GFx::AS2::Value::SetAsObject(
          (Scaleform::GFx::AS2::Value *)HIDWORD(name),
          (Scaleform::GFx::AS2::Object *)str[0].pNode->pLower);
        return 1;
      }
      else
      {
        pLower = str[0].pNode->pLower;
        if ( pLower
          && (*(unsigned __int8 (__thiscall **)(unsigned int *, Scaleform::GFx::AS2::Environment *, _DWORD, _DWORD))(pLower->HashFlags + 16))(
               &pLower->HashFlags,
               penv,
               name,
               HIDWORD(name)) )
        {
          return 1;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)name, "_global") && penv )
        {
          Scaleform::GFx::AS2::Value::SetAsObject(
            (Scaleform::GFx::AS2::Value *)HIDWORD(name),
            penv->StringContext.pContext->pGlobal.pObject);
          return 1;
        }
        else
        {
          return 0;
        }
      }
  }
}
