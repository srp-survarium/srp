void __cdecl Scaleform::GFx::AS2::Selection::DoTransferFocus(Scaleform::GFx::MovieImpl *fn)
{
  Scaleform::GFx::AS2::Environment *pObject; // edx
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  long double v5; // st7
  Scaleform::GFx::AS2::Environment *v6; // edx
  Scaleform::GFx::FocusMovedType v7; // ebx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  unsigned int v10; // edi
  unsigned int pHeap; // eax
  Scaleform::GFx::AS2::Environment *v12; // esi
  int v13; // ecx
  Scaleform::GFx::CharacterHandle *v14; // ecx
  Scaleform::GFx::InteractiveObject *v15; // eax
  Scaleform::GFx::MovieImpl *proot; // [esp+10h] [ebp+4h]

  pObject = (Scaleform::GFx::AS2::Environment *)fn->AdvanceStats.pObject;
  proot = pObject->Target->pASRoot->pMovieImpl;
  v3 = (unsigned int)(&fn->pHeap[-1].TrackDebugInfo + 2);
  v4 = 0;
  if ( v3 <= 32 * (pObject->Stack.Pages.Data.Size - 1) + pObject->Stack.pCurrent - pObject->Stack.pPageStart )
    v4 = &pObject->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, (Scaleform::GFx::AS2::Environment *)fn->AdvanceStats.pObject);
  v6 = (Scaleform::GFx::AS2::Environment *)fn->AdvanceStats.pObject;
  v7 = (int)v5;
  v8 = (unsigned int)(&fn->pHeap[-1].TrackDebugInfo + 1);
  v9 = 0;
  if ( v8 <= 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart )
    v9 = &v6->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToUInt32(v9, (Scaleform::GFx::AS2::Environment *)fn->AdvanceStats.pObject);
  pHeap = (unsigned int)fn->pHeap;
  v12 = (Scaleform::GFx::AS2::Environment *)fn->AdvanceStats.pObject;
  v13 = 0;
  if ( pHeap <= 32 * (v12->Stack.Pages.Data.Size - 1) + v12->Stack.pCurrent - v12->Stack.pPageStart )
    v13 = (int)&v12->Stack.Pages.Data.Data[pHeap >> 5]->Values[pHeap & 0x1F];
  if ( *(_BYTE *)v13 == 7
    && v12
    && (v14 = *(Scaleform::GFx::CharacterHandle **)(v13 + 4)) != 0
    && (v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v14, v12->Target->pASRoot->pMovieImpl)) != 0 )
  {
    Scaleform::GFx::MovieImpl::TransferFocus(
      proot,
      LOBYTE(v15->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
    ? (Scaleform::GFx::Sprite *)v15
    : 0,
      v10,
      v7);
  }
  else
  {
    Scaleform::GFx::MovieImpl::TransferFocus(proot, 0, v10, v7);
  }
}
