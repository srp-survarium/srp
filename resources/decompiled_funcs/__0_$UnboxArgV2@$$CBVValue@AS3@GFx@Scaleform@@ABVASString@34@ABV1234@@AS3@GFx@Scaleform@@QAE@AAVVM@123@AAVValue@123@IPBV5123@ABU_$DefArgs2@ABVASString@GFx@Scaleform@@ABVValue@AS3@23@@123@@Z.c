void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &> *da)
{
  const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &> *v6; // edx
  Scaleform::GFx::AS3::Value *v7; // ebp
  const Scaleform::GFx::AS3::Value *v9; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a0; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx

  v6 = da;
  v7 = argv;
  v9 = result;
  this->Vm = vm;
  this->r = v9;
  pNode = v6->_0.pNode;
  p_a0 = &this->a0;
  this->a0.pNode = v6->_0.pNode;
  ++pNode->RefCount;
  if ( argc )
  {
    if ( (v7->Flags & 0x1F) - 12 > 3 || v7->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(v7, (Scaleform::GFx::AS3::CheckResult *)&vm, &this->a0);
    }
    else
    {
      pManager = p_a0->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v13 = p_a0->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      if ( p_a0->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      p_a0->pNode = p_NullStringNode;
    }
  }
  if ( argc <= 1 )
    this->a1 = &da->_1;
  else
    this->a1 = v7 + 1;
}
