void __cdecl Scaleform::GFx::AS2::XmlNodeProto::HasChildNodes(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::XML::ElementNode *pObject; // ecx
  bool HasChildren; // al
  Scaleform::GFx::AS2::Value *v8; // edi
  bool v9; // bl

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
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 2;
        Result->V.BooleanValue = 0;
        pObject = (Scaleform::GFx::XML::ElementNode *)p_pProto[14].pObject;
        if ( pObject )
        {
          if ( pObject->Type == 1 )
          {
            HasChildren = Scaleform::GFx::XML::ElementNode::HasChildren(pObject);
            v8 = fn->Result;
            v9 = HasChildren;
            Scaleform::GFx::AS2::Value::DropRefs(v8);
            v8->T.Type = 2;
            v8->V.BooleanValue = v9;
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
