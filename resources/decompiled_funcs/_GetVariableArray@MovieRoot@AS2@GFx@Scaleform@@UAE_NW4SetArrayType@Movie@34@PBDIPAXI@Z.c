char __thiscall Scaleform::GFx::AS2::MovieRoot::GetVariableArray(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int type,
        char *ppathToVar,
        Scaleform::GFx::ASString index,
        const char *pdata,
        Scaleform::GFx::ASStringNode *count)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v9; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::MovieImpl *v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v16; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v17; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v19; // ecx
  Scaleform::GFx::AS2::Environment *v20; // esi
  Scaleform::GFx::AS2::Object *v21; // eax
  Scaleform::GFx::AS2::Object *v22; // esi
  int v23; // eax
  int *v24; // ebp
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *v25; // ebx
  unsigned int RootIndex; // edi
  unsigned int v27; // esi
  const char *v28; // ebp
  unsigned int v29; // ebx
  Scaleform::GFx::AS2::Value *v30; // ecx
  unsigned int v31; // esi
  const char *v32; // ebp
  unsigned int v33; // ebx
  Scaleform::GFx::AS2::Value *v34; // ecx
  unsigned int v35; // esi
  const char *v36; // ebp
  unsigned int v37; // ebx
  Scaleform::GFx::AS2::Value *v38; // ecx
  double v39; // st7
  char *v40; // esi
  unsigned int v41; // ebx
  unsigned int v42; // ebp
  Scaleform::GFx::AS2::Value *v43; // edi
  unsigned int v44; // esi
  unsigned int v45; // eax
  unsigned int v46; // edi
  Scaleform::GFx::AS2::Value *v47; // ecx
  Scaleform::GFx::ASStringNode *v48; // esi
  int v49; // eax
  unsigned int v51; // eax
  int v52; // ebx
  unsigned int v53; // esi
  Scaleform::GFx::AS2::Value *v54; // ecx
  Scaleform::GFx::ASStringNode *v55; // eax
  unsigned int v56; // eax
  unsigned int v57; // ebx
  Scaleform::MemoryHeap_vtbl *v58; // edx
  int v59; // eax
  _WORD *v60; // esi
  unsigned int v61; // edi
  const char *v62; // ebp
  _WORD *v63; // ebx
  unsigned int v64; // eax
  Scaleform::GFx::ASStringNode *v65; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Environment *penv; // [esp+8h] [ebp-24h]
  unsigned int _CurrentState; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::ASString path; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::MovieRoot *v71; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value retVal; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int n; // [esp+30h] [ebp+4h]
  unsigned int na; // [esp+30h] [ebp+4h]
  Scaleform::GFx::AS2::Object *pobj; // [esp+34h] [ebp+8h]

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v9 = 0;
  v71 = this;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v9 >= Size )
      return 0;
  }
  if ( !Data[v9].pSprite.pObject )
    return 0;
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v13 = this->pMovieImpl;
  v14 = v13->MovieLevels.Data.Size;
  v15 = 0;
  if ( v14 )
  {
    v16 = v13->MovieLevels.Data.Data;
    v17 = v16;
    while ( v17->Level )
    {
      ++v15;
      ++v17;
      if ( v15 >= v14 )
        goto LABEL_11;
    }
    pObject = v16[v15].pSprite.pObject;
  }
  else
  {
LABEL_11:
    pObject = 0;
  }
  v19 = (int)pObject + 4 * pObject->AvmObjOffset;
  v20 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v19 + 124))(v19);
  penv = v20;
  path.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v20->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 ppathToVar);
  ++path.pNode->RefCount;
  retVal.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v20, &path, &retVal, 0, 0, 0, 0)
    || retVal.T.Type != 6
    || (v21 = Scaleform::GFx::AS2::Value::ToObject(&retVal, v20), v22 = v21, (pobj = v21) == 0)
    || v21->GetObjectType(&v21->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
  {
    if ( retVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&retVal);
    pNode = path.pNode;
    --path.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    _controlfp_s((unsigned int *)&pdata, dpg.fpc, 0x30000u);
    return 0;
  }
  Scaleform::GFx::MovieImpl::GetRetValHolder(this->pMovieImpl);
  v24 = (int *)v23;
  v25 = (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)(v23 + 8);
  *(_DWORD *)(v23 + 24) = 0;
  _CurrentState = v23 + 8;
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)(v23 + 8),
    1u);
  RootIndex = v22[1].RootIndex;
  switch ( type )
  {
    case 0u:
      v27 = 0;
      if ( RootIndex >= (unsigned int)count )
        RootIndex = (unsigned int)count;
      if ( RootIndex )
      {
        v28 = pdata;
        v29 = (int)index.pNode;
        do
        {
          v30 = (Scaleform::GFx::AS2::Value *)(&pobj[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[v29];
          if ( v30 )
            *(_DWORD *)&v28[4 * v27] = (int)Scaleform::GFx::AS2::Value::ToNumber(v30, penv);
          else
            *(_DWORD *)&v28[4 * v27] = 0;
          ++v27;
          ++v29;
        }
        while ( v27 < RootIndex );
      }
      break;
    case 1u:
      v35 = 0;
      if ( RootIndex >= (unsigned int)count )
        RootIndex = (unsigned int)count;
      if ( RootIndex )
      {
        v36 = pdata;
        v37 = (int)index.pNode;
        do
        {
          v38 = (Scaleform::GFx::AS2::Value *)(&pobj[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[v37];
          if ( v38 )
            v39 = Scaleform::GFx::AS2::Value::ToNumber(v38, penv);
          else
            v39 = 0.0;
          *(double *)&v36[8 * v35++] = v39;
          ++v37;
        }
        while ( v35 < RootIndex );
      }
      break;
    case 2u:
      v31 = 0;
      if ( RootIndex >= (unsigned int)count )
        RootIndex = (unsigned int)count;
      if ( RootIndex )
      {
        v32 = pdata;
        v33 = (int)index.pNode;
        do
        {
          v34 = (Scaleform::GFx::AS2::Value *)(&pobj[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[v33];
          if ( v34 )
            *(float *)&v32[4 * v31] = Scaleform::GFx::AS2::Value::ToNumber(v34, penv);
          else
            *(float *)&v32[4 * v31] = 0.0;
          ++v31;
          ++v33;
        }
        while ( v31 < RootIndex );
      }
      break;
    case 3u:
      v44 = (unsigned int)count;
      if ( RootIndex >= (unsigned int)count )
      {
        n = (unsigned int)count;
      }
      else
      {
        v44 = RootIndex;
        n = RootIndex;
      }
      v45 = 1;
      if ( v44 )
        v45 = v44;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        v25,
        v45);
      v46 = 0;
      if ( v44 )
      {
        count = (Scaleform::GFx::ASStringNode *)(4 * (int)index.pNode);
        do
        {
          v47 = *(Scaleform::GFx::AS2::Value **)((char *)&count->pData + (unsigned int)pobj[1].pRCC);
          if ( v47 )
          {
            Scaleform::GFx::AS2::Value::ToStringImpl(v47, &index, penv, -1, 0);
            v48 = index.pNode;
            *(_DWORD *)&pdata[4 * v46] = index.pNode->pData;
            v49 = v24[6];
            v24[6] = v49 + 1;
            Scaleform::GFx::ASString::operator=(&v25->Data[v49], &index);
            if ( v48->RefCount-- == 1 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v48);
          }
          else
          {
            *(_DWORD *)&pdata[4 * v46] = 0;
          }
          count = (Scaleform::GFx::ASStringNode *)((char *)count + 4);
          ++v46;
        }
        while ( v46 < n );
      }
      break;
    case 4u:
      v51 = (unsigned int)count;
      v52 = 0;
      if ( RootIndex >= (unsigned int)count )
      {
        na = (unsigned int)count;
      }
      else
      {
        v51 = v22[1].RootIndex;
        na = v51;
      }
      if ( !v51 )
        v51 = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        v51);
      v53 = 0;
      if ( RootIndex )
      {
        index.pNode = (Scaleform::GFx::ASStringNode *)((int)index.pNode * 4);
        do
        {
          v54 = *(Scaleform::GFx::AS2::Value **)((char *)&index.pNode->pData + (unsigned int)pobj[1].pRCC);
          if ( v54 )
          {
            Scaleform::GFx::AS2::Value::ToStringImpl(v54, (Scaleform::GFx::ASString *)&count, penv, -1, 0);
            Scaleform::GFx::ASString::operator=(
              (Scaleform::GFx::ASString *)(*(_DWORD *)_CurrentState + 4 * v53),
              (const Scaleform::GFx::ASString *)&count);
            v52 += Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&count) + 1;
            v55 = count;
            --count->RefCount;
            if ( !v55->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v55);
          }
          index.pNode = (Scaleform::GFx::ASStringNode *)((char *)index.pNode + 4);
          ++v53;
        }
        while ( v53 < RootIndex );
      }
      v56 = v24[1];
      v57 = (2 * v52 + 4095) & 0xFFFFF000;
      if ( v56 < v57 || v56 > v57 && v56 - v57 > 0x1000 )
      {
        v58 = Scaleform::Memory::pGlobalHeap->__vftable;
        if ( *v24 )
          v59 = ((int (__stdcall *)(int, unsigned int))v58->Realloc)(*v24, v57);
        else
          v59 = ((int (__stdcall *)(unsigned int, _DWORD))v58->Alloc)(v57, 0);
        *v24 = v59;
        v24[1] = v57;
      }
      v60 = (_WORD *)*v24;
      v61 = 0;
      if ( na )
      {
        v62 = pdata;
        do
        {
          pdata = **(const char ***)(*(_DWORD *)_CurrentState + 4 * v61);
          v63 = v60;
          while ( 1 )
          {
            v64 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pdata);
            if ( !v64 )
              break;
            *v60++ = v64;
          }
          --pdata;
          *v60 = 0;
          *(_DWORD *)&v62[4 * v61++] = v63;
          ++v60;
        }
        while ( v61 < na );
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)_CurrentState,
        1u);
      break;
    case 5u:
      if ( RootIndex >= (unsigned int)count )
        RootIndex = (unsigned int)count;
      if ( RootIndex )
      {
        v40 = (char *)pdata;
        v41 = (int)index.pNode;
        v42 = RootIndex;
        do
        {
          v43 = (Scaleform::GFx::AS2::Value *)(&pobj[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[v41];
          if ( (*((_DWORD *)v40 + 1) & 0x40) != 0 )
          {
            (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v40 + 8))(v40, *((_DWORD *)v40 + 2));
            *(_DWORD *)v40 = 0;
          }
          *((_DWORD *)v40 + 1) = 0;
          if ( v43 )
            Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v71, penv, v43, (Scaleform::GFx::Value *)v40);
          else
            *((_DWORD *)v40 + 1) = 0;
          ++v41;
          v40 += 24;
          --v42;
        }
        while ( v42 );
      }
      break;
    default:
      break;
  }
  if ( retVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&retVal);
  v65 = path.pNode;
  --path.pNode->RefCount;
  if ( !v65->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v65);
  _controlfp_s((unsigned int *)&pdata, dpg.fpc, 0x30000u);
  return 1;
}
