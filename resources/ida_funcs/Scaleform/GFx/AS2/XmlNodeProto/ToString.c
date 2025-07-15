void __cdecl Scaleform::GFx::AS2::XmlNodeProto::ToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  bool v2; // al
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::XML::ElementNode *pObject; // eax
  char *pData; // esi
  unsigned int Size; // ebp
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v11; // zf
  Scaleform::GFx::AS2::Value *v12; // edi
  Scaleform::StringBuffer str; // [esp+8h] [ebp-18h] BYREF

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
    if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
    {
      Scaleform::StringBuffer::StringBuffer(&str, Scaleform::Memory::pGlobalHeap);
      pObject = (Scaleform::GFx::XML::ElementNode *)p_pProto[14].pObject;
      if ( pObject )
      {
        if ( pObject->Type == 1 )
          Scaleform::GFx::AS2::BuildXMLString(fn->Env, pObject, &str);
        else
          Scaleform::StringBuffer::AppendString(&str, (char *)pObject->Value.pNode->pData, 0xFFFFFFFF);
        pData = str.pData;
        Size = str.Size;
        if ( !str.pData )
          pData = (char *)&buf;
        StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(fn->Env->StringContext.pContext);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, pData, Size);
        ++StringNode->RefCount;
        Result = fn->Result;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 5;
        Result->NV.Int32Value = (int)StringNode;
        v11 = ++StringNode->RefCount == 1;
        --StringNode->RefCount;
        if ( v11 )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
          Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&str);
          return;
        }
      }
      else
      {
        v12 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v12);
        v12->T.Type = 0;
      }
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&str);
    }
  }
}
