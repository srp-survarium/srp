Scaleform::GFx::AS2::FunctionObject *__thiscall Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(
        Scaleform::GFx::AS2::GlobalContext *this,
        const Scaleform::GFx::ASString *functionName)
{
  Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *BuiltinClassRegistrar; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *p_ResolvedFunc; // edi
  int v5; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::LocalFrame *v7; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // ecx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // ecx
  unsigned int v13; // eax
  unsigned __int8 Flags; // bl
  unsigned int v15; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *pNode; // [esp-4h] [ebp-2Ch]
  Scaleform::GFx::ASStringNode *v20; // [esp-4h] [ebp-2Ch]
  Scaleform::GFx::AS2::FunctionRefBase v21; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // [esp+1Ch] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // [esp+20h] [ebp-8h]
  char v24; // [esp+24h] [ebp-4h]

  pNode = functionName->pNode;
  ++pNode->RefCount;
  BuiltinClassRegistrar = Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(this, pNode);
  if ( !BuiltinClassRegistrar )
    return 0;
  p_ResolvedFunc = &BuiltinClassRegistrar->ResolvedFunc;
  if ( !BuiltinClassRegistrar->ResolvedFunc.pObject )
  {
    v5 = (int)BuiltinClassRegistrar->RegistrarFunc((Scaleform::GFx::AS2::FunctionRef *)&v22, this);
    Function = *(Scaleform::GFx::AS2::FunctionObject **)v5;
    v21.Flags = 0;
    v21.Function = Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    v7 = *(Scaleform::GFx::AS2::LocalFrame **)(v5 + 4);
    v21.pLocalFrame = 0;
    if ( v7 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v21, v7, *(_BYTE *)(v5 + 8) & 1);
      Function = v21.Function;
    }
    if ( (v24 & 2) == 0 )
    {
      if ( v22 )
      {
        RefCount = v22->RefCount;
        v9 = v22;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v22->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
    }
    v22 = 0;
    if ( (v24 & 1) == 0 )
    {
      if ( v23 )
      {
        v10 = v23->RefCount;
        v11 = v23;
        if ( (v10 & 0x3FFFFFF) != 0 )
        {
          v23->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
    }
    v20 = functionName->pNode;
    ++v20->RefCount;
    p_ResolvedFunc = &Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(this, v20)->ResolvedFunc;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    pObject = p_ResolvedFunc->pObject;
    if ( p_ResolvedFunc->pObject )
    {
      v13 = pObject->RefCount;
      if ( (v13 & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = v13 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    Flags = v21.Flags;
    p_ResolvedFunc->pObject = Function;
    if ( (Flags & 2) == 0 )
    {
      if ( Function )
      {
        v15 = Function->RefCount;
        if ( (v15 & 0x3FFFFFF) != 0 )
        {
          Function->RefCount = v15 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = v21.pLocalFrame;
      if ( v21.pLocalFrame )
      {
        v17 = v21.pLocalFrame->RefCount;
        if ( (v17 & 0x3FFFFFF) != 0 )
        {
          v21.pLocalFrame->RefCount = v17 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
  }
  return p_ResolvedFunc->pObject;
}
