void __cdecl Scaleform::GFx::AS2::XmlNodeProto::CloneNode(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  int p_pProto; // edi
  bool v5; // cc
  Scaleform::GFx::AS2::Value *v6; // eax
  _BYTE *v7; // ecx
  Scaleform::GFx::XML::ElementNode *v8; // ebx
  Scaleform::GFx::AS2::XmlNodeObject *v9; // edi
  unsigned int v10; // eax
  int v11; // edi
  unsigned __int8 v12; // dl
  Scaleform::GFx::AS2::XmlNodeObject *pObject; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-14h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> clone; // [esp+8h] [ebp-4h] BYREF

  v1 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Du);
  v2 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu);
  if ( !v1 && !v2 )
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XMLNode", 0, 0);
    return;
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    p_pProto = (int)&ThisPtr[-2].pProto;
    if ( p_pProto )
    {
      if ( *(_DWORD *)(p_pProto + 56) )
      {
        v5 = fn->NArgs <= 0;
        LOBYTE(clone.pObject) = 0;
        if ( !v5 )
        {
          Env = fn->Env;
          v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          LOBYTE(clone.pObject) = Scaleform::GFx::AS2::Value::ToBool(v6, p_pProto, Env);
        }
        v7 = *(_BYTE **)(p_pProto + 56);
        if ( v7[32] != 1 )
        {
          v11 = *(_DWORD *)(p_pProto + 56);
          v8 = (Scaleform::GFx::XML::ElementNode *)(*(int (__thiscall **)(_BYTE *, Scaleform::GFx::AS2::XmlNodeObject *))(*(_DWORD *)v7 + 4))(
                                                     v7,
                                                     clone.pObject);
          Scaleform::GFx::AS2::CreateShadow(&clone, fn->Env, v8, 0);
          v12 = *(_BYTE *)(v11 + 32);
          pObject = clone.pObject;
          v8->Type = v12;
          Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, pObject);
          if ( pObject )
          {
            RefCount = pObject->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
            }
          }
          goto LABEL_18;
        }
        v8 = (Scaleform::GFx::XML::ElementNode *)(*(int (__thiscall **)(_BYTE *, Scaleform::GFx::AS2::XmlNodeObject *))(*(_DWORD *)v7 + 4))(
                                                   v7,
                                                   clone.pObject);
        Scaleform::GFx::AS2::CreateShadow(&clone, fn->Env, v8, 0);
        v9 = clone.pObject;
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, clone.pObject);
        if ( v9 )
        {
          v10 = v9->RefCount;
          if ( (v10 & 0x3FFFFFF) != 0 )
          {
            v9->RefCount = v10 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
          }
        }
        if ( v8 )
LABEL_18:
          Scaleform::RefCountNTSImpl::Release(v8);
      }
    }
  }
}
