void __thiscall Scaleform::GFx::AS3::Instances::fl::Error::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // ebx
  Scaleform::GFx::ASString *p_message; // edi
  Scaleform::GFx::ASStringManager *pManager; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi

  v3 = argv;
  if ( argc )
  {
    p_message = &this->message;
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->message);
    }
    else
    {
      pManager = p_message->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = p_message->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      if ( p_message->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      p_message->pNode = p_NullStringNode;
    }
  }
  if ( argc > 1
    && Scaleform::GFx::AS3::Value::Convert2Int32(v3 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, (int *)&argv)->Result )
  {
    this->ID = (int)argv;
  }
}
