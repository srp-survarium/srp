char __userpurge Scaleform::GFx::AS2::MovieRoot::GetVariableArray@<al>(
        Scaleform::GFx::AS2::MovieRoot *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::Movie::SetArrayType type,
        __m128i *ppathToVar,
        Scaleform::GFx::ASString index,
        Scaleform::GFx::Value *pdata,
        Scaleform::GFx::ASString count)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v10; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v17; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v18; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v20; // ecx
  Scaleform::GFx::AS2::Environment *v21; // esi
  Scaleform::GFx::AS2::Object *v22; // eax
  Scaleform::GFx::AS2::Object *v23; // esi
  int v24; // eax
  int *v25; // ebp
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *v26; // ebx
  Scaleform::GFx::ASStringNode *RootIndex; // edi
  unsigned int v28; // esi
  Scaleform::GFx::Value *v29; // ebp
  int pNode; // ebx
  Scaleform::GFx::AS2::Value *v31; // ecx
  unsigned int v32; // esi
  Scaleform::GFx::Value *v33; // ebp
  int v34; // ebx
  Scaleform::GFx::AS2::Value *v35; // ecx
  unsigned int v36; // esi
  Scaleform::GFx::Value *v37; // ebp
  int v38; // ebx
  Scaleform::GFx::AS2::Value *v39; // ecx
  double v40; // st7
  Scaleform::GFx::Value *v41; // esi
  int v42; // ebx
  Scaleform::GFx::ASStringNode *v43; // ebp
  Scaleform::GFx::AS2::Value *v44; // edi
  Scaleform::GFx::ASStringNode *v45; // esi
  unsigned int v46; // eax
  unsigned int v47; // edi
  Scaleform::GFx::AS2::Value *v48; // ecx
  Scaleform::GFx::ASStringNode *v49; // esi
  int v50; // eax
  unsigned int v52; // eax
  int v53; // ebx
  unsigned int v54; // esi
  Scaleform::GFx::AS2::Value *v55; // ecx
  Scaleform::GFx::ASStringNode *v56; // eax
  unsigned int v57; // eax
  unsigned int v58; // ebx
  Scaleform::MemoryHeap_vtbl *v59; // edx
  int v60; // eax
  _WORD *v61; // esi
  unsigned int v62; // edi
  Scaleform::GFx::Value *v63; // ebp
  _WORD *v64; // ebx
  unsigned int Char_Advance0; // eax
  Scaleform::GFx::ASStringNode *v66; // eax
  Scaleform::GFx::ASStringNode *v67; // eax
  __int64 v68; // [esp-18h] [ebp-44h]
  Scaleform::GFx::AS2::Environment *penv; // [esp+8h] [ebp-24h]
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *v71; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::ASStringNode *StringNode; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int _CurrentState; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::MovieRoot *v74; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value v75; // [esp+1Ch] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *v76; // [esp+30h] [ebp+4h]
  Scaleform::GFx::ASStringNode *v77; // [esp+30h] [ebp+4h]
  Scaleform::GFx::AS2::Object *v78; // [esp+34h] [ebp+8h]

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v10 = 0;
  v74 = this;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v10 >= Size )
      return 0;
  }
  if ( !Data[v10].pSprite.pObject )
    return 0;
  _controlfp_s(a2, &_CurrentState, 0, 0);
  _controlfp_s(a2, (unsigned int *)&v71, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  v14 = this->pMovieImpl;
  v15 = v14->MovieLevels.Data.Size;
  v16 = 0;
  if ( v15 )
  {
    v17 = v14->MovieLevels.Data.Data;
    v18 = v17;
    while ( v18->Level )
    {
      ++v16;
      ++v18;
      if ( v16 >= v15 )
        goto LABEL_11;
    }
    pObject = v17[v16].pSprite.pObject;
  }
  else
  {
LABEL_11:
    pObject = 0;
  }
  v20 = (int)pObject + 4 * pObject->AvmObjOffset;
  v21 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 124))(v20);
  penv = v21;
  HIDWORD(v68) = &v75;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v21->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 ppathToVar);
  ++StringNode->RefCount;
  LODWORD(v68) = &StringNode;
  v75.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v21, v68, 0, 0, 0)
    || v75.T.Type != 6
    || (v22 = Scaleform::GFx::AS2::Value::ToObject(&v75, v21), v23 = v22, (v78 = v22) == 0)
    || v22->GetObjectType(&v22->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
  {
    if ( v75.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v75);
    v67 = StringNode;
    --StringNode->RefCount;
    if ( !v67->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v67);
    _controlfp_s(a2, (unsigned int *)&pdata, _CurrentState, (unsigned int)&loc_30000);
    return 0;
  }
  Scaleform::GFx::MovieImpl::GetRetValHolder(this->pMovieImpl);
  v25 = (int *)v24;
  v26 = (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)(v24 + 8);
  *(_DWORD *)(v24 + 24) = 0;
  v71 = (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)(v24 + 8);
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)(v24 + 8),
    1u);
  RootIndex = (Scaleform::GFx::ASStringNode *)v23[1].RootIndex;
  switch ( type )
  {
    case SA_Int:
      v28 = 0;
      if ( RootIndex >= count.pNode )
        RootIndex = count.pNode;
      if ( RootIndex )
      {
        v29 = pdata;
        pNode = (int)index.pNode;
        do
        {
          v31 = (Scaleform::GFx::AS2::Value *)(&v78[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[pNode];
          if ( v31 )
            *((_DWORD *)&v29->pObjectInterface + v28) = (int)Scaleform::GFx::AS2::Value::ToNumber(v31, penv);
          else
            *((_DWORD *)&v29->pObjectInterface + v28) = 0;
          ++v28;
          ++pNode;
        }
        while ( v28 < (unsigned int)RootIndex );
      }
      break;
    case SA_Double:
      v36 = 0;
      if ( RootIndex >= count.pNode )
        RootIndex = count.pNode;
      if ( RootIndex )
      {
        v37 = pdata;
        v38 = (int)index.pNode;
        do
        {
          v39 = (Scaleform::GFx::AS2::Value *)(&v78[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v38];
          if ( v39 )
            v40 = Scaleform::GFx::AS2::Value::ToNumber(v39, penv);
          else
            v40 = 0.0;
          *(double *)&(&v37->pObjectInterface)[2 * v36++] = v40;
          ++v38;
        }
        while ( v36 < (unsigned int)RootIndex );
      }
      break;
    case SA_Float:
      v32 = 0;
      if ( RootIndex >= count.pNode )
        RootIndex = count.pNode;
      if ( RootIndex )
      {
        v33 = pdata;
        v34 = (int)index.pNode;
        do
        {
          v35 = (Scaleform::GFx::AS2::Value *)(&v78[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v34];
          if ( v35 )
            *((float *)&v33->pObjectInterface + v32) = Scaleform::GFx::AS2::Value::ToNumber(v35, penv);
          else
            *((float *)&v33->pObjectInterface + v32) = 0.0;
          ++v32;
          ++v34;
        }
        while ( v32 < (unsigned int)RootIndex );
      }
      break;
    case SA_String:
      v45 = count.pNode;
      if ( RootIndex >= count.pNode )
      {
        v76 = count.pNode;
      }
      else
      {
        v45 = RootIndex;
        v76 = RootIndex;
      }
      v46 = 1;
      if ( v45 )
        v46 = (unsigned int)v45;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        v26,
        v46);
      v47 = 0;
      if ( v45 )
      {
        count.pNode = (Scaleform::GFx::ASStringNode *)(4 * (int)index.pNode);
        do
        {
          v48 = *(Scaleform::GFx::AS2::Value **)((char *)&count.pNode->pData + (unsigned int)v78[1].pRCC);
          if ( v48 )
          {
            Scaleform::GFx::AS2::Value::ToStringImpl(v48, &index, penv, -1, 0);
            v49 = index.pNode;
            *((_DWORD *)&pdata->pObjectInterface + v47) = index.pNode->pData;
            v50 = v25[6];
            v25[6] = v50 + 1;
            Scaleform::GFx::ASString::operator=(&v26->Data[v50], &index);
            if ( v49->RefCount-- == 1 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v49);
          }
          else
          {
            *((_DWORD *)&pdata->pObjectInterface + v47) = 0;
          }
          count.pNode = (Scaleform::GFx::ASStringNode *)((char *)count.pNode + 4);
          ++v47;
        }
        while ( v47 < (unsigned int)v76 );
      }
      break;
    case SA_StringW:
      v52 = (unsigned int)count.pNode;
      v53 = 0;
      if ( RootIndex >= count.pNode )
      {
        v77 = count.pNode;
      }
      else
      {
        v52 = v23[1].RootIndex;
        v77 = (Scaleform::GFx::ASStringNode *)v52;
      }
      if ( !v52 )
        v52 = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        v71,
        v52);
      v54 = 0;
      if ( RootIndex )
      {
        index.pNode = (Scaleform::GFx::ASStringNode *)((int)index.pNode * 4);
        do
        {
          v55 = *(Scaleform::GFx::AS2::Value **)((char *)&index.pNode->pData + (unsigned int)v78[1].pRCC);
          if ( v55 )
          {
            Scaleform::GFx::AS2::Value::ToStringImpl(v55, &count, penv, -1, 0);
            Scaleform::GFx::ASString::operator=(&v71->Data[v54], &count);
            v53 += Scaleform::GFx::ASConstString::GetLength(&count) + 1;
            v56 = count.pNode;
            --count.pNode->RefCount;
            if ( !v56->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v56);
          }
          index.pNode = (Scaleform::GFx::ASStringNode *)((char *)index.pNode + 4);
          ++v54;
        }
        while ( v54 < (unsigned int)RootIndex );
      }
      v57 = v25[1];
      v58 = (2 * v53 + 4095) & 0xFFFFF000;
      if ( v57 < v58 || v57 > v58 && v57 - v58 > 0x1000 )
      {
        v59 = Scaleform::Memory::pGlobalHeap->__vftable;
        if ( *v25 )
          v60 = ((int (__stdcall *)(int, unsigned int))v59->Realloc)(*v25, v58);
        else
          v60 = ((int (__stdcall *)(unsigned int, _DWORD))v59->Alloc)(v58, 0);
        *v25 = v60;
        v25[1] = v58;
      }
      v61 = (_WORD *)*v25;
      v62 = 0;
      if ( v77 )
      {
        v63 = pdata;
        do
        {
          pdata = (Scaleform::GFx::Value *)v71->Data[v62].pNode->pData;
          v64 = v61;
          while ( 1 )
          {
            Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&pdata);
            if ( !Char_Advance0 )
              break;
            *v61++ = Char_Advance0;
          }
          pdata = (Scaleform::GFx::Value *)((char *)pdata - 1);
          *v61 = 0;
          *((_DWORD *)&v63->pObjectInterface + v62++) = v64;
          ++v61;
        }
        while ( v62 < (unsigned int)v77 );
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        v71,
        1u);
      break;
    case SA_Value:
      if ( RootIndex >= count.pNode )
        RootIndex = count.pNode;
      if ( RootIndex )
      {
        v41 = pdata;
        v42 = (int)index.pNode;
        v43 = RootIndex;
        do
        {
          v44 = (Scaleform::GFx::AS2::Value *)(&v78[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v42];
          if ( (v41->Type & 0x40) != 0 )
          {
            ((void (__stdcall *)(Scaleform::GFx::Value *, int))v41->pObjectInterface->ObjectRelease)(
              v41,
              v41->mValue.IValue);
            v41->pObjectInterface = 0;
          }
          v41->Type = VT_Undefined;
          if ( v44 )
            Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v74, penv, v44, v41);
          else
            v41->Type = VT_Undefined;
          ++v42;
          ++v41;
          v43 = (Scaleform::GFx::ASStringNode *)((char *)v43 - 1);
        }
        while ( v43 );
      }
      break;
    default:
      break;
  }
  if ( v75.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v75);
  v66 = StringNode;
  --StringNode->RefCount;
  if ( !v66->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v66);
  _controlfp_s(a2, (unsigned int *)&pdata, _CurrentState, (unsigned int)&loc_30000);
  return 1;
}
