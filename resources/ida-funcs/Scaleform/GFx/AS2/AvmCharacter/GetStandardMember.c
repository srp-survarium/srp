bool __userpurge Scaleform::GFx::AS2::AvmCharacter::GetStandardMember@<al>(
        Scaleform::GFx::AS2::AvmCharacter *this@<ecx>,
        double Alpha@<st0>,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *val,
        bool opcodeFlag)
{
  Scaleform::GFx::AS2::Environment *v6; // eax
  bool v7; // al
  double (*GetX)(void); // edx
  bool v9; // al
  char *v10; // edi
  const Scaleform::GFx::AS2::Environment *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // esi
  bool v13; // zf
  const Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::InteractiveObject *v16; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // edi
  Scaleform::GFx::InteractiveObject *v18; // ebx
  float x; // eax
  char *pData; // edi
  unsigned int Size; // ebx
  const Scaleform::GFx::AS2::Environment *v22; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::InteractiveObject *v24; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::InteractiveObject *TopMostEntity; // edi
  Scaleform::GFx::ASStringNode *v27; // eax
  char *v28; // edi
  const Scaleform::GFx::AS2::Environment *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // esi
  Scaleform::GFx::InteractiveObject *v31; // ecx
  Scaleform::GFx::MovieDefImpl *(__thiscall *GetResourceMovieDef)(Scaleform::GFx::DisplayObjectBase *); // eax
  unsigned int v33; // edi
  int v34; // eax
  char *v35; // eax
  char *v36; // ebx
  Scaleform::GFx::ASStringNode *v37; // eax
  int v38; // edx
  char v39; // cl
  const Scaleform::GFx::AS2::Environment *v40; // eax
  Scaleform::GFx::ASStringNode *v41; // esi
  const Scaleform::GFx::AS2::Environment *v42; // eax
  unsigned int v43; // eax
  unsigned int v44; // eax
  Scaleform::GFx::AS2::Environment *v45; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::ArrayObject *v47; // eax
  float v48; // eax
  const Scaleform::Render::FilterSet *v49; // eax
  const Scaleform::Render::FilterSet *v50; // edi
  unsigned int v51; // ebx
  Scaleform::Ptr<Scaleform::Render::Filter> *Data; // ecx
  Scaleform::GFx::AS2::BitmapFilterObject *v53; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v54; // esi
  float v55; // esi
  int v56; // eax
  Scaleform::GFx::InteractiveObject *v57; // ecx
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v59; // eax
  int EdgeAAMode; // eax
  const char *geomData_88; // [esp+3D8h] [ebp-A8h]
  Scaleform::GFx::InteractiveObject *geomData_92; // [esp+3DCh] [ebp-A4h]
  Scaleform::GFx::ASString str; // [esp+3F8h] [ebp-88h] BYREF
  Scaleform::Render::Point<float> v64; // [esp+3FCh] [ebp-84h] BYREF
  Scaleform::GFx::ASString result; // [esp+404h] [ebp-7Ch] BYREF
  Scaleform::StringBuffer v66; // [esp+408h] [ebp-78h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType v67; // [esp+420h] [ebp-60h] BYREF

  if ( opcodeFlag && (unsigned int)member >= M_parent )
  {
    v6 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::AS2::AvmCharacter *, const char *, Scaleform::GFx::AS2::AvmCharacter::StandardMember))this->GetASEnvironment)(
                                               this,
                                               "Invalid GetProperty query, property number %d",
                                               member);
    Scaleform::GFx::AS2::Environment::LogScriptError(v6, geomData_88);
    return 0;
  }
  if ( member == M_InvalidMember || member > M_edgeaaMode || (this->GetStandardMemberBitMask(this) & (1 << member)) == 0 )
    return 0;
  switch ( member )
  {
    case M_x:
      GetX = (double (*)(void))this->pDispObj->GetX;
      goto LABEL_10;
    case M_y:
      GetX = (double (*)(void))this->pDispObj->GetY;
      goto LABEL_10;
    case M_xscale:
      GetX = (double (*)(void))this->pDispObj->GetXScale;
      goto LABEL_10;
    case M_yscale:
      Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&v67);
      GetX = (double (*)(void))this->pDispObj->GetYScale;
      goto LABEL_10;
    case M_alpha:
      Alpha = Scaleform::GFx::DisplayObjectBase::GetAlpha(this->pDispObj);
      goto LABEL_11;
    case M_visible:
      v9 = this->pDispObj->GetVisible(this->pDispObj);
      Scaleform::GFx::AS2::Value::SetBool(val, v9);
      return 1;
    case M_width:
      GetX = (double (*)(void))this->pDispObj->GetWidth;
      goto LABEL_10;
    case M_height:
      GetX = (double (*)(void))this->pDispObj->GetHeight;
      goto LABEL_10;
    case M_rotation:
      GetX = (double (*)(void))this->pDispObj->GetRotation;
LABEL_10:
      Alpha = GetX();
      goto LABEL_11;
    case M_target:
      Scaleform::StringBuffer::StringBuffer(&v66, Scaleform::Memory::pGlobalHeap);
      *(float *)&v16 = COERCE_FLOAT((int)this->GetTopParent(this, 0));
      str.pNode = (Scaleform::GFx::ASStringNode *)v16;
      if ( *(float *)&v16 != 0.0 )
        ++v16->RefCount;
      pDispObj = this->pDispObj;
      if ( pDispObj )
      {
        v18 = v16;
        do
        {
          if ( pDispObj == v18 )
            break;
          Scaleform::GFx::DisplayObject::GetName(pDispObj, (Scaleform::GFx::ASString *)&v64);
          Scaleform::StringBuffer::Insert(&v66, *(char **)LODWORD(v64.x), 0, -1);
          Scaleform::StringBuffer::Insert(&v66, "/", 0, -1);
          x = v64.x;
          --*(_DWORD *)(LODWORD(v64.x) + 12);
          if ( !*(_DWORD *)(LODWORD(x) + 12) )
            Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)LODWORD(x));
          pDispObj = pDispObj->pParent;
        }
        while ( pDispObj );
      }
      pData = v66.pData;
      Size = v66.Size;
      if ( !v66.pData )
        pData = (char *)&buf;
      v22 = this->GetASEnvironment(this);
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)v22->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     pData,
                     Size);
      ++StringNode->RefCount;
      LODWORD(v64.x) = StringNode;
      Scaleform::GFx::AS2::Value::SetString(val, (const Scaleform::GFx::ASString *)&v64);
      v13 = StringNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      if ( *(float *)&str.pNode != 0.0 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)str.pNode);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v66);
      return 1;
    case M_name:
      Name = Scaleform::GFx::DisplayObject::GetName(this->pDispObj, &result);
      Scaleform::GFx::AS2::Value::SetString(val, Name);
      pNode = result.pNode;
      --result.pNode->RefCount;
      if ( pNode->RefCount )
        goto LABEL_12;
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return 1;
    case M_droptarget:
      Scaleform::GFx::AS2::Value::DropRefs(val);
      val->T.Type = 0;
      pMovieImpl = this->GetASEnvironment(this)->Target->pASRoot->pMovieImpl;
      geomData_92 = this->pDispObj;
      str.pNode = (Scaleform::GFx::ASStringNode *)LODWORD(pMovieImpl->mMouseState[0].LastPosition.y);
      v64.x = pMovieImpl->mMouseState[0].LastPosition.x;
      v64.y = *(float *)&str.pNode;
      TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(pMovieImpl, &v64, 0, 1, geomData_92);
      Scaleform::StringBuffer::StringBuffer(&v66, Scaleform::Memory::pGlobalHeap);
      for ( ; TopMostEntity; TopMostEntity = TopMostEntity->pParent )
      {
        Scaleform::GFx::DisplayObject::GetName(TopMostEntity, &str);
        Scaleform::StringBuffer::Insert(&v66, (char *)str.pNode->pData, 0, -1);
        Scaleform::StringBuffer::Insert(&v66, "/", 0, -1);
        v27 = str.pNode;
        --str.pNode->RefCount;
        if ( !v27->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
      v28 = v66.pData;
      str.pNode = (Scaleform::GFx::ASStringNode *)v66.Size;
      if ( !v66.pData )
        v28 = (char *)&buf;
      v29 = this->GetASEnvironment(this);
      *(float *)&v30 = COERCE_FLOAT(
                         Scaleform::GFx::ASStringManager::CreateStringNode(
                           (Scaleform::GFx::ASStringManager *)v29->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                           v28,
                           (unsigned int)str.pNode));
      ++v30->RefCount;
      str.pNode = v30;
      Scaleform::GFx::AS2::Value::SetString(val, &str);
      v13 = v30->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v66);
      return 1;
    case M_url:
      v31 = this->pDispObj;
      GetResourceMovieDef = v31->GetResourceMovieDef;
      *(float *)&v33 = 0.0;
      memset(&v66, 0, 12);
      v34 = (int)GetResourceMovieDef(v31);
      *(float *)&v35 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v34 + 48))(v34));
      str.pNode = (Scaleform::GFx::ASStringNode *)v35;
      if ( *(float *)&v35 != 0.0 )
        *(float *)&v33 = COERCE_FLOAT(strlen(v35));
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
        (Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *)&v66,
        v33 + 1);
      v36 = v66.pData;
      if ( *(float *)&v33 != 0.0 )
      {
        v37 = str.pNode;
        v38 = v66.pData - (char *)str.pNode;
        str.pNode = (Scaleform::GFx::ASStringNode *)v33;
        do
        {
          v39 = (char)v37->pData;
          if ( LOBYTE(v37->pData) == 92 )
            v39 = 47;
          *((_BYTE *)&v37->pData + v38) = v39;
          v37 = (Scaleform::GFx::ASStringNode *)((char *)v37 + 1);
          --str.pNode;
        }
        while ( *(float *)&str.pNode != 0.0 );
      }
      v36[v33] = 0;
      Scaleform::String::String((Scaleform::String *)&v64);
      Scaleform::GFx::ASUtils::EscapePath(v36, v33, (Scaleform::String *)&v64);
      v40 = this->GetASEnvironment(this);
      *(float *)&v41 = COERCE_FLOAT(
                         Scaleform::GFx::ASStringManager::CreateStringNode(
                           (Scaleform::GFx::ASStringManager *)v40->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                           (char *)((LODWORD(v64.x) & 0xFFFFFFFC) + 8),
                           *(_DWORD *)(LODWORD(v64.x) & 0xFFFFFFFC) & 0x7FFFFFFF));
      ++v41->RefCount;
      str.pNode = v41;
      Scaleform::GFx::AS2::Value::SetString(val, &str);
      v13 = v41->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v41);
      Scaleform::String::~String((Scaleform::String *)&v64);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v66);
      return 1;
    case M_highquality:
      goto LABEL_96;
    case M_focusrect:
      v43 = this->pDispObj->Flags & 0x180;
      if ( v43 )
      {
        Scaleform::GFx::AS2::Value::SetBool(val, v43 == 384);
      }
      else
      {
        Scaleform::GFx::AS2::Value::DropRefs(val);
        val->T.Type = 1;
      }
      return 1;
    case M_soundbuftime:
      Alpha = 0.0;
      goto LABEL_11;
    case M_quality:
      v42 = this->GetASEnvironment(this);
      *(float *)&v12 = COERCE_FLOAT(
                         Scaleform::GFx::ASStringManager::CreateStringNode(
                           (Scaleform::GFx::ASStringManager *)v42->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                           "HIGH"));
      ++v12->RefCount;
      str.pNode = v12;
      Scaleform::GFx::AS2::Value::SetString(val, &str);
      v13 = v12->RefCount-- == 1;
      if ( v13 )
        goto LABEL_22;
      goto LABEL_12;
    case M_xmouse:
      this->pDispObj->GetMouseX(this->pDispObj);
      goto LABEL_11;
    case M_ymouse:
      this->pDispObj->GetMouseY(this->pDispObj);
      goto LABEL_11;
    case M_parent:
      v24 = this->pDispObj;
      if ( !v24->pParent )
        goto LABEL_44;
      Scaleform::GFx::AS2::Value::SetAsCharacter(val, v24->pParent);
      return 1;
    case M_blendMode:
      v10 = (char *)GFx_BlendModeNames[this->pDispObj->GetBlendMode(this->pDispObj)];
      v11 = this->GetASEnvironment(this);
      *(float *)&v12 = COERCE_FLOAT(
                         Scaleform::GFx::ASStringManager::CreateStringNode(
                           (Scaleform::GFx::ASStringManager *)v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                           v10));
      ++v12->RefCount;
      str.pNode = v12;
      Scaleform::GFx::AS2::Value::SetString(val, &str);
      v13 = v12->RefCount-- == 1;
      if ( !v13 )
        goto LABEL_12;
LABEL_22:
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v7 = 1;
      break;
    case M_cacheAsBitmap:
      v57 = this->pDispObj;
      if ( v57
        && Scaleform::GFx::DisplayObjectBase::GetRenderNode(v57)
        && (RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this->pDispObj),
            Scaleform::Render::TreeNode::GetFilters(RenderNode)) )
      {
LABEL_96:
        Scaleform::GFx::AS2::Value::SetBool(val, 1);
        return 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::SetBool(val, 0);
        return 1;
      }
    case M_filters:
      *(float *)&v45 = COERCE_FLOAT((int)this->GetASEnvironment(this));
      p_StringContext = &v45->StringContext;
      str.pNode = (Scaleform::GFx::ASStringNode *)v45;
      v47 = (Scaleform::GFx::AS2::ArrayObject *)v45->StringContext.pContext->pHeap->Alloc(
                                                  v45->StringContext.pContext->pHeap,
                                                  80u,
                                                  0);
      if ( v47 )
      {
        Scaleform::GFx::AS2::ArrayObject::ArrayObject(v47, p_StringContext);
        v64.x = v48;
      }
      else
      {
        v64.x = 0.0;
      }
      v49 = this->pDispObj->GetFilters(this->pDispObj);
      v50 = v49;
      if ( v49 )
      {
        v51 = 0;
        if ( v49->Filters.Data.Size )
        {
          do
          {
            Data = v50->Filters.Data.Data;
            if ( Data[v51].pObject )
            {
              v53 = Scaleform::GFx::AS2::BitmapFilterObject::CreateFromDesc(
                      (Scaleform::GFx::AS2::Environment *)str.pNode,
                      Data[v51].pObject);
              v54 = v53;
              if ( v53 )
              {
                Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)&v66, v53);
                Scaleform::GFx::AS2::ArrayObject::PushBack(
                  (Scaleform::GFx::AS2::ArrayObject *)LODWORD(v64.x),
                  (const Scaleform::GFx::AS2::Value *)&v66);
                if ( LOBYTE(v66.pData) >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v66);
                Scaleform::GFx::AS2::RefCountBaseGC<323>::Release(v54);
              }
            }
            ++v51;
          }
          while ( v51 < v50->Filters.Data.Size );
        }
      }
      v55 = v64.x;
      Scaleform::GFx::AS2::Value::SetAsObject(val, (Scaleform::GFx::AS2::Object *)LODWORD(v64.x));
      if ( LODWORD(v64.x) )
      {
        v56 = *(_DWORD *)(LODWORD(v64.x) + 12);
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v56) != 0 )
        {
          *(_DWORD *)(LODWORD(v64.x) + 12) = v56 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)LODWORD(v55));
        }
      }
      return 1;
    case M_enabled:
      Scaleform::GFx::AS2::Value::SetBool(val, (this->pDispObj->Flags & 0x10) != 0);
      return 1;
    case M_trackAsMenu:
      Scaleform::GFx::AS2::Value::SetBool(val, (this->pDispObj->Flags & 0x4000) != 0);
      return 1;
    case M_tabEnabled:
      v44 = this->pDispObj->Flags & 0x60;
      if ( v44 )
      {
        Scaleform::GFx::AS2::Value::SetBool(val, v44 == 96);
        return 1;
      }
      else
      {
LABEL_44:
        Scaleform::GFx::AS2::Value::DropRefs(val);
        val->T.Type = 0;
        return 1;
      }
    case M_tabIndex:
      Alpha = (double)this->pDispObj->TabIndex;
LABEL_11:
      Scaleform::GFx::AS2::Value::SetNumber(val, Alpha);
LABEL_12:
      v7 = 1;
      break;
    case M_useHandCursor:
      if ( (this->pDispObj->Flags & 0x600) == 0 )
        return 0;
      Scaleform::GFx::AS2::Value::SetBool(val, (this->pDispObj->Flags & 0x600) == 1536);
      v7 = 1;
      break;
    case M_edgeaaMode:
      v59 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this->pDispObj);
      EdgeAAMode = Scaleform::Render::TreeNode::GetEdgeAAMode(v59);
      if ( EdgeAAMode == 4 )
      {
        Scaleform::GFx::AS2::Value::SetNumber(val, 1.0);
        v7 = 1;
      }
      else if ( EdgeAAMode == 8 )
      {
        Scaleform::GFx::AS2::Value::SetNumber(val, 2.0);
        v7 = 1;
      }
      else
      {
        if ( EdgeAAMode == 12 )
          Scaleform::GFx::AS2::Value::SetNumber(val, 3.0);
        else
          Scaleform::GFx::AS2::Value::SetNumber(val, 0.0);
        v7 = 1;
      }
      break;
    default:
      return 0;
  }
  return v7;
}
