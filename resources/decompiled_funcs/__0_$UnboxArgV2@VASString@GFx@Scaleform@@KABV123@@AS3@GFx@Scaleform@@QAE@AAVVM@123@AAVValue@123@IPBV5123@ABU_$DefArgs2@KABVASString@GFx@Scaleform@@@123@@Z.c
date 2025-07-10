void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<unsigned long,Scaleform::GFx::ASString const &> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<unsigned long,Scaleform::GFx::ASString const &> *v6; // ebp
  Scaleform::GFx::AS3::VM *v8; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a1; // ebx
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi

  v6 = da;
  this->Result = result;
  v8 = vm;
  this->Vm = vm;
  p_EmptyStringNode = &v8->StringManagerRef->pStringManager->EmptyStringNode;
  this->r.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v10 = argc == 0;
  this->a0 = v6->_0;
  if ( !v10 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  pNode = v6->_1.pNode;
  p_a1 = &this->a1;
  this->a1.pNode = pNode;
  ++pNode->RefCount;
  if ( !v8->HandleException && argc > 1 )
  {
    if ( (argv[1].Flags & 0x1F) - 12 > 3 || argv[1].value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a1);
    }
    else
    {
      pManager = p_a1->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v14 = p_a1->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      v10 = p_a1->pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      p_a1->pNode = p_NullStringNode;
    }
  }
}
