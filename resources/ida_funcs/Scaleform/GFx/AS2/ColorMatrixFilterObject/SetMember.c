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
  unsigned int v12; // edx
  unsigned int Index[20]; // [esp+Ch] [ebp-50h]
  float vala; // [esp+68h] [ebp+Ch]

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
      Index[10] = 8;
      v10 = 0;
      v11 = v8[15] <= 0;
      Index[0] = 0;
      Index[1] = 1;
      Index[2] = 2;
      Index[3] = 3;
      Index[4] = 16;
      Index[5] = 4;
      Index[6] = 5;
      Index[7] = 6;
      Index[8] = 7;
      Index[9] = 17;
      Index[11] = 9;
      Index[12] = 10;
      Index[13] = 11;
      Index[14] = 18;
      Index[15] = 12;
      Index[16] = 13;
      Index[17] = 14;
      Index[18] = 15;
      Index[19] = 19;
      if ( !v11 )
      {
        do
        {
          vala = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)*(_DWORD *)(v8[14] + 4 * v10), penv);
          v12 = Index[v10++];
          *((float *)&pLocalFrame->Variables.mHash.pTable + v12) = vala;
        }
        while ( v10 < v8[15] );
      }
    }
  }
  return 1;
}
