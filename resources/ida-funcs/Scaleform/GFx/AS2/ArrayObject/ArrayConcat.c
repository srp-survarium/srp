void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayConcat(Scaleform::GFx::AS2::ArrayObject *fn)
{
  unsigned int RootIndex; // eax
  unsigned int v3; // edi
  Scaleform::GFx::AS2::ArrayObject *v4; // ebx
  int i; // edi
  Scaleform::GFx::AS2::Environment *pObject; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // edx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value val; // [esp+4h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v11; // [esp+18h] [ebp+4h]

  if ( fn->RootIndex && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)fn->RootIndex + 8))(fn->RootIndex) == 7 )
  {
    RootIndex = fn->RootIndex;
    if ( RootIndex )
      v3 = RootIndex - 16;
    else
      v3 = 0;
    *(_BYTE *)(v3 + 76) = 0;
    v4 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                               (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject,
                                               *(Scaleform::GFx::AS2::Object **)(fn->pProto.pObject[2].RefCount + 48),
                                               (const Scaleform::GFx::ASString *)(*(_DWORD *)(*(_DWORD *)(fn->pProto.pObject[2].RefCount + 20)
                                                                                            + 12)
                                                                                + 172),
                                               0,
                                               -1);
    v11 = v4;
    if ( v4 )
    {
      Scaleform::GFx::AS2::Value::Value(&val, (Scaleform::GFx::AS2::Object *)v3);
      Scaleform::GFx::AS2::ArrayObject::Concat(v4, (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject, &val);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      for ( i = 0; i < (int)fn->Members.mHash.pTable; ++i )
      {
        pObject = (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject;
        v7 = (unsigned int)fn->ResolveHandler.Function - i;
        v8 = 0;
        if ( v7 <= 32 * (pObject->Stack.Pages.Data.Size - 1) + pObject->Stack.pCurrent - pObject->Stack.pPageStart )
          v8 = &pObject->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
        v4 = v11;
        Scaleform::GFx::AS2::ArrayObject::Concat(v11, pObject, v8);
      }
    }
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)fn->pRCC, v4);
    if ( v4 )
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
