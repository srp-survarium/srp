void __thiscall Scaleform::GFx::AS2::GASSharedObjectLoader::AddProperty(
        Scaleform::GFx::AS2::GASSharedObjectLoader *this,
        const Scaleform::String *name,
        const Scaleform::String *value,
        Scaleform::GFx::ASStringNode *type)
{
  Scaleform::GFx::AS2::ArrayObject *v5; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // edi
  bool v7; // zf
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  long double v10; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS2::Value v; // [esp+18h] [ebp-10h] BYREF

  v5 = (Scaleform::GFx::AS2::ArrayObject *)this->ObjectStack.Data.Data[this->ObjectStack.Data.Size - 1];
  v.T.Type = 0;
  switch ( (unsigned int)type )
  {
    case 0u:
      Scaleform::GFx::AS2::Value::DropRefs(&v);
      v.T.Type = 0;
      break;
    case 1u:
      Scaleform::GFx::AS2::Value::DropRefs(&v);
      v.T.Type = 1;
      break;
    case 2u:
      LOBYTE(value) = strncmp(
                        (const char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8),
                        (const char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1],
                        4u) == 0;
      Scaleform::GFx::AS2::Value::DropRefs(&v);
      v.T.Type = 2;
      v.V.BooleanValue = (char)value;
      break;
    case 5u:
      v10 = atof((char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      v.T.Type = 3;
      v.NV.NumberValue = v10;
      break;
    case 6u:
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     (char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8),
                     *(_DWORD *)(value->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++StringNode->RefCount;
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      v.T.Type = 5;
      v.NV.Int32Value = (int)StringNode;
      v7 = ++StringNode->RefCount == 1;
      --StringNode->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      break;
    default:
      break;
  }
  if ( this->bArrayIsTop )
  {
    Scaleform::GFx::AS2::ArrayObject::PushBack(v5, &v);
  }
  else
  {
    pEnv = this->pEnv;
    LOBYTE(value) = 0;
    type = Scaleform::GFx::ASStringManager::CreateStringNode(
             (Scaleform::GFx::ASStringManager *)pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             (char *)((name->HeapTypeBits & 0xFFFFFFFC) + 8),
             *(_DWORD *)(name->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++type->RefCount;
    v5->SetMember(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      this->pEnv,
      (const Scaleform::GFx::ASString *)&type,
      &v,
      (const Scaleform::GFx::AS2::PropFlags *)&value);
    v9 = type;
    --type->RefCount;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
}
