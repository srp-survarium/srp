void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayPush(Scaleform::GFx::AS2::ArrayObject *fn)
{
  unsigned int RootIndex; // ebx
  Scaleform::GFx::AS2::ArrayObject *v3; // ebx
  int v4; // edi
  Scaleform::GFx::AS2::Object *pObject; // ecx
  int v6; // ebx
  Scaleform::GFx::AS2::Object *v7; // ebp
  $C9E2C53B7BF33D1B05D56CCE19B38030 *v8; // ecx
  unsigned int v9; // eax
  const Scaleform::GFx::AS2::Value *v10; // edx
  Scaleform::GFx::AS2::Value *pRCC; // esi
  int Size; // ebx
  Scaleform::GFx::AS2::ArrayObject *i; // [esp+8h] [ebp+4h]

  if ( fn->RootIndex && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)fn->RootIndex + 8))(fn->RootIndex) == 7 )
  {
    RootIndex = fn->RootIndex;
    if ( RootIndex )
      v3 = (Scaleform::GFx::AS2::ArrayObject *)(RootIndex - 16);
    else
      v3 = 0;
    v4 = 0;
    v3->LengthValueOverriden = 0;
    for ( i = v3; v4 < (int)fn->Members.mHash.pTable; ++v4 )
    {
      pObject = fn->pProto.pObject;
      v6 = (int)pObject->pRCC - pObject->RootIndex;
      v7 = pObject->pProto.pObject;
      v8 = &pObject->4;
      v9 = (unsigned int)fn->ResolveHandler.Function - v4;
      v10 = 0;
      if ( v9 <= 32 * (int)(&v7[-1].IsListenerSet + 2) + (v6 >> 4) )
        v10 = (const Scaleform::GFx::AS2::Value *)&(&v8[4].pRCC->__vftable)[v9 >> 5][4 * (v9 & 0x1F)];
      v3 = i;
      Scaleform::GFx::AS2::ArrayObject::PushBack(i, v10);
    }
    pRCC = (Scaleform::GFx::AS2::Value *)fn->pRCC;
    Size = v3->Elements.Data.Size;
    if ( pRCC->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pRCC);
    pRCC->NV.Int32Value = Size;
    pRCC->T.Type = 4;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
