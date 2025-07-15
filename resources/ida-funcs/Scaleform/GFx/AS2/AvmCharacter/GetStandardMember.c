double __userpurge Scaleform::GFx::AS2::AvmCharacter::GetStandardMember@<st0>(
        Scaleform::GFx::AS2::AvmCharacter *this@<ecx>,
        double Alpha@<st0>,
        double TabIndex@<st1>,
        int member,
        Scaleform::GFx::AS2::Value *val,
        bool opcodeFlag)
{
  Scaleform::GFx::AS2::Environment *v7; // eax
  void (*GetX)(void); // edx
  bool v9; // al
  __m128i *v10; // edi
  const Scaleform::GFx::AS2::Environment *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // esi
  bool v13; // zf
  const Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASString v16; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // edi
  Scaleform::GFx::ASStringNode *pNode; // ebx
  float x; // eax
  __m128i *pData; // edi
  unsigned int Size; // ebx
  const Scaleform::GFx::AS2::Environment *v22; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::InteractiveObject *v24; // edx
  int v25; // ecx
  Scaleform::GFx::InteractiveObject *TopMostEntity; // edi
  Scaleform::GFx::ASStringNode *v27; // eax
  __m128i *v28; // edi
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
  int v42; // eax
  unsigned int v43; // eax
  unsigned int v44; // eax
  Scaleform::GFx::ASString v45; // eax
  Scaleform::GFx::AS2::ASStringContext *p_Size; // edi
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
  const char *vala; // [esp+0h] [ebp-A8h]
  Scaleform::GFx::InteractiveObject *val_4; // [esp+4h] [ebp-A4h]
  Scaleform::GFx::ASString str; // [esp+20h] [ebp-88h] BYREF
  Scaleform::Render::Point<float> v64; // [esp+24h] [ebp-84h] BYREF
  Scaleform::GFx::ASString result; // [esp+2Ch] [ebp-7Ch] BYREF
  Scaleform::StringBuffer v66; // [esp+30h] [ebp-78h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType v67; // [esp+48h] [ebp-60h] BYREF

  if ( opcodeFlag && (unsigned int)member >= 0x16 )
  {
    v7 = (Scaleform::GFx::AS2::Environment *)((int (__usercall *)@<eax>(Scaleform::GFx::AS2::AvmCharacter *@<ecx>, const char *, int, double@<st0>))this->GetASEnvironment)(
                                               this,
                                               "Invalid GetProperty query, property number %d",
                                               member,
                                               Alpha);
    Scaleform::GFx::AS2::Environment::LogScriptError(v7, vala);
  }
  else if ( member != -1 && member <= 32 && (this->GetStandardMemberBitMask(this) & (1 << member)) != 0 )
  {
    switch ( member )
    {
      case 0:
        GetX = (void (*)(void))this->pDispObj->GetX;
        goto LABEL_10;
      case 1:
        GetX = (void (*)(void))this->pDispObj->GetY;
        goto LABEL_10;
      case 2:
        GetX = (void (*)(void))this->pDispObj->GetXScale;
        goto LABEL_10;
      case 3:
        Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(&v67);
        GetX = (void (*)(void))this->pDispObj->GetYScale;
        goto LABEL_10;
      case 6:
        TabIndex = Scaleform::GFx::DisplayObjectBase::GetAlpha(this->pDispObj);
        goto LABEL_11;
      case 7:
        v9 = this->pDispObj->GetVisible(this->pDispObj);
        Scaleform::GFx::AS2::Value::SetBool(val, v9);
        return Alpha;
      case 8:
        GetX = (void (*)(void))this->pDispObj->GetWidth;
        goto LABEL_10;
      case 9:
        GetX = (void (*)(void))this->pDispObj->GetHeight;
        goto LABEL_10;
      case 10:
        GetX = (void (*)(void))this->pDispObj->GetRotation;
LABEL_10:
        GetX();
        goto LABEL_11;
      case 11:
        Scaleform::StringBuffer::StringBuffer(&v66, Scaleform::Memory::pGlobalHeap);
        *(float *)&v16.pNode = COERCE_FLOAT(
                                 ((int (__usercall *)@<eax>(Scaleform::GFx::AS2::AvmCharacter *@<ecx>, _DWORD, double@<st0>))this->GetTopParent)(
                                   this,
                                   0,
                                   Alpha));
        str.pNode = v16.pNode;
        if ( *(float *)&v16.pNode != 0.0 )
          ++v16.pNode->pManager;
        pDispObj = this->pDispObj;
        if ( pDispObj )
        {
          pNode = v16.pNode;
          do
          {
            if ( pDispObj == (Scaleform::GFx::InteractiveObject *)pNode )
              break;
            Scaleform::GFx::DisplayObject::GetName(pDispObj, (Scaleform::GFx::ASString *)&v64);
            Scaleform::StringBuffer::Insert(&v66, *(const __m128i **)LODWORD(v64.x), 0, -1);
            Scaleform::StringBuffer::Insert(&v66, (const __m128i *)"/", 0, -1);
            x = v64.x;
            --*(_DWORD *)(LODWORD(v64.x) + 12);
            if ( !*(_DWORD *)(LODWORD(x) + 12) )
              Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)LODWORD(x));
            pDispObj = pDispObj->pParent;
          }
          while ( pDispObj );
        }
        pData = (__m128i *)v66.pData;
        Size = v66.Size;
        if ( !v66.pData )
          pData = (__m128i *)uri;
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
        return Alpha;
      case 13:
        Name = Scaleform::GFx::DisplayObject::GetName(this->pDispObj, &result);
        Scaleform::GFx::AS2::Value::SetString(val, Name);
        v15 = result.pNode;
        --result.pNode->RefCount;
        if ( !v15->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        return Alpha;
      case 14:
        Scaleform::GFx::AS2::Value::DropRefs(val);
        val->T.Type = 0;
        v25 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((int (__usercall *)@<eax>(Scaleform::GFx::AS2::AvmCharacter *@<ecx>, double@<st0>))this->GetASEnvironment)(
                                                    this,
                                                    Alpha)
                                                + 112)
                                    + 16)
                        + 8);
        val_4 = this->pDispObj;
        str.pNode = *(Scaleform::GFx::ASStringNode **)(v25 + 4624);
        v64.x = *(float *)(v25 + 4620);
        Alpha = *(float *)&str.pNode;
        v64.y = *(float *)&str.pNode;
        TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(
                          (Scaleform::GFx::MovieImpl *)v25,
                          &v64,
                          0.0,
                          1,
                          val_4);
        Scaleform::StringBuffer::StringBuffer(&v66, Scaleform::Memory::pGlobalHeap);
        for ( ; TopMostEntity; TopMostEntity = TopMostEntity->pParent )
        {
          Scaleform::GFx::DisplayObject::GetName(TopMostEntity, &str);
          Scaleform::StringBuffer::Insert(&v66, (const __m128i *)str.pNode->pData, 0, -1);
          Scaleform::StringBuffer::Insert(&v66, (const __m128i *)"/", 0, -1);
          v27 = str.pNode;
          --str.pNode->RefCount;
          if ( !v27->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v27);
        }
        v28 = (__m128i *)v66.pData;
        str.pNode = (Scaleform::GFx::ASStringNode *)v66.Size;
        if ( !v66.pData )
          v28 = (__m128i *)uri;
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
        return Alpha;
      case 15:
        v31 = this->pDispObj;
        GetResourceMovieDef = v31->GetResourceMovieDef;
        *(float *)&v33 = 0.0;
        memset(&v66, 0, 12);
        v34 = ((int (__usercall *)@<eax>(Scaleform::GFx::InteractiveObject *@<ecx>, double@<st0>))GetResourceMovieDef)(
                v31,
                Alpha);
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
                             (__m128i *)((LODWORD(v64.x) & 0xFFFFFFFC) + 8),
                             *(_DWORD *)(LODWORD(v64.x) & 0xFFFFFFFC) & 0x7FFFFFFF));
        ++v41->RefCount;
        str.pNode = v41;
        Scaleform::GFx::AS2::Value::SetString(val, &str);
        v13 = v41->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v41);
        Scaleform::String::~String((Scaleform::String *)&v64);
        Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v66);
        return Alpha;
      case 16:
        goto LABEL_95;
      case 17:
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
        return Alpha;
      case 18:
        TabIndex = 0.0;
        goto LABEL_11;
      case 19:
        v42 = ((int (__usercall *)@<eax>(Scaleform::GFx::AS2::AvmCharacter *@<ecx>, double@<st0>))this->GetASEnvironment)(
                this,
                Alpha);
        *(float *)&v12 = COERCE_FLOAT(
                           Scaleform::GFx::ASStringManager::CreateStringNode(
                             *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v42 + 116) + 20)
                                                                             + 12)
                                                                 + 788),
                             (__m128i *)"HIGH"));
        ++v12->RefCount;
        str.pNode = v12;
        Scaleform::GFx::AS2::Value::SetString(val, &str);
        v13 = v12->RefCount-- == 1;
        if ( v13 )
          goto LABEL_22;
        return Alpha;
      case 20:
        this->pDispObj->GetMouseX(this->pDispObj);
        goto LABEL_11;
      case 21:
        this->pDispObj->GetMouseY(this->pDispObj);
        goto LABEL_11;
      case 22:
        v24 = this->pDispObj;
        if ( !v24->pParent )
          goto LABEL_44;
        Scaleform::GFx::AS2::Value::SetAsCharacter(val, v24->pParent);
        break;
      case 23:
        v10 = (__m128i *)GFx_BlendModeNames[((int (__usercall *)@<eax>(Scaleform::GFx::InteractiveObject *@<ecx>, double@<st0>))this->pDispObj->GetBlendMode)(
                                              this->pDispObj,
                                              Alpha)];
        v11 = this->GetASEnvironment(this);
        *(float *)&v12 = COERCE_FLOAT(
                           Scaleform::GFx::ASStringManager::CreateStringNode(
                             (Scaleform::GFx::ASStringManager *)v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             v10));
        ++v12->RefCount;
        str.pNode = v12;
        Scaleform::GFx::AS2::Value::SetString(val, &str);
        v13 = v12->RefCount-- == 1;
        if ( v13 )
LABEL_22:
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        break;
      case 24:
        v57 = this->pDispObj;
        if ( v57
          && Scaleform::GFx::DisplayObjectBase::GetRenderNode(v57)
          && (RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this->pDispObj),
              Scaleform::Render::TreeNode::GetFilters(RenderNode)) )
        {
LABEL_95:
          Scaleform::GFx::AS2::Value::SetBool(val, 1);
        }
        else
        {
          Scaleform::GFx::AS2::Value::SetBool(val, 0);
        }
        break;
      case 25:
        *(float *)&v45.pNode = COERCE_FLOAT(
                                 ((int (__usercall *)@<eax>(Scaleform::GFx::AS2::AvmCharacter *@<ecx>, double@<st0>))this->GetASEnvironment)(
                                   this,
                                   Alpha));
        p_Size = (Scaleform::GFx::AS2::ASStringContext *)&v45.pNode[4].Size;
        str.pNode = v45.pNode;
        v47 = (Scaleform::GFx::AS2::ArrayObject *)(*(int (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)(v45.pNode[4].Size + 24)
                                                                                             + 40))(
                                                    *(_DWORD *)(v45.pNode[4].Size + 24),
                                                    80,
                                                    0);
        if ( v47 )
        {
          Scaleform::GFx::AS2::ArrayObject::ArrayObject(v47, p_Size);
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
          if ( (v56 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(LODWORD(v64.x) + 12) = v56 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)LODWORD(v55));
          }
        }
        break;
      case 26:
        Scaleform::GFx::AS2::Value::SetBool(val, (this->pDispObj->Flags & 0x10) != 0);
        break;
      case 27:
        Scaleform::GFx::AS2::Value::SetBool(val, (this->pDispObj->Flags & 0x4000) != 0);
        break;
      case 29:
        v44 = this->pDispObj->Flags & 0x60;
        if ( v44 )
        {
          Scaleform::GFx::AS2::Value::SetBool(val, v44 == 96);
        }
        else
        {
LABEL_44:
          Scaleform::GFx::AS2::Value::DropRefs(val);
          val->T.Type = 0;
        }
        break;
      case 30:
        TabIndex = (double)this->pDispObj->TabIndex;
LABEL_11:
        Scaleform::GFx::AS2::Value::SetNumber(val, TabIndex);
        break;
      case 31:
        if ( (this->pDispObj->Flags & 0x600) != 0 )
          Scaleform::GFx::AS2::Value::SetBool(val, (this->pDispObj->Flags & 0x600) == 1536);
        break;
      case 32:
        v59 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this->pDispObj);
        EdgeAAMode = Scaleform::Render::TreeNode::GetEdgeAAMode(v59);
        switch ( EdgeAAMode )
        {
          case 4:
            Scaleform::GFx::AS2::Value::SetNumber(val, 1.0);
            break;
          case 8:
            Scaleform::GFx::AS2::Value::SetNumber(val, 2.0);
            break;
          case 12:
            Scaleform::GFx::AS2::Value::SetNumber(val, 3.0);
            break;
          default:
            Scaleform::GFx::AS2::Value::SetNumber(val, 0.0);
            break;
        }
        break;
      default:
        return Alpha;
    }
  }
  return Alpha;
}
