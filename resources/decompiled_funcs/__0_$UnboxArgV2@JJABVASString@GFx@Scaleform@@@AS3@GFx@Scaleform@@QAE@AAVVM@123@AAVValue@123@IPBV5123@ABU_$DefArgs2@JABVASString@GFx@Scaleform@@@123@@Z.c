void __thiscall Scaleform::GFx::AS3::UnboxArgV2<long,long,Scaleform::GFx::ASString const &>::UnboxArgV2<long,long,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::AS3::UnboxArgV2<long,long,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<long,Scaleform::GFx::ASString const &> *da)
{
  bool v6; // zf
  Scaleform::GFx::AS3::VM *v7; // ebx
  const Scaleform::GFx::AS3::DefArgs2<long,Scaleform::GFx::ASString const &> *v8; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a1; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx

  v6 = argc == 0;
  v7 = vm;
  v8 = da;
  this->Result = result;
  this->Vm = v7;
  this->r = 0;
  this->a0 = v8->_0;
  if ( !v6 )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
  pNode = v8->_1.pNode;
  p_a1 = &this->a1;
  this->a1.pNode = pNode;
  ++pNode->RefCount;
  if ( !v7->HandleException && argc > 1 )
  {
    if ( (argv[1].Flags & 0x1F) - 12 > 3 || argv[1].value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a1);
    }
    else
    {
      pManager = p_a1->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v13 = p_a1->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      v6 = p_a1->pNode->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      p_a1->pNode = p_NullStringNode;
    }
  }
}
