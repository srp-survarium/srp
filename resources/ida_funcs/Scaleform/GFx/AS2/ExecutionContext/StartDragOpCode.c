void __thiscall Scaleform::GFx::AS2::ExecutionContext::StartDragOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // ecx
  Scaleform::GFx::InteractiveObject *TargetByValue; // eax
  Scaleform::GFx::AS2::Environment *v6; // edx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // ecx
  Scaleform::GFx::AS2::Environment *v11; // edx
  Scaleform::GFx::AS2::Value *v12; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // edx
  Scaleform::GFx::AS2::Value *v15; // ecx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Environment *v17; // edx
  Scaleform::GFx::AS2::Value *v18; // ecx
  unsigned int v19; // eax
  int v20; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  float v23; // [esp+4h] [ebp-2Ch]
  float v24; // [esp+4h] [ebp-2Ch]
  float v25; // [esp+4h] [ebp-2Ch]
  float v26; // [esp+4h] [ebp-2Ch]
  char lockCenter; // [esp+8h] [ebp-28h]
  Scaleform::GFx::MovieImpl::DragState st; // [esp+Ch] [ebp-24h] BYREF

  st.BoundLT.y = 0.0;
  pEnv = this->pEnv;
  st.BoundLT.x = 0.0;
  st.BoundRB.y = 0.0;
  st.pCharacter = 0;
  st.BoundRB.x = 0.0;
  st.LockCenter = 0;
  st.CenterDelta.y = 0.0;
  st.Bound = 0;
  st.CenterDelta.x = 0.0;
  st.MouseIndex = -1;
  pCurrent = pEnv->Stack.pCurrent;
  if ( pCurrent <= pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  lockCenter = Scaleform::GFx::AS2::Value::ToBool(pPrevPageTop, pEnv);
  TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(this->pEnv, this->pEnv->Stack.pCurrent);
  v6 = this->pEnv;
  st.pCharacter = TargetByValue;
  v7 = 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart;
  v8 = 0;
  if ( v7 >= 2 )
    v8 = &v6->Stack.Pages.Data.Data[(v7 - 2) >> 5]->Values[(v7 - 2) & 0x1F];
  st.Bound = Scaleform::GFx::AS2::Value::ToBool(v8, v6);
  if ( st.Bound )
  {
    v9 = 32 * (this->pEnv->Stack.Pages.Data.Size - 1) + this->pEnv->Stack.pCurrent - this->pEnv->Stack.pPageStart;
    v10 = 0;
    if ( v9 >= 6 )
      v10 = &this->pEnv->Stack.Pages.Data.Data[(v9 - 6) >> 5]->Values[(v9 - 6) & 0x1F];
    v23 = Scaleform::GFx::AS2::Value::ToNumber(v10, this->pEnv);
    v11 = this->pEnv;
    v12 = 0;
    st.BoundLT.x = v23 * 20.0;
    v13 = 32 * (v11->Stack.Pages.Data.Size - 1) + v11->Stack.pCurrent - v11->Stack.pPageStart;
    if ( v13 >= 5 )
      v12 = &v11->Stack.Pages.Data.Data[(v13 - 5) >> 5]->Values[(v13 - 5) & 0x1F];
    v24 = Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
    v14 = this->pEnv;
    v15 = 0;
    st.BoundLT.y = v24 * 20.0;
    v16 = 32 * (v14->Stack.Pages.Data.Size - 1) + v14->Stack.pCurrent - v14->Stack.pPageStart;
    if ( v16 >= 4 )
      v15 = &v14->Stack.Pages.Data.Data[(v16 - 4) >> 5]->Values[(v16 - 4) & 0x1F];
    v25 = Scaleform::GFx::AS2::Value::ToNumber(v15, v14);
    v17 = this->pEnv;
    v18 = 0;
    st.BoundRB.x = v25 * 20.0;
    v19 = 32 * (v17->Stack.Pages.Data.Size - 1) + v17->Stack.pCurrent - v17->Stack.pPageStart;
    if ( v19 >= 3 )
      v18 = &v17->Stack.Pages.Data.Data[(v19 - 3) >> 5]->Values[(v19 - 3) & 0x1F];
    v26 = Scaleform::GFx::AS2::Value::ToNumber(v18, v17);
    v20 = 4;
    p_Stack = &this->pEnv->Stack;
    st.BoundRB.y = v26 * 20.0;
    do
    {
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      if ( --p_Stack->pCurrent < p_Stack->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
      --v20;
    }
    while ( v20 );
  }
  if ( st.pCharacter )
  {
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, lockCenter, 0);
    pMovieImpl = this->pEnv->Target->pASRoot->pMovieImpl;
    if ( pMovieImpl )
      Scaleform::GFx::MovieImpl::SetDragState(pMovieImpl, &st);
  }
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&this->pEnv->Stack);
}
