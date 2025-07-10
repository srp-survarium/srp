void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &> *da)
{
  const Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::VM *v7; // ebp
  const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &> *v9; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a0; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASString *p_a1; // ebx
  Scaleform::GFx::ASStringManager *v18; // edi
  Scaleform::GFx::ASStringNode *v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // edi

  v6 = result;
  v7 = vm;
  v9 = da;
  this->Vm = vm;
  this->r = v6;
  pNode = v9->_0.pNode;
  p_a0 = &this->a0;
  this->a0.pNode = v9->_0.pNode;
  ++pNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
    }
    else
    {
      pManager = p_a0->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v13 = p_a0->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      v15 = p_a0->pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      p_a0->pNode = p_NullStringNode;
    }
  }
  v16 = da->_1.pNode;
  p_a1 = &this->a1;
  this->a1.pNode = v16;
  ++v16->RefCount;
  if ( !v7->HandleException && argc > 1 )
  {
    if ( (argv[1].Flags & 0x1F) - 12 > 3 || argv[1].value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&da, &this->a1);
    }
    else
    {
      v18 = p_a1->pNode->pManager;
      ++v18->NullStringNode.RefCount;
      v19 = p_a1->pNode;
      v20 = &v18->NullStringNode;
      v15 = p_a1->pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      p_a1->pNode = v20;
    }
  }
}
