void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::SetControllerFocusGroup(unsigned int fn)
{
  Scaleform::GFx::AS2::Value *v2; // edi
  Scaleform::GFx::AS2::Environment *v3; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::AS2::Value *v5; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // edx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  unsigned int v10; // eax
  bool v11; // al
  Scaleform::GFx::AS2::Value *v12; // esi
  bool v13; // bl
  unsigned int controllerIdx; // [esp+Ch] [ebp+4h]

  v2 = *(Scaleform::GFx::AS2::Value **)(fn + 4);
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( *(int *)(fn + 28) >= 2 )
  {
    v3 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
    pMovieImpl = v3->Target->pASRoot->pMovieImpl;
    v5 = 0;
    if ( *(_DWORD *)(fn + 32) <= 32 * (v3->Stack.Pages.Data.Size - 1) + v3->Stack.pCurrent - v3->Stack.pPageStart )
      v5 = &v3->Stack.Pages.Data.Data[*(_DWORD *)(fn + 32) >> 5]->Values[*(_DWORD *)(fn + 32) & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToUInt32(v5, *(Scaleform::GFx::AS2::Environment **)(fn + 24));
    v7 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
    controllerIdx = v6;
    v8 = *(_DWORD *)(fn + 32) - 1;
    v9 = 0;
    if ( v8 <= 32 * (v7->Stack.Pages.Data.Size - 1) + v7->Stack.pCurrent - v7->Stack.pPageStart )
      v9 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToUInt32(v9, v7);
    v11 = pMovieImpl->SetControllerFocusGroup(pMovieImpl, controllerIdx, v10);
    v12 = *(Scaleform::GFx::AS2::Value **)(fn + 4);
    v13 = v11;
    Scaleform::GFx::AS2::Value::DropRefs(v12);
    v12->V.BooleanValue = v13;
    v12->T.Type = 2;
  }
}
