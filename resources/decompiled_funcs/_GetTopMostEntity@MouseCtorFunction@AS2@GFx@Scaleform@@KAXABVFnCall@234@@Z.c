void __cdecl Scaleform::GFx::AS2::MouseCtorFunction::GetTopMostEntity(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  unsigned int v3; // edi
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::MovieImpl *v7; // ebx
  int v8; // eax
  int NArgs; // ecx
  Scaleform::GFx::AS2::Value *v10; // eax
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Environment *v12; // edx
  Scaleform::GFx::AS2::Value *v13; // ecx
  long double v14; // st7
  Scaleform::GFx::AS2::Environment *v15; // edx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value *v17; // ecx
  Scaleform::GFx::DisplayObjectBase *pMainMovie; // ecx
  double v19; // st7
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  Scaleform::GFx::AS2::Environment *v21; // [esp+160h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *v22; // [esp+160h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *v23; // [esp+160h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *v24; // [esp+160h] [ebp-64h]
  double v25; // [esp+17Ch] [ebp-48h]
  char v26; // [esp+184h] [ebp-40h]
  Scaleform::GFx::MovieImpl *pMovieImpl; // [esp+188h] [ebp-3Ch]
  float v28; // [esp+18Ch] [ebp-38h]
  float v29; // [esp+190h] [ebp-34h]
  float controllerIdx_4; // [esp+198h] [ebp-2Ch]
  Scaleform::Render::Point<float> v31; // [esp+19Ch] [ebp-28h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+1A4h] [ebp-20h] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  v3 = 0;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  v26 = 1;
  if ( fn->NArgs < 1 )
    goto LABEL_8;
  if ( fn->FirstArgBottomIndex > 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v4 = 0;
  else
    v4 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  if ( v4->T.Type == 2 )
  {
    v21 = fn->Env;
    v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v26 = Scaleform::GFx::AS2::Value::ToBool(v5, v21);
    if ( fn->NArgs >= 2 )
    {
      v22 = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v3 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v6, v22);
    }
    goto LABEL_8;
  }
  NArgs = fn->NArgs;
  if ( NArgs == 1 )
  {
    v23 = fn->Env;
    v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v3 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v10, v23);
LABEL_8:
    v7 = pMovieImpl;
    if ( v3 >= pMovieImpl->GetMouseCursorCount(pMovieImpl) )
      return;
    if ( v3 < 6 )
      v8 = (int)&pMovieImpl->mMouseState[v3];
    else
      v8 = 0;
    controllerIdx_4 = *(float *)(v8 + 36);
    v31.x = *(float *)(v8 + 32);
    v19 = controllerIdx_4;
    goto LABEL_22;
  }
  if ( NArgs < 2 )
    goto LABEL_8;
  if ( NArgs >= 3 )
  {
    v24 = fn->Env;
    v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
    v26 = Scaleform::GFx::AS2::Value::ToBool(v11, v24);
  }
  v12 = fn->Env;
  v13 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (v12->Stack.Pages.Data.Size - 1) + v12->Stack.pCurrent - v12->Stack.pPageStart )
    v13 = &v12->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  v14 = Scaleform::GFx::AS2::Value::ToNumber(v13, fn->Env);
  v15 = fn->Env;
  v29 = v14 * 20.0;
  v16 = fn->FirstArgBottomIndex - 1;
  v17 = 0;
  if ( v16 <= 32 * (v15->Stack.Pages.Data.Size - 1) + v15->Stack.pCurrent - v15->Stack.pPageStart )
    v17 = &v15->Stack.Pages.Data.Data[v16 >> 5]->Values[v16 & 0x1F];
  v25 = Scaleform::GFx::AS2::Value::ToNumber(v17, v15);
  v7 = pMovieImpl;
  pMainMovie = pMovieImpl->pMainMovie;
  if ( pMainMovie )
  {
    pmat.M[0][0] = 1.0;
    pmat.M[0][1] = 0.0;
    pmat.M[0][2] = 0.0;
    pmat.M[0][3] = 0.0;
    pmat.M[1][0] = 0.0;
    pmat.M[1][2] = 0.0;
    pmat.M[1][3] = 0.0;
    pmat.M[1][1] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pMainMovie, &pmat);
    v3 = 0;
    v28 = v25 * 20.0;
    v31.x = pmat.M[0][0] * v29 + v28 * pmat.M[0][1] + pmat.M[0][3];
    v19 = v28 * pmat.M[1][1] + v29 * pmat.M[1][0] + pmat.M[1][3];
LABEL_22:
    v31.y = v19;
    TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(v7, &v31, v3, v26, 0);
    if ( TopMostEntity )
      Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, TopMostEntity);
  }
}
