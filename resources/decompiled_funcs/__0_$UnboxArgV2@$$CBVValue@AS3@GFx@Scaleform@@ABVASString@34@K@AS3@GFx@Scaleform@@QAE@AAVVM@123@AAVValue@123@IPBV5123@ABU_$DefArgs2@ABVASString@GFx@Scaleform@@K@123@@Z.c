void __thiscall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,unsigned long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,unsigned long>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,unsigned long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,unsigned long> *da)
{
  Scaleform::GFx::AS3::Value *v6; // ebx
  const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,unsigned long> *v8; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *p_a0; // edi
  Scaleform::GFx::ASStringManager *pManager; // ebx
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // ebx

  v6 = argv;
  v8 = da;
  this->Vm = vm;
  this->r = result;
  pNode = v8->_0.pNode;
  p_a0 = &this->a0;
  this->a0.pNode = v8->_0.pNode;
  ++pNode->RefCount;
  if ( argc )
  {
    if ( (v6->Flags & 0x1F) - 12 > 3 || v6->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a0);
    }
    else
    {
      pManager = p_a0->pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      v12 = p_a0->pNode;
      p_NullStringNode = &pManager->NullStringNode;
      if ( p_a0->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      p_a0->pNode = p_NullStringNode;
      v6 = argv;
    }
  }
  this->a1 = da->_1;
  if ( !vm->HandleException && argc > 1 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(v6 + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->a1);
}
