void __cdecl Scaleform::GFx::AS2::XmlNodeProto::RemoveNode(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::XML::Node *pObject; // eax
  Scaleform::GFx::XML::ElementNode *Parent; // edi
  Scaleform::GFx::XML::RootNode *RootNode; // eax
  Scaleform::RefCountNTSImpl *v8; // ecx
  Scaleform::GFx::XML::RootNode *v9; // ebx

  v1 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Du);
  v2 = Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu);
  if ( v1 || v2 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        pObject = (Scaleform::GFx::XML::Node *)p_pProto[14].pObject;
        if ( pObject )
        {
          Parent = pObject->Parent;
          if ( Parent )
          {
            RootNode = Scaleform::GFx::XML::ObjectManager::CreateRootNode(Parent->MemoryManager.pObject, pObject);
            v8 = (Scaleform::RefCountNTSImpl *)p_pProto[13].pObject;
            v9 = RootNode;
            if ( v8 )
              Scaleform::RefCountNTSImpl::Release(v8);
            p_pProto[13].pObject = (Scaleform::GFx::AS2::Object *)v9;
            Scaleform::GFx::XML::ElementNode::RemoveChild(Parent, (Scaleform::GFx::XML::Node *)p_pProto[14].pObject);
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
