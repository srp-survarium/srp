void __thiscall Scaleform::GFx::AS3::Classes::fl::String::AS3fromCharCode(
        Scaleform::GFx::AS3::Classes::fl::String *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *v5; // ebx
  unsigned int v6; // esi
  Scaleform::GFx::AS3::Value *v7; // edi
  char *pData; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  unsigned int r; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::StringBuffer sb; // [esp+14h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&sb, Scaleform::Memory::pGlobalHeap);
  v5 = argc;
  v6 = 0;
  if ( argc )
  {
    v7 = argv;
    while ( Scaleform::GFx::AS3::Value::Convert2UInt32(v7, (Scaleform::GFx::AS3::CheckResult *)&argc, &r)->Result )
    {
      Scaleform::StringBuffer::AppendChar(&sb, (unsigned __int16)r);
      ++v6;
      ++v7;
      if ( v6 >= (unsigned int)v5 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    pData = sb.pData;
    if ( !sb.pData )
      pData = (char *)&buf;
    argc = Scaleform::GFx::ASStringManager::CreateStringNode(
             this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
             pData,
             sb.Size);
    ++argc->RefCount;
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&argc);
    v9 = argc;
    --argc->RefCount;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sb);
}
