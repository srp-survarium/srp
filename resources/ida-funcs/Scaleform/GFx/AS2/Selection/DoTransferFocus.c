void __cdecl Scaleform::GFx::AS2::Selection::DoTransferFocus(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  long double v5; // st7
  Scaleform::GFx::AS2::Environment *v6; // edx
  Scaleform::GFx::FocusMovedType v7; // ebx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  unsigned int v10; // edi
  unsigned int FirstArgBottomIndex; // eax
  Scaleform::GFx::AS2::Environment *v12; // esi
  int v13; // ecx
  Scaleform::GFx::CharacterHandle *v14; // ecx
  Scaleform::GFx::InteractiveObject *v15; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // [esp+10h] [ebp+4h]

  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  v3 = fn->FirstArgBottomIndex - 1;
  v4 = 0;
  if ( v3 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v4 = &Env->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, fn->Env);
  v6 = fn->Env;
  v7 = (int)v5;
  v8 = fn->FirstArgBottomIndex - 2;
  v9 = 0;
  if ( v8 <= 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart )
    v9 = &v6->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToUInt32(v9, fn->Env);
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  v12 = fn->Env;
  v13 = 0;
  if ( FirstArgBottomIndex <= 32 * (v12->Stack.Pages.Data.Size - 1) + v12->Stack.pCurrent - v12->Stack.pPageStart )
    v13 = (int)&v12->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  if ( *(_BYTE *)v13 == 7
    && v12
    && (v14 = *(Scaleform::GFx::CharacterHandle **)(v13 + 4)) != 0
    && (v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v14, v12->Target->pASRoot->pMovieImpl)) != 0 )
  {
    Scaleform::GFx::MovieImpl::TransferFocus(
      pMovieImpl,
      LOBYTE(v15->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
    ? (Scaleform::GFx::Sprite *)v15
    : 0,
      v10,
      v7);
  }
  else
  {
    Scaleform::GFx::MovieImpl::TransferFocus(pMovieImpl, 0, v10, v7);
  }
}
