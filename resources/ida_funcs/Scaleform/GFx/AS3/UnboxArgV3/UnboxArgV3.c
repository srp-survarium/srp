void __thiscall Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const,long,long,Scaleform::GFx::ASString const &>::UnboxArgV3<Scaleform::GFx::AS3::Value const,long,long,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,long,long,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs3<long,long,Scaleform::GFx::ASString const &> *da)
{
  const Scaleform::GFx::AS3::DefArgs3<long,long,Scaleform::GFx::ASString const &> *v6; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a2; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v11; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx

  v6 = da;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  pNode = v6->_2.pNode;
  p_a2 = &this->a2;
  this->a2.pNode = pNode;
  ++pNode->RefCount;
  if ( !vm->HandleException && argc > 2 )
  {
    if ( (argv[2].Flags & 0x1F) - 12 > 3 || argv[2].value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a2);
    }
    else
    {
      pManager = p_a2->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v11 = p_a2->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      if ( p_a2->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      p_a2->pNode = p_NullStringNode;
    }
  }
}


void __thiscall Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const,bool,unsigned long,Scaleform::GFx::ASString const &>::UnboxArgV3<Scaleform::GFx::AS3::Value const,bool,unsigned long,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,bool,unsigned long,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs3<bool,unsigned long,Scaleform::GFx::ASString const &> *da)
{
  const Scaleform::GFx::AS3::DefArgs3<bool,unsigned long,Scaleform::GFx::ASString const &> *v6; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a2; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v11; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx

  v6 = da;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,bool,unsigned long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,bool,unsigned long>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  pNode = v6->_2.pNode;
  p_a2 = &this->a2;
  this->a2.pNode = pNode;
  ++pNode->RefCount;
  if ( !vm->HandleException && argc > 2 )
  {
    if ( (argv[2].Flags & 0x1F) - 12 > 3 || argv[2].value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->a2);
    }
    else
    {
      pManager = p_a2->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v11 = p_a2->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      if ( p_a2->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      p_a2->pNode = p_NullStringNode;
    }
  }
}
