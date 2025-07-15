char __thiscall Scaleform::GFx::AS2::ColorMatrixFilterObject::SetMember(
        Scaleform::GFx::AS2::ColorMatrixFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebp
  _DWORD *v8; // edi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v10; // esi
  bool v11; // cc
  int v12; // edx
  _DWORD v14[20]; // [esp+Ch] [ebp-50h]
  float v15; // [esp+68h] [ebp+Ch]

  if ( strcmp(name->pNode->pData, "matrix") )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  v6 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
  pLocalFrame = this->ResolveHandler.pLocalFrame;
  v8 = &v6->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
  if ( !pLocalFrame || pLocalFrame->RootIndex != 8 )
    return 0;
  if ( v6 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Array);
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *, int))(v8[4] + 72))(
           v8 + 4,
           penv,
           Prototype,
           1) )
    {
      v14[10] = 8;
      v10 = 0;
      v11 = v8[15] <= 0;
      v14[0] = 0;
      v14[1] = 1;
      v14[2] = 2;
      v14[3] = 3;
      v14[4] = 16;
      v14[5] = 4;
      v14[6] = 5;
      v14[7] = 6;
      v14[8] = 7;
      v14[9] = 17;
      v14[11] = 9;
      v14[12] = 10;
      v14[13] = 11;
      v14[14] = 18;
      v14[15] = 12;
      v14[16] = 13;
      v14[17] = 14;
      v14[18] = 15;
      v14[19] = 19;
      if ( !v11 )
      {
        do
        {
          v15 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)*(_DWORD *)(v8[14] + 4 * v10), penv);
          v12 = v14[v10++];
          *((float *)&pLocalFrame->Variables.mHash.pTable + v12) = v15;
        }
        while ( v10 < v8[15] );
      }
    }
  }
  return 1;
}
