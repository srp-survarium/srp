void __usercall Scaleform::GFx::AS2::ExecutionContext::StartDragOpCode(
        Scaleform::GFx::AS2::ExecutionContext *this@<ecx>,
        int a2@<edi>)
{
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // ecx
  bool v6; // al
  Scaleform::GFx::AS2::Environment *v7; // ecx
  Scaleform::GFx::ASStringNode *v8; // edi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **Data; // edi
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // ecx
  Scaleform::GFx::AS2::Environment *v15; // edx
  Scaleform::GFx::AS2::Value *v16; // ecx
  unsigned int v17; // eax
  Scaleform::GFx::AS2::Environment *v18; // edx
  Scaleform::GFx::AS2::Value *v19; // ecx
  unsigned int v20; // eax
  Scaleform::GFx::AS2::Environment *v21; // edx
  Scaleform::GFx::AS2::Value *v22; // ecx
  unsigned int v23; // eax
  int v24; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::ASStringNode *v27; // [esp+4h] [ebp-2Ch] BYREF
  bool lockCenter[4]; // [esp+8h] [ebp-28h]
  Scaleform::GFx::MovieImpl::DragState st; // [esp+Ch] [ebp-24h] BYREF

  st.BoundLT.y = 0.0;
  st.BoundLT.x = 0.0;
  pEnv = this->pEnv;
  st.BoundRB.y = 0.0;
  st.BoundRB.x = 0.0;
  st.CenterDelta.y = 0.0;
  st.pCharacter = 0;
  st.CenterDelta.x = 0.0;
  st.LockCenter = 0;
  st.Bound = 0;
  st.MouseIndex = -1;
  pCurrent = pEnv->Stack.pCurrent;
  if ( pCurrent <= pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  v6 = Scaleform::GFx::AS2::Value::ToBool(pPrevPageTop, a2, pEnv);
  v7 = this->pEnv;
  lockCenter[0] = v6;
  st.pCharacter = Scaleform::GFx::AS2::Environment::FindTargetByValue(
                    v7,
                    (Scaleform::GFx::ASStringNode *)v7->Stack.pCurrent);
  if ( !st.pCharacter && (*((_BYTE *)this + 54) & 1) != 0 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(
      this->pEnv->Stack.pCurrent,
      (Scaleform::GFx::ASString *)&v27,
      this->pEnv,
      -1,
      (Scaleform::GFx::ASString)1);
    v8 = v27;
    Scaleform::GFx::AS2::ActionLogger::LogScriptError(&this->LogF, "StartDrag of invalid target '%s'.", v27->pData);
    if ( v8->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  Data = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **)(32
                                                                                 * (this->pEnv->Stack.Pages.Data.Size - 1));
  v11 = (unsigned int)Data + this->pEnv->Stack.pCurrent - this->pEnv->Stack.pPageStart;
  v12 = 0;
  if ( v11 >= 2 )
  {
    Data = this->pEnv->Stack.Pages.Data.Data;
    v12 = &Data[(v11 - 2) >> 5]->Values[(v11 - 2) & 0x1F];
  }
  st.Bound = Scaleform::GFx::AS2::Value::ToBool(v12, (int)Data, this->pEnv);
  if ( st.Bound )
  {
    v13 = 32 * (this->pEnv->Stack.Pages.Data.Size - 1) + this->pEnv->Stack.pCurrent - this->pEnv->Stack.pPageStart;
    v14 = 0;
    if ( v13 >= 6 )
      v14 = &this->pEnv->Stack.Pages.Data.Data[(v13 - 6) >> 5]->Values[(v13 - 6) & 0x1F];
    *(float *)&v27 = Scaleform::GFx::AS2::Value::ToNumber(v14, this->pEnv);
    v15 = this->pEnv;
    v16 = 0;
    st.BoundLT.x = *(float *)&v27 * 20.0;
    v17 = 32 * (v15->Stack.Pages.Data.Size - 1) + v15->Stack.pCurrent - v15->Stack.pPageStart;
    if ( v17 >= 5 )
      v16 = &v15->Stack.Pages.Data.Data[(v17 - 5) >> 5]->Values[(v17 - 5) & 0x1F];
    *(float *)&v27 = Scaleform::GFx::AS2::Value::ToNumber(v16, v15);
    v18 = this->pEnv;
    v19 = 0;
    st.BoundLT.y = *(float *)&v27 * 20.0;
    v20 = 32 * (v18->Stack.Pages.Data.Size - 1) + v18->Stack.pCurrent - v18->Stack.pPageStart;
    if ( v20 >= 4 )
      v19 = &v18->Stack.Pages.Data.Data[(v20 - 4) >> 5]->Values[(v20 - 4) & 0x1F];
    *(float *)&v27 = Scaleform::GFx::AS2::Value::ToNumber(v19, v18);
    v21 = this->pEnv;
    v22 = 0;
    st.BoundRB.x = *(float *)&v27 * 20.0;
    v23 = 32 * (v21->Stack.Pages.Data.Size - 1) + v21->Stack.pCurrent - v21->Stack.pPageStart;
    if ( v23 >= 3 )
      v22 = &v21->Stack.Pages.Data.Data[(v23 - 3) >> 5]->Values[(v23 - 3) & 0x1F];
    *(float *)&v27 = Scaleform::GFx::AS2::Value::ToNumber(v22, v21);
    v24 = 4;
    p_Stack = &this->pEnv->Stack;
    st.BoundRB.y = *(float *)&v27 * 20.0;
    do
    {
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      if ( --p_Stack->pCurrent < p_Stack->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
      --v24;
    }
    while ( v24 );
  }
  if ( st.pCharacter )
  {
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, lockCenter[0], 0);
    pMovieImpl = this->pEnv->Target->pASRoot->pMovieImpl;
    if ( pMovieImpl )
      Scaleform::GFx::MovieImpl::SetDragState(pMovieImpl, &st);
  }
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&this->pEnv->Stack);
}
