bool __thiscall Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::String opcodeFlag)
{
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v4; // ebx
  bool v6; // al
  Scaleform::GFx::AS2::Environment *v7; // eax
  Scaleform::GFx::AS2::Environment *v8; // esi
  Scaleform::GFx::AS2::Value *v9; // ebx
  unsigned __int64 v10; // st7
  Scaleform::GFx::AS2::Value *v11; // ebx
  unsigned __int64 v12; // st7
  Scaleform::GFx::AS2::Value *v13; // ebx
  unsigned __int64 v14; // st7
  Scaleform::GFx::AS2::Value *v15; // ebx
  unsigned __int64 v16; // st7
  Scaleform::GFx::AS2::Value *v17; // ebx
  unsigned __int64 v18; // st7
  Scaleform::GFx::AS2::Value *v19; // ebx
  unsigned __int64 v20; // st7
  Scaleform::GFx::AS2::Value *v21; // ebx
  unsigned __int64 v22; // st7
  Scaleform::GFx::AS2::Value *v23; // ebx
  long double alpha; // st7
  void (__thiscall **p_SetVisible)(Scaleform::GFx::DisplayObjectBase *, bool); // ebx
  unsigned __int8 v26; // al
  Scaleform::GFx::ASStringNode *v27; // ebx
  Scaleform::Render::BlendMode v28; // esi
  bool v29; // zf
  Scaleform::Render::BlendMode v30; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  char v32; // al
  char v33; // al
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::AS2::Value *v35; // esi
  const Scaleform::GFx::AS2::Environment *v36; // eax
  char v37; // al
  Scaleform::GFx::AS2::Environment *v38; // eax
  Scaleform::GFx::AS2::Value *v39; // esi
  const Scaleform::GFx::AS2::Environment *v40; // eax
  char v41; // al
  Scaleform::GFx::AS2::Value *v42; // esi
  const Scaleform::GFx::AS2::Environment *v43; // eax
  char v44; // al
  Scaleform::GFx::AS2::Object *v45; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::Render::FilterSet *v47; // eax
  Scaleform::String::DataDesc *v48; // eax
  Scaleform::GFx::Resource *pData; // ebx
  unsigned __int8 *p_PropFlags; // eax
  bool v51; // cc
  Scaleform::GFx::AS2::Value *v52; // ecx
  Scaleform::GFx::AS2::Object *v53; // ebx
  Scaleform::GFx::AS2::Object *v54; // eax
  void (__thiscall **p_SetCacheAsBitmap)(Scaleform::GFx::DisplayObjectBase *, bool); // esi
  const Scaleform::GFx::AS2::Environment *v56; // eax
  unsigned __int8 v57; // al
  Scaleform::Render::EdgeAAMode v58; // esi
  Scaleform::GFx::AS2::Environment *v59; // eax
  double v60; // st7
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::GFx::ASString result; // [esp+18h] [ebp-4h] BYREF

  v4 = member;
  if ( LOBYTE(opcodeFlag.pData) && (unsigned int)member >= M_parent )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
      &this->pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "Invalid SetProperty request, property number %d",
      member);
    return 0;
  }
  if ( member == M_InvalidMember || member > M_edgeaaMode || (this->GetStandardMemberBitMask(this) & (1 << v4)) == 0 )
    return 0;
  v7 = this->GetASEnvironment(this);
  v8 = v7;
  switch ( v4 )
  {
    case M_x:
      v9 = val;
      if ( !Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        *(double *)&v10 = Scaleform::GFx::AS2::Value::ToNumber(v9, v8);
        ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->SetX)(
          this->pDispObj,
          v10,
          HIDWORD(v10));
      }
      return 1;
    case M_y:
      v11 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
        return 1;
      *(double *)&v12 = Scaleform::GFx::AS2::Value::ToNumber(v11, v8);
      ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->SetY)(
        this->pDispObj,
        v12,
        HIDWORD(v12));
      return 1;
    case M_xscale:
      v13 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
        return 1;
      *(double *)&v14 = Scaleform::GFx::AS2::Value::ToNumber(v13, v8);
      ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->SetXScale)(
        this->pDispObj,
        v14,
        HIDWORD(v14));
      return 1;
    case M_yscale:
      v15 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
        return 1;
      *(double *)&v16 = Scaleform::GFx::AS2::Value::ToNumber(v15, v8);
      ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->SetYScale)(
        this->pDispObj,
        v16,
        HIDWORD(v16));
      return 1;
    case M_currentframe:
    case M_totalframes:
    case M_target:
    case M_framesloaded:
    case M_droptarget:
    case M_url:
    case M_xmouse:
    case M_ymouse:
    case M_parent:
      Name = Scaleform::GFx::DisplayObject::GetName(this->pDispObj, &result);
      Scaleform::GFx::AS2::Environment::LogScriptWarning(
        v8,
        "Attempt to write read-only property %s.%s, ignored",
        Name->pNode->pData,
        Scaleform::GFx::AS2::AvmCharacter::MemberTable[v4].pName);
      pNode = result.pNode;
      goto LABEL_43;
    case M_alpha:
      v23 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
        return 1;
      alpha = Scaleform::GFx::AS2::Value::ToNumber(v23, v8);
      Scaleform::GFx::DisplayObjectBase::SetAlpha(this->pDispObj, alpha);
      return 1;
    case M_visible:
      p_SetVisible = &this->pDispObj->SetVisible;
      v26 = Scaleform::GFx::AS2::Value::ToBool(val, v7);
      (*p_SetVisible)(this->pDispObj, v26);
      return 1;
    case M_width:
      v19 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
        return 1;
      *(double *)&v20 = Scaleform::GFx::AS2::Value::ToNumber(v19, v8);
      ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->SetWidth)(
        this->pDispObj,
        v20,
        HIDWORD(v20));
      return 1;
    case M_height:
      v21 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
        return 1;
      *(double *)&v22 = Scaleform::GFx::AS2::Value::ToNumber(v21, v8);
      ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->SetHeight)(
        this->pDispObj,
        v22,
        HIDWORD(v22));
      return 1;
    case M_rotation:
      v17 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
        return 1;
      *(double *)&v18 = Scaleform::GFx::AS2::Value::ToNumber(v17, v8);
      ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->pDispObj->SetRotation)(
        this->pDispObj,
        v18,
        HIDWORD(v18));
      return 1;
    case M_name:
      Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&member, v7, -1, 0);
      Scaleform::GFx::DisplayObject::SetName(this->pDispObj, (int)&member);
      pNode = (Scaleform::GFx::ASStringNode *)member;
LABEL_43:
      if ( --pNode->RefCount )
        goto LABEL_35;
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return 1;
    case M_highquality:
    case M_soundbuftime:
    case M_quality:
      return 1;
    case M_focusrect:
      v39 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        this->pDispObj->Flags &= 0xFFFFFF9F;
      }
      else
      {
        v40 = this->GetASEnvironment(this);
        v41 = Scaleform::GFx::AS2::Value::ToBool(v39, v40);
        Scaleform::GFx::InteractiveObject::SetFocusRectFlag(this->pDispObj, v41);
      }
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
      return 1;
    case M_blendMode:
      if ( val->T.Type != 5 )
      {
        v30 = (int)Scaleform::GFx::AS2::Value::ToNumber(val, v7);
        if ( v30 >= Blend_HardLight )
        {
          this->pDispObj->SetBlendMode(this->pDispObj, Blend_HardLight);
          return 1;
        }
        if ( v30 <= Blend_Normal )
          v30 = Blend_Normal;
        this->pDispObj->SetBlendMode(this->pDispObj, v30);
        return 1;
      }
      Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&val, v7, -1, 0);
      v27 = (Scaleform::GFx::ASStringNode *)val;
      Scaleform::String::String(&opcodeFlag, *(char **)&val->T.Type);
      v28 = Blend_Normal;
      while ( !Scaleform::String::operator==(&opcodeFlag, GFx_BlendModeNames[v28]) )
      {
        if ( (unsigned int)++v28 >= Blend_Overwrite )
        {
          Scaleform::String::~String(&opcodeFlag);
          v29 = v27->RefCount-- == 1;
          if ( v29 )
          {
            Scaleform::GFx::ASStringNode::ReleaseNode(v27);
            return 1;
          }
          return 1;
        }
      }
      this->pDispObj->SetBlendMode(this->pDispObj, v28);
      Scaleform::String::~String(&opcodeFlag);
      v29 = v27->RefCount-- == 1;
      if ( v29 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
LABEL_35:
      v6 = 1;
      break;
    case M_cacheAsBitmap:
      p_SetCacheAsBitmap = &this->pDispObj->SetCacheAsBitmap;
      v56 = this->GetASEnvironment(this);
      v57 = Scaleform::GFx::AS2::Value::ToBool(val, v56);
      (*p_SetCacheAsBitmap)(this->pDispObj, v57);
      return 1;
    case M_filters:
      v45 = Scaleform::GFx::AS2::Value::ToObject(val, v7);
      if ( !v45 )
        goto LABEL_35;
      Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v8->StringContext.pContext, ASBuiltin_Array);
      if ( !v45->InstanceOf(&v45->Scaleform::GFx::AS2::ObjectInterface, v8, Prototype, 1) )
        goto LABEL_35;
      v47 = (Scaleform::Render::FilterSet *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(0x18u);
      if ( v47 )
      {
        Scaleform::Render::FilterSet::FilterSet(v47, 0);
        pData = (Scaleform::GFx::Resource *)v48;
        opcodeFlag.pData = v48;
      }
      else
      {
        pData = 0;
        opcodeFlag.pData = 0;
      }
      p_PropFlags = 0;
      v51 = (signed int)v45[1].RootIndex <= 0;
      val = 0;
      if ( !v51 )
      {
        do
        {
          v52 = (Scaleform::GFx::AS2::Value *)(&v45[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[(_DWORD)p_PropFlags];
          if ( v52 )
          {
            v53 = Scaleform::GFx::AS2::Value::ToObject(v52, v8);
            if ( v53 )
            {
              v54 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v8->StringContext.pContext, ASBuiltin_BitmapFilter);
              if ( v53->InstanceOf(&v53->Scaleform::GFx::AS2::ObjectInterface, v8, v54, 1) )
                Scaleform::Render::FilterSet::AddFilter(
                  (Scaleform::Render::FilterSet *)opcodeFlag.pData,
                  (Scaleform::GFx::Resource *)v53[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable);
            }
            pData = (Scaleform::GFx::Resource *)opcodeFlag.pData;
          }
          p_PropFlags = &val->T.PropFlags;
          v51 = (int)&val->T.PropFlags < (signed int)v45[1].RootIndex;
          val = (Scaleform::GFx::AS2::Value *)((char *)val + 1);
        }
        while ( v51 );
      }
      if ( pData )
        Scaleform::RefCountImpl::AddRef(pData);
      Scaleform::GFx::AS2::AvmCharacter::SetFilters(this, (Scaleform::Ptr<Scaleform::Render::FilterSet>)pData);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
      this->pDispObj->SetAcceptAnimMoves(this->pDispObj, 0);
      if ( !pData )
        goto LABEL_35;
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pData);
      return 1;
    case M_enabled:
      v32 = Scaleform::GFx::AS2::Value::ToBool(val, v7);
      Scaleform::GFx::InteractiveObject::SetEnabledFlag(this->pDispObj, v32);
      return 1;
    case M_trackAsMenu:
      v33 = Scaleform::GFx::AS2::Value::ToBool(val, v7);
      Scaleform::GFx::InteractiveObject::SetTrackAsMenuFlag(this->pDispObj, v33);
      return 1;
    case M_tabEnabled:
      v35 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        this->pDispObj->Flags &= 0xFFFFFF9F;
      }
      else
      {
        v36 = this->GetASEnvironment(this);
        v37 = Scaleform::GFx::AS2::Value::ToBool(v35, v36);
        Scaleform::GFx::InteractiveObject::SetTabEnabledFlag(this->pDispObj, v37);
      }
      return 1;
    case M_tabIndex:
      v38 = this->GetASEnvironment(this);
      this->pDispObj->TabIndex = (int)Scaleform::GFx::AS2::Value::ToNumber(val, v38);
      return 1;
    case M_useHandCursor:
      v42 = val;
      if ( Scaleform::GFx::AS2::Value::IsUndefined(val) )
      {
        this->pDispObj->Flags &= 0xFFFFF9FF;
      }
      else
      {
        v43 = this->GetASEnvironment(this);
        v44 = Scaleform::GFx::AS2::Value::ToBool(v42, v43);
        Scaleform::GFx::InteractiveObject::SetUseHandCursorFlag(this->pDispObj, v44);
      }
      return 1;
    case M_edgeaaMode:
      v58 = EdgeAA_Inherit;
      v59 = this->GetASEnvironment(this);
      opcodeFlag.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::AS2::Value::ToInt32(val, v59);
      v60 = (double)(int)opcodeFlag.pData;
      if ( 3.0 == v60 )
      {
        v58 = EdgeAA_Disable;
      }
      else if ( 1.0 == v60 )
      {
        v58 = EdgeAA_On;
      }
      else if ( 2.0 == v60 )
      {
        v58 = EdgeAA_Off;
      }
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this->pDispObj);
      Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, v58);
      return 1;
    default:
      return 0;
  }
  return v6;
}
