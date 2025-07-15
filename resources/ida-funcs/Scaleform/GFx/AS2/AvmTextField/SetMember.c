char __thiscall Scaleform::GFx::AS2::AvmTextField::SetMember(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *origVal,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::AvmTextField *v6; // edi
  Scaleform::String::DataDesc *StandardMemberConstant; // ebx
  Scaleform::GFx::AS2::Object *v8; // ecx
  Scaleform::GFx::TextField *pObject; // edi
  bool v10; // al
  char v11; // al
  unsigned int v12; // eax
  Scaleform::GFx::ASStringNode *v13; // esi
  Scaleform::GFx::ASStringNode *v14; // ecx
  unsigned int Version; // eax
  Scaleform::GFx::ASStringNode *v16; // esi
  unsigned int v17; // eax
  const __m128i *v18; // eax
  int v19; // esi
  char v20; // bl
  char v21; // bl
  char v22; // al
  Scaleform::Render::Text::DocView *v23; // ecx
  char v24; // bl
  char v25; // al
  Scaleform::Render::Text::DocView *v26; // edi
  Scaleform::GFx::ASStringNode *v27; // ecx
  bool v28; // al
  Scaleform::Render::Text::DocView *v29; // eax
  char v30; // bl
  Scaleform::Render::Text::DocView *v31; // eax
  int v32; // eax
  bool v33; // al
  bool v34; // al
  long double v35; // st7
  unsigned int v36; // eax
  long double v37; // st7
  unsigned int v38; // eax
  bool v39; // bl
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::ASStringNode *v41; // ebp
  bool v42; // zf
  bool v43; // bl
  Scaleform::Render::Text::EditorKitBase *v44; // eax
  bool v45; // bl
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // esi
  bool v48; // zf
  Scaleform::RefCountVImpl *v49; // esi
  bool v50; // al
  bool v51; // bl
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v53; // ebp
  bool v54; // zf
  Scaleform::String::DataDesc *pData; // ebx
  bool v56; // bl
  bool v57; // bl
  Scaleform::GFx::ASStringNode *v58; // eax
  Scaleform::GFx::ASStringNode *v59; // esi
  bool v60; // zf
  Scaleform::String::DataDesc *v61; // ebx
  bool v62; // bl
  bool v63; // al
  Scaleform::GFx::AS2::Object *v64; // eax
  Scaleform::GFx::AS2::Object *v65; // ebx
  Scaleform::GFx::AS2::AvmTextField::CSSHolder *v66; // eax
  Scaleform::GFx::TextField::CSSHolderBase *v67; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v68; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v69; // ecx
  unsigned int RefCount; // eax
  Scaleform::Render::Text::EditorKitBase *v71; // eax
  unsigned int CSSData; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v73; // ecx
  _DWORD *v74; // esi
  unsigned int v75; // eax
  unsigned int v76; // eax
  const Scaleform::GFx::AS2::Environment *v77; // eax
  bool v78; // al
  const Scaleform::GFx::AS2::Environment *v79; // eax
  bool v80; // al
  bool v81; // al
  Scaleform::Render::Text::DocView *v82; // edi
  long double v83; // st7
  Scaleform::Render::Text::DocView *v84; // ecx
  long double v85; // st7
  Scaleform::Render::Text::DocView *v86; // eax
  bool v87; // al
  bool v88; // al
  long double v89; // st7
  Scaleform::Render::Text::DocView *v90; // eax
  long double v91; // st7
  Scaleform::Render::Text::DocView *v92; // edx
  bool v93; // al
  bool v94; // al
  unsigned int v95; // eax
  long double v96; // st7
  const Scaleform::GFx::AS2::Environment *v97; // eax
  bool v98; // al
  Scaleform::Render::Text::EditorKitBase *v99; // eax
  const Scaleform::GFx::AS2::Environment *v100; // eax
  bool v101; // al
  Scaleform::GFx::Text::EditorKit *v102; // edi
  Scaleform::GFx::Text::EditorKit *v103; // edi
  Scaleform::GFx::Text::EditorKit *v104; // edi
  Scaleform::GFx::Text::EditorKit *v105; // edi
  bool v106; // al
  bool v107; // al
  Scaleform::GFx::AS2::Object *v108; // ebx
  Scaleform::GFx::AS2::Object *Prototype; // eax
  char *v110; // eax
  bool v111; // cc
  Scaleform::GFx::AS2::Value *v112; // ecx
  Scaleform::GFx::AS2::Object *v113; // ebp
  Scaleform::GFx::AS2::Object *v114; // eax
  Scaleform::GFx::ASStringNode *v115; // eax
  char v116; // bl
  Scaleform::GFx::AS2::Value v117; // [esp+24h] [ebp-84h] BYREF
  Scaleform::String v118; // [esp+34h] [ebp-74h] BYREF
  double result; // [esp+38h] [ebp-70h] BYREF
  Scaleform::String v120; // [esp+40h] [ebp-68h] BYREF
  char v121; // [esp+47h] [ebp-61h]
  Scaleform::GFx::ASStringNode *v122; // [esp+48h] [ebp-60h] BYREF
  Scaleform::RefCountVImpl *v123; // [esp+4Ch] [ebp-5Ch] BYREF
  Scaleform::GFx::AS2::Value v124; // [esp+50h] [ebp-58h] BYREF
  Scaleform::Render::Text::TextFilter f; // [esp+60h] [ebp-48h] BYREF

  v6 = (Scaleform::GFx::AS2::AvmTextField *)((char *)this - 4);
  LODWORD(result) = this;
  v120.pData = (Scaleform::String::DataDesc *)&this[-1].ASTextFieldObj;
  StandardMemberConstant = (Scaleform::String::DataDesc *)Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                                                            (Scaleform::GFx::AS2::AvmTextField *)((char *)this - 4),
                                                            name);
  Scaleform::GFx::AS2::Value::Value(&v117, origVal);
  if ( (unsigned int)StandardMemberConstant >= 0x16 )
  {
    if ( penv )
    {
      if ( Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(v6) )
      {
        v8 = (Scaleform::GFx::AS2::Object *)*((_DWORD *)&this->VariableVal.NV + 3);
        if ( v8->pWatchpoints )
        {
          v124.T.Type = 0;
          if ( Scaleform::GFx::AS2::Object::InvokeWatchpoint(v8, penv, name, &v117, &v124) )
            Scaleform::GFx::AS2::Value::operator=(&v117, &v124);
          if ( v124.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v124);
        }
      }
    }
  }
  if ( v6->SetStandardMember(v6, (Scaleform::GFx::AS2::AvmCharacter::StandardMember)StandardMemberConstant, origVal, 0) )
  {
LABEL_12:
    if ( v117.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v117);
    return 1;
  }
  else
  {
    pObject = (Scaleform::GFx::TextField *)this->pProto.pObject;
    switch ( (unsigned int)StandardMemberConstant )
    {
      case 0x19u:
        goto $LN14_70;
      case 0x28u:
        Scaleform::GFx::TextField::ResetBlink(pObject, 1, 0);
        Version = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)this->pProto.pObject);
        Scaleform::GFx::AS2::Value::ToStringVersioned(&v117, (Scaleform::GFx::ASString *)&result, penv, Version);
        v16 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        Scaleform::GFx::TextField::SetTextValue(pObject, *(const __m128i **)LODWORD(result), 0, 1);
        v42 = v16->RefCount-- == 1;
        if ( v42 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        if ( v117.T.Type < 5u )
          return 1;
        goto LABEL_26;
      case 0x2Bu:
        v17 = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        Scaleform::GFx::TextField::SetTextColor(pObject, v17);
        if ( v117.T.Type < 5u )
          return 1;
        goto LABEL_26;
      case 0x2Du:
        v10 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetHtml(pObject, v10);
        goto LABEL_12;
      case 0x2Eu:
        v12 = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)this->pProto.pObject);
        Scaleform::GFx::AS2::Value::ToStringVersioned(&v117, (Scaleform::GFx::ASString *)&result, penv, v12);
        v13 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        Scaleform::GFx::TextField::SetTextValue(
          pObject,
          *(const __m128i **)LODWORD(result),
          (pObject->Flags & 2) != 0,
          1);
        goto LABEL_16;
      case 0x2Fu:
        v64 = Scaleform::GFx::AS2::Value::ToObject(&v117, penv);
        v65 = v64;
        if ( v64 && v64->GetObjectType(&v64->Scaleform::GFx::AS2::ObjectInterface) == Object_StyleSheet )
        {
          if ( !Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)pObject) )
          {
            v66 = (Scaleform::GFx::AS2::AvmTextField::CSSHolder *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x44u);
            if ( v66 )
              Scaleform::GFx::AS2::AvmTextField::CSSHolder::CSSHolder(v66);
            else
              v67 = 0;
            Scaleform::GFx::TextField::SetCSSData(pObject, v67);
          }
          v68 = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)(Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)this->pProto.pObject)
                                                            + 64);
          v65->RefCount = (v65->RefCount + 1) & 0x8FFFFFFF;
          v69 = *v68;
          if ( *v68 )
          {
            RefCount = v69->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v69->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v69);
            }
          }
          *v68 = v65;
          v71 = pObject->pDocument.pObject->pEditorKit.pObject;
          if ( v71 )
            LOWORD(v71[16].__vftable) |= 1u;
          Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
          if ( *(_DWORD *)(*(_DWORD *)(Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)this->pProto.pObject)
                                     + 64)
                         + 72) == 1 )
            Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(pObject);
        }
        else if ( Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)this->pProto.pObject) )
        {
          CSSData = Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)this->pProto.pObject);
          v73 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(CSSData + 64);
          v74 = (_DWORD *)(CSSData + 64);
          if ( v73 )
          {
            v75 = v73->RefCount;
            if ( (v75 & 0x3FFFFFF) != 0 )
            {
              v73->RefCount = v75 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v73);
            }
          }
          *v74 = 0;
        }
        Scaleform::GFx::TextField::CollectUrlZones(pObject);
        Scaleform::GFx::TextField::UpdateUrlStyles(pObject);
        pObject->Flags |= (unsigned int)&_sbh_sizeHeaderList;
        goto LABEL_19;
      case 0x30u:
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&result, penv, -1, 0);
        if ( v117.T.Type == 2 )
        {
          if ( Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv) )
            v18 = (const __m128i *)"left";
          else
            v18 = (const __m128i *)"none";
        }
        else
        {
          v18 = *(const __m128i **)LODWORD(result);
        }
        Scaleform::String::String(&v118, v18);
        v19 = pObject->pDocument.pObject->AlignProps & 3;
        v20 = pObject->Flags & 1;
        if ( Scaleform::String::operator==(&v118, "none") )
        {
          pObject->Flags &= ~1u;
          Scaleform::GFx::TextField::SetAlignment(pObject, Align_Center);
        }
        else
        {
          pObject->Flags |= 1u;
          if ( Scaleform::String::operator==(&v118, "left") )
          {
            Scaleform::GFx::TextField::SetAlignment(pObject, Align_Center);
          }
          else if ( Scaleform::String::operator==(&v118, "right") )
          {
            Scaleform::GFx::TextField::SetAlignment(pObject, Align_TopCenter);
          }
          else if ( Scaleform::String::operator==(&v118, "center") )
          {
            Scaleform::GFx::TextField::SetAlignment(pObject, Align_BottomCenter);
          }
        }
        if ( v19 != (pObject->pDocument.pObject->AlignProps & 3) || v20 != (pObject->Flags & 1) )
          Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings((Scaleform::GFx::AS2::AvmTextField *)v120.pData);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        Scaleform::String::~String(&v118);
        v14 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        v42 = (*(_DWORD *)(LODWORD(result) + 12))-- == 1;
        if ( v42 )
          goto LABEL_18;
        goto LABEL_19;
      case 0x31u:
        v21 = (pObject->pDocument.pObject->Flags & 8) != 0;
        v22 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        if ( v22 == v21 )
          goto LABEL_167;
        v23 = pObject->pDocument.pObject;
        if ( v22 )
          Scaleform::Render::Text::DocView::SetWordWrap(v23);
        else
          Scaleform::Render::Text::DocView::ClearWordWrap(v23);
        goto LABEL_49;
      case 0x32u:
        v24 = (pObject->pDocument.pObject->Flags & 4) != 0;
        v25 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        if ( v24 == v25 )
          goto LABEL_167;
        v26 = pObject->pDocument.pObject;
        if ( v25 )
          v26->Flags |= 4u;
        else
          v26->Flags &= ~4u;
LABEL_49:
        Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings((Scaleform::GFx::AS2::AvmTextField *)((char *)this - 4));
        goto LABEL_167;
      case 0x33u:
        v33 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetBorder(pObject, v33);
        goto LABEL_19;
      case 0x34u:
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&result, penv, -1, 0);
        Scaleform::GFx::ASString::operator=(
          (Scaleform::GFx::ASString *)&this->Scaleform::GFx::AvmTextFieldBase,
          (const Scaleform::GFx::ASString *)&result);
        v27 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        v42 = (*(_DWORD *)(LODWORD(result) + 12))-- == 1;
        if ( v42 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
        ((void (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this->EventHandlers.mHash.pTable[15].EntryCount)(&this->EventHandlers);
        pObject->Flags |= 0x8000u;
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(pObject);
        goto LABEL_19;
      case 0x35u:
        v28 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetSelectable(pObject, (Scaleform::RefCountVImpl *)v28);
        goto LABEL_19;
      case 0x36u:
        v42 = !Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        v29 = pObject->pDocument.pObject;
        if ( v42 )
          v29->Flags |= 0x20u;
        else
          v29->Flags &= ~0x20u;
        goto LABEL_61;
      case 0x37u:
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&v118, penv, -1, 0);
        v51 = penv->StringContext.SWFVersion > 6u;
        ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                            "normal",
                            6u,
                            0);
        v53 = ConstStringNode;
        ++ConstStringNode->RefCount;
        if ( v51 )
        {
          v54 = ConstStringNode == (Scaleform::GFx::ASStringNode *)v118.pData;
        }
        else
        {
          if ( !ConstStringNode->pLower )
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(ConstStringNode);
          pData = v118.pData;
          if ( !*(_DWORD *)v118.pData->Data )
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl((Scaleform::GFx::ASStringNode *)v118.pData);
          v54 = v53->pLower == *(Scaleform::GFx::ASStringNode **)pData->Data;
        }
        v56 = v54;
        v42 = v53->RefCount-- == 1;
        if ( v42 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v53);
        if ( v56 )
        {
          pObject->pDocument.pObject->Flags &= ~0x40u;
        }
        else
        {
          v57 = penv->StringContext.SWFVersion > 6u;
          v58 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                  (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  "advanced",
                  8u,
                  0);
          v59 = v58;
          ++v58->RefCount;
          if ( v57 )
          {
            v60 = v58 == (Scaleform::GFx::ASStringNode *)v118.pData;
          }
          else
          {
            if ( !v58->pLower )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v58);
            v61 = v118.pData;
            if ( !*(_DWORD *)v118.pData->Data )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl((Scaleform::GFx::ASStringNode *)v118.pData);
            v60 = v59->pLower == *(Scaleform::GFx::ASStringNode **)v61->Data;
          }
          v62 = v60;
          v42 = v59->RefCount-- == 1;
          if ( v42 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v59);
          if ( v62 )
            pObject->pDocument.pObject->Flags |= 0x40u;
        }
        Scaleform::GFx::TextField::SetDirtyFlag(*(Scaleform::GFx::TextField **)(LODWORD(result) + 12));
        v14 = (Scaleform::GFx::ASStringNode *)v118.pData;
        v42 = v118.pData[1].Size-- == 1;
        if ( v42 )
          goto LABEL_18;
        goto LABEL_19;
      case 0x38u:
        LODWORD(result) = Scaleform::GFx::AS2::Value::ToInt32(&v117, penv);
        if ( SLODWORD(result) < 0 )
          LODWORD(result) = 0;
        Scaleform::GFx::TextField::SetHScrollOffset(pObject, (double)SLODWORD(result));
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x39u:
        v32 = Scaleform::GFx::AS2::Value::ToInt32(&v117, penv);
        if ( v32 < 1 )
          v32 = 1;
        Scaleform::Render::Text::DocView::SetVScrollOffset(pObject->pDocument.pObject, v32 - 1);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x3Cu:
        v34 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetBackground(pObject, v34);
        goto LABEL_19;
      case 0x3Du:
        v35 = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v35) )
        {
          v36 = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
          Scaleform::GFx::TextField::SetBackgroundColor(pObject, v36);
        }
        goto LABEL_19;
      case 0x3Eu:
        v37 = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v37) )
        {
          v38 = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
          Scaleform::GFx::TextField::SetBorderColor(pObject, v38);
        }
        goto LABEL_19;
      case 0x40u:
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&v118, penv, -1, 0);
        v39 = penv->StringContext.SWFVersion > 6u;
        v40 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                "dynamic",
                7u,
                0);
        v41 = v40;
        ++v40->RefCount;
        if ( v39 )
        {
          v42 = v40 == (Scaleform::GFx::ASStringNode *)v118.pData;
        }
        else
        {
          if ( !v40->pLower )
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v40);
          StandardMemberConstant = v118.pData;
          if ( !*(_DWORD *)v118.pData->Data )
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl((Scaleform::GFx::ASStringNode *)v118.pData);
          v42 = v41->pLower == *(Scaleform::GFx::ASStringNode **)StandardMemberConstant->Data;
        }
        v43 = v42;
        v42 = v41->RefCount-- == 1;
        if ( v42 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v41);
        if ( v43 )
        {
          v44 = pObject->pDocument.pObject->pEditorKit.pObject;
          if ( v44 )
            LOWORD(v44[16].__vftable) |= 1u;
        }
        else
        {
          v45 = penv->StringContext.SWFVersion > 6u;
          v46 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                  (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  "input",
                  5u,
                  0);
          v47 = v46;
          ++v46->RefCount;
          if ( v45 )
          {
            v48 = v46 == (Scaleform::GFx::ASStringNode *)v118.pData;
          }
          else
          {
            if ( !v46->pLower )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v46);
            StandardMemberConstant = v118.pData;
            if ( !*(_DWORD *)v118.pData->Data )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl((Scaleform::GFx::ASStringNode *)v118.pData);
            v48 = v47->pLower == *(Scaleform::GFx::ASStringNode **)StandardMemberConstant->Data;
          }
          LOBYTE(StandardMemberConstant) = v48;
          v42 = v47->RefCount-- == 1;
          if ( v42 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v47);
          if ( (_BYTE)StandardMemberConstant
            && !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(LODWORD(result) + 20) + 96))(LODWORD(result) + 20) )
          {
            v49 = *Scaleform::GFx::TextField::CreateEditorKit(pObject, (int)StandardMemberConstant, (int)&v123);
            if ( v123 )
              Scaleform::RefCountImpl::Release(v123);
            LOWORD(v49[16].__vftable) &= ~1u;
          }
        }
        v14 = (Scaleform::GFx::ASStringNode *)v118.pData;
        pObject->pDocument.pObject->RTFlags |= 1u;
        v42 = v14->RefCount-- == 1;
        if ( v42 )
          goto LABEL_18;
        goto LABEL_19;
      case 0x41u:
        result = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(result) && result >= 0.0 )
          pObject->pDocument.pObject->MaxLength = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        goto LABEL_19;
      case 0x42u:
        v50 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetCondenseWhite(pObject, v50);
        goto LABEL_19;
      case 0x43u:
        v63 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetMouseWheelEnabled(pObject, v63);
        goto LABEL_19;
      case 0x44u:
        v30 = (pObject->Flags & 4) != 0;
        LOBYTE(result) = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        if ( v30 == LOBYTE(result) )
          goto LABEL_167;
        Scaleform::GFx::TextField::SetPassword(pObject, SLOBYTE(result));
        v31 = pObject->pDocument.pObject;
        if ( LOBYTE(result) )
          v31->Flags |= 0x10u;
        else
          v31->Flags &= ~0x10u;
LABEL_61:
        pObject->pDocument.pObject->RTFlags |= 2u;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x45u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&result, penv, -1, 0);
        v13 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        Scaleform::GFx::TextField::SetShadowStyle(pObject, *(__m128i **)LODWORD(result));
        goto LABEL_16;
      case 0x46u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v76 = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        Scaleform::GFx::TextField::SetShadowColor(pObject, v76);
        goto LABEL_19;
      case 0x47u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v77 = (const Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)v120.HeapTypeBits + 124))(v120.pData);
        v78 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, v77);
        Scaleform::GFx::InteractiveObject::SetHitTestDisableFlag(pObject, v78);
        goto LABEL_19;
      case 0x48u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v79 = (const Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)v120.HeapTypeBits + 124))(v120.pData);
        v80 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, v79);
        Scaleform::GFx::TextField::SetNoTranslate(pObject, v80);
        pObject->pDocument.pObject->RTFlags |= 2u;
        goto LABEL_19;
      case 0x4Bu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&result, penv, -1, 0);
        v13 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        Scaleform::String::String(&v118, *(const __m128i **)LODWORD(result));
        if ( Scaleform::String::operator==(&v118, "none") )
        {
          pObject->pDocument.pObject->Flags &= ~2u;
          Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Top);
        }
        else
        {
          Scaleform::Render::Text::DocView::SetAutoSizeY(pObject->pDocument.pObject);
          if ( Scaleform::String::operator==(&v118, "top") )
          {
            Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Center);
          }
          else if ( Scaleform::String::operator==(&v118, "bottom") )
          {
            Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Bottom);
          }
          else if ( Scaleform::String::operator==(&v118, "center") )
          {
            Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Bottom|VAlign_Center);
          }
        }
        pObject->Flags |= 0x2000u;
        Scaleform::GFx::TextField::SetDirtyFlag(pObject);
        goto LABEL_209;
      case 0x4Cu:
        if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          v96 = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
          if ( v96 <= 0.0 || v96 >= 1000.0 )
          {
            Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
          }
          else
          {
            *(float *)&result = v96;
            Scaleform::GFx::TextField::SetFontScaleFactor(pObject, *(float *)&result);
            Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
          }
        }
        goto LABEL_271;
      case 0x4Du:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&result, penv, -1, 0);
        v13 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        Scaleform::String::String(&v118, *(const __m128i **)LODWORD(result));
        if ( Scaleform::String::operator==(&v118, "none") )
        {
          Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Top);
        }
        else if ( Scaleform::String::operator==(&v118, "top") )
        {
          Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Center);
        }
        else if ( Scaleform::String::operator==(&v118, "bottom") )
        {
          Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Bottom);
        }
        else if ( Scaleform::String::operator==(&v118, "center") )
        {
          Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Bottom|VAlign_Center);
        }
LABEL_209:
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        Scaleform::String::~String(&v118);
        goto LABEL_16;
      case 0x4Eu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&result, penv, -1, 0);
        v13 = (Scaleform::GFx::ASStringNode *)LODWORD(result);
        Scaleform::String::String(&v120, *(const __m128i **)LODWORD(result));
        if ( Scaleform::String::operator==(&v120, "none") )
        {
          Scaleform::GFx::TextField::SetTextAutoSize(pObject, TAS_None);
        }
        else if ( Scaleform::String::operator==(&v120, "shrink") )
        {
          Scaleform::GFx::TextField::SetTextAutoSize(pObject, TAS_Shrink);
        }
        else if ( Scaleform::String::operator==(&v120, "fit") )
        {
          Scaleform::GFx::TextField::SetTextAutoSize(pObject, TAS_Fit);
        }
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        Scaleform::String::~String(&v120);
LABEL_16:
        v42 = v13->RefCount-- == 1;
        if ( v42 )
        {
          v14 = v13;
LABEL_18:
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        }
        goto LABEL_19;
      case 0x4Fu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v97 = (const Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)v120.HeapTypeBits + 124))(v120.pData);
        v98 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, v97);
        Scaleform::GFx::TextField::SetUseRichClipboard(pObject, v98);
        v99 = pObject->pDocument.pObject->pEditorKit.pObject;
        if ( v99 )
        {
          if ( (pObject->Flags & 0x100) != 0 )
            LOWORD(v99[16].__vftable) |= 4u;
          else
            LOWORD(v99[16].__vftable) &= ~4u;
        }
        goto LABEL_19;
      case 0x50u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v100 = (const Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)v120.HeapTypeBits + 124))(v120.pData);
        v101 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, v100);
        Scaleform::GFx::TextField::SetAlwaysShowSelection(pObject, v101);
        goto LABEL_19;
      case 0x53u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v103 = (Scaleform::GFx::Text::EditorKit *)pObject->pDocument.pObject->pEditorKit.pObject;
        if ( !v103 )
          goto LABEL_271;
        v103->ActiveSelectionBkColor = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v103);
        goto LABEL_19;
      case 0x54u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v102 = (Scaleform::GFx::Text::EditorKit *)pObject->pDocument.pObject->pEditorKit.pObject;
        if ( !v102 )
          goto LABEL_271;
        v102->ActiveSelectionTextColor = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v102);
        goto LABEL_19;
      case 0x55u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v105 = (Scaleform::GFx::Text::EditorKit *)pObject->pDocument.pObject->pEditorKit.pObject;
        if ( !v105 )
          goto LABEL_271;
        v105->InactiveSelectionBkColor = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v105);
        goto LABEL_19;
      case 0x56u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v104 = (Scaleform::GFx::Text::EditorKit *)pObject->pDocument.pObject->pEditorKit.pObject;
        if ( !v104 )
          goto LABEL_271;
        v104->InactiveSelectionTextColor = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v104);
        goto LABEL_19;
      case 0x57u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v106 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetNoAutoSelection(pObject, v106);
        goto LABEL_19;
      case 0x58u:
        if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          v107 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
          Scaleform::GFx::TextField::SetIMEDisabledFlag(pObject, v107);
        }
        else
        {
$LN14_70:
          v108 = Scaleform::GFx::AS2::Value::ToObject(&v117, penv);
          if ( v108 )
          {
            Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Array);
            if ( v108->InstanceOf(&v108->Scaleform::GFx::AS2::ObjectInterface, penv, Prototype, 1) )
            {
              Scaleform::Render::Text::TextFilter::TextFilter(&f);
              v110 = 0;
              v111 = (signed int)v108[1].RootIndex <= 0;
              v121 = 0;
              v120.pData = 0;
              if ( !v111 )
              {
                do
                {
                  v112 = (Scaleform::GFx::AS2::Value *)(&v108[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[(_DWORD)v110];
                  if ( v112 )
                  {
                    v113 = Scaleform::GFx::AS2::Value::ToObject(v112, penv);
                    if ( v113 )
                    {
                      v114 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(
                               penv->StringContext.pContext,
                               ASBuiltin_BitmapFilter);
                      if ( v113->InstanceOf(&v113->Scaleform::GFx::AS2::ObjectInterface, penv, v114, 1) )
                      {
                        Scaleform::Render::Text::TextFilter::LoadFilterDesc(
                          &f,
                          (const Scaleform::Render::Filter *)v113[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable);
                        v121 = 1;
                      }
                    }
                  }
                  v110 = (char *)&v120.pData->Size + 1;
                  v111 = (int)++v120.pData < (signed int)v108[1].RootIndex;
                }
                while ( v111 );
                if ( v121 )
                {
                  Scaleform::GFx::TextField::SetTextFilters(pObject, &f);
                  Scaleform::GFx::TextField::SetDirtyFlag(*(Scaleform::GFx::TextField **)(LODWORD(result) + 12));
                  pObject->SetAcceptAnimMoves(pObject, 0);
                }
              }
              Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&f);
            }
          }
        }
        goto LABEL_19;
      case 0x5Cu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v81 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        v82 = pObject->pDocument.pObject;
        if ( v81 )
          v82->Flags |= 0x80u;
        else
          v82->Flags &= ~0x80u;
LABEL_167:
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x5Du:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v83 = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        v84 = pObject->pDocument.pObject;
        *(float *)&result = v83 * 20.0;
        v84->Filter.BlurX = *(float *)&result;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x5Eu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v85 = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        v86 = pObject->pDocument.pObject;
        *(float *)&result = v85 * 20.0;
        v86->Filter.BlurY = *(float *)&result;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x5Fu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        *(float *)&result = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        pObject->pDocument.pObject->Filter.BlurStrength = *(float *)&result;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x60u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        *(float *)&result = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        pObject->pDocument.pObject->Outline = *(float *)&result;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x61u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v87 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetFauxBold(pObject, v87);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x62u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        v88 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetFauxItalic(pObject, v88);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x63u:
        if ( v117.T.Type < 2u || v117.T.Type == 10 )
        {
          Scaleform::GFx::TextField::ClearRestrict((Scaleform::GFx::TextField *)this->pProto.pObject);
        }
        else
        {
          Scaleform::GFx::AS2::Value::ToStringImpl(&v117, (Scaleform::GFx::ASString *)&v122, penv, -1, 0);
          Scaleform::GFx::TextField::SetRestrict(pObject, (int)StandardMemberConstant, (const __m128i ***)&v122);
          v115 = v122;
          --v122->RefCount;
          if ( !v115->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v115);
        }
        goto LABEL_271;
      case 0x64u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        *(float *)&result = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        Scaleform::GFx::TextField::SetShadowAlpha(pObject, *(float *)&result);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x65u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        *(float *)&result = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        *(float *)&result = *(float *)&result * 0.01745329238474369;
        Scaleform::GFx::TextField::SetShadowAngle(pObject, *(float *)&result);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x66u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v89 = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        v90 = pObject->pDocument.pObject;
        *(float *)&result = v89 * 20.0;
        v90->Filter.ShadowParams.BlurX = *(float *)&result;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x67u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v91 = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        v92 = pObject->pDocument.pObject;
        *(float *)&result = v91 * 20.0;
        v92->Filter.ShadowParams.BlurY = *(float *)&result;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x68u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        *(float *)&result = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        *(float *)&result = *(float *)&result * 20.0;
        Scaleform::GFx::TextField::SetShadowDistance(pObject, *(float *)&result);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x69u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v93 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetShadowHideObject(pObject, v93);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x6Au:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v94 = Scaleform::GFx::AS2::Value::ToBool(&v117, (int)pObject, penv);
        Scaleform::GFx::TextField::SetShadowKnockOut(pObject, v94);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x6Bu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v95 = Scaleform::GFx::AS2::Value::ToUInt32(&v117, penv);
        Scaleform::GFx::TextField::SetShadowQuality(pObject, v95);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto LABEL_19;
      case 0x6Cu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_271;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        *(float *)&result = Scaleform::GFx::AS2::Value::ToNumber(&v117, penv);
        pObject->pDocument.pObject->Filter.ShadowParams.Strength = *(float *)&result;
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
LABEL_19:
        if ( v117.T.Type < 5u )
          return 1;
LABEL_26:
        Scaleform::GFx::AS2::Value::DropRefs(&v117);
        v11 = 1;
        break;
      default:
LABEL_271:
        v116 = Scaleform::GFx::AS2::AvmCharacter::SetMember(this, penv, name, &v117, flags);
        if ( v117.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v117);
        return v116;
    }
  }
  return v11;
}
