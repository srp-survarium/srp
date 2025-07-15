void __cdecl Scaleform::GFx::AS2::XmlNodeProto::InsertBefore(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  Scaleform::GFx::XML::ElementNode *pObject; // ebx
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // esi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // edi
  Scaleform::GFx::AS2::RefCountCollector<323> *v11; // eax
  Scaleform::GFx::XML::ElementNode *NumPages; // eax
  Scaleform::RefCountNTSImpl *pRCC; // ebp
  Scaleform::GFx::AS2::RefCountCollector<323> *v14; // ecx
  Scaleform::GFx::AS2::Object *v15; // eax
  Scaleform::RefCountNTSImpl *v16; // ecx
  Scaleform::RefCountNTSImpl *v17; // edi
  Scaleform::GFx::AS2::RefCountCollector<323> *v18; // edx
  Scaleform::GFx::AS2::Object *v19; // eax
  Scaleform::RefCountNTSImpl *v20; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v22; // [esp-Ch] [ebp-18h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v23; // [esp+8h] [ebp-4h]

  v1 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Du);
  v2 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu);
  if ( v1 || v2 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      v23 = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        pObject = (Scaleform::GFx::XML::ElementNode *)p_pProto[14].pObject;
        if ( pObject )
        {
          if ( pObject->Type == 1 && fn->NArgs > 1 )
          {
            Env = fn->Env;
            v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
            v7 = Scaleform::GFx::AS2::Value::ToObject(v6, Env);
            v22 = fn->Env;
            v8 = v7;
            v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
            v10 = Scaleform::GFx::AS2::Value::ToObject(v9, v22);
            if ( v8 )
            {
              if ( v8->GetObjectType(&v8->Scaleform::GFx::AS2::ObjectInterface) == Object_XMLNode )
              {
                if ( v10
                  && v10->GetObjectType(&v10->Scaleform::GFx::AS2::ObjectInterface) == Object_XMLNode
                  && (v11 = v10[1].pRCC) != 0
                  && (NumPages = (Scaleform::GFx::XML::ElementNode *)v11->Roots.NumPages) != 0
                  && NumPages == pObject )
                {
                  pRCC = (Scaleform::RefCountNTSImpl *)v8[1].pRCC;
                  if ( pRCC )
                  {
                    ++pRCC->RefCount;
                    v14 = v8[1].pRCC;
                    if ( v14->Roots.NumPages )
                      Scaleform::GFx::XML::ElementNode::RemoveChild(
                        (Scaleform::GFx::XML::ElementNode *)v14->Roots.NumPages,
                        (Scaleform::GFx::XML::Node *)v8[1].pRCC);
                    Scaleform::GFx::XML::ElementNode::InsertBefore(
                      pObject,
                      (Scaleform::GFx::XML::Node *)v8[1].pRCC,
                      (Scaleform::GFx::XML::Node *)v10[1].pRCC);
                    v15 = v23[13].pObject;
                    if ( v15 )
                      ++v15->pRCC;
                    v16 = (Scaleform::RefCountNTSImpl *)v8[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
                    if ( v16 )
                      Scaleform::RefCountNTSImpl::Release(v16);
                    v8[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)v23[13].pObject;
                    Scaleform::RefCountNTSImpl::Release(pRCC);
                  }
                }
                else
                {
                  v17 = (Scaleform::RefCountNTSImpl *)v8[1].pRCC;
                  if ( v17 )
                  {
                    ++v17->RefCount;
                    v18 = v8[1].pRCC;
                    if ( v18->Roots.NumPages )
                      Scaleform::GFx::XML::ElementNode::RemoveChild(
                        (Scaleform::GFx::XML::ElementNode *)v18->Roots.NumPages,
                        (Scaleform::GFx::XML::Node *)v8[1].pRCC);
                    Scaleform::GFx::XML::ElementNode::AppendChild(pObject, (Scaleform::GFx::XML::Node *)v8[1].pRCC);
                    v19 = p_pProto[13].pObject;
                    if ( v19 )
                      ++v19->pRCC;
                    v20 = (Scaleform::RefCountNTSImpl *)v8[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
                    if ( v20 )
                      Scaleform::RefCountNTSImpl::Release(v20);
                    v8[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)p_pProto[13].pObject;
                    Scaleform::RefCountNTSImpl::Release(v17);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XMLNode", 0, 0);
  }
}
