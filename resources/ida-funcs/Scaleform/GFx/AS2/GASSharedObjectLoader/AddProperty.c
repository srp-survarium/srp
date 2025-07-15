void __userpurge Scaleform::GFx::AS2::GASSharedObjectLoader::AddProperty(
        Scaleform::GFx::AS2::GASSharedObjectLoader *this@<ecx>,
        int a2@<edi>,
        const Scaleform::String *name,
        const Scaleform::String *value,
        Scaleform::GFx::ASStringNode *type)
{
  Scaleform::GFx::AS2::ArrayObject *v6; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // edi
  bool v8; // zf
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  long double v11; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS2::Value val; // [esp+18h] [ebp-10h] BYREF

  v6 = (Scaleform::GFx::AS2::ArrayObject *)this->ObjectStack.Data.Data[this->ObjectStack.Data.Size - 1];
  val.T.Type = 0;
  switch ( (unsigned int)type )
  {
    case 0u:
      Scaleform::GFx::AS2::Value::DropRefs(&val);
      val.T.Type = 0;
      break;
    case 1u:
      Scaleform::GFx::AS2::Value::DropRefs(&val);
      val.T.Type = 1;
      break;
    case 2u:
      LOBYTE(value) = strncmp((const char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8), "true", 4u) == 0;
      Scaleform::GFx::AS2::Value::DropRefs(&val);
      val.T.Type = 2;
      val.V.BooleanValue = (char)value;
      break;
    case 5u:
      v11 = atof(a2, (char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      val.T.Type = 3;
      val.NV.NumberValue = v11;
      break;
    case 6u:
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     (__m128i *)((value->HeapTypeBits & 0xFFFFFFFC) + 8),
                     *(_DWORD *)(value->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++StringNode->RefCount;
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      val.T.Type = 5;
      val.NV.Int32Value = (int)StringNode;
      v8 = ++StringNode->RefCount == 1;
      --StringNode->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      break;
    default:
      break;
  }
  if ( this->bArrayIsTop )
  {
    Scaleform::GFx::AS2::ArrayObject::PushBack(v6, &val);
  }
  else
  {
    pEnv = this->pEnv;
    LOBYTE(value) = 0;
    type = Scaleform::GFx::ASStringManager::CreateStringNode(
             (Scaleform::GFx::ASStringManager *)pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             (__m128i *)((name->HeapTypeBits & 0xFFFFFFFC) + 8),
             *(_DWORD *)(name->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++type->RefCount;
    v6->SetMember(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      this->pEnv,
      (const Scaleform::GFx::ASString *)&type,
      &val,
      (const Scaleform::GFx::AS2::PropFlags *)&value);
    v10 = type;
    --type->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}
