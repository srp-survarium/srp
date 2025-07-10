void __cdecl Scaleform::GFx::AS2::XmlNodeProto::CloneNode(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  bool v5; // cc
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Object *pObject; // ecx
  Scaleform::GFx::XML::ElementNode *v8; // ebx
  Scaleform::GFx::AS2::XmlNodeObject *v9; // edi
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Object *v11; // edi
  unsigned __int8 Function; // dl
  Scaleform::GFx::AS2::XmlNodeObject *v13; // edi
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
    p_pProto = &ThisPtr[-2].pProto;
    if ( p_pProto )
    {
      if ( p_pProto[14].pObject )
      {
        v5 = fn->NArgs <= 0;
        LOBYTE(clone.pObject) = 0;
        if ( !v5 )
        {
          Env = fn->Env;
          v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          LOBYTE(clone.pObject) = Scaleform::GFx::AS2::Value::ToBool(v6, Env);
        }
        pObject = p_pProto[14].pObject;
        if ( LOBYTE(pObject->ResolveHandler.Function) != 1 )
        {
          v11 = p_pProto[14].pObject;
          v8 = (Scaleform::GFx::XML::ElementNode *)((int (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::XmlNodeObject *))pObject->Finalize_GC)(
                                                     pObject,
                                                     clone.pObject);
          Scaleform::GFx::AS2::CreateShadow(&clone, fn->Env, v8, 0);
          Function = (unsigned __int8)v11->ResolveHandler.Function;
          v13 = clone.pObject;
          v8->Type = Function;
          Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v13);
          if ( v13 )
          {
            RefCount = v13->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
            {
              v13->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
            }
          }
          goto LABEL_18;
        }
        v8 = (Scaleform::GFx::XML::ElementNode *)((int (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::XmlNodeObject *))pObject->Finalize_GC)(
                                                   pObject,
                                                   clone.pObject);
        Scaleform::GFx::AS2::CreateShadow(&clone, fn->Env, v8, 0);
        v9 = clone.pObject;
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, clone.pObject);
        if ( v9 )
        {
          v10 = v9->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v10) != 0 )
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
